//#include <cstdio>  // c中用 <stdio.h>
#include <iostream> //这是个头文件，并且没有扩展名
using namespace std;


//解释 cout 是一个对象 end
struct student
{
    char name[100];
    int number;
};
namespace std 
{
    int itest;
    struct student cout1;  // 这就是定义一个结构变量（对象）
}
//解释 cout 是一个对象 end

int main002()
{
    //C++从基础到进阶-视频-02

    std::cout << "002_基本输入输出cin、cout精解\n";

    /*
        c++中，我们不用printf，而是用c++提供的标准库。
        不要排斥c++标准库，与c++语言 一起学习。
        iostream库（输入输出流），什么叫流：流就是一个字符序列。

        std : 命名空间，标准库命名空间。

        cout : console out的缩写，是个对象。“标准输出”对象，我们就认为这个对象是屏幕。
            c语言中 叫结构，c++中叫类
            C语言中我们定义一个结构变量，在c++中我们不叫结构变量，叫对象

        << ：在这里是 “输出”运算符。 表示将 << 右边的值写到 cout 中去。
            << 可以当成函数，有参数。第一个参数在 << 左边，就是 cout 对象。第二个参数在 << 右边，此处是一个字符串。

        '\n' ：换行符，跟c语言中一个意思。
    */


    int x = 3;
    std::cout << x << "的平方是" << x * x << std::endl;
    x++;
    std::cout << x << "的平方是" << x * x << std::endl;

    /*
        std::endl : 是个模板函数名，相当于函数指针，先暂时理解为函数，以后会详细讲解模板函数。
            作用：
                1. 输出换行符 '\n'。
                2. 强制 刷新 输出缓冲区，缓冲区中所有数据 都被系统清除。
                    - 输出缓冲区：是一段内存。cout输出的时候，实际是往输出缓冲区输出内容。
                    - 那么输出缓冲区什么时候把内容输出到屏幕去的呢？
                        a：缓冲区满了；
                        b：程序执行到 main 的 return 语句；
                        c：调用了 std::endl ，能够 强制刷新 输出缓冲区（把缓冲区的内容往屏幕上写）；
                        d：当系统不太繁忙的时候，系统也会查看缓冲区内容，发现新内容也会正常输出到屏幕；
                                
    */

    //ostream &std::cout.operator<<();  // << 的定义，<< 返回的是一个写入了给定值的 cout 对象。
    //std::cout << "002_基本输入输出cin、cout精解\n";  //返回的是 cout 对象

    cout << "-------------------------------------------------------" << endl;

    // F9：加断点，F5：调试并走到断点，F10：程序向下走（逐过程）
    // vs2022中输出23，所以是从右往左算的（在其他的编译器中，可能有不同的表现）
    // 开发中，要避免在一个表达式中多起的（超过1次）改变一个变量的值。
    std::cout << "应该避免这么写（语义不好理解）" << endl;
    int i = 3;
    std::cout << i-- << i-- << endl;
    // ---
    std::cout << "应该这么写" << endl;
    int j = 3;
    j--;
    std::cout << j;
    j--;
    std::cout << j << endl;

    cout << "-------------------------------------------------------" << endl;

    /*
        std::cin 基本输入
        cin：这也是个对象，叫标准输入（大家就理解为键盘）。 c中用scanf
        
        >> ： 是一个“输入”运算符，
            1. 返回其左侧运算对象，作为其计算结果
                std::cin >> value1 >> value2; 相当于 (std::cin >> value1) >> value2;
    */
    std::cout << "请输入两个数" << std::endl;
    int value1 = 0, value2 = 0;
    std::cin >> value1 >> value2;  // 输入多个值
    std::cout << value1 << " 和 " << value2 << " 相加的结果为：" << value1 + value2 << endl;

    return 0;
}