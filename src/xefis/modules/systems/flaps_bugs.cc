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

// Xefis:
#include <xefis/config/all.h>

// Local:
#include "flaps_bugs.h"


FlapsBugs::FlapsBugs (std::unique_ptr<FlapsBugsIO> module_io, xf::Flaps const& flaps, std::string_view const& instance):
	Module (std::move (module_io), instance),
	_flaps (flaps)
{ }


void
FlapsBugs::process (xf::Cycle const&)
{
	if (_flaps_setting_changed())
	{
		if (io.flaps_setting)
		{
			io.flaps_up_label = "UP";
			io.flaps_up_speed = *io.margin_factor * _flaps.find_setting (0_deg).speed_range().min();

			std::optional<std::string> label_a;
			std::optional<si::Velocity> speed_a;
			std::optional<std::string> label_b;
			std::optional<si::Velocity> speed_b;

			auto sett_b = _flaps.find_setting (*io.flaps_setting);
			auto sett_a = sett_b.prev();

			label_b = sett_b.label().toStdString();
			speed_b = *io.margin_factor * sett_b.speed_range().min();

			if (sett_a)
			{
				label_a = sett_a->label().toStdString();
				speed_a = *io.margin_factor * sett_a->speed_range().min();
			}

			io.flaps_a_label = label_a;
			io.flaps_a_speed = speed_a;
			io.flaps_b_label = label_b;
			io.flaps_b_speed = speed_b;
		}
		else
		{
			io.flaps_a_label = xf::nil;
			io.flaps_a_speed = xf::nil;
			io.flaps_b_label = xf::nil;
			io.flaps_b_speed = xf::nil;
		}
	}
}

