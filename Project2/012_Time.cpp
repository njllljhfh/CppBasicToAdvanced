#include "012_Time.h"
#include <iostream>

// '::' 是 作用域运算符。表示 initTime 函数属于 Time011 类。
void Time012::initTime(int tmphour, int tmpminute, int tmpsec)
{
    // 成员函数中，可以直接使用成员变量名
    // 哪个对象调用的该成员函数，这些成员变量就属于哪个对象
    Hour = tmphour;
    Minute = tmpminute;
    Secend = tmpsec;
    initMillTime(0);
}

void Time012::initMillTime(int mls)
{
    //成员函数可以访问成员变量，不管成员是否是私有
    Millisecond = mls;
}

//构造函数
Time012::Time012(int tmphour, int tmpminute, int tmpsec)
    :Hour(tmphour), Minute(tmpminute), Secend(tmpsec), Millisecond(0) //构造函数初始化列表。在函数体执行之前执行。（这里是换行写的，也可以不换行）
    //:Hour(tmphour), Minute(Hour), Secend(tmpsec), Millisecond(0) // 构造函数初始化列表中，变量的初始化顺序取决于在同文件中，函数声明时变量的定义顺序，先定义的先初始化（开发中不要这样使用，可以尝试修改变量顺序，打断点调试看看）。
{
    //Hour = tmphour;
    //Minute = tmpminute;
    //Secend = tmpsec;
    //initMillTime(0);
    std::cout << "调用了 Time012::Time012(int tmphour, int tmpminute, int tmpsec) 构造函数" << std::endl;
}

//构造函数
Time012::Time012()
{
    Hour = 12;
    Minute = 59;
    Secend = 59;
    Millisecond = 59;
    std::cout << "调用了 Time012::Time012() 构造函数" << std::endl;
}

//带2个参数的 构造函数
Time012::Time012(int tmphour, int tmpminute)
{
    Hour = tmphour;
    Minute = tmpminute;
    Secend = 59;
    initMillTime(0);
    std::cout << "调用了 Time012::Time012(int tmphour, int tmpminute) 构造函数" << std::endl;
}

//带1个参数的 构造函数
Time012::Time012(int tmphour)
{
    Hour = tmphour;
    Minute = 59;
    Secend = 59;
    initMillTime(0);
    std::cout << "调用了 Time012::Time012(int tmphour) 构造函数" << std::endl;
}