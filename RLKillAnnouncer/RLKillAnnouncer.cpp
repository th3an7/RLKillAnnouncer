#include "pch.h"
#include "RLKillAnnouncer.h"
#include <Windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <iostream>
#include <chrono>

#pragma comment(lib, "Winmm.lib")


BAKKESMOD_PLUGIN(RLKillAnnouncer, "Play sounds in Rocket League using BakkesMod plugin", plugin_version, PLUGINTYPE_THREADED)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

typedef std::chrono::steady_clock Clock;

void RLKillAnnouncer::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->log("Announcer Loaded");
	
	gameWrapper->HookEventWithCaller<ServerWrapper>("Function TAGame.GFxHUD_TA.HandleStatTickerMessage", std::bind(&RLKillAnnouncer::onStatTickerMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	gameWrapper->HookEvent("Function GameEvent_Soccar_TA.WaitingForPlayers.BeginState", std::bind(&RLKillAnnouncer::StartGame, this));
	gameWrapper->HookEvent("Function Engine.PlayerInput.InitInputSystem", std::bind(&RLKillAnnouncer::StartGame, this));
}

void RLKillAnnouncer::onUnload()
{
	gameWrapper->UnhookEvent("Function TAGame.GFxHUD_TA.HandleStatTickerMessage");
	gameWrapper->UnhookEvent("Function GameEvent_Soccar_TA.WaitingForPlayers.BeginState");
	gameWrapper->UnhookEvent("Function Engine.PlayerInput.InitInputSystem");
}

void RLKillAnnouncer::onStatTickerMessage(ServerWrapper caller, void* params, std::string eventname)
{
	StatTickerParams* pStruct = (StatTickerParams*)params;
	PriWrapper receiver = PriWrapper(pStruct->Receiver);
	PriWrapper victim = PriWrapper(pStruct->Victim);
	StatEventWrapper statEvent = StatEventWrapper(pStruct->StatEvent);

	if (statEvent.GetEventName() != "Demolish") return;
	if (!receiver || !victim) return;

	PlayerControllerWrapper playerController = gameWrapper->GetPlayerController();
	if (!playerController) return;

	PriWrapper playerPRI = playerController.GetPRI();
	if (!playerPRI) return;

	if (playerPRI.memory_address == victim.memory_address)
	{
		PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\Totalled.wav", NULL, SND_ASYNC);
		counter = 0;
		combo = 0;
		previousDemoTime = Clock::now();
	}

	if (playerPRI.memory_address == receiver.memory_address)
	{
		++counter;
		switch (counter) {
			case 1:
				PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\first_blood.wav", NULL, SND_ASYNC);
				break;
			case 3:
				PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\Killing_Spree.wav", NULL, SND_ASYNC);
				break;
			case 5:
				PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\Dominating.wav", NULL, SND_ASYNC);
				break;
			case 7:
				PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\Unstoppable.wav", NULL, SND_ASYNC);
				break;
			case 10:
				PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\GodLike.wav", NULL, SND_ASYNC);
				break;
			case 15:
				PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\WhickedSick.wav", NULL, SND_ASYNC);
				break;
		}
		++combo;

		if (Clock::now() - previousDemoTime > std::chrono::seconds(10))
		{
			previousDemoTime = Clock::now();
			combo = 0;
		}
		else
		{
			switch (combo) {
				case 1:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\Double_Kill.wav", NULL, SND_ASYNC);
					break;
				case 2:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\MultiKill.wav", NULL, SND_ASYNC);
					break;
				case 3:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\MegaKill.wav", NULL, SND_ASYNC);
					break;
				case 4:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\UltraKill.wav", NULL, SND_ASYNC);
					break;
				case 5:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\MonsterKill.wav", NULL, SND_ASYNC);
					break;
				case 6:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\LudicrousKill.wav", NULL, SND_ASYNC);
					break;
				case 7:
					PlaySound("C:\\Users\\lukas\\AppData\\Roaming\\bakkesmod\\bakkesmod\\data\\RLKillAnnouncer\\HolyShit_F.wav", NULL, SND_ASYNC);
					break;
				
			}
			
		}
		
	}

}

void RLKillAnnouncer::StartGame()
{
	counter = 0;
	combo = 0;
	previousDemoTime = Clock::now();
}