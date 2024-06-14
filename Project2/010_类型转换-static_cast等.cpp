#include<iostream>
#include <string>
#include<vector>
using namespace std;


int main010()
{
    //C++从基础到进阶-视频-10
    cout << "010_类型转换-static_cast等" << endl;
    /*
        一、隐式类型转换：系统自动进行，不需要开发者介入。
    */
    int m = 3 + 45.6; //把小数部分截掉了，属于隐式类型转换。
    double n = 3 + 45.6;

    cout << "-------------------------------------------------------" << endl;
    
    /*
        二、显示类型转换（强制类型转换）
    */
    //int k = 5 % 3.2; //语法错误
    //int k = 5 % (int)3.2; //C语言风格的强制类型转换
    int k = 5 % int(3.2); //函数风格的强制类型转换（C语言风格）
    cout << k << endl;

    cout << "-------" << endl;
    /*
        c++强制类型转换分为4种：
            1. static_cast
            2. dynamic_cast
            3. const_cast
            4. reinterpret_cast
        这4个强制类型转换都被称为 “命名强制类型转换”。

        通用形式：
            强制类型转换名<type>(express);
                - 强制类型转换名：上面的4个中的一个
                - type：转换的目标类型
                - express：要转换的值
    */

    /*
        static_cast：静态转换，编译的时候就会进行类型转换的检查。
            - 代码中药保证转换的安全性和正确性，static_cast跟c语言中的强制类型转换类似。
            - c风格的强制类型转换，以及 编译器能够进行的隐式类型转换，都可以用static_cast来显示完成。
    */
    cout << "static_cast 可用于：" << endl;
    cout << "1. 相关类型转换：比如整型和实型之间的转换" << endl;
    double f = 100.34f;
    int i = (int)f;  //c风格
    int i2 = static_cast<int>(f);  //c++风格的类型转换
    cout << "----------" << endl;

    cout << "2. 子类转成父类类型" << endl;
    class A {};
    class B : public A {};
    B b;
    A a = static_cast<A>(b);  // 把子类转成父类的对象
    cout << "----------" << endl;

    cout << "3. void* 与其他类型指针之间的转换" << endl;
    //void*：无类型指针，他是可以指向任何类型的指针（万能指针）
    int i3 = 10;
    int* p3 = &i3;
    //void* q3 = p3; // 可以
    void* q3 = static_cast<void*>(p3); // int* 转成 void*
    int* d3 = static_cast<int*>(q3); // void* 转成 int*
    cout << "-----------------------------------------" << endl;

    cout << "static_cast 不可用于：" << endl;
    cout << "1. 一般不能用于指针类型之间的转换" << endl;
    // 比如 int* 转 double*、float* 转 double* 等。
    double f4 = 100.0;
    double* pf4 = &f4;
    //int* i4 = static_cast<int*>(pf4); //不可以
    //float* fd4 = static_cast<float*>(pf4); //不可以
    cout << "-------------------------------------------------------" << endl;
    
    /*
        dynamic_cast：主要用于 运行时类型识别和检查。
            - 主要用来父类型和子类型之间转换用的（父类型指针指向子类型对象，然后用dynamic_cast把父类型指针转为子类型指针）
            - 后续课程讲解，此处不讲。
    */
    cout << "dynamic_cast（后续课程讲解）" << endl;
    cout << "-------------------------------------------------------" << endl;
    
    /*
        const_cast：去除指针或引用的 const属性（只有这一种用法）。编译时就会进行类型转换。
    */
    cout << "const_cast" << endl;
    const int i5 = 90;
    //int ai5 = const_cast<int>(i5);  //i5不是指针也不是引用，不能转换。
    const int* pi5 = &i5;
    int* pi5_2 = const_cast<int*>(pi5);
    //*pi5_2 = 120;  //这种写值行为 属于一种未定义行为（ide调试和打印结果不同！！！）。不要这么干。
    //cout << i5 << endl;
    //cout << *pi5_2 << endl;
    //--------
    // c风格的写法
    //int* pi5_3 = (int*)&i5;
    //*pi5_3 = 123; // 这也是 未定义行为。不要这么干。
    //cout << i5 << endl;
    //cout << *pi5_3 << endl;
    cout << "-------------------------------------------------------" << endl;
    
    /*
        reinterpret_cast：
            - 重新解释，将操作数内容解释为另一种不同类型（能把操作数的类型都转换掉）。
            - 处理无关类型的转换。也就是两个类型之间没有什么关系。相当于可以乱转换，自由转换。
            - 编译时就会进行类型转换检查。
            - reinterpret_cast 被业界认为是危险的类型转换！！！

        常用语以下转换：
            1. 将一个整型（地址）转换为指针，将一种类型指针转换成另一种类型指针。
                - 按照转换后的内容，重新解释内存中的内容。
            2. 从一个指针类型转换成一个整型。
    */
    cout << "reinterpret_cast" << endl;
    int i6 = 10;
    int* pi6 = &i6;
    //int* pi6_2 = reinterpret_cast<int*>(&i6);
    //char* pc6 = reinterpret_cast<char*>(pi6); // 乱转
    //-----

    int i7 = 20;
    int* pi7 = &i7;
    void* pvoid = reinterpret_cast<char*>(pi7); // 转成万能指针
    // ... 一系列操作后
    int* pi7_2 = reinterpret_cast<int*>(pvoid); // 再从万能指针 转成 int*
    //-----

    int i8 = 100;
    long long i9 = 8898899400; //8字节，十六进制：2 126A 6DC8
    int* pi8 = (int*)i8; //c语言风格。把 整型 转为 整型指针。 pi8 的值 0x0000000000000064
    pi8 = reinterpret_cast<int*>(i9);  //把 长整型 转为 整型指针。 pi8 的值 0x00000002126a6dc8 (与视频中不同，应该是因为视频中老师的电脑是32位的系统，所以他的电脑指针的大小是32位的。我的电脑是64位系统。)
    long long ne = reinterpret_cast<long long>(pi8); //把 整型指针 转为 长整型。ne = 8898899400，十六进制：2 126A 6DC8
    cout << "-------------------------------------------------------" << endl;

    /*
        总结：
            1. 这些强制类型转换，都不建议使用。强制类型转换能够抑制编译器报错。
            2. 学习目的：认识这些类型转换符，方便阅读别人写的代码。
            3. 很多资料说：reinterpret_cast危险。需要使用reinterpret_cast，意味着代码设计缺陷。
            4. 如果实在需要使用类型转换，不要再使用c语言风格的类型转换了，用c++风格的类型转换。
            5. 一般 static_cast 和 reinterpret_cast 就能很好的取代c语言风格的类型转换。

        reinterpret_cast 只要好好用，合乎规则的用，不要卵用，其实 reinterpret_cast 很好用。
    */
    return 0;
}