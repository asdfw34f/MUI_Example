#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../HelloModule_ru_ru/resource.h"
#include <locale>
int main()
{
	WCHAR userLanguagesMultiString[] = L"ru-RU\0\0";
	DWORD langCount = 0;
	bool info = GetUILanguageInfo(MUI_LANGUAGE_NAME, userLanguagesMultiString, NULL, 0, &langCount);
	if (info)
	{
		setlocale(LC_ALL, "");
	}
	//setlocale(LC_ALL, "RUS");
	HINSTANCE hinstLib;
	hinstLib = LoadLibrary(TEXT("HelloModule_ru_ru.dll"));
	char qwe[100];
	LoadStringA(hinstLib, HELLO_MUI_STR_0, qwe, sizeof(qwe));

	printf_s("%s", qwe);
	_getch();
	return 0;
}

