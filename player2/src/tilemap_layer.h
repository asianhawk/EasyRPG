/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG Player.
// 
// EasyRPG Player is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// EasyRPG Player is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

#ifndef _TILEMAP_LAYER_H_
#define _TILEMAP_LAYER_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include "drawable.h"
#include "bitmap.h"
#include "sprite.h"

////////////////////////////////////////////////////////////
/// TilemapLayer class
////////////////////////////////////////////////////////////
class TilemapLayer : public Drawable {
public:
	TilemapLayer(int ilayer);
	~TilemapLayer();

	void Draw();

	Bitmap* GetChipset() const;
	void SetChipset(Bitmap* nchipset);
	std::vector<short> GetMapData() const;
	void SetMapData(std::vector<short> nmap_data);
	std::vector<unsigned char> GetPassable() const;
	void SetPassable(std::vector<unsigned char> npassable);
	bool GetVisible() const;
	void SetVisible(bool nvisible);
	int GetOx() const;
	void SetOx(int nox);
	int GetOy() const;
	void SetOy(int noy);
	int GetWidth() const;
	void SetWidth(int nwidth);
	int GetHeight() const;
	void SetHeight(int nheight);

	int GetZ() const;
	unsigned long GetId() const;

private:
	Bitmap* chipset;
	std::vector<short> map_data;
	std::vector<unsigned char> passable;
	bool visible;
	int ox;
	int oy;
	int width;
	int height;

	unsigned long ID;
	int layer;

	std::vector<std::vector<Sprite*> > sprites;
	std::vector<Bitmap*> autotiles;

	struct TileData {
		int id;
		int z;
	};
	std::vector<std::vector<TileData> > data_cache;
};

#endif
