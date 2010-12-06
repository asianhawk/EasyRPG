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
#include "window_equip.h"
#include "game_actors.h"

////////////////////////////////////////////////////////////
Window_Equip::Window_Equip(int actor_id) :
	Window_Selectable(124, 32, 196, 96),
	actor_id(actor_id),
	help_window(NULL) {
	contents = new Bitmap(width-16, height-16);
	Refresh();
	index = 0;
}

////////////////////////////////////////////////////////////
Window_Equip::~Window_Equip() {
}

////////////////////////////////////////////////////////////
int Window_Equip::GetItemId() {
	return data[index];
}

////////////////////////////////////////////////////////////
void Window_Equip::Refresh() {
	contents->Clear();
	Rect rect(0, 0, contents->GetWidth(), contents->GetHeight());
	contents->FillofColor(rect, windowskin->GetColorKey());
	contents->SetColorKey(windowskin->GetColorKey());

	// Add the equipment of the actor to data
	data.clear();
	Game_Actor* actor = Game_Actors::GetActor(actor_id);
	data.push_back(actor->GetWeaponId());
	data.push_back(actor->GetShieldId());
	data.push_back(actor->GetArmorId());
	data.push_back(actor->GetHelmetId());
	data.push_back(actor->GetAccessoryId());
	item_max = data.size();

	// Draw equipment text
	for (int i = 0; i < 5; ++i) {
		DrawEquipmentType(actor, 0, (12 + 4) * i, i);
		if (data[i] > 0) {
			DrawItemName(&Data::items[data[i] - 1], 60, (12 + 4) * i);
		}
	}
}

////////////////////////////////////////////////////////////
void Window_Equip::SetHelpWindow(Window_Help* help_window) {
	this->help_window = help_window;
}

////////////////////////////////////////////////////////////
void Window_Equip::UpdateHelp() {
	help_window->SetText(GetItemId() == 0 ? "" : 
		Data::items[GetItemId()].description);
}
