
#include "include.h"

using namespace std;

string gen_random(const int len, DWORD procID) {

	string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	srand((unsigned)time(NULL) * procID);

	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

	return tmp_s;
}

int main()
{
	SetConsoleTitle("ARWARE");
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL)
	{ 
	MoveWindow(hwnd, 340, 150, 750, 500, TRUE);
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX); 
	} //size + noresize

	userinterface::change_color(3);
	cout << "ARWARE External - by github.com/00cloud00 (cloudev0@protonmail.com)" << endl;
	userinterface::change_color(7);

	DWORD pID;
	cout << "Enter <csgo.exe> processID:" << endl;
	cin >> pID;

	SetConsoleTitle(gen_random(8, pID).c_str());

	getProcess(pID);
	gameModule = getModule(XOR(LPSTR("client.dll")));
	engineModule = getModule(XOR(LPSTR("engine.dll")));
	
	if (!engineModule || !gameModule)
	{
		cout << "Couldn't find game modules." << endl;
		Sleep(1000);
		return -1;
	}
	Sleep(500);
	system("cls");

	userinterface::change_color(2);
	cout << std::dec << "Initializing..." << endl;
	Sleep(500);

	userinterface::ui();

	localPlayer::initLocal();

	//main loop
	while (true)
	{
		if (GetAsyncKeyState(VK_END) && 1)
			break;

		userinterface::get_keys();
		//threads, ui
		
		bhop::bhop();
		triggerbot::trigger();
		norecoil::rcs();

		//iteration
		for (int i = 0; i < 32; i++)
		{
			glowesp::glow(i);
			radar::show(i);
		}
		
	}

}