#pragma once
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
#include <string>
#include <yaml-cpp/yaml.h>

namespace OpenXcom
{
//class Game;
class Mod;
/**
 * Represents an alien base on the world.
 */
class OverlayPolygon
{
private:
//	Game *_game;
	int _globeShowMode;
	std::vector<int> _layer1; //assuming that the amount of polygons stay the same over the savegames
public:
	/// Creates an alien base.
	OverlayPolygon();
	/// Cleans up the alien base.
	~OverlayPolygon();

	void init(const Mod *mod);
	int getLayer1Value(int unsigned index);

	void setGlobeShowMode(int mode);
	int getGlobeShowMode() const;
	void load(const YAML::Node &node);
	YAML::Node save() const;


};

}