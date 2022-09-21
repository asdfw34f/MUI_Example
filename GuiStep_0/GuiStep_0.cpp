#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../HelloModule_ru_ru/resource.h"
#include <locale>
int main()
{
	WCHAR userLanguagesMultiString[] = L"ru-RU\0\0";
	DWORD langCount = 0;
	HINSTANCE hinstLib;

	bool info = GetUILanguageInfo(MUI_LANGUAGE_NAME, userLanguagesMultiString, NULL, 0, &langCount);
	if (info)
	{
		setlocale(LC_ALL, "");
		hinstLib = LoadLibrary(TEXT("HelloModule_ru_ru.dll"));
	} else 
		hinstLib = LoadLibrary(TEXT("HelloModule_en_us.dll"));
	char qwe[100];
	LoadStringA(hinstLib, HELLO_MUI_STR_0, qwe, sizeof(qwe));

	printf_s("%s", qwe);
	_getch();
	return 0;
}

