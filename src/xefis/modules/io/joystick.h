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

#ifndef XEFIS__MODULES__IO__JOYSTICK_H__INCLUDED
#define XEFIS__MODULES__IO__JOYSTICK_H__INCLUDED

// Standard:
#include <cstddef>
#include <vector>
#include <array>

// Qt:
#include <QObject>
#include <QSocketNotifier>
#include <QTimer>
#include <QDomElement>

// Xefis:
#include <xefis/config/all.h>
#include <xefis/core/v2/module.h>
#include <xefis/core/v2/property.h>
#include <xefis/core/v2/setting.h>
#include <xefis/utility/range.h>


class JoystickInput:
	public QObject,
	public x2::Module
{
  public:
	/*
	 * Settings
	 */

	x2::Setting<bool>			restart_on_failure		{ this, true };

  private:
	Q_OBJECT

	// This is defined by HID interface:
	static constexpr size_t kMaxEventID = 256;

	// Events from HID device are identified by such an ID:
	typedef std::size_t HandlerID;

	enum class EventType
	{
		Unknown = 0,
		ButtonEvent,
		AxisEvent,
	};

	/**
	 * Base class for axes and buttons.
	 */
	class Handler
	{
	  public:
		/**
		 * Called when new joystick event comes.
		 * \param	value
		 *			Joystick event value, unchanged.
		 */
		virtual void
		handle (EventType, HandlerID, int32_t value) = 0;

		virtual void
		reset() = 0;
	};

	class Button: public Handler
	{
	  public:
		// Ctor
		Button (QDomElement const& button_element, x2::PropertyOut<bool>&);

		x2::PropertyOut<bool>&
		property();

		void
		handle (EventType, HandlerID, int32_t value) override;

		void
		reset() override;

	  private:
		void
		set_value (float value);

	  private:
		x2::PropertyOut<bool>&	_property;
	};

	class Axis: public Handler
	{
	  public:
		// Ctor
		Axis (QDomElement const& axis_element, x2::PropertyOut<double>&, x2::PropertyOut<si::Angle>&, xf::Range<si::Angle>& angle_range);

		/**
		 * Make Axis that is emulated by two buttons on the joystick.
		 */
		Axis (QDomElement const& axis_element, x2::PropertyOut<double>&, x2::PropertyOut<si::Angle>&, xf::Range<si::Angle>& angle_range, Optional<HandlerID> up_button_id, Optional<HandlerID> down_button_id);

		x2::PropertyOut<double>&
		property();

		void
		handle (EventType, HandlerID id, int32_t value) override;

		void
		reset() override;

	  private:
		void
		set_value (float value);

	  private:
		x2::PropertyOut<double>&	_property;
		x2::PropertyOut<si::Angle>&	_angle_property;
		xf::Range<si::Angle>&		_angle_range;
		float						_center			= 0.f;
		float						_dead_zone		= 0.f;
		float						_reverse		= 1.f;
		float						_scale			= 1.f;
		float						_power			= 1.f;
		float						_output_minimum	= -1.f;
		float						_output_maximum	= +1.f;
		// If these are present, Axis is emulated with those two buttons,
		// that is when they're present, the property will be set to +1 or -1.
		Optional<HandlerID>			_up_button_id;
		Optional<HandlerID>			_down_button_id;
	};

	typedef std::array<std::vector<Shared<Handler>>, kMaxEventID>		Handlers;
	typedef std::array<Unique<x2::PropertyOut<bool>>, kMaxEventID>		ButtonProperties;
	typedef std::array<Unique<x2::PropertyOut<double>>, kMaxEventID>	AxisProperties;
	typedef std::array<Unique<x2::PropertyOut<si::Angle>>, kMaxEventID>	AngleAxisProperties;
	typedef std::array<xf::Range<si::Angle>, kMaxEventID>				AngleAxisRanges;

  public:
	// Ctor
	JoystickInput (QDomElement const& config, std::string const& instance = {});

	// Module API
	void
	initialize() override;

	/**
	 * Return reference to a button property.
	 */
	x2::PropertyOut<bool>&
	button (HandlerID);

	/**
	 * Return reference to an axis property.
	 */
	x2::PropertyOut<double>&
	axis (HandlerID);

	/**
	 * Return reference to an axis property that uses si::Angle.
	 * The range is defined per-axis, and subsequent calls to the same axis with different ranges will overwrite
	 * previous ranges.
	 */
	x2::PropertyOut<si::Angle>&
	angle_axis (HandlerID, xf::Range<si::Angle>);

  private slots:
	/**
	 * Try to open input device.
	 */
	void
	open_device();

	/**
	 * Close device after failure is detected.
	 */
	void
	failure();

	/**
	 * Start reopen timer.
	 */
	void
	restart();

	/**
	 * Read event from the device.
	 */
	void
	read();

  private:
	/**
	 * Set all properties to nil.
	 */
	void
	reset_properties();

  private:
	Optional<std::string>	_device_path;
	int						_device				= 0;
	Unique<QSocketNotifier>	_notifier;
	Unique<QTimer>			_reopen_timer;
	std::set<HandlerID>		_available_buttons;
	std::set<HandlerID>		_available_axes;
	Handlers				_handlers;
	ButtonProperties		_button_properties;
	AxisProperties			_axis_properties;
	AngleAxisProperties		_angle_axis_properties;
	AngleAxisRanges			_angle_axis_ranges;
	unsigned int			_failure_count		= 0;
};


inline x2::PropertyOut<bool>&
JoystickInput::button (HandlerID id)
{
	return *_button_properties[id];
}


inline x2::PropertyOut<double>&
JoystickInput::axis (HandlerID id)
{
	return *_axis_properties[id];
}


inline x2::PropertyOut<si::Angle>&
JoystickInput::angle_axis (HandlerID id, xf::Range<si::Angle> range)
{
	_angle_axis_ranges[id] = range;
	return *_angle_axis_properties[id];
}

#endif