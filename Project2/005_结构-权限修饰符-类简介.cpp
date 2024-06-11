#include <iostream>
#include "005_student.h"
using namespace std;

struct student 
{
public: //结构成员默认都是public的权限，所以可以不加public。类内可以访问，类外也可以访问。
    // 成员变量
    int number; //学号
    char name[100]; //学生名
    void func() // 成员函数（也叫方法）
    {
        numAddOne();
    }
private: //类内可以访问，类外不可以访问，子类不可以访问
    void numAddOne()
    {
        number++;
    }
};

// 形参用结构变量（值传递）
void func(student tmpstu)
{
    tmpstu.number = 2000;
    strcpy_s(tmpstu.name, sizeof(tmpstu.name), "who");
    return;
}

// 形参用引用（地址传递）
void func2(student& tmpstu)
{
    tmpstu.number = 2000;
    strcpy_s(tmpstu.name, sizeof(tmpstu.name), "who2");
    return;
}

// 用指向结构体的指针做函数参数（地址传递）
void func3(student* ptmpstu)
{
    ptmpstu->number = 3000;  // -> 指向运算符
    strcpy_s(ptmpstu->name, sizeof(ptmpstu->name), "who3");
    return;
}

int main005()
{
    //C++从基础到进阶-视频-05

    cout << "005_结构-权限修饰符-类简介" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "一、结构回顾" << endl;
    /*
        一、结构体回顾
            结构体：自定义的数据类型
            c++中的结构体 和 c中的结构体 有什么区别呢？
                - c++中的结构体除具备了c中结构体的所有功能外，还增加了很多扩展功能：
                    - c++中的结构体不仅仅有成员变量，还可以在其中定义成员函数。
    */
    student student1; //定义结构变量。这里可以省略 struct 关键字，直接用结构名 student。
    student1.number = 1001;
    strcpy_s(student1.name, sizeof(student1.name), "zhangsan");
    cout << student1.number << endl;
    cout << student1.name << endl;
    cout << "---------" << endl;

    cout << "形参用结构变量（值传递）：" << endl;
    func(student1); //效率低，因为实参传递给形参时，发生了数据拷贝
    cout << student1.number << endl;  //值没有被函数改变
    cout << student1.name << endl;  //值没有被函数改变
    cout << "---------" << endl;

    cout << "形参用引用（地址传递）：" << endl;
    func2(student1);
    cout << student1.number << endl;  //值被函数改变
    cout << student1.name << endl;  //值被函数改变
    cout << "---------" << endl;

    cout << "用指向结构体的指针做函数参数（地址传递）：" << endl;
    func3(&student1);
    cout << student1.number << endl;  //值被函数改变
    cout << student1.name << endl;  //值被函数改变
    cout << "---------" << endl;

    cout << "成员函数：" << endl;
    student1.func();
    cout << student1.number << endl;  //3001

    cout << "-------------------------------------------------------" << endl;

    cout << "二、权限修饰符" << endl;
    /*
        二、权限修饰符：public(公有)，private(私有)，protected(保护)。本节课只谈 public，private。
            public：公共的意思，用其修饰的 成员变量 和 成员函数 可以被外界访问。
            private：私有的意思，用其修饰的 成员变量 和 成员函数 只能被内部定义的成员函数使用，子类不可访问。
    */
    cout << "-------------------------------------------------------" << endl;
    cout << "三、类简介" << endl;
    /*
        三、类简介：类也是用户自定义的类型
            结构体 和 类 有什么区别？
                1. c++中才有类的概念，c中没有类的概念。
                    - 结构体用 struct 定义，类用 class 定义。
                    - 在c中，定义一个类型为某个结构体的变量，称之为 结构变量。
                    - 在c++中，定义一个类型为某个类的变量，称之为 对象。
                    - 结构变量 和 类的对象 它们都是一块能够存储数据，并且具有某种类型的内存空间。
                2. c++中，结构体 和 类 其相似，区别有两点：
                    2.1
                        - c++结构体内部的 成员变量 以及 成员函数 默认的权限是 public。
                        - c++类内部的 成员变量 以及 成员函数 默认的权限是 private。
                    2.2
                        - c++结构体继承默认是public，而类的继承默认是 private。

        额外说明：
            1. 标准c++库里包含大量丰富的类和函数（例如 string）。
            2. 写代码尽量封装成类。
    */
    cout << "-------------------------------------------------------" << endl;

    cout << "四、类的组织（书写规范）" << endl;
    /*
        四、类的组织（书写规范）：
            类的定义代码放在一个 .h 的头文件中，头文件命可以跟类文件名相同。
            类的具体实现代码，放在一个 .cpp 文件中。
    */
    Student2 stu;
    stu.number = 110;
    strcpy_s(stu.name, sizeof(stu.name), "lisi");
    cout << "number: " << stu.number << endl;
    cout << "name: " << stu.name << endl;
    stu.func();
    cout << "number: " << stu.number << endl;

    cout << "-------------------------------------------------------" << endl;

    return 0;
}