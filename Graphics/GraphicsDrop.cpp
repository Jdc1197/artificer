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
