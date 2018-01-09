// KeyboardTest.cpp : 定义控制台应用程序的入口点。
//

#include <tchar.h>
#include <windows.h>

#include <iostream>
#include <string>

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
    wstring strTime(GetNowTime());
    wcout << _T("当前时间：") << strTime << endl;
    wstring strYear = strTime.substr(0, 4);
    wstring strMon = strTime.substr(5, 2);
    wstring strDay = strTime.substr(8, 2);
    wcout << strYear << _T("年") << strMon << _T("月") << strDay << _T("日") << endl;
    wstring strHour = strTime.substr(11, 2);
    wstring strMin = strTime.substr(14, 2);
    wstring strSec = strTime.substr(17, 2);
    wcout << strHour << _T("时") << strMin << _T("分") << strSec << _T("秒") << endl;
}

//设置预设键盘效果
void ChangeEffect()
{
    SwitchLedEffect(EFF_FULL_ON);
}

//设置个性化LED效果
void ChangeLED()
{
    COLOR_MATRIX colorMatrix;
    for (int i = 0; i < MAX_LED_ROW; ++i)
    {
        for (int j = 0; j < MAX_LED_COLUMN; ++j)
        {
            if (15 <= j)
            {
                colorMatrix.KeyColor[i][j] = KEY_COLOR(0, 0, 0);
            }
            else
            {
                colorMatrix.KeyColor[i][j] = KEY_COLOR(255, 255, 255);
            }
        }
    }
    SetAllLedColor(colorMatrix);
}

//设置LED效果
void setLEDEffect()
{
    EnableLedControl(true);

    ChangeLED();
    Sleep(5000);

    EnableLedControl(false);
}

int main()
{
    initKeyboardTest();
    printInfo();
    setLEDEffect();

    system("pause");
    return 0;
}

