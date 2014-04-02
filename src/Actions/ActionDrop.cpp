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

#include "Actions/ActionDrop.h"
#include "Graphics/GraphicsDrop.h"
#include "Reference.h"

void ActionDrop::HandleInput(TCOD_key_t key)
{
	// Cancels operation when escape key is pressed	
	if (key.vk != TCODK_ESCAPE)
	{
		Being * Player = GameReference::GetPlayer();
		Item * i = Player->Inv[key.c];
		if (i)
			Player->Send(5.0f, DROP, i);
	}
	GameReference::CloseMenu();
}

void ActionDrop::Draw()
{
	GraphicsDrop Renderer(&GameReference::GetPlayer()->Inv);
	Renderer.Draw();
}