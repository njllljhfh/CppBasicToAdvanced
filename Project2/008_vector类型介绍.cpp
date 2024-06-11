#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student008
{
    int num;
};

int main008()
{
    //C++从基础到进阶-视频-00

    cout << "008_vector类型介绍" << endl;
    /*
        一、vector类型简介
            来自于标准库，集合或者动态数组。可以把若干对象放在里边。
            vector也被称为容器，能把其他对象装进去。
    */
    // <int>：类模板，vector本身就是个类模板，<int>实际上就是类模板实例化的过程。
    // vector：当成类 类型（残缺的类 类型）
    // vector<int>：在vector之后加一对<>，<>内部放上类型信息（完整的类 类型）
    vector<int> vjihe;  //表示vjihe 里面保存的是int型数据；
    vector<Student008> stulist;
    vector<vector<string>> strchuan; //可以，该集合中的每一个元素又是一个 vector<string> 对象： 集合套集合。
    vector<int*> vjihe2;
    // 不能往 vector 中装引用。
    //vector<int&> vjihe3; //引用是个别名，不是个对象。不是对象不能往vector里边放。
    cout << "-------------------------------------------------------" << endl;

    /*
        二、定义和初始化vector对象
    */
    cout << "二、定义和初始化vector对象" << endl;
    cout << "1. 定义空vector（比较常用）" << endl;
    vector<string> mystr;  //创建了一个string类型的空的vector对象，目前mystr里不包含任何元素。
    mystr.push_back("abcde");
    mystr.push_back("def");
    cout << "-------------" << endl;
    
    cout << "2. 元素拷贝的初始化方式" << endl;
    vector<string> mystr2(mystr); //把 mystr 的元素拷贝给了 mystr2
    vector<string> mystr3 = mystr; //把 mystr 的元素拷贝给了 mystr3
    cout << "-------------" << endl;

    cout << "3. c++11标准中，用 列表初始化 方法 给值，用{}括起来" << endl;
    vector<string> mystr4 = { "aaa","bbb","ccc" };
    cout << "-------------" << endl;

    cout << "4. 创建指定数量的元素。有元素数量概念的东西，一般会用圆括号。" << endl;
    vector<int> ijihe(15, -200); // 创建15个int类型的元素，每个元素的值是-200。
    vector<string>mystr5(5, "hello"); //创建5个string类型的元素，每个元素的值是"hello"。
    vector<int> ijihe2(20); //20个元素，每一个元素默认值是0。
    vector<string> mystr6(5);  //5个元素，每个元素默认值是空字符串。
    cout << "-------------" << endl;

    cout << "5. 多种初始化方式" << endl;
    /*
        一般规律，并不绝对:
            1. ()中一般表示 vector对象 中 元素数量
            2. {}中一般表示 vector对象 中 元素内容

        要想正常通过{}进行初始化，那么{}里边值的类型，必须要跟vector后面的<>中的类型相同。
    */
    vector<int> i1(10); //表示10个元素，每个元素默认是0
    vector<int> i2{ 10 }; //表示只有一个元素，元素值是10
    vector<string> mystr7{ "hello" };
    vector<string> mystr8{ 10 }; //表示10个元素，每个元素默认是0。（不推荐这么写）
    vector<string> mystr9{ 10, "hello" }; //表示10个元素，每个元素的值是"hello"
    vector<int> i3(10, 1); //10个元素，每个元素的值是1
    vector<int> i4{ 10, 1 };//2个元素，第一个是10，第二个是1（等同于用 列表初始化）
    cout << "-------------------------------------------------------" << endl;

    /*
        三、vector对象上的操作
            - 最常用的是不知道 vector 里有多少元素。需要动态增加/减少。所以，一般先创建空vector。
            - vector 很多操作跟 string 很类似。
    */
    cout << "1. 判断是否为空 empty()，返回布尔值" << endl;
    vector<int> ivec;
    if (ivec.empty())
    {
        cout << "ivec为空" << endl;
    }
    cout << "-------------" << endl;

    cout << "2. push_back，常用方法，向vector的末尾增加一个元素" << endl;
    ivec.push_back(1);
    ivec.push_back(2);
    for (int i = 3; i <= 100; i++)
    {
        ivec.push_back(i);
    }
    cout << "-------------" << endl;

    cout << "3. size，返回元素个数" << endl;
    cout << ivec.size() << endl;
    cout << "-------------" << endl;

    cout << "4. clear，移除所有元素，将容器清空" << endl;
    //ivec.clear();
    //cout << ivec.size() << endl;
    cout << "-------------" << endl;

    cout << "5. v[n]，返回第n个元素（不常用）" << endl;
    // 如果下标n越界，那么会产生不可预测的结果。编译器发现不了。
    cout << ivec[1] << endl;
    cout << "-------------" << endl;

    cout << "6. = 赋值" << endl;
    vector<int> ivec2;
    ivec2.push_back(111);
    ivec2 = ivec;  //ivec2得到了ivec中的100个元素，ivec2原来的元素被删除掉了。
    ivec2 = { 12,13,14,15 };  // 用{}中的值取代了ivec2原有的值。
    cout << ivec2.size() << endl;
    cout << "-------------" << endl;

    cout << "7. ==，!=   相等，不相等" << endl;
    //两个vector相等：元素数量相同，对应位置的元素值也要意义昂。否则就是不等。
    vector<int> ivec3;
    ivec3 = ivec;
    if (ivec3 == ivec)
    {
        cout << "ivec3 == ivec" << endl;
    }

    ivec3.push_back(12345);
    if (ivec3 != ivec)
    {
        cout << "ivec3 != ivec" << endl;
    }

    ivec3.clear();
    ivec.clear();
    if (ivec3 == ivec)
    {
        cout << "ivec3 == ivec" << endl;
    }
    cout << "-------------" << endl;

    cout << "8. 范围for的应用" << endl;
    vector<int> vecvalue{ 1,2,3,4,5 };
    for (auto& vecitem : vecvalue)
    {
        vecitem *= 2; //每个元素扩大一倍
    }
    for (auto& vecitem : vecvalue)
    {
        cout << vecitem << endl;
    }
    cout << "------" << endl;

    /*
        范围for进一步讲解
            - auto vecitem 每次循环都会执行
            - 第一次循环时会记录 vecvalue 的结束地址
            - 遍历完 vecvalue 的结束地址，循环就结束
            - 增加/删除数据，会导致 vecvalue 的结束位置变更

        结论：在for语句中（遍历一个容器等类似的操作中）千万不要改动 vector 容器的容量，增加/删除都不可以。
    */
    for (auto vecitem : vecvalue)
    {
        vecvalue.push_back(888); //导致数据错乱，千万不要这么干。
        cout << vecitem << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    return 0;
}