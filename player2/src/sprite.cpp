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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include "sprite.h"
#include "player.h"
#include "graphics.h"

////////////////////////////////////////////////////////////
/// Defines
////////////////////////////////////////////////////////////
#define max(a, b)	(((a) > (b)) ? (a) : (b))
#define min(a, b)	(((a) < (b)) ? (a) : (b))

////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////
Sprite::Sprite() {
	bitmap = NULL;
	src_rect = Rect();
	visible = true;
	x = 0;
	y = 0;
	z = 0;
	ox = 0;
	oy = 0;
	zoom_x = 1.0;
	zoom_y = 1.0;
	angle = 0.0;
	flipx = false;
	flipy = false;
	bush_depth = 0;
	opacity = 255;
	blend_type = 0;
	color = Color();
	tone = Tone();

	sprite = NULL;
	flash_duration = 0;

	ID = Graphics::ID++;
	Graphics::drawable_list.push_back(this);
	Graphics::drawable_list.sort(Graphics::SortDrawable);
}

////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////
Sprite::~Sprite() {
	Graphics::RemoveDrawable(ID);
	delete sprite;
}

////////////////////////////////////////////////////////////
/// Draw
////////////////////////////////////////////////////////////
void Sprite::Draw() {
	if (!visible) return;
	if (GetWidth() <= 0 || GetHeight() <= 0) return;
	if (x < -GetWidth() || x > Player::GetWidth() || y < -GetHeight() || y > Player::GetHeight()) return;
	if (zoom_x <= 0 || zoom_y <= 0) return;
	if (opacity <= 0) return;
	if (!bitmap) return;
	
	Refresh();
	
	sprite->BlitScreen(x - ox, y - oy);
}

////////////////////////////////////////////////////////////
/// Refresh
////////////////////////////////////////////////////////////
void Sprite::Refresh() {
	if (!needs_refresh) return;

	needs_refresh = false;

	delete sprite;
	
	sprite = new Bitmap(bitmap, src_rect);
		
	sprite->ToneChange(tone);
	sprite->OpacityChange(opacity, bush_depth);
	sprite->Flip(flipx, flipy);
	sprite->Zoom(zoom_x, zoom_y);
	sprite->Rotate(angle);

	if (flash_duration > 0) {
		sprite->Flash(flash_color, flash_frame, flash_duration);
	}
}

////////////////////////////////////////////////////////////
/// Get Width
////////////////////////////////////////////////////////////
int Sprite::GetWidth() {
	return src_rect.width;
}

////////////////////////////////////////////////////////////
/// Get Height
////////////////////////////////////////////////////////////
int Sprite::GetHeight() {
	return src_rect.height;
}

////////////////////////////////////////////////////////////
/// Update
////////////////////////////////////////////////////////////
void Sprite::Update() {
	if (flash_duration != 0) {
		flash_frame += 1;
		if (flash_duration == flash_frame) {
			flash_duration = 0;
		}
		needs_refresh = true;
	}
}

////////////////////////////////////////////////////////////
/// Flash
////////////////////////////////////////////////////////////
void Sprite::Flash(int duration){
	flash_color = Color(0, 0, 0, 0);
	flash_duration = duration;
	flash_frame = 0;
}
void Sprite::Flash(Color color, int duration){
	flash_color = color;
	flash_duration = duration;
	flash_frame = 0;
}

////////////////////////////////////////////////////////////
/// Properties
////////////////////////////////////////////////////////////
Bitmap* Sprite::GetBitmap() {
	return bitmap;
}
void Sprite::SetBitmap(Bitmap* nbitmap) {
	bitmap = nbitmap;
	if (!bitmap) {
		src_rect = Rect();
	} else {
		src_rect = bitmap->GetRect();
	}
	needs_refresh = true;
}
Rect Sprite::GetSrcRect() {
	return src_rect;
}
void Sprite::SetSrcRect(Rect nsrc_rect) {
	if (src_rect != nsrc_rect) needs_refresh = true;
	src_rect = nsrc_rect;
}
bool Sprite::GetVisible() {
	return visible;
}
void Sprite::SetVisible(bool nvisible) {
	visible = nvisible;
}
int Sprite::GetX() {
	return x;
}
void Sprite::SetX(int nx) {
	x = nx;
}
int Sprite::GetY() {
	return y;
}
void Sprite::SetY(int ny) {
	y = ny;
}
int Sprite::GetZ() {
	return z;
}
void Sprite::SetZ(int nz) {
	if (z != nz) Graphics::drawable_list.sort(Graphics::SortDrawable);
	z = nz;
}
int Sprite::GetOx() {
	return ox;
}
void Sprite::SetOx(int nox) {
	//if (ox != nox) needs_refresh = true;
	ox = nox;
}
int Sprite::GetOy() {
	return oy;
}
void Sprite::SetOy(int noy) {
	//if (oy != noy) needs_refresh = true;
	oy = noy;
}
double Sprite::GetZoomX() {
	return zoom_x;
}
void Sprite::SetZoomX(double nzoom_x) {
	if (zoom_x != nzoom_x) needs_refresh = true;
	zoom_x = nzoom_x;
}
double Sprite::GetZoomY() {
	return zoom_y;
}
void Sprite::SetZoomY(double nzoom_y) {
	if (zoom_y != nzoom_y) needs_refresh = true;
	zoom_y = nzoom_y;
}
double Sprite::GetAngle() {
	return angle;
}
void Sprite::SetAngle(double nangle) {
	if (angle != nangle) needs_refresh = true;
	angle = nangle;
}
bool Sprite::GetFlipX() {
	return flipx;
}
void Sprite::SetFlipX(bool nflipx) {
	if (flipx != nflipx) needs_refresh = true;
	flipx = nflipx;
}
bool Sprite::GetFlipY() {
	return flipy;
}
void Sprite::SetFlipY(bool nflipy) {
	if (flipy != nflipy) needs_refresh = true;
	flipy = nflipy;
}
int Sprite::GetBushDepth() {
	return bush_depth;
}
void Sprite::SetBushDepth(int nbush_depth) {
	if (bush_depth != nbush_depth) needs_refresh = true;
	bush_depth = nbush_depth;
}
int Sprite::GetOpacity() {
	return opacity;
}
void Sprite::SetOpacity(int nopacity) {
	opacity = nopacity;
}
int Sprite::GetBlendType() {
	return blend_type;
}
void Sprite::SetBlendType(int nblend_type) {
	blend_type = nblend_type;
}
Color Sprite::GetColor() {
	return color;
}
void Sprite::SetColor(Color ncolor) {
	color = ncolor;
}
Tone Sprite::GetTone() {
	return tone;
}
void Sprite::SetTone(Tone ntone) {
	if (tone != ntone) needs_refresh = true;
	tone = ntone;
}

////////////////////////////////////////////////////////////
/// Get id
////////////////////////////////////////////////////////////
unsigned long Sprite::GetId() {
	return ID;
}
