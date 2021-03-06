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

#ifndef XEFIS__MODULES__SYSTEMS__AFCS_AP_H__INCLUDED
#define XEFIS__MODULES__SYSTEMS__AFCS_AP_H__INCLUDED

// Standard:
#include <cstddef>

// Xefis:
#include <xefis/config/all.h>
#include <xefis/core/logger.h>
#include <xefis/core/module.h>
#include <xefis/core/property.h>
#include <xefis/core/property_observer.h>
#include <xefis/core/setting.h>
#include <xefis/support/control/pid_controller.h>
#include <xefis/utility/smoother.h>


class AFCS_AP_IO: public xf::ModuleIO
{
  public:
	/*
	 * Settings
	 */

	xf::Setting<double>				overall_gain			{ this, "overall_gain", 1.0 };
	xf::Setting<xf::PIDSettings<>>	pitch_pid_settings		{ this, "pitch_pid_settings" };
	xf::Setting<double>				pitch_gain				{ this, "pitch_gain", 1.0 };
	xf::Setting<xf::PIDSettings<>>	roll_pid_settings		{ this, "roll_pid_settings" };
	xf::Setting<double>				roll_gain				{ this, "roll_gain", 1.0 };

	/*
	 * Input
	 */

	xf::PropertyIn<si::Angle>		cmd_pitch				{ this, "cmd-pitch" };
	xf::PropertyIn<si::Angle>		cmd_roll				{ this, "cmd-roll" };
	xf::PropertyIn<si::Angle>		measured_pitch			{ this, "measured-pitch" };
	xf::PropertyIn<si::Angle>		measured_roll			{ this, "measured-roll" };
	xf::PropertyIn<si::Angle>		elevator_minimum		{ this, "limits/elevator/minimum" };
	xf::PropertyIn<si::Angle>		elevator_maximum		{ this, "limits/elevator/maximum" };
	xf::PropertyIn<si::Angle>		ailerons_minimum		{ this, "limits/ailerons/minimum" };
	xf::PropertyIn<si::Angle>		ailerons_maximum		{ this, "limits/ailerons/maximum" };

	/*
	 * Output
	 */

	xf::PropertyOut<bool>			serviceable				{ this, "serviceable" };
	xf::PropertyOut<si::Angle>		elevator				{ this, "elevator" };
	xf::PropertyOut<si::Angle>		ailerons				{ this, "ailerons" };
};


/**
 * Steers control surfaces (ailerons, elevator) to obtain desired orientation (pitch, roll).
 */
class AFCS_AP: public xf::Module<AFCS_AP_IO>
{
  private:
	static constexpr char kLoggerScope[] = "mod::AFCS_AP";

  public:
	// Ctor
	explicit
	AFCS_AP (std::unique_ptr<AFCS_AP_IO>, xf::Logger const&, std::string_view const& instance = {});

  protected:
	// Module API
	void
	initialize() override;

	// Module API
	void
	process (xf::Cycle const&) override;

	// Module API
	void
	rescue (xf::Cycle const&, std::exception_ptr) override;

  private:
	/**
	 * Do all FBW computations and write to output properties.
	 */
	void
	compute_ap();

	/**
	 * Check properties and diagnose problem on the log.
	 */
	void
	diagnose();

  private:
	xf::Logger								_logger;
	xf::PIDController<si::Angle, si::Angle>	_elevator_pid;
	xf::PIDController<si::Angle, si::Angle>	_ailerons_pid;
	xf::Smoother<si::Angle>					_elevator_smoother	{ 50_ms };
	xf::Smoother<si::Angle>					_ailerons_smoother	{ 50_ms };
	xf::PropertyObserver					_ap_computer;
};

#endif
