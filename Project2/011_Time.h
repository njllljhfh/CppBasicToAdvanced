//#pragma once
#ifndef __MYTIME__
#define __MYTIME__

//int g_global = 5; 全局变量。重复定义，报错。

//类声明
class Time011
{
private:
    int Millisecond; //毫秒
    void initMillTime(int mls);

public:
    int Hour;  //时
    int Minute; //分
    int Secend; //秒

    //成员函数
    void initTime(int tmphour, int tmpminute, int tmpsec);

};

#endif // !__MYTIME__
