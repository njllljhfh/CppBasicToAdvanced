#include "011_Time.h"

// '::' 是 作用域运算符。表示 initTime 函数属于 Time011 类。
void Time011::initTime(int tmphour, int tmpminute, int tmpsec)
{
    // 成员函数中，可以直接使用成员变量名
    // 哪个对象调用的该成员函数，这些成员变量就属于哪个对象
    Hour = tmphour;
    Minute = tmpminute;
    Secend = tmpsec;
    initMillTime(11);
}

void Time011::initMillTime(int mls)
{
    //成员函数可以访问成员变量，不管成员是否是私有
    Millisecond = mls;
}