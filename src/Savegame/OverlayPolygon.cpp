/*
 * Copyright 2010-2016 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "OverlayPolygon.h"
#include "../Engine/Language.h"

#include "../Mod/RuleGlobe.h"
#include "../Mod/Polygon.h"
#include "../Engine/State.h"
#include "../Engine/Game.h"
#include "../Mod/Mod.h"

namespace OpenXcom
{

/**
 * Initializes an alien base
 */
OverlayPolygon::OverlayPolygon() : _globeShowMode(0)
{

}

/**
 *
 */
OverlayPolygon::~OverlayPolygon()
{
}


void OverlayPolygon::init(const Mod *mod)
{
	RuleGlobe* _rGlobe = mod->getGlobe();

	for (std::list<Polygon*>::iterator i = _rGlobe->getPolygons()->begin(); i != _rGlobe->getPolygons()->end(); ++i)
	{
		//_layer1.push_back((*i)->getBuscherTexture());

		int j = std::distance(_rGlobe->getPolygons()->begin(), i);
		_layer1.push_back((j/13)%13);
	}

}

int OverlayPolygon::getLayer1Value(unsigned int index)
{
	if (_layer1.size() > index)
	{
		return _layer1[index];
	}
	else
	{
		return 0;
	}
}

/**
 * Loads the time from a YAML file.
 * @param node YAML node.
 */
void OverlayPolygon::load(const YAML::Node &node)
{
	_globeShowMode = node["globeShowMode"].as<int>(_globeShowMode);
}

/**
 * Saves the time to a YAML file.
 * @return YAML node.
 */
YAML::Node OverlayPolygon::save() const
{
	YAML::Node node;
	node["globeShowMode"] = _globeShowMode;
	return node;
}

void OverlayPolygon::setGlobeShowMode(int mode)
{
	_globeShowMode = mode;
}

int OverlayPolygon::getGlobeShowMode() const
{
	return _globeShowMode;
}

}