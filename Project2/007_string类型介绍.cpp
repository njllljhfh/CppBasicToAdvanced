#include <iostream>
#include <string>
using namespace std;

int main007()
{
    //C++从基础到进阶-视频-07

    cout << "007_string类型介绍" << endl;
    cout << "-------------------------------------------------------" << endl;
    /*
        一、前言
            c++内置类型：int，float，char 等。
            c++标准库：string，vector(一种集合或者容器的概念) 等。
    */

    /*
        二、string类型简介：c++标准库中的类型，代表一个可变长字符串。
            - string类型 和 字符数组 可以相互转换（后续会学到）。
            - string 是个类，位于 std 命名空间中。
    */
    char str[100] = "I Love China"; //c语言中的用法

    /*
        三、定义 和 初始化 string 对象
    */
    string s1; // 默认初始化，s1=""，空字符串。
    string s2 = "I Lovee China!";  // 把字符串内容拷贝到了 s2代表的一段内存中。拷贝时不包括末尾的'\0'。
    string s3("I Love China");  //跟s2的写法效果一样。
    string s4 = s2; //定义时初始化，把s2中的内容拷贝到了 s4所代表的一段内存中。

    int num = 6;
    string s5(num, 'a');//s5="aaaaaa"，把s5初始化为连续num个字符'a'组成的字符串。这种方式不太推荐，因为会在系统内部创建临时对象。

    /*
        四、string对象上的操作
    */
    cout << "四、string对象上的操作" << endl;
    cout << "1.判断是否为空 empty()，返回布尔值。" << endl;
    string s6;
    if (s6.empty())
    {
        cout << "s6为空" << endl;
    }
    cout << "-------------" << endl;

    cout << "2. size()/length()，返回字节/字符数量 代表该字符串的长度（unsigned int）。" << endl;
    string s7;
    cout << s7.size() << endl; //0
    cout << s7.length() << endl; //0
    cout << "------" << endl;
    string s8 = "我爱中国";
    cout << s8.size() << endl; //8
    cout << s8.length() << endl; //8
    cout << "------" << endl;
    string s9 = "I Love China!";
    cout << s9.size() << endl; //13
    cout << s9.length() << endl; //13
    cout << "-------------" << endl;

    cout << "3. s[n]，返回s中的第n个字符（0 <= n <= size() - 1）。" << endl;
    //如果下标n超过这个范围，或者s是空字符串。s[n]访问数据时，会产生不可预测的结果。
    string s10 = "I Love China!";
    if (s10.size() > 4)
    {
        cout << s10[4] << endl;  //v
        s10[4] = 'w';
    }
    cout << s10 << endl;  //I Lowe China!
    cout << "-------------" << endl;

    cout << "4. s1 + s2，字符串的链接，返回连接后的结果。" << endl;
    string s11 = "abcd";
    string s12 = "hijk";
    string s13 = s11 + s12; //abcdhijk
    cout << s13 << endl;
    cout << "-------------" << endl;

    cout << "5. s1 = s2，字符串对象赋值，用s2里边的内容取代原来的s1里的内容。" << endl;
    string s14 = "abcd";
    string s15 = "de";
    s14 = s15;
    cout << s15 << endl;  //de
    cout << "-------------" << endl;

    cout << "6. s1 == s2，判断两个字符串是否相等（大小写敏感）。" << endl;
    // 相等：长度相同，并且字符全相同。
    string s16 = "abc";
    string s17 = "abc";
    if (s16 == s17)
    {
        cout << "s16 == s17" << endl;
    }
    cout << "-------------" << endl;

    cout << "7. s1 != s2，判断两个字符串是否不相等（大小写敏感）。" << endl;
    // 相等：长度相同，并且字符全相同。
    string s18 = "abc";
    string s19 = "abC";
    if (s18 != s19)
    {
        cout << "s18 != s19" << endl;
    }
    cout << "-------------" << endl;

    cout << "8. s.c_str()，返回一个字符串s中的内容指针。" << endl;
    // 返回一个指向正规的c语言字符串的 常量指针，也就是以'\0'结尾的。
    // 这个函数的引入是为了与c语言兼容，c语言中没有string类型，所以通过string类对象的c_str()成员函数，把string对象转换成c语言中的字符串样式。
    string s20 = "abC";
    const char* p20 = s20.c_str(); //abC
    char str20[100];
    strcpy_s(str20, sizeof(str20), p20);
    cout << str20 << endl; //abC

    string s21(s20);  //用c语言的字符数组，初始化string类型。
    cout << "-------------" << endl; 

    cout << "9. 读写string对象。" << endl;
    //string s22;
    //cin >> s22; //从键盘输入
    //cout << s22 << endl;
    cout << "-------------" << endl;

    cout << "10. 字面值 和 string 相加。" << endl;
    string s23 = "abc";
    string s24 = "defg";
    string s25 = s23 + " and " + s24 + 'e';  //发生了隐式类型转换，并且中间过程会生成临时变量，后续课程会有讲解
    cout << s25 << endl;

    //string s26 = "abc" + "def"; //语法错误（两个字符串字面量不能挨着相加），编译器不知道该如何转换类型
    cout << "-------------" << endl;

    cout << "11. 范围 for 针对 string 的使用。" << endl;
    //c++中提供了范围for：能够遍历一个序列中的每一个元素
    //string可以看成是一个 字符序列
    string s26 = "I Love China!";
    for (auto c : s26)  // auto：变量类型自动推断
    {
        cout << c << endl;
    }
    cout << "-----" << endl;

    string s27 = "I Love China!";
    for (auto& c : s27)  // c是引用
    {
        //toupper()把小写字符转成大写，大写字符没变化。
        c = toupper(c); //因为c是一个引用，所以这里改变了s27中的值
    }
    cout << s27 << endl;
    cout << "-------------" << endl;
    return 0;
}