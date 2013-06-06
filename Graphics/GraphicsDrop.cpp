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

#include "Graphics/GraphicsDrop.h"
#include "Graphics/GraphicsBorders.h"
#include "Graphics/GraphicsInterface.h"
#include "Graphics/GraphicsMap.h"
#include "Reference.h"

GraphicsDrop::GraphicsDrop(Inventory* i)
{
	Inv = i;
}

void GraphicsDrop::Draw()
{
	GameReference::DrawSubconsoles();
	Graphics::BlitSubconsoles();
	if (Inv->GetSize() > 0)
	{
		char lowest, highest;
		lowest = Inv->GetLowestIdentifier();
		highest = Inv->GetHighestIdentifier();
		RootConsole->printLeft(1, 10, TCOD_BKGND_SET, "What do you wish to drop? (%c-%c)", lowest, highest);
	}
	else
		RootConsole->printLeft(1, 10, TCOD_BKGND_SET, "What do you wish to drop? (Empty)");
	

}
