#include "pch.h"
#include "GUI.h"
#include "framework.h"
#include <filesystem>
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_win32.h"
#include "TygerFrameworkAPI.hpp"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "resource.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "core.h"
#include "totals.h"
#include "level.h"
#include "windows.h"
#include "include/TyNumberFont.hpp"

std::map<std::string, unsigned int> GUI::icons;


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool GUI::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_KEYDOWN && wParam == VK_F3) {
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) 
            GUI::isShown = !GUI::isShown;
        else if (GUI::isShown)
            GUI::showLevelCounts = !GUI::showLevelCounts;
    }
    if (API::DrawingGUI())
        if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
            return true;
    return false;
}

void GUI::Initialize() {

    ImGui::CreateContext();

    ImFontAtlas* fonts = ImGui::GetIO().Fonts;
    fonts->Clear();

    ImFontConfig custom_icons{};
    custom_icons.FontDataOwnedByAtlas = false;

    fonts->AddFontFromMemoryCompressedTTF(TyNumberFont_compressed_data, TyNumberFont_compressed_size, 40);
    fonts->Build();

    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    if (API::GetTyWindowHandle() == 0) {
        API::LogPluginMessage("Error");
        return;
    }

    ImGui_ImplWin32_InitForOpenGL(API::GetTyWindowHandle());
    ImGui_ImplOpenGL3_Init();

    if (!GUI::LoadIcons()) {
        API::LogPluginMessage("Failed to load icons.");
        return;
    }

    API::LogPluginMessage("Initialized ImGui");
    GUI::init = true;
}

//ImGui Drawing code
void GUI::DrawUI() {
    if (!isShown)
        return;

    if (!GUI::init)
        Initialize();


    HWND hwnd = (HWND)API::GetTyWindowHandle();
    RECT rect;
    if (!GetClientRect(hwnd, &rect)) {
        API::LogPluginMessage("Failed to get window size.");
        return;
    }    
    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;
    const int baseWidth = 1920;
    const int baseHeight = 1080;
    float widthScale = static_cast<float>(windowWidth) / baseWidth;
    float heightScale = static_cast<float>(windowHeight) / baseHeight;
    float uiScale = min(widthScale, heightScale);
    int iconScale = static_cast<int>(uiScale * 64);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 5.0f, 5.0f });
    ImGui::PushStyleColor(ImGuiCol_WindowBg, { 0.0f, 0.0f, 0.0f, 0.0f });

    ImGui::SetNextWindowBgAlpha(0.0f);

    ImGui::Begin((API::PluginName + " Overlay").c_str(), nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::SetWindowFontScale(uiScale);

    auto totalType = GUI::showLevelCounts ? TotalType::Level : TotalType::Global;

    int count = 0;
    ImVec2 textSize;
    float textVerticalOffset;
    ImVec2 shadowOffset = ImVec2(uiScale * 3.0f, uiScale * 3.0f);
    ImVec4 shadowColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);  
    ImVec4 defaultColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);  
    ImVec2 originalPos;

    ImGui::Image((ImTextureID)(intptr_t)icons["thegg"], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentThunderEggCount(totalType);
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);

    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    ImGui::Image((ImTextureID)(intptr_t)icons["cog"], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentCogCount(totalType);
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);

    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    ImGui::Image((ImTextureID)(intptr_t)icons["bilby"], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentBilbyCount(totalType);
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);

    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    auto currentLevel = Level::getCurrentLevel();
    std::string opalType = "";
    switch ((int)currentLevel / 4) {
        case 0: opalType = "opalZ"; break;
        case 1: opalType = "opalA"; break;
        case 2: opalType = "opalB"; break;
        default: opalType = "opalC"; break;
    }
    ImGui::Image((ImTextureID)(intptr_t)icons[opalType], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentOpalCount(false);
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);

    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    ImGui::Image((ImTextureID)(intptr_t)icons["frame"], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentFrameCount(totalType);
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);

    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    ImGui::Image((ImTextureID)(intptr_t)icons["rang"], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentRangCount();
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);

    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    ImGui::Image((ImTextureID)(intptr_t)icons["talisman"], ImVec2(iconScale, iconScale));
    count = Totals::getCurrentTalismanCount();
    textSize = ImGui::CalcTextSize(std::to_string(count).c_str());
    textVerticalOffset = (iconScale - textSize.y) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + textVerticalOffset);
    originalPos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(originalPos.x + shadowOffset.x, originalPos.y + shadowOffset.y));
    ImGui::TextColored(shadowColor, "%d", count);
    ImGui::SetCursorPos(originalPos);
    ImGui::Text("%d", count);
    ImGui::Dummy(ImVec2(0.0f, uiScale * 7.0f));

    ImGui::End();

    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool GUI::ImGuiWantCaptureMouse() {
    return GUI::init && ImGui::GetIO().WantCaptureMouse;
}

GLuint GUI::LoadTextureFromResource(int resource_id) {
    auto hModule = GetModuleHandle(std::wstring(API::PluginName.begin(), API::PluginName.end()).c_str());

    HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(resource_id), L"PNG");
    if (!hResource) {
        API::LogPluginMessage("Failed to find resource\n");
        return 0;
    }

    HGLOBAL hMemory = LoadResource(hModule, hResource);
    if (!hMemory) {
        API::LogPluginMessage("Failed to load resource\n");
        return 0;
    }

    DWORD size = SizeofResource(hModule, hResource);
    if (size == 0) {
        API::LogPluginMessage("Resource size is zero\n");
        return 0;
    }

    void* pData = LockResource(hMemory);
    if (!pData) {
        API::LogPluginMessage("Failed to lock resource\n");
        return 0;
    }

    int width, height, channels;
    unsigned char* data = stbi_load_from_memory((unsigned char*)pData, size, &width, &height, &channels, 4);
    if (!data) {
         API::LogPluginMessage(stbi_failure_reason());  // Log the reason for failure
        return 0;
    }

    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    return texture_id;
}

bool GUI::LoadIcons() {
    icons["thegg"] = GUI::LoadTextureFromResource(THEGG_ICON);
    icons["cog"] = GUI::LoadTextureFromResource(COG_ICON);
    icons["opalA"] = GUI::LoadTextureFromResource(OPAL_A_ICON);
    icons["opalB"] = GUI::LoadTextureFromResource(OPAL_B_ICON);
    icons["opalC"] = GUI::LoadTextureFromResource(OPAL_C_ICON);
    icons["opalZ"] = GUI::LoadTextureFromResource(OPAL_Z_ICON);
    icons["talisman"] = GUI::LoadTextureFromResource(TALISMAN_ICON);
    icons["rang"] = GUI::LoadTextureFromResource(RANG_ICON);
    icons["bilby"] = GUI::LoadTextureFromResource(BILBY_ICON);
    icons["frame"] = GUI::LoadTextureFromResource(FRAME_ICON);
    return true;
}
