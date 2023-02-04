/*
* 2nd Sem College project using sfml 2.5.1 32bit
*/
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