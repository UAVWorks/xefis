/* vim:ts=4
 *
 * Copyleft 2008…2013  Michał Gawron
 * Marduk Unix Labs, http://mulabs.org/
 *
 * This code was based on awesome source released by Written by Curtis L. Olson (started July 2000).
 * <http://www.flightgear.org/~curt> and available in SimGear library.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Visit http://www.gnu.org/licenses/gpl-3.0.html for more information on licensing.
 */

#ifndef XEFIS__SUPPORT__EARTH__NAVIGATION__MAGNETIC_VARIATION_H__INCLUDED
#define XEFIS__SUPPORT__EARTH__NAVIGATION__MAGNETIC_VARIATION_H__INCLUDED

// Standard:
#include <cstddef>

// Xefis:
#include <xefis/config/all.h>
#include <xefis/utility/numeric.h>


namespace xf {

/**
 * Original implementation wrapped in an object, so it doesn't work on a global state (sic!)
 */
class MagneticVariationImpl
{
  public:
	// Ctor
	MagneticVariationImpl();

	unsigned long int
	yymmdd_to_julian_days (int yyyy, int mm, int dd);

	double
	calc_magvar (double lat, double lon, double h, long dat, double* field);

#ifdef TEST_NHV_HACKS
	double
	SGMagVarOrig (double lat, double lon, double h, long dat, double* field);
#endif // TEST_NHV_HACKS

  private:
	double	P[13][13];
	double	DP[13][13];
	double	gnm[13][13];
	double	hnm[13][13];
	double	sm[13];
	double	cm[13];
	double	root[13];
	double	roots[13][13][2];
};


/**
 * The main API
 */
class MagneticVariation
{
  public:
	/**
	 * Set position on earth.
	 */
	void
	set_position (LonLat const& position);

	/**
	 * Set altitude.
	 */
	void
	set_altitude_amsl (Length altitude_amsl);

	/**
	 * Set date. Supported years: 1950…2049.
	 */
	void
	set_date (int year, int month, int day);

	/**
	 * Calculate result.
	 */
	void
	update();

	/**
	 * Return resulting magnetic declination.
	 */
	Angle
	magnetic_declination() const;

	/**
	 * Return resulting magnetic inclination.
	 */
	Angle
	magnetic_inclination() const;

  private:
	LonLat					_position;
	Length					_altitude_amsl;
	long					_julian_date;
	Angle					_magnetic_declination;
	Angle					_magnetic_inclination;
	MagneticVariationImpl	_implementation;
};


inline void
MagneticVariation::set_position (LonLat const& position)
{
	_position = position;
}


inline void
MagneticVariation::set_altitude_amsl (Length altitude_amsl)
{
	_altitude_amsl = altitude_amsl;
}


inline Angle
MagneticVariation::magnetic_declination() const
{
	return _magnetic_declination;
}


inline Angle
MagneticVariation::magnetic_inclination() const
{
	return _magnetic_inclination;
}

} // namespace xf

#endif

