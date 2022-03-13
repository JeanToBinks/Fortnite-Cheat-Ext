#include "win_utils.h"

void RectFilled(int x, int y, int w, int h, ImColor color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
}
void ShadowText(int posx, int posy, ImColor clr, const char* text)
{
	ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 2), ImColor(0, 0, 0, 200), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 2), ImColor(0, 0, 0, 200), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
}
void Rect(int x, int y, int w, int h, ImColor color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0, thickness);
}

namespace CL
{
	void CL_ToggleButton(bool* option, float x, float y)
	{
		ImGui::SetCursorPos({ x, y });

		ImVec2 pos = ImGui::GetWindowPos();

		if (ImGui::Button("", ImVec2{30, 15}))
			*option = !*option;

		if (*option)
		{
			RectFilled(pos.x + x, pos.y + y, 30, 15, ImColor(200, 0, 0, 255));// background
			RectFilled(pos.x + x, pos.y + y, 12, 15, ImColor(96, 97, 100, 255)); // button
		}
		else
		{
			RectFilled(pos.x + x, pos.y + y, 30, 15, ImColor(0, 200, 0, 255)); // background
			RectFilled(pos.x + x + 20, pos.y + y, 12, 15, ImColor(96, 97, 100, 255)); // button
		}
	}
}