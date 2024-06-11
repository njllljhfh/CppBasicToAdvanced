#include <iostream>
using namespace std;


int main004() 
{
    //C++从基础到进阶-视频-04

    cout << "004_范围for-new内存动态分配-nullptr" << endl;
    /*
        一、范围for语句：用于遍历一个序列
    */
    cout << "范围for语句（把v中每个元素拷贝到x中）：" << endl;
    int v[]{ 12,13,14,18 };
    for (auto x : v)  // 数组v中每个元素，依次放入x中并打印x值。把v中每个元素拷贝到x中，打印x值。
    {
        cout << x << endl;
    }

    cout << "---------" << endl;

    cout << "范围for语句（不拷贝）：" << endl;
    for (auto& x : v)  // 用引用，省了拷贝动作，提高执行效率
    {
        cout << x << endl;
    }

    cout << "---------" << endl;

    for (auto x : {11,34,56,21,34,38})
    {
        cout << x << endl;
    }

    cout << "-------------------------------------------------------" << endl;
    /*
        二、动态内存分配问题（很重要）
            c 中：
                供程序使用的存储空间：
                    - 程序区
                    - 静态存储区
                    - 东岱存储区

            c++ 中：
                供程序使用的存储空间，进一步详细分为5个区域：
                    1. 栈：一般函数内的局部变量都会放在这里，由编译器自动分配和释放。
                    2. 堆：程序员 malloc/new 分配，用 free/delete 来释放。如果没有释放，当程序结束时由系统回收。
                    3. 全局/静态存储区：放 全局变量 和 静态变量(static)，程序结束时，系统释放。
                    4. 常量存储区：存储常量。
                    5. 程序代码区。

                堆 和 栈 不同的用途和区别
                    1. 栈：空间是有限的。是由系统规定的。分配速度快，程序员也控制不了。
                    2. 堆：
                        - 只要不超出实际拥有的物理内存，也在操作系统允许的能够分配的最大内存大小之内，都可以分配给你。
                        - 分配速度比栈慢，可以随时使用 malloc/new 来分配，用 free/delete 来释放，非常灵活。
            
            malloc 和 free：在c语言中，用 malloc 和 free 从堆中分配和释放内存。malloc 和 free 是函数。
                malloc（memory allocation）：动态内存分配。
                    一般形式（声明形式）：
                        void* malloc(int NumBytes);  //NumBytes：要分配的字节数。void*：万能类型指针，可以指向认可类型。
                            分配成功则返回被分配内存的指针，分配失败则返回NULL。
                            当这段分配的内存不再使用，应该用free()函数将内存释放掉，供其他地方使用。
                free：
                    一般形式（声明形式）：
                        void free(void* FirstBytes);  // 将之前用 malloc 分配的内存空间释放掉，还给程序（操作系统）。
    */
    
    cout << "malloc/free（这是 C 语言的写法）：" << endl;
    int* p = NULL; // c语言写法，等价于 数字0。
    p = (int*)malloc(sizeof(int)); // 在堆中分配4个字节（malloc 返回的是 void*，所以此处要用 int* 进行强制转换）。
    if (p != NULL)
    {
        // 分配成功
        *p = 5;
        cout << *p << endl;
        free(p); // 释放掉，千万不要忘记。
    }
    cout << "-------" << endl;

    char* point = NULL;
    point = (char*)malloc(100 * sizeof(char)); // 100位置（100个字节），char*可以表示字符串
    if (point != NULL)
    {
        // strcpy（字符串拷贝）：c语言的语法，将目标字符串拷贝到 point 指向的内存中去，这里报错了，编译器提示用strcpy_s。
        // strcpy 当 长度溢出时，不会警告，会把超出的部分考到未知的内存中去，可能影响程序执行。
        //strcpy(point, "hello world!");
        //strcat() --- strcat_s()，应该还有这两个函数（题外话）

        // 第2个参数 是 要拷贝的字节数，如果目标字符串超出这个字节数，会弹窗提示（目标字符串小于这个数字是允许的）。
        // 字符串结尾有个'\0'的结束标记，占用1个字节。所以，"hello world!" 一共占用13个字节。
        strcpy_s(point, 100, "hello world!");
        cout << point << endl;
        free(point); // 释放掉，千万不要忘记。
    }
    cout << "-------" << endl;

    int* p2 = (int*)malloc(sizeof(int) * 100); //分配可以放下100个整形的内存空间
    if (p2 != NULL)
    {
        int* q = p2;
        //自增运算符"++" 和 指针运算符"*" 的优先级是相同的，而且都是 右结合性，
        //所以此处等价于：*(q++)，即先执行 *q = 1; 再执行 q++;
        *q++ = 1;  
        *q++ = 5;  
        cout << *p2 << endl; //输出：1
        cout << *(p2 +1) << endl; //输出：5
        free(p2);
    }
    cout << "-----------------------------" << endl;

    /*
        new 和 delete：是运算符（标识符）。c++ 中就用 new/delete 分配和释放内存，不再使用 malloc/free 来分配和释放内存。
           - new/delete 和 malloc/free 干了一样的事，就是分配和释放内存。同时 new/delete 还干了更多的事情（比如new会调用类的构造函数，malloc不会，此处先不展开讲，后续课程会有详细讲解）。 
           - new 一般用法：
               1. 指针变量名 = new 类型标识符;
               2. 指针类型名 = new 类型标识符(初始值);  //注意：这里是圆括号括起来，表示初始值
               3. 指针类型名 = new 类型标识符[内存单元个数];  //注意：这里是[]，表示分配一个数组
    */
    cout << "new/delete（这是 c++ 语言的写法）：" << endl;
    cout << "1. 指针变量名 = new 类型标识符;" << endl;
    int* myint = new int;  //对比，int *p = (int*)malloc(sizeof(int));
    if (myint != NULL)
    {
        *myint = 8;
        cout << *myint << endl;
        delete myint;  //释放 单个值的内存空间
    }
    cout << "-------" << endl;

    cout << "2. 指针类型名 = new 类型标识符(初始值);" << endl;
    int* myint2 = new int(18); // 初始值 是 18
    if (myint2 != NULL)
    {
        cout << *myint2 << endl;  // 输出：18
        delete myint2;  //释放 单个值的内存空间
    }
    cout << "-------" << endl;

    cout << "3. 指针类型名 = new 类型标识符[内存单元个数];" << endl;
    int* pa = new int[100]; //开辟一个大小为 100 的整型数组空间
    if (pa != NULL)
    {
        int* q3 = pa;  // q3 指向 pa 的首地址
        *q3++ = 12;  // 第0个元素 = 12。执行后，q3指向 第1个元素
        *q3++ = 18;  // 第1个元素 = 18。执行后，q3指向 第2个元素
        cout << *pa << endl;  // 输出：12
        cout << *(pa+1) << endl;  // 输出：18
        delete[] pa;  // 释放 数组内存空间（new的时候用了[]，那么delete的时就必须用[]，[]中什么都不写）
    }

    /*
        额外补充知识：
            1. 配对使用：有malloc成功必然有free，有new成功必然有delete。
            2. free/delete，不要重复调用（对同一个变量名）。如果第一次已经释放的内存被系统再次分配，可能会产生未知错误。
            3. malloc/free 和 new/delete 的区别，后续课程会讲解。
    */

    cout << "-------------------------------------------------------" << endl;

    /*
        三、nullptr : c++11 中引入的新关键字
            nullprt 代表的也是空指针。
    */
    cout << "nullptr:" << endl;
    char* p4 = NULL;  // NULL 实际就是 0
    char* q4 = nullptr;
    int* p5 = nullptr;
    //int a4 = nullptr;  // 报错
    //int a5 = NULL;  // 可以

    if (p4 == nullptr)  // 条件成立
    {
        cout << "NULL == nullptr" << endl;
    }

    if (q4 == NULL)  // 条件成立
    {
        cout << "q4 == NULL" << endl;
    }

    int xxx = 0;
    if (NULL == xxx)  // 条件成立
    {
        cout << "NULL == 0" << endl;
    }
    // 使用 nullptr 能够避免在 整数 和 指针 之间发生混淆。
    cout << "-------" << endl;

    // typeid(NULL).name()，打印类型名称。
    // NULL 和 nullptr 实际上是不同的类型。
    cout << typeid(NULL).name() << endl;  // int
    cout << typeid(nullptr).name() << endl;  // std::nullptr_t
    cout << "-------------------------------------------------------" << endl;

    // 结论：对于指针的初始化，和以往使用到的指针有关的 NULL 的场景，能用 nullptr 的都用 nullptr 取代 NULL。

    return 0;
}
