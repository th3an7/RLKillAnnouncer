#include "pch.h"
#include "RLKillAnnouncer.h"

/* Plugin Settings Window code here
std::string RLKillAnnouncer::GetPluginName() {
	return "RLKillAnnouncer";
}

void RLKillAnnouncer::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> RLKillAnnouncer
void RLKillAnnouncer::RenderSettings() {
	ImGui::TextUnformatted("RLKillAnnouncer plugin settings");
}
*/

/*
// Do ImGui rendering here
void RLKillAnnouncer::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string RLKillAnnouncer::GetMenuName()
{
	return "rlkillannouncer";
}

// Title to give the menu
std::string RLKillAnnouncer::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void RLKillAnnouncer::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool RLKillAnnouncer::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool RLKillAnnouncer::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void RLKillAnnouncer::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void RLKillAnnouncer::OnClose()
{
	isWindowOpen_ = false;
}
*/
