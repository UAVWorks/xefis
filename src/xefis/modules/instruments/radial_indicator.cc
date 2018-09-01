/* vim:ts=4
 *
 * Copyleft 2012…2016  Michał Gawron
 * Marduk Unix Labs, http://mulabs.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Visit http://www.gnu.org/licenses/gpl-3.0.html for more information on licensing.
 */

// Standard:
#include <cstddef>
#include <vector>

// Xefis:
#include <xefis/config/all.h>
#include <xefis/utility/numeric.h>

// Local:
#include "radial_indicator.h"


static QColor const normal_fill (0x43, 0x49, 0x54);


void
BasicRadialIndicator::paint (xf::PaintRequest& paint_request, IndicatorValues& values) const
{
	auto aids = get_aids (paint_request);
	auto painter = get_painter (paint_request);
	auto rect = aids->centered_rect (paint_request.canvas().rect(), xf::WidthForHeight (250.0 / 200.0));
	float const q = 0.068f * rect.height();
	float const r = values.dial_scale * 6.5f * q;

	painter.translate (aids->width() / 2.f, aids->height() / 2.4f);
	paint_text (values, paint_request, *aids, painter, q);
	paint_indicator (values, *aids, painter, r);
}


void
BasicRadialIndicator::paint_text (IndicatorValues& values, xf::PaintRequest const& paint_request, xf::InstrumentAids& aids, xf::InstrumentPainter& painter, float q) const
{
	QFont const font (aids.font_5.font);
	QFontMetricsF const metrics (font);
	QFont const small_font (aids.font_3.font);
	QFontMetricsF const small_metrics (small_font);

	QPen text_pen = aids.get_pen (Qt::white, 0.8f);
	QPen box_pen = text_pen;

	if (values.critical_condition)
	{
		text_pen = aids.get_pen (kCriticalColor, 1.0f);
		box_pen = text_pen;
	}
	else if (values.warning_condition)
	{
		text_pen = aids.get_pen (kWarningColor, 1.0f);
		box_pen.setColor (kCriticalColor);
	}

	float const margin = 0.4f * q;
	float const zero_width = metrics.width ('0');
	float const small_zero_width = small_metrics.width ('0');

	if (paint_request.size_changed() || !_box_text_width)
	{
		QString const sample_text = QString::fromStdString ((boost::format (values.format) % 0.0).str());
		const_cast<BasicRadialIndicator*> (this)->_box_text_width = metrics.width (sample_text);
	}

	QRectF text_rect (0.5f * text_pen.width(), -0.6f * q, *_box_text_width, 0.9f * metrics.height());
	text_rect.translate (margin, -text_rect.height());
	QRectF rect = text_rect.adjusted (-margin, 0, margin, 0);

	painter.save_context ([&] {
		painter.setFont (font);

		if (values.value_str)
		{
			painter.setPen (box_pen);
			painter.drawRect (rect);
			painter.setPen (text_pen);
			painter.fast_draw_text (text_rect, Qt::AlignRight | Qt::AlignVCenter, QString::fromStdString (*values.value_str));
		}
		else
		{
			painter.setPen (box_pen);
			painter.drawRect (rect);
		}

		if (values.reference_str)
		{
			painter.setFont (small_font);
			painter.setPen (aids.get_pen (Qt::green, 1.0f));
			painter.fast_draw_text (QPointF (text_rect.right() - zero_width + small_zero_width, text_rect.top()),
									Qt::AlignBottom | Qt::AlignRight,
									QString::fromStdString (*values.reference_str));
		}
	});
}


