//#pragma once
#ifndef __MYTIME__
#define __MYTIME__

//int g_global = 5; ȫ�ֱ������ظ����壬����

//������
class Time012
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

public:
    //���캯��
    //Time012(int tmphour, int tmpminute, int tmpsec = 12);
    //Time012(int tmphour, int tmpminute, int tmpsec);
    explicit Time012(int tmphour, int tmpminute, int tmpsec);
    Time012(int tmphour, int tmpminute);
    explicit Time012(int tmphour);
    Time012(); //���Ӳ�����
};

#endif // !__MYTIME__
