//#pragma once
#ifndef __MYTIME__
#define __MYTIME__

//int g_global = 5; ȫ�ֱ������ظ����壬����

//������
class Time011
{
private:
    int Millisecond; //����
    void initMillTime(int mls);

public:
    int Hour;  //ʱ
    int Minute; //��
    int Secend; //��

    //��Ա����
    void initTime(int tmphour, int tmpminute, int tmpsec);

};

#endif // !__MYTIME__
