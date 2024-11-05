#pragma once
#include <gl/GL.h>
#include <gl/GLU.h>
#include <map>
#include <string>

class GUI
{
private:
	static GLuint LoadTextureFromResource(int resource_id);
public:
	static inline bool init;
	static inline bool isShown;
	static inline bool showLevelCounts;
	static inline float cachedWindowHeight;
	static std::map<std::string, GLuint> icons;
	static bool LoadIcons();
	static void Initialize();
	static void DrawUI();
	static bool ImGuiWantCaptureMouse();
	static bool WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

