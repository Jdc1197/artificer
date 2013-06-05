#include "Reference.h"

Game * Reference::GameInstance;
bool Reference::SetGameInstance(Game * Instance)
{
	if (Instance != nullptr)
		GameInstance = Instance;
	return (Instance != nullptr);
}

Being* GameReference::GetPlayer() { return GameInstance->Player; }
Map* GameReference::GetMap() { return GameInstance->CurrentMap; }
Interface* GameReference::GetInterface() { return &GameInstance->GameInterface; }

void GameReference::OpenMenu(Menu* MenuToOpen) { GameInstance->OpenMenu(MenuToOpen); }
void GameReference::CloseMenu() { GameInstance->CloseMenu(); }
void GameReference::DrawSubconsoles() { GameInstance->DrawSubconsoles(); }

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