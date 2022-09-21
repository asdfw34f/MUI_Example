mkdir .\en-US
muirct.exe -q DoReverseMuiLoc.rcconfig -v 2 -x 0x0409 -g 0x0407 .\HelloModule_en_us.dll .\HelloModule.dll .\en-US\HelloModule.dll.mui
muirct.exe -c HelloModule.dll -e en-US\HelloModule.dll.mui

mkdir .\ru-RU
muirct.exe -q DoReverseMuiLoc.rcconfig -v 2 -x 0x0419 -g 0x0407 .\HelloModule_ru_ru.dll .\HelloModule_discard.dll .\ru-RU\HelloModule.dll.mui
muirct.exe -c HelloModule.dll -e ru-RU\HelloModule.dll.mui
