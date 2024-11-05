#pragma once

#ifdef TYGERMEM_EXPORTS
#define TYGERMEM __declspec(dllexport)
#else
#define TYGERMEM __declspec(dllimport)
#endif

enum TotalType {
	Level,
	Global
};

class TYGERMEM Totals
{
public:
	static int getCurrentThunderEggCount(TotalType totalType);
	static int getCurrentCogCount(TotalType totalType);
	static int getCurrentBilbyCount(TotalType totalType);
	static int getCurrentFrameCount(TotalType totalType);
	static int getCurrentOpalCount(bool thisLoad);
	static int getCurrentRangCount();
	static int getCurrentTalismanCount();
};

