#pragma once
#ifdef TYGERMEM_EXPORTS
#define TYGERMEM __declspec(dllexport)
#else
#define TYGERMEM __declspec(dllimport)
#endif
#include "pch.h"
#include <string>

enum class FrontEndScreen {
	KromeLogo = 1,
	TyLogo = 2,
	FullTyLogo = 3,
	MainMenu = 4,
	LoadGame = 5,
	NewGame = 6,
	Extras = 7,
	Gallery = 8,
	Options = 9,
	Sound = 10,
	Screen = 11,
	Controls = 12,
	Credits = 15,
	Movies = 16,
	UNKNOWN = 30
};

enum class PauseMenuScreen {
	Unpaused = 0,
	PauseMenu = 3,
	LevelTotals = 4,
	Boomerangs = 5,
	GameTotals = 6,
	Options = 7,
	Sound = 8,
	Screen = 9,
	Controls = 10,
	SaveGame = 11,
	HardDiskRemoved = 13,
	SaveFailed = 14,
	Dot = 15,
	ChangeLevel = 16,
	EndCredits = 17,
	Leaderboard = 18,
	UNKNOWN = 21
};

class TYGERMEM GameState
{
public:
	static bool onMainMenu();
	static bool onLoadScreenOrMainMenu();

	/// <summary>
	/// <para>Displays a custom in-game message using the hard disk failure screen.</para>
	/// <para>Will not display a message if the player is on the main menu, loading, or in a cutscene.</para>
	/// <para>When seconds is 0, the message will display indefinitely and display "Pres ESC to continue".</para>
	/// </summary>
	/// <param name='message:'>Message to be displayed.</param>
	/// <param name='seconds:'>Time for the message to be displayed.</param>
	static void displayInGameMessage(std::string message, int seconds);

	static void setCollectibleLinesVisibility(bool status);
	static bool getCollectibleLineVisibility();
	static void setLevelSelectMenuVisibility(bool status);
	static bool getLevelSelectMenuVisibility();
	static void setFrontEndMenuScreen(FrontEndScreen screen);
	static FrontEndScreen getFrontEndMenuScreen();
	static void setPauseMenuScreen(PauseMenuScreen screen);
	static PauseMenuScreen getPauseMenuScreen();
	static void setPreviousPauseMenuScreen(PauseMenuScreen screen);
	static PauseMenuScreen getPreviousPauseMenuScreen();
	static void forceMainMenu();
	static void forcePrepNewGame(int slot);
	static void forceNewGameScreen();
	static void forceNewGame(int countdown, int saveSlot);
	static void setNoIdle(bool status);
	static bool getNoIdle();
	static void setNewGameText(std::string title, std::string bottomTitle, std::string bottomSubtitle);
};

