/* vim:ts=4
 *
 * Copyleft 2012…2014  Michał Gawron
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
#include "property_utils.h"


namespace Xefis {

std::string const&
PropertyType::check_validity (std::string const& type)
{
	static std::set<std::string> valid_types = {
		"boolean",
		"integer",
		"float",
		"string",
		"acceleration",
		"angle",
		"capacity",
		"current",
		"pressure",
		"frequency",
		"length",
		"speed",
		"temperature",
		"time",
		"torque",
		"weight",
	};

	if (valid_types.find (type) == valid_types.end())
		throw BadType (type);

	return type;
}

} // namespace Xefis
