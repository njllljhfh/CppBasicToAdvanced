#include "011_Time.h"

// '::' �� ���������������ʾ initTime �������� Time011 �ࡣ
void Time011::initTime(int tmphour, int tmpminute, int tmpsec)
{
    // ��Ա�����У�����ֱ��ʹ�ó�Ա������
    // �ĸ�������õĸó�Ա��������Щ��Ա�����������ĸ�����
    Hour = tmphour;
    Minute = tmpminute;
    Secend = tmpsec;
    initMillTime(11);
}

void Time011::initMillTime(int mls)
{
    //��Ա�������Է��ʳ�Ա���������ܳ�Ա�Ƿ���˽��
    Millisecond = mls;
}