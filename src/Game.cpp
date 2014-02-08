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

#include <iostream>
#include <assert.h>
#include "Game.h"

#include "FOV.h"

// Actions //
#include "MenuInventory.h"
#include "Actions/ActionDrop.h"
#include "Actions/ActionPickUp.h"

// Graphics //
#include "Graphics/GraphicsMap.h"
#include "Graphics/GraphicsInterface.h"
#include "Graphics/GraphicsBorders.h"

// Map Generators //
#include "MapGenerators/CaveGenerator.h"

Game::Game()
{
	Player = SpawnBeing(BeingHuman, 0);
	CurrentMenu = nullptr;
	MenuOpen = false;
	MapGenerator::CaveGenerator Generator(Player);
	CurrentMap = Generator.GenerateMap();
	this->Debug = false;
	
	// Initialize Graphics //
	Graphics::Init();
	InterfaceRenderer = new GraphicsInterface(&GameInterface);
	BorderRenderer = new GraphicsBorders();
	MapRenderer = nullptr;
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
			// Compute the FOV
		BinaryMap FOVMap = FOV::GetFOVMap(Player->GetX(), Player->GetY(), 15, CurrentMap);
			// Draw the map
			if (MapRenderer) delete MapRenderer;
			MapRenderer = new GraphicsMap(CurrentMap, FOVMap);
			DrawSubconsoles();
			Graphics::BlitSubconsoles();
		}
		// Flush and Displays the screen
		Graphics::FlushRoot();
		
		TCOD_key_t key;
		TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr, true);
		if (MenuOpen)
			CurrentMenu->HandleInput(key);
		else
			HandleInput(key);
		// Simulate Time
		if (!MenuOpen && TimeEngine.IsInList(Player))
		{
			TimedEvent E;
			do
			{
				E = TimeEngine.ExecuteNextEvent();
				CurrentMap->ElapseTime(E.Delay);
			} 
			while (E.Sender != Player);
		}
	}
}

void Game::DrawSubconsoles()
{
	MapRenderer->Draw();
	InterfaceRenderer->Draw();
	BorderRenderer->Draw();
}

void Game::AddEvent(float delay, Message msg, Being* sender, Object* receiver)
{
	TimedEvent T;
	T.Delay = delay; 
	T.Msg = msg;
	T.Sender = sender;
	T.Receiver = receiver;
	TimeEngine.AddEvent(T);
}

Being* Game::GetPlayer() { return Player; }
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
		if (!IsOOB(Player->GetX()-1,Player->GetY()))	
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX()-1,Player->GetY())); 
		break;
	case 'j':
		if (!IsOOB(Player->GetX(),Player->GetY()+1))	
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX(),Player->GetY()+1));
		break;
	case 'k':
		if (!IsOOB(Player->GetX(),Player->GetY()-1))	
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX(),Player->GetY()-1));
		break;
	case 'l':
		if (!IsOOB(Player->GetX()+1,Player->GetY()))
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX()+1,Player->GetY()));
		break;
	case 'y':
		if (!IsOOB(Player->GetX()-1,Player->GetY()-1))
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX()-1,Player->GetY()-1));
		break;
	case 'u':
		if (!IsOOB(Player->GetX()+1,Player->GetY()-1))
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX()+1,Player->GetY()-1));
		break;
	case 'n':
		if (!IsOOB(Player->GetX()+1,Player->GetY()+1))
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX()+1,Player->GetY()+1));
		break;
	case 'b':
		if (!IsOOB(Player->GetX()-1,Player->GetY()+1))
			Player->Send(5.0f, MOVE, CurrentMap->GetMapCell(Player->GetX()-1,Player->GetY()+1));
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
