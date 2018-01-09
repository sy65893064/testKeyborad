// KeyboardTest.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <tchar.h>
#include <windows.h>
#include "SDKDLL.h"

using namespace std;

// 初始化键盘测试程序
void initKeyboardTest()
{
    //设置中文输出环境
    wcout.imbue(locale(locale(), "", LC_CTYPE));

    //设置操作键盘
    SetControlDevice(DEV_MKeys_L_White);
}

// 打印键盘信息
void printInfo()
{
    //获取DLL版本
    wcout << _T("DLL版本：") << GetCM_SDK_DllVer() << endl;

    //监测键盘是否插入
    WCHAR* isKeyboardPlug;
    if (IsDevicePlug() == true)
    {
        isKeyboardPlug = L"true";
    }
    else
    {
        isKeyboardPlug = L"false";
    }
    wcout << _T("键盘是否插入：") << isKeyboardPlug << endl;

    //监测键盘布局
    wcout << _T("键盘布局：");
    switch (GetDeviceLayout())
    {
    case LAYOUT_KEYBOARD::LAYOUT_UNINIT:
        wcout << _T("未知") << endl;
        break;
    case LAYOUT_KEYBOARD::LAYOUT_US:
        wcout << _T("美式") << endl;
        break;
    case LAYOUT_KEYBOARD::LAYOUT_EU:
        wcout << _T("欧式") << endl;
        break;
    default:
        wcout << _T("异常") << endl;
        break;
    }

    //获取当前时间
    WCHAR* strTime = NULL;
    strTime = GetNowTime();
    wcout << _T("当前时间：") << strTime << endl;
}

int main()
{
    initKeyboardTest();
    printInfo();

    system("pause");
    return 0;
}