void
BasicRadialIndicator::paint_indicator (IndicatorValues& values, xf::InstrumentAids& aids, xf::InstrumentPainter& painter, float r) const
{
	constexpr si::Angle kValueSpanAngle = 210_deg;

	auto get_round_pen = [&aids] (QColor color, float width) {
		QPen pen = aids.get_pen (color, width);
		pen.setCapStyle (Qt::RoundCap);
		return pen;
	};

	auto get_angle = [](std::optional<float> const& normalized) -> std::optional<si::Angle> {
		if (normalized)
			return kValueSpanAngle * *normalized;
		else
			return std::nullopt;
	};

	std::optional<si::Angle> const value_angle = get_angle (values.normalized_value);
	std::optional<si::Angle> const reference_angle = get_angle (values.normalized_reference);
	std::optional<si::Angle> const target_angle = get_angle (values.normalized_target);
	std::optional<si::Angle> const automatic_angle = get_angle (values.normalized_automatic);

	QPen const silver_pen = get_round_pen (kSilver, 1.f);
	QPen const pen = get_round_pen (Qt::white, 1.f);
	QPen const pointer_pen = get_round_pen (Qt::white, 1.2f);
	QPen const warning_pen = get_round_pen (kWarningColor, 1.1f);
	QPen const critical_pen = get_round_pen (kCriticalColor, 1.1f);
	QPen const reference_pen = get_round_pen (QColor (0x00, 0xff, 0x00), 1.f);
	QPen zero_point_pen = get_round_pen (normal_fill.lighter (150), 1.f);
	QPen const automatic_pen = get_round_pen (QColor (0x22, 0xaa, 0xff), 1.1f);
	QRectF const rect (-r, -r, 2.f * r, 2.f * r);

	xf::Shadow black_shadow;
	black_shadow.set_color (Qt::black);

	painter.save_context ([&] {
		if (value_angle)
		{
			// Filled pie:
			painter.save_context ([&] {
				QBrush brush (normal_fill, Qt::SolidPattern);

				if (values.critical_condition)
				{
					brush.setColor (kCriticalColor.darker (120));
					zero_point_pen.setColor (kCriticalColor.lighter (120));
				}
				else if (values.warning_condition)
				{
					brush.setColor (kWarningColor.darker (120));
					zero_point_pen.setColor (kWarningColor.lighter (120));
				}

				painter.setPen (Qt::NoPen);
				painter.setBrush (brush);
				painter.drawPie (rect, aids.angle_for_qpainter (0_deg), -aids.angle_for_qpainter (*value_angle));
				painter.setPen (zero_point_pen);
				painter.drawLine (QPointF (0.f, 0.f), QPointF (r, 0.f));
			});
		}

		// Warning/critical bugs:
		painter.save_context ([&] {
			constexpr si::Angle angle_gap = 4_deg;

			std::optional<si::Angle> const minimum_critical_angle = get_angle (values.normalized_minimum_critical);
			std::optional<si::Angle> const minimum_warning_angle = get_angle (values.normalized_minimum_warning);
			std::optional<si::Angle> const maximum_warning_angle = get_angle (values.normalized_maximum_warning);
			std::optional<si::Angle> const maximum_critical_angle = get_angle (values.normalized_maximum_critical);

			QPen const no_pen;
			QColor const no_color;
			float const no_tick_len {};
			float const tick_dir = values.normalized_reference ? -1.5f : +1.f;
			auto& point_infos = values.point_infos;

			point_infos.clear();
			point_infos.push_back ({ PointInfo::Minimums, 0_deg, no_pen, no_tick_len });

			if (minimum_critical_angle)
				point_infos.push_back ({ PointInfo::Minimums, *minimum_critical_angle, critical_pen, tick_dir * 0.2f * r });

			if (minimum_warning_angle)
				point_infos.push_back ({ PointInfo::Minimums, *minimum_warning_angle, warning_pen, tick_dir * (minimum_critical_angle ? 0.1f : 0.2f) * r });

			if (maximum_warning_angle)
				point_infos.push_back ({ PointInfo::Maximums, *maximum_warning_angle, warning_pen, tick_dir * (maximum_critical_angle ? 0.1f : 0.2f) * r });

			if (maximum_critical_angle)
				point_infos.push_back ({ PointInfo::Maximums, *maximum_critical_angle, critical_pen, tick_dir * 0.2f * r });

			point_infos.push_back ({ PointInfo::Maximums, kValueSpanAngle, no_pen, no_tick_len });

			// Actual painting:
			for (size_t i = 0u; i < point_infos.size() - 1; ++i)
			{
				PointInfo const prev = point_infos[i];
				PointInfo const next = point_infos[i + 1];
				bool const add_min_gap = (prev.zone == PointInfo::Minimums) && (i > 0);
				bool const add_max_gap = (next.zone == PointInfo::Maximums) && (i < point_infos.size() - 2);

				painter.save_context ([&] {
					auto const angle_0 = prev.angle + (add_min_gap ? angle_gap : 0_rad);
					auto const angle_1 = next.angle - (add_max_gap ? angle_gap : 0_rad);
					auto const span = angle_1 - angle_0;

					if (next.zone == PointInfo::Minimums)
					{
						painter.setPen (next.pen);
						painter.drawArc (rect, -aids.angle_for_qpainter (angle_0), -aids.angle_for_qpainter (span));
						painter.rotate (angle_1.in<si::Degree>());
						painter.drawLine (QPointF (r, 0.f), QPointF (r + next.tick_len, 0.f));
					}
					else if (next.zone != PointInfo::Minimums && prev.zone != PointInfo::Maximums)
					{
						if (values.critical_condition)
							painter.setPen (critical_pen);
						else if (values.warning_condition)
							painter.setPen (warning_pen);
						else
							painter.setPen (silver_pen);

						painter.drawArc (rect, -aids.angle_for_qpainter (angle_0), -aids.angle_for_qpainter (span));
					}
					else if (prev.zone == PointInfo::Maximums)
					{
						painter.setPen (prev.pen);
						painter.drawArc (rect, -aids.angle_for_qpainter (angle_0), -aids.angle_for_qpainter (span));
						painter.rotate (angle_0.in<si::Degree>());
						painter.drawLine (QPointF (r, 0.f), QPointF (r + prev.tick_len, 0.f));
					}
				});
			}

			// Normal value bug:
			if (reference_angle)
			{
				painter.setPen (reference_pen);
				painter.rotate (reference_angle->in<si::Degree>());
				painter.drawLine (QPointF (r + aids.pen_width (1.f), 0.f), QPointF (1.17f * r, 0.f));
				painter.drawLine (QPointF (1.15f * r, 0.f), QPointF (1.3f * r, -0.14f * r));
				painter.drawLine (QPointF (1.15f * r, 0.f), QPointF (1.3f * r, +0.14f * r));
			}
		});

		// Needle:
		if (value_angle)
		{
			painter.rotate (value_angle->in<si::Degree>());

			auto draw_outside_arc = [&] (si::Angle angle, float ext_adj, float intr, float extr, bool with_core_pointer)
			{
				painter.paint (black_shadow, [&] {
					painter.save_context ([&] {
						if (with_core_pointer)
							painter.drawLine (QPointF (0.0, 0.0), QPointF (extr, 0.0));
						else
							painter.drawLine (QPointF (1.0, 0.0), QPointF (extr, 0.0));

						painter.rotate ((angle - *value_angle).in<si::Degree>());
						painter.drawLine (QPointF (intr, 0.0), QPointF (extr, 0.0));
						painter.drawArc (rect.adjusted (-ext_adj, -ext_adj, +ext_adj, +ext_adj),
										 -aids.angle_for_qpainter (0_deg),
										 -aids.angle_for_qpainter (*value_angle - angle));
					});
				});
			};

			painter.save_context ([&] {
				painter.setPen (automatic_pen);

				if (automatic_angle)
					draw_outside_arc (*automatic_angle, 0.10 * r, 0.95 * r, 1.10 * r, false);
			});

			if (values.critical_condition)
				painter.setPen (critical_pen);
			else if (values.warning_condition)
				painter.setPen (warning_pen);
			else
				painter.setPen (pointer_pen);

			if (target_angle)
				draw_outside_arc (*target_angle, 0.15 * r, 1.01 * r, 1.15 * r, true);
			else
			{
				painter.paint (black_shadow, [&] {
					painter.drawLine (QPointF (0.0, 0.0), QPointF (0.99f * r, 0.0));
				});
			}
		}
	});
}

