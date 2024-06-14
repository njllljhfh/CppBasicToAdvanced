#include <iostream>
#include <string>
#include "011_Time.h"
using namespace std;


class Student011
{
public:
    int number;
    char name[100];
};

// c语言初始化的方式
void initTime(Time011& stmptime, int tmphour, int tmpminute, int tmpsec)
{
    stmptime.Hour = tmphour;
    stmptime.Minute = tmpminute;
    stmptime.Secend = tmpsec;
}

int main011()
{
    //C++从基础到进阶-视频-11
    cout << "011_类_成员函数-对象拷贝-私有成员" << endl;
    /*
        一、综述：
            - 类使我们自定义的数据类型
            - 设计类时要考虑的角度：
                1. 站在设计和实现者的角度来考虑。
                2. 站在使用者的角度来考虑。
                3. 父类、子类的角度。

    */

    /*
        二、类基础
            1. 一个类就是开发者自定义的数据类型，可以把类想象成一个命名空间，包着一堆东西（成员函数、成员变量）
            2. 一个类的构成： 成员变量、成员函数（有很多特殊成员函数，后续慢慢讲解）。
            3. 通过类对象访问成员的语法：
                - 类对象.成员名
            4. 通过类对象的指针访问成员的语法：
                - 指针名->成员名
            5. public 成员提供接口，暴露给外界，供外界调用。private 成员提供各种实现类功能的细节方法，不暴露给外界，外界无法使用。
            6. class成员的默认权限 private。struct成员的默认权限是 public。
                - struct A{...} 等价于 class A{public:...}
    */
    cout << "二、类基础" << endl;
    Student011 someone;  //定义类的对象
    someone.number = 1000; //通过类对象访问成员
    Student011* psomeone = &someone;
    psomeone->number = 1005; //通过类对象的指针访问成员
    cout << someone.number << endl;
    cout << "-------------------------------------------------------" << endl;

    /*
        三、成员函数
    */
    cout << "三、成员函数" << endl;
    Time011 myTime; // 类对象
    initTime(myTime, 11, 14, 5); // c语言风格的初始化的方式
    cout << myTime.Hour << endl;
    cout << myTime.Minute << endl;
    cout << myTime.Secend << endl;
    cout << "----------" << endl;

    Time011 myTime2;
    myTime2.initTime(11, 14, 5);
    cout << myTime2.Hour << endl;
    cout << myTime2.Minute << endl;
    cout << myTime2.Secend << endl;

    cout << "-------------------------------------------------------" << endl;

    /*
        四、对象拷贝
            - 对象本身是可以拷贝的
            - 默认情况下，这种类对象的拷贝，是每个成员变量逐个拷贝。
                - 如果在类中定义适当的 赋值运算符，就能够控制对象的这种拷贝行为。
    */
    cout << "四、对象拷贝" << endl;
    Time011 myTime3;
    myTime3.Hour = 12;
    myTime3.Minute = 15;
    myTime3.Secend = 40;
    // 以下的写法都是对象拷贝
    Time011 myTime4 = myTime3;
    Time011 myTime5(myTime3);
    Time011 myTime6{ myTime3 };
    Time011 myTime7 = { myTime3 };
    myTime7.Hour = 8;
    cout << "-------------------------------------------------------" << endl;
    /*
        五、私有成员
    */
    cout << "五、私有成员" << endl;
    Time011 myTime8;
    //myTime8.Millisecond = 1000;  //不能访问私有成员变量：无法访问 private 成员
    //myTime8.initMillTime(1);  //不能访问私有成员函数：无法访问 private 成员
    myTime8.initTime(1, 2, 3);
    cout << "-------------------------------------------------------" << endl;

    return 0;
}
