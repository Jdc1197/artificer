#include "Graphics/GraphicsInterface.h"
#include "Graphics/GraphicsColoredString.h"

GraphicsInterface::GraphicsInterface(Interface* I)
{
	ToDraw = I;
};

void GraphicsInterface::Draw()
{
	ScreenMessages->clear();
	for (int i = 0; i < 9; i++)
	{
		GraphicsColoredString G(ToDraw->GetMessage(i));
		G.Draw(0, 8-i, ScreenMessages);
	}
	//TCODConsole::blit(ScreenMessages, 0, 0, ScreenMessages->getWidth(), ScreenMessages->getHeight(), RootConsole, 0, 0);
}