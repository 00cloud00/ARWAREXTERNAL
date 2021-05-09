#include "include.h"

using namespace std;

void userinterface::change_color(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void userinterface::ui()
{
	system("cls");
	userinterface::change_color(3);
	cout << "ARWARE External - by github.com/00cloud00 (cloudev0@protonmail.com)" << endl;
	userinterface::change_color(7);
	cout << "[END]->Panic key" << endl;

	if (bhop::bhop_status)
	{
		cout << "[F1]->Bhop = ";
		userinterface::change_color(2);
		cout << "ON" << endl;
	}
	else {
		cout << "[F1]->Bhop = ";
		userinterface::change_color(4);
		cout << "OFF" << endl;	
	}
	userinterface::change_color(7);

	if (triggerbot::triggerbot_status)
	{
		cout << "[F2]->Triggerbot = ";
		userinterface::change_color(2);
		cout << "ON" << endl;
	}
	else {
		cout << "[F2]->Triggerbot = ";
		userinterface::change_color(4);
		cout << "OFF" << endl;
	}
	userinterface::change_color(7);

	if (glowesp::glow_status)
	{
		cout << "[F3]->GlowESP = ";
		userinterface::change_color(2);
		cout << "ON" << endl;
	}
	else {
		cout << "[F3]->GlowESP = ";
		userinterface::change_color(4);
		cout << "OFF" << endl;
	}
	userinterface::change_color(7);

	if (radar::radar_status)
	{
		cout << "[F4]->Radar = ";
		userinterface::change_color(2);
		cout << "ON" << endl;
	}
	else {
		cout << "[F4]->Radar = ";
		userinterface::change_color(4);
		cout << "OFF" << endl;
	}
	userinterface::change_color(7);
	if(norecoil::norecoil_status)
	{
		cout << "[F6]->NoRecoil = ";
		userinterface::change_color(2);
		cout << "ON" << endl;
	}
	else {
		cout << "[F6]->NoRecoil = ";
		userinterface::change_color(4);
		cout << "OFF" << endl;
	}
	userinterface::change_color(7);

}

void userinterface::get_keys()
{
	if (GetAsyncKeyState(VK_F1) & 1)
	{
		bhop::bhop_status = !bhop::bhop_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F2) & 1)
	{
		triggerbot::triggerbot_status = !triggerbot::triggerbot_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F3) & 1)
	{
		glowesp::glow_status = !glowesp::glow_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		radar::radar_status = !radar::radar_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F6) & 1)
	{
		norecoil::norecoil_status = !norecoil::norecoil_status;
		userinterface::ui();
	}

}