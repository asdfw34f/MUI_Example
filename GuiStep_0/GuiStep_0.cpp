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
    setlocale(LC_ALL, "RUS");
    

    hinstLib = LoadLibrary(TEXT("HelloModule.dll"));

    wchar_t* desc = NULL;
    wchar_t qwe[100];
    LoadStringW(hinstLib, HELLO_MUI_STR_0, qwe, sizeof(qwe));

    int age;
    printf_s("\nВведите возраст:\t");
    scanf_s("%d", &age);

    wchar_t string[15];
    wprintf_s(L"\nВведите имя:\t");
    wscanf_s(L"%ls", &string);

    DWORD_PTR pArgs[] = { (DWORD_PTR)string ,
       (DWORD_PTR)age };

    FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ARGUMENT_ARRAY,
        qwe,
        0,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (wchar_t*)&desc,
        0,
        (va_list*)pArgs);
    
    wprintf(L"%s", desc);

    LocalFree(desc);
    FreeLibrary(hinstLib);

    _getch();
    return 0;
}

