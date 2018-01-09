// KeyboardTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <tchar.h>
#include <windows.h>

#include <iostream>
#include <string>

#include "SDKDLL.h"

using namespace std;

// ��ʼ�����̲��Գ���
void initKeyboardTest()
{
    //���������������
    wcout.imbue(locale(locale(), "", LC_CTYPE));

    //���ò�������
    SetControlDevice(DEV_MKeys_L_White);
}

// ��ӡ������Ϣ
void printInfo()
{
    //��ȡDLL�汾
    wcout << _T("DLL�汾��") << GetCM_SDK_DllVer() << endl;

    //�������Ƿ����
    WCHAR* isKeyboardPlug;
    if (IsDevicePlug() == true)
    {
        isKeyboardPlug = L"true";
    }
    else
    {
        isKeyboardPlug = L"false";
    }
    wcout << _T("�����Ƿ���룺") << isKeyboardPlug << endl;

    //�����̲���
    wcout << _T("���̲��֣�");
    switch (GetDeviceLayout())
    {
    case LAYOUT_KEYBOARD::LAYOUT_UNINIT:
        wcout << _T("δ֪") << endl;
        break;
    case LAYOUT_KEYBOARD::LAYOUT_US:
        wcout << _T("��ʽ") << endl;
        break;
    case LAYOUT_KEYBOARD::LAYOUT_EU:
        wcout << _T("ŷʽ") << endl;
        break;
    default:
        wcout << _T("�쳣") << endl;
        break;
    }

    //��ȡ��ǰʱ��
    wstring strTime(GetNowTime());
    wcout << _T("��ǰʱ�䣺") << strTime << endl;
    wstring strYear = strTime.substr(0, 4);
    wstring strMon = strTime.substr(5, 2);
    wstring strDay = strTime.substr(8, 2);
    wcout << strYear << _T("��") << strMon << _T("��") << strDay << _T("��") << endl;
    wstring strHour = strTime.substr(11, 2);
    wstring strMin = strTime.substr(14, 2);
    wstring strSec = strTime.substr(17, 2);
    wcout << strHour << _T("ʱ") << strMin << _T("��") << strSec << _T("��") << endl;
}

//����Ԥ�����Ч��
void ChangeEffect()
{
    SwitchLedEffect(EFF_FULL_ON);
}

//���ø��Ի�LEDЧ��
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

//����LEDЧ��
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

