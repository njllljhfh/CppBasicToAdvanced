#include <iostream>
#include "003_head1.h"
#include "003_head2.h"
using namespace std;


// 形参是 引用类型
void func(int& ta, int& tb)
{
    ta = 4; // 改变这个值，会影响到外界。
    tb = 5;
}

constexpr int func13(int abc)
{
    abc = 1;
    return 5;
}

int main003()
{
    //C++从基础到进阶-视频-03

    cout << "003_auto-头文件防卫-引用-常量" << endl;

    /*
        一、局部变量及初始化
            随时用到随时定义。
    */

    // i 的作用域仅仅限制在for语句内
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    cout << "int 定义新写法：" << endl;
    //int abc = 5; // 定义的时候初始化
    int abc{ 5 };  // 新的c++标准中（c++11开始），可以用{}初始化
    int x={ 6 };  // 等号在这里可有可无
    cout << abc << endl;
    cout << x << endl;
    cout << "-------------------------------------------------------" << endl;
    
    cout << "for 循环新写法：" << endl;
    for (int i{ 0 }; i < 10; i++)
        cout << i << endl;
    cout << "-------------------------------------------------------" << endl;

    cout << "数组定义：" << endl;
    int a[]{ 11,12,34 };  // 等号可有可无，{}里包含一组数据的情况
    cout << a[2] << endl;

    //int abc2 = 3.5f; // .5 被系统截断了（不会报错）
    //int abc3{ 3.5f }; // 编译失败： 从“float”转换到“int”需要收缩转换
    cout << "-------------------------------------------------------" << endl;


    /*
        二：auto，变量的自动类型推断
            auto 可以在声明变量的时候，根据变量初始值的类型自动为此变量选择匹配的类型
                - 声明时要赋予初始值（初始化）
                - auto自动类型推断发生在编译期间。所以使用auto不会造成程序执行效率变低。
    */
    cout << "auto，变量的自动类型推断：" << endl;
    auto bvalue = true;  // bool
    auto ch = 'a';  // char
    auto dv = 1.2f; // flot
    auto iv = 5;
    cout << "-------------------------------------------------------" << endl;


    /*
        三：头文件防卫声明（语法参看 003_head1.h、003_head2.h 文件）
    */
    cout << "头文件防卫声明：" << endl;
    cout << g_globalh1 << endl;
    cout << g_globalh2 << endl;
    cout << "-------------------------------------------------------" << endl;


    /*
        四：引用
            引用理解成：为变量起了另外一个名字，一般用 & 符号表示。这个别名和变量本身，就看成是同一个变量。
            定义引用，并不额外占用内存，引用和原变量占用同一块内存。
            定义引用的时候，必须初始化。
    */
    cout << "引用：" << endl;
    // 引用基本语法：
    // 数据类型& 别名 = 原名
    int value = 10;
    int& refval = value; // value 的别名是 refval。& 符在这里不是地址运算符，只是起标识作用。
    refval = 3;
    cout << value << endl;
    cout << refval << endl;

    // 错误用法举例：
    //int& refval2;  // 错误：定义引用的时候，必须初始化。
    //int& refval3 = 10; // 错误：引用 必须绑定到标量上去，绑定到对象上也可以。不能绑定到常量上去。
    //float& refval4 = value; // 错误：类型要和原变量相同。

    // 引用 与 指针的写法区别：
    //int a11 = 3;
    //int& b11 = a11; // 引用：注意 & 符号在 = 的左边。
    //int* p11 = &a11;  // 指针：注意 & 符号在 = 的右边。
    cout << "------" << endl;

    cout << "引用-函数：" << endl;
    int a12 = 13;
    int b12 = 14;
    cout << "函数调用前：" << endl;
    cout << a12 << endl;
    cout << b12 << endl;
    cout << "函数调用后：" << endl;
    func(a12, b12);
    cout << a12 << endl;
    cout << b12 << endl;
    
    cout << "-------------------------------------------------------" << endl;

    /*
        五：常量
            const : 关键字，表示不变的意思
    */
    cout << "常量 const ：" << endl;
    const int var = 7; //命名常量：表示这个变量的值不会去改变。
    //var = 15;  // 报错：表达式必须是可修改的左值

    cout << "--- 此段的代码仅供学习，开发不要这么用 start ---" << endl;
    int& var2 = (int&)var;
    var2 = 18;
    // 查看变量内存：双击鼠标左键选中变量，然后按 shift + F9 
    // 用断点调试的时候，var 和 var2 都是 18。
    // 输出到控制台的时候，var=7，var2=18。
    cout << var << endl;  // 输出：7
    cout << var2 << endl; // 输出：18
    //--- 此段的代码仅供学习，开发不要这么用 end ---
    cout << "------" << endl;


    /*
        constexpr : 关键字，c++11才引入的，它也是个常量的概念，在编译的时候求值，肯定能提升性能。
            constexpr 标识的函数的函数体，要写的比较简单，不要写复杂的逻辑（比如循环、分支、递归等）。
    */
    cout << "常量 constexpr ：" << endl;
    cout << "constexpr: 视频里测试了一堆逻辑（不知要讲啥。。。）" << endl;
    constexpr int var13 = 1;
    int b13 = 5;
    //constexpr int var132 = b13;  // 报错
    constexpr int var132 = func13(11);
    int var133 = func13(4);
    cout << "------" << endl;

    cout << "--- 此段的代码仅供学习，开发不要这么用 start ---" << endl;
    constexpr int var14 = 3;
    cout << var14 << endl;
    int& var142 = (int&)var14;
    var142 = 5;
    cout << var142 << endl;
    // 在ide里调试 var14=5，var142=5（它们的内存地址也相同），但是控制台没有输出 same。
    if (var14 == var142)
        cout << "same" << endl;
    //--- 此段的代码仅供学习，开发不要这么用 end ---

    cout << "-------------------------------------------------------" << endl;

    return 0;
}
