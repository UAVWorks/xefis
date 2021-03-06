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

#ifndef XEFIS__MODULES__SYSTEMS__FLAPS_BUGS_H__INCLUDED
#define XEFIS__MODULES__SYSTEMS__FLAPS_BUGS_H__INCLUDED

// Standard:
#include <cstddef>
#include <set>

// Xefis:
#include <xefis/config/all.h>
#include <xefis/core/module.h>
#include <xefis/core/property.h>
#include <xefis/core/setting.h>
#include <xefis/support/airframe/flaps.h>
#include <xefis/utility/actions.h>


class FlapsBugsIO: public xf::ModuleIO
{
  public:
	/*
	 * Settings
	 */

	xf::Setting<double>				margin_factor	{ this, "margin_factor", 1.2 };

	/*
	 * Input
	 */

	xf::PropertyIn<si::Angle>		flaps_setting	{ this, "flaps-setting" };

	/*
	 * Output
	 */

	xf::PropertyOut<std::string>	flaps_up_label	{ this, "flaps-up-label" };
	xf::PropertyOut<si::Velocity>	flaps_up_speed	{ this, "flaps-up-speed" };
	xf::PropertyOut<std::string>	flaps_a_label	{ this, "flaps-a-label" };
	xf::PropertyOut<si::Velocity>	flaps_a_speed	{ this, "flaps-a-speed" };
	xf::PropertyOut<std::string>	flaps_b_label	{ this, "flaps-b-label" };
	xf::PropertyOut<si::Velocity>	flaps_b_speed	{ this, "flaps-b-speed" };
};


/**
 * Computes two speed bugs - for two adjacent flap settings - that should
 * be displayed on EFIS' speed ladder.
 */
class FlapsBugs: public xf::Module<FlapsBugsIO>
{
  public:
	// Ctor
	explicit
	FlapsBugs (std::unique_ptr<FlapsBugsIO>, xf::Flaps const& flaps, std::string_view const& instance = {});

  protected:
	// Module API
	void
	process (xf::Cycle const&) override;

  private:
	xf::Flaps const&			_flaps;
	xf::PropChanged<si::Angle>	_flaps_setting_changed	{ io.flaps_setting };
};

#endif
