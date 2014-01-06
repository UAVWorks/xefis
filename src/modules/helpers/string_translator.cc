/* vim:ts=4
 *
 * Copyleft 2012…2013  Michał Gawron
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
#include <xefis/utility/qdom.h>

// Local:
#include "string_translator.h"


XEFIS_REGISTER_MODULE_CLASS ("helpers/string-translator", StringTranslator);


StringTranslator::StringsSet::StringsSet (QDomElement const& config)
{
	if (!config.hasAttribute ("input-path") || !config.hasAttribute ("output-path"))
		throw Xefis::Exception ("<translate> needs @input-path and @output-path attributes");

	_input.set_path (config.attribute ("input-path").toStdString());
	_output.set_path (config.attribute ("output-path").toStdString());

	for (QDomElement e: config)
	{
		if (e == "string")
		{
			if (!e.hasAttribute ("input") || !e.hasAttribute ("output"))
				throw Xefis::Exception ("<string> needs @input and @output attributes");
			_map.insert ({ e.attribute ("input").toLong(), e.attribute ("output").toStdString() });
		}
		else if (e == "default")
		{
			if (!e.hasAttribute ("output"))
				throw Xefis::Exception ("<default> needs @output attribute");
			_default = e.attribute ("output").toStdString();
		}
	}

	update();
}


void
StringTranslator::StringsSet::process()
{
	if (_input.fresh())
		update();
}


void
StringTranslator::StringsSet::update()
{
	if (_input.valid())
	{
		Map::iterator it = _map.find (*_input);
		if (it != _map.end())
			_output.write (it->second);
		else
			_output.write (_default);
	}
	else
		_output.write (_default);
}


StringTranslator::StringTranslator (Xefis::ModuleManager* module_manager, QDomElement const& config):
	Module (module_manager, config)
{
	for (QDomElement e: config)
	{
		if (e == "translate")
			_sets.emplace_back (e);
	}
}


void
StringTranslator::data_updated()
{
	for (auto& s: _sets)
		s.process();
}
