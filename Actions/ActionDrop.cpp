#include "Actions/ActionDrop.h"
#include "Graphics/GraphicsDrop.h"
#include "Reference.h"

void ActionDrop::HandleInput(TCOD_key_t key)
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

void ActionDrop::Draw()
{
	GraphicsDrop Renderer(&GameReference::GetPlayer()->Inv);
	Renderer.Draw();
}