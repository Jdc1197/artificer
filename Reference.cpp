/*	
	Artificer: A roguelike game.
    Copyright (C) 2013 Jdc1197

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Contact Jdc1197 by email at: Jdc1197@gmail.com
*/

#include "Reference.h"

Game * Reference::GameInstance;
bool Reference::SetGameInstance(Game * Instance)
{
	if (Instance != nullptr)
		GameInstance = Instance;
	return (Instance != nullptr);
}

Being* GameReference::GetPlayer() { /*GameInstance->GetPlayer()->GetX();*/ return GameInstance->GetPlayer(); }
Map* GameReference::GetMap() { return GameInstance->CurrentMap; }
Interface* GameReference::GetInterface() { return &GameInstance->GameInterface; }

void GameReference::OpenMenu(Menu* MenuToOpen) { GameInstance->OpenMenu(MenuToOpen); }
void GameReference::CloseMenu() { GameInstance->CloseMenu(); }
void GameReference::DrawSubconsoles() { GameInstance->DrawSubconsoles(); }
void GameReference::AddEvent(float delay, Message msg, Being* sender, Object* receiver) { GameInstance->AddEvent(delay, msg, sender, receiver); }

bool MapReference::IsItemOnTile(int x, int y) { return GameInstance->CurrentMap->IsItemOnTile(x,y); }
bool MapReference::IsBeingOnTile(int x, int y) { return GameInstance->CurrentMap->IsBeingOnTile(x,y); }
void MapReference::RemoveItem(Item * ItemToRemove, bool DestroyItem = false) { GameInstance->CurrentMap->RemoveItem(ItemToRemove, DestroyItem); }
void MapReference::RemoveBeing(Being * BeingToRemove, bool DestroyBeing = false) { GameInstance->CurrentMap->RemoveBeing(BeingToRemove, DestroyBeing); }
void MapReference::AddBeing(Being * ToSpawn, int x, int y) {GameInstance->CurrentMap->AddBeing(ToSpawn, x, y);}
void MapReference::AddItem(Item * ToSpawn, int x, int y) {GameInstance->CurrentMap->AddItem(ToSpawn, x, y);}
vector<Item*> MapReference::GetItemsOnTile(int x, int y) { return GameInstance->CurrentMap->GetItemsOnTile(x,y); }

void InterfaceReference::AddMessage(string MessageToAdd) { GameInstance->GameInterface.AddMessage(MessageToAdd); }
void InterfaceReference::AddMessage(ostringstream* MessageToAdd) { GameInstance->GameInterface.AddMessage(MessageToAdd); }
void InterfaceReference::AddMessage(const char * MessageToAdd) { GameInstance->GameInterface.AddMessage(MessageToAdd); }