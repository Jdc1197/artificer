#include <Windows.h>
#include <libtcod.hpp>
#include "Game.h"
#include "Reference.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game CurrentInstance;
	Reference::SetGameInstance(&CurrentInstance);
	CurrentInstance.Run();
	return 4;
}