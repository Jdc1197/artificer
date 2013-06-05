#include <Windows.h>
#include <iostream>
#include "Game.h"

// Actions //
#include "MenuInventory.h"
#include "Actions/ActionDrop.h"
#include "Actions/ActionPickUp.h"

// Graphics //
#include "Graphics/GraphicsMap.h"
#include "Graphics/GraphicsInterface.h"
#include "Graphics/GraphicsBorders.h"

Game::Game()
{
	Player = SpawnBeing(BeingHuman, 0);
	CurrentMenu = nullptr;
	MenuOpen = false;
	CurrentMap = new Map;
	CurrentMap->AddBeing(Player, 1, 1);
	this->Debug = false;
	Graphics::Init();
	MapRenderer = new GraphicsMap(CurrentMap);
	InterfaceRenderer = new GraphicsInterface(&GameInterface);
	BorderRenderer = new GraphicsBorders();
}

Game::~Game()
{
	delete CurrentMenu;
	delete CurrentMap;
	delete MapRenderer;
	delete InterfaceRenderer;
	delete BorderRenderer;
	Graphics::Destroy();
}

void Game::Run()
{
	while (!TCODConsole::isWindowClosed())
	{
		if (MenuOpen)
			CurrentMenu->Draw();
		else
		{
			DrawSubconsoles();
			Graphics::BlitSubconsoles();
		}
		// Flush and Displays the screen
		Graphics::FlushRoot();
		
		TCOD_key_t key = TCODConsole::waitForKeypress(true);
		if (MenuOpen)
			CurrentMenu->HandleInput(key);
		else
			HandleInput(key);
	}
}

void Game::DrawSubconsoles()
{
	MapRenderer->Draw();
	InterfaceRenderer->Draw();
	BorderRenderer->Draw();
}
void Game::OpenMenu(Menu * ToOpen)
{
	CurrentMenu = ToOpen;
	CurrentMenu->Init();
	if (CurrentMenu != nullptr)
		MenuOpen = true;
}
void Game::CloseMenu()
{
	delete CurrentMenu;
	CurrentMenu = nullptr;
	MenuOpen = false;
}

void Game::HandleInput(TCOD_key_t Key)
{
	switch (Key.c)
	{
	case 'h':
		Player->Send(CurrentMap->MapCell[Player->GetX()-1][Player->GetY()],   MOVE); 
		break;
	case 'j':
		Player->Send(CurrentMap->MapCell[Player->GetX()][Player->GetY()+1],   MOVE);
		break;
	case 'k':
		Player->Send(CurrentMap->MapCell[Player->GetX()][Player->GetY()-1],   MOVE);
		break;
	case 'l':
		Player->Send(CurrentMap->MapCell[Player->GetX()+1][Player->GetY()],   MOVE);
		break;
	case 'y':
		Player->Send(CurrentMap->MapCell[Player->GetX()-1][Player->GetY()-1], MOVE);
		break;
	case 'u':
		Player->Send(CurrentMap->MapCell[Player->GetX()+1][Player->GetY()-1], MOVE);
		break;
	case 'n':
		Player->Send(CurrentMap->MapCell[Player->GetX()+1][Player->GetY()+1], MOVE);
		break;
	case 'b':
		Player->Send(CurrentMap->MapCell[Player->GetX()-1][Player->GetY()+1], MOVE);
		break;
	case 'i':
		OpenMenu(new MenuInventory(&Player->Inv));
		break;
	case 'g':
		OpenMenu(new ActionPickUp(Player->GetX(), Player->GetY(), Player));					
		break;
	case 'd':
		OpenMenu(new ActionDrop());
		break;
	}
}