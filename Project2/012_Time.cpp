#include "012_Time.h"
#include <iostream>

// '::' �� ���������������ʾ initTime �������� Time011 �ࡣ
void Time012::initTime(int tmphour, int tmpminute, int tmpsec)
{
    // ��Ա�����У�����ֱ��ʹ�ó�Ա������
    // �ĸ�������õĸó�Ա��������Щ��Ա�����������ĸ�����
    Hour = tmphour;
    Minute = tmpminute;
    Secend = tmpsec;
    initMillTime(0);
}

void Time012::initMillTime(int mls)
{
    //��Ա�������Է��ʳ�Ա���������ܳ�Ա�Ƿ���˽��
    Millisecond = mls;
}

//���캯��
Time012::Time012(int tmphour, int tmpminute, int tmpsec)
    :Hour(tmphour), Minute(tmpminute), Secend(tmpsec), Millisecond(0) //���캯����ʼ���б��ں�����ִ��֮ǰִ�С��������ǻ���д�ģ�Ҳ���Բ����У�
    //:Hour(tmphour), Minute(Hour), Secend(tmpsec), Millisecond(0) // ���캯����ʼ���б��У������ĳ�ʼ��˳��ȡ������ͬ�ļ��У���������ʱ�����Ķ���˳���ȶ�����ȳ�ʼ���������в�Ҫ����ʹ�ã����Գ����޸ı���˳�򣬴�ϵ���Կ�������
{
    //Hour = tmphour;
    //Minute = tmpminute;
    //Secend = tmpsec;
    //initMillTime(0);
    std::cout << "������ Time012::Time012(int tmphour, int tmpminute, int tmpsec) ���캯��" << std::endl;
}

//���캯��
Time012::Time012()
{
    Hour = 12;
    Minute = 59;
    Secend = 59;
    Millisecond = 59;
    std::cout << "������ Time012::Time012() ���캯��" << std::endl;
}

//��2�������� ���캯��
Time012::Time012(int tmphour, int tmpminute)
{
    Hour = tmphour;
    Minute = tmpminute;
    Secend = 59;
    initMillTime(0);
    std::cout << "������ Time012::Time012(int tmphour, int tmpminute) ���캯��" << std::endl;
}

//��1�������� ���캯��
Time012::Time012(int tmphour)
{
    Hour = tmphour;
    Minute = 59;
    Secend = 59;
    initMillTime(0);
    std::cout << "������ Time012::Time012(int tmphour) ���캯��" << std::endl;
}