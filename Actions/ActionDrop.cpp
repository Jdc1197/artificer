#include "Actions/ActionDropItem.h"
#include "Reference.h"

void ActionDropItem::HandleInput(TCOD_key_t key)
{
	if (key.vk != TCODK_ESCAPE)			// Cancels operation when escape is pressed
	{
		Being * Player = GameReference::GetPlayer();
		Item * i = Player->Inv[key.c];
		if (i)
			Player->Send(i, DROP);
	}
	GameReference::CloseMenu();
}

void ActionDropItem::Draw()
{
	Inventory * Inv = &GameReference::GetPlayer()->Inv;
	if (Inv->GetSize() > 0)
	{
		char lowest, highest;
		lowest = Inv->GetLowestIdentifier();
		highest = Inv->GetHighestIdentifier();
		TCODConsole::root->printLeft(1, 10, TCOD_BKGND_SET, "What do you wish to drop? (%c-%c)", lowest, highest);
	}
	else
		TCODConsole::root->printLeft(1, 10, TCOD_BKGND_SET, "What do you wish to drop? (Empty)");
}