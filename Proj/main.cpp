#include"app.h"

int main()
{
	//MessageBox(NULL, L"HELLO", L"HELLO", MB_OK);
	App app;
	while (app.isRunning())
	{
		app.update();
		app.render();
	}
	return 0;
}