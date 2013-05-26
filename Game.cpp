#include <Windows.h>
#include <iostream>
#include "Game.h"
#include "MenuInventory.h"
#include "Actions/ActionDropItem.h"
#include "Actions/ActionPickUp.h"


Game::Game()
{
	Player = SpawnBeing(BeingHuman, 0);
	CurrentMenu = nullptr;
	MenuOpen = false;
	
	CurrentMap.AddBeing(Player, 1, 1);
	this->Debug = false;
}

Game::~Game()
{
	delete CurrentMenu;
}

void Game::Run()
{
	while (!TCODConsole::isWindowClosed())
	{
		if (MenuOpen && CurrentMenu != nullptr)
			CurrentMenu->Draw();
		else
		{
			// Renders the Map, Beings, Item
			GraphicsEngine.RenderPlayingScreen(&CurrentMap);
			// Renders the Message Window
			GraphicsEngine.RenderMessageWindow(&GameInterface);
			// Renders the borders around the screen
			GraphicsEngine.RenderBorders();
		}
		// Flush and Displays the screen
		GraphicsEngine.DisplayScreen();
		
		TCOD_key_t key = TCODConsole::waitForKeypress(true);
		if (MenuOpen && CurrentMenu != nullptr)
			CurrentMenu->HandleInput(key);
		else
			HandleInput(key);
	}
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
		Player->Send(CurrentMap.MapCell[Player->GetX()-1][Player->GetY()],   MOVE); 
		break;
	case 'j':
		Player->Send(CurrentMap.MapCell[Player->GetX()][Player->GetY()+1],   MOVE);
		break;
	case 'k':
		Player->Send(CurrentMap.MapCell[Player->GetX()][Player->GetY()-1],   MOVE);
		break;
	case 'l':
		Player->Send(CurrentMap.MapCell[Player->GetX()+1][Player->GetY()],   MOVE);
		break;
	case 'y':
		Player->Send(CurrentMap.MapCell[Player->GetX()-1][Player->GetY()-1], MOVE);
		break;
	case 'u':
		Player->Send(CurrentMap.MapCell[Player->GetX()+1][Player->GetY()-1], MOVE);
		break;
	case 'n':
		Player->Send(CurrentMap.MapCell[Player->GetX()+1][Player->GetY()+1], MOVE);
		break;
	case 'b':
		Player->Send(CurrentMap.MapCell[Player->GetX()-1][Player->GetY()+1], MOVE);
		break;
	case 'i':
		OpenMenu(new MenuInventory(&Player->Inv));
		break;
	case 'g':
		OpenMenu(new ActionPickUp(Player->GetX(), Player->GetY(), Player));					
		break;
	case 'd':
		OpenMenu(new ActionDropItem());
		break;
	}
}