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

#ifndef XEFIS__MODULES__SYSTEMS__SPEEDS_H__INCLUDED
#define XEFIS__MODULES__SYSTEMS__SPEEDS_H__INCLUDED

// Standard:
#include <cstddef>

// Xefis:
#include <xefis/config/all.h>
#include <xefis/core/module.h>
#include <xefis/core/property.h>
#include <xefis/core/property_observer.h>


class SpeedsIO: public xf::ModuleIO
{
  public:
	/*
	 * Input
	 */

	xf::PropertyIn<si::Angle>		flaps_angle				{ this, "flaps-angle" };
	xf::PropertyIn<si::Velocity>	stall_speed_5deg		{ this, "stall-speed" };

	/*
	 * Output
	 */

	xf::PropertyOut<si::Velocity>	speed_minimum			{ this, "speed.minimum" };
	xf::PropertyOut<si::Velocity>	speed_minimum_maneuver	{ this, "speed.minimum-maneuver" };
	xf::PropertyOut<si::Velocity>	speed_maximum_maneuver	{ this, "speed.maximum-maneuver" };
	xf::PropertyOut<si::Velocity>	speed_maximum			{ this, "speed.maximum" };
};


class Speeds: public xf::Module<SpeedsIO>
{
  public:
	// Ctor
	explicit
	Speeds (std::unique_ptr<SpeedsIO>, xf::Airframe*, std::string_view const& instance = {});

	// Module API
	void
	process (xf::Cycle const&) override;

  private:
	void
	compute();

	template<class T>
		static T
		max (std::optional<T>, T);

	template<class T>
		static T
		min (std::optional<T>, T);

  private:
	xf::Airframe*			_airframe;
	xf::PropertyObserver	_speeds_computer;
};

#endif

