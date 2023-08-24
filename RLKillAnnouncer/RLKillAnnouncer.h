#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

struct StatTickerParams {
	uintptr_t Receiver;
	uintptr_t Victim;
	uintptr_t StatEvent;
};


class RLKillAnnouncer: public BakkesMod::Plugin::BakkesModPlugin/*, public BakkesMod::Plugin::PluginSettingsWindow*//*, public BakkesMod::Plugin::PluginWindow*/
{

	//std::shared_ptr<bool> enabled;

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	unsigned int combo = 0;
	unsigned int counter = 0;
	std::chrono::steady_clock::time_point previousDemoTime;
	void onStatTickerMessage(ServerWrapper caller, void* params, std::string eventname);
	void StartGame();
};
