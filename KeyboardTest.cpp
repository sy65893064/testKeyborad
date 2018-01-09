// KeyboardTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <tchar.h>
#include <windows.h>
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
    WCHAR* strTime = NULL;
    strTime = GetNowTime();
    wcout << _T("��ǰʱ�䣺") << strTime << endl;
}

int main()
{
    initKeyboardTest();
    printInfo();

    system("pause");
    return 0;
}

