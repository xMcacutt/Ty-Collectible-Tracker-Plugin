#pragma once
#ifdef TYGERMEM_EXPORTS
#define TYGERMEM __declspec(dllexport)
#else
#define TYGERMEM __declspec(dllimport)
#endif
#include <string>

enum class LevelCode {
	Z1,
	Z2,
	Z3,
	Z4,
	A1,
	A2,
	A3,
	A4,
	B1,
	B2,
	B3,
	B4,
	C1,
	C2,
	C3,
	C4,
	D1,
	D2,
	D3,
	D4,
	E1,
	E2,
	E3,
	E4,
};

class TYGERMEM Level
{
public:

	/// <summary>
	///		Gets the current level.
	/// </summary>
	/// <returns>
	///		The level code of the current level.
	/// </returns>
	static LevelCode getCurrentLevel();

	/// <summary>
	///		Warps the player directly to a given level.
	///		<para>Note* this only works if the player is not on the main menu or an fmv cutscene</para>
	/// </summary>
	/// <param name="code:">
	///		<para>The LevelCode of the level to warp to.</para>
	/// </param>
	static void changeLevel(LevelCode code);
};

