#include<iostream>
#include <string>
#include<vector>
using namespace std;


struct Student009
{
    int num;
};
//---------------------------------

struct conf
{
    char itemname[40];
    char itemcontent[100];
};


//通过 itemname 获取 itemcontent
char* getinfo(vector<conf*>& conflist, const char* pitem)
{
    for (auto pos = conflist.begin(); pos != conflist.end(); ++pos)
    {
        if (_stricmp((*pos)->itemname, pitem) == 0)
        {
            return (*pos)->itemcontent;
        }
    }
    return nullptr;
}

int main()
{
    //C++从基础到进阶-视频-09
    cout << "009_迭代器精彩演绎，失效分析及弥补、实战" << endl;
    /*
        一、迭代器简介
            - 迭代器是一种遍历容器内元素的 数据类型，这种数据类型感觉有点像指针，可以理解为迭代器用来指向容器中的某个元素。
            - 例如 string，vector 可以用下标访问元素。在c++中，更常用的访问方式是用迭代器访问（更通用）。
            - 通过迭代器，可以读取容器中的元素值，也可以修改某个迭代器所指向的元素值。
            - 迭代器可以进行 ++，-- 操作。
            - c++标准库为每一种容器，都定义了其对应的迭代器类型。
            - “list,map”(容器，目前没讲)。
            - 要学会用迭代器来访问容器中的元素。
    */
    cout << "-------------------------------------------------------" << endl;

    /*
        二、容器的迭代器类型
    */
    vector<int> iv = { 100,200,300 };
    // 每一种容器类型内部，都有这个 iterator 成员
    vector<int>::iterator iter;  //给 iv 定义迭代器，也必须是 vector<int>
    cout << "-------------------------------------------------------" << endl;

    /*
        三、迭代器操作 begin()/end() ，反向迭代器操作 rbegin()/rend()
    */
    // begin()/end() 用来 返回 迭代器类型。
    cout << "1. begin() 返回一个迭代器类型" << endl;
    // 如果容器中有元素，则begin返回的迭代器指向的是容器中的第一个元素。
    // 如果容器为空，则begin返回 一个很特殊的标志。
    // iter 相当于 指向了 iv[0]
    iter = iv.begin();
    cout << "-------" << endl;

    cout << "2. end() 返回的迭代器并不是最后一个元素。而是最后一个元素后面的结束标记（容器尾部哨兵）。" << endl;
    iter = iv.end();
    cout << "-------" << endl;

    cout << "3. 如果一个容器为空，那么 begin() 和 end() 返回的迭代器相同" << endl;
    vector<int> iv2;
    vector<int>::iterator iterbegin = iv2.begin();
    vector<int>::iterator iterend = iv2.end();
    if (iterbegin == iterend)
    {
        cout << "容器iv2为空" << endl; //条件成立
    }
    cout << "-------" << endl;

    cout << "4. 传统 for 用迭代器遍历 容器" << endl;
    vector<int> iv3{ 100,200,300 };
    for (vector<int>::iterator iter = iv3.begin(); iter != iv3.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << "-------" << endl;

    cout << "5. 反向迭代器（逆向迭代器）" << endl;
    // 反向迭代器（逆向迭代器）：rbegin()/rend()
    // rbegin()：返回一个反向迭代器，指向容器中的最后一个元素。
    // rend()：返回一个反向迭代器，指向容器中第一个元素前面的位置（容器头部哨兵）。
    for (vector<int>::reverse_iterator riter = iv3.rbegin(); riter != iv3.rend(); riter++)
    {
        cout << *riter << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        四、迭代器运算符
    */
    cout << "*iter：返回迭代器 iter 所指向的元素的引用。必须保证 iter 指向的是 有效的容器元素，不能指向end()/rend()。" << endl;
    // *iter：返回迭代器 iter 所指向的元素的引用。必须保证 iter 指向的是 有效的容器元素，不能指向end()/rend()。
    //vector<int>::iterator iterx = iv3.end();  // 程序崩溃
    //vector<int>::reverse_iterator iterx2 = iv3.rend();  // 程序崩溃
    vector<int>::iterator iterx = iv3.begin();  // 可以
    cout << *iterx << endl;
    vector<int>::reverse_iterator iterx2 = iv3.rbegin(); // 可以
    cout << *iterx2 << endl;
    cout << "-------" << endl;

    cout << "++iter，iter++：让迭代器指向容器中下一个元素" << endl;
    // ++iter，iter++：让迭代器指向容器中下一个元素。当 iter已经指向end()的时候，就不能再 ++ 了。
    //vector<int>::iterator iter4 = iv3.end();
    //iter4++; // 程序崩溃
    vector<int>::iterator iter4 = iv3.begin();
    iter4++;
    cout << *iter4 << endl;  // 200
    ++iter4;
    cout << *iter4 << endl;  // 200
    cout << "-------" << endl;

    cout << "--iter，iter--：让迭代器指向容器中上一个元素" << endl;
    // 当 iter 已经指向 begin() 的时候，就不能再 -- 了。
    vector<int> iv4{ 100,200,300 };
    //vector<int>::iterator iter5 = iv4.begin();
    //iter5--; // 程序崩溃
    vector<int>::iterator iter5 = iv4.end();
    iter5--;
    cout << *iter5 << endl; // 300

    //vector<int>::reverse_iterator iter6;
    //iter6 = iv4.rbegin();
    //iter6--; // 程序崩溃
    vector<int>::reverse_iterator iter6;
    iter6 = iv4.rend();
    iter6--;
    cout << *iter6 << endl; // 100
    cout << "-------" << endl;

    cout << "iter1 -- iter2，iter1 != iter2 判断两个迭代器是否相等" << endl;
    // 如果两个迭代器指向的是同一个元素，他们就相等，否则就不等（参看上面for循环遍历的例子）。
    cout << "-------------------------------------------------------" << endl;

    cout << "用迭代器获取容器中的 结构变量的 成员。" << endl;
    vector<Student009> sv;
    Student009 mystu;
    mystu.num = 100;
    sv.push_back(mystu); //把对象mystu拷贝到sv容器中
    vector<Student009>::iterator iter7;
    iter7 = sv.begin();
    cout << (*iter7).num << endl;  //这种写法，要加括号
    cout << iter7->num << endl;

    /*
        迭代器还有很多其他用法（不常用），此处不赘述，遇到自己进一步学习，例如下面的用法：
            - 迭代器之前 也可以做加减 表示两个迭代器之间的距离。
            - 迭代器 + n，表示跳过n个元素。
    */
    cout << "-------------------------------------------------------" << endl;

    /*
        五、const_iterator 迭代器（常量迭代器）
            - const_iterator迭代器，表示迭代器指向的这个元素的值不可以改变，但是迭代器可以重新指向其他元素。
            - 只能从容器中读取元素，不能通过这个迭代器改写容器中的元素。类似于 常量指针。
    */
    cout << "const_iterator 迭代器（常量迭代器）" << endl;
    //const vector<int> iv5 = { 100,200,300 };  // 常量容器，必须用常量迭代器来遍历
    vector<int> iv5 = { 100,200,300 };
    vector<int>::const_iterator iter8;
    for (iter8 = iv5.begin(); iter8 != iv5.end(); ++iter8)
    {
        //*iter8 = 4; //编译报错
        cout << *iter8 << endl; // 可以正常读
    }
    cout << "-------" << endl;

    cout << "cbegin() 和 cend()" << endl;
    // cbegin() 和 cend() 
    // c++11引入的两个新函数，跟 begin()/end() 类似，cbegin()/cend()返回的都是常量迭代器。
    for (auto iter = iv5.cbegin(); iter != iv5.cend(); iter++)
    {
        //*iter8 = 4; //编译报错，不能给常量赋值。这说明cbegin返回的是常量迭代器。
        cout << *iter << endl; // 可以正常读
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        六、迭代器失效
            - 在使用了迭代器的循环体中，千万不要改变 容器 的容量，也就是在遍历容器的过程中 不要 增加或删除容器中的数据。
            - 向容器中增加或者从容器中删除元素，这些操作可能会使指向容器元素的指针、引用、迭代器失效。失效表示不能再代表任何容器中的元素。
    */
    cout << "迭代器失效" << endl;
    vector<int> vecvalue{ 1,2,3,4,5 };
    // 范围for遍历容器(内部也是迭代器实现的)
    for (auto vecitem : vecvalue)
    {
        //vecvalue.push_back(888); // 数据错乱
        cout << vecitem << endl;
    }
    cout << "-------" << endl;

    // 迭代器遍历容器
    for (auto beg = vecvalue.begin(); beg != vecvalue.end(); ++beg)
    {
        //vecvalue.push_back(888); // 程序崩溃
        cout << *beg << endl;
    }
    cout << "-------" << endl;

    // 如果一定要在循环中加数据，那么加完马上break，再开启另一个循环遍历容器
    for (auto beg = vecvalue.begin(); beg != vecvalue.end(); ++beg)
    {
        vecvalue.push_back(888);
        break;
    }
    for (auto beg = vecvalue.begin(); beg != vecvalue.end(); ++beg)
    {
        cout << *beg << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        灾难程序演示1
    */
    cout << "灾难程序演示1" << endl;
    vector<int> vecvalue2{ 1,2,3,4,5 };
    auto beg2 = vecvalue2.begin();
    auto end2 = vecvalue2.end();
    while (beg2 != end2)  // 每次循环，end2没有变过
    {
        cout << *beg2 << endl;
        // 插入新值，第一个参数为插入位置，第二个参数为插入的元素。返回插入位置的迭代器。
        // 这里插入肯定会到时迭代器失效（具体哪里失效不确定）。
        vecvalue2.insert(beg2, 80);
        break; // 插入新值后，不想出错，要break（此行注释掉，程序会崩溃）
        ++beg2; //不要忘记
    }
    cout << "-------" << endl;
    beg2 = vecvalue2.begin();
    end2 = vecvalue2.end();
    while (beg2 != end2)
    {
        cout << *beg2 << endl;
        ++beg2; //不要忘记
    }
    cout << "-------" << endl;

    cout << "下面这种处理，实现了在循环中插入数据" << endl;
    vector<int> vecvalue3{ 1,2,3,4,5 };
    auto beg3 = vecvalue3.begin();
    int icount = 0;
    while (beg3 != vecvalue3.end()) //每次循环进行条件判断时，都会执行 vecvalue3.end() ，获取新的尾部。
    {
        // 这里一定要对 迭代器beg3 重新赋值。否则程序崩溃。
        beg3 = vecvalue3.insert(beg3, icount + 80);
        icount++;
        if (icount > 10)
        {
            break;
        }
        ++beg3;
    }
    beg3 = vecvalue3.begin();
    auto end3 = vecvalue3.end();
    while (beg3 != end3)
    {
        cout << *beg3 << endl;
        ++beg3; //不要忘记
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        灾难程序演示2
    */
    cout << "灾难程序演示2" << endl;
    vector<int> iv6 = { 100,200,300 };
    //for (auto iter = iv6.begin(); iter != iv6.end(); ++iter)
    //{
    //    //erase函数，移除iter位置上的元素，返回下一个元素位置。
    //    iv6.erase(iter);  // 程序崩溃
    //}
    cout << "-------" << endl;
    // 下面的逻辑，删除容器内除了最后一个元素的其他元素
    vector<int>::iterator iter9 = iv6.begin();
    icount = 0;
    int iv6Size = (int)iv6.size();
    cout << "iv6的元素个数：" << iv6.size() << endl;
    while (iter9 != iv6.end())
    {
        iter9 = iv6.erase(iter9);
        icount++;
        if (icount == iv6Size - 1)
        {
            break;
        }
    }

    iter9 = iv6.begin();
    auto end6 = iv6.end();
    while (iter9 != end6)
    {
        cout << *iter9 << endl;
        ++iter9; //不要忘记
    }
    cout << "iv6的元素个数：" << iv6.size() << endl;
    cout << "-------" << endl;

    cout << "另一种删除方式：" << endl;
    vector<int> iv7 = { 100,200,300 };
    while (!iv7.empty())
    {
        auto iter = iv7.begin();
        iv7.erase(iter);
    }
    if (iv7.empty())
    {
        cout << "iv7 为空" << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        七、范例演示
    */
    cout << "七、范例演示" << endl;
    cout << "7.1 用迭代器遍历string类型数据" << endl;
    string str("I Love China!");
    for (auto iter = str.begin(); iter != str.end(); ++iter)
    {
        *iter = toupper(*iter);
    }
    cout << str << endl;
    cout << "-------" << endl;

    cout << "7.2 vector容器常用操作与内存释放" << endl;
    //实践程序：
    //ServerName = 1区  //服务器名称
    //ServerID = 100000  //服务器ID
    conf* pconf1 = new conf;
    strcpy_s(pconf1->itemname, sizeof(pconf1->itemname), "ServerName");
    strcpy_s(pconf1->itemcontent, sizeof(pconf1->itemcontent), "1区");

    conf* pconf2 = new conf;
    strcpy_s(pconf2->itemname, sizeof(pconf2->itemname), "ServerID");
    strcpy_s(pconf2->itemcontent, sizeof(pconf2->itemcontent), "100000");

    vector<conf*> conflist;
    conflist.push_back(pconf1);
    conflist.push_back(pconf2);
    //strcpy_s(pconf1->itemname, sizeof(pconf1->itemname), "ServerName123");

    char* p_tmp = getinfo(conflist, "ServerName");
    if (p_tmp != nullptr)
    {
        cout << p_tmp << endl;
    }

    //new出来的数据用完后，必须要释放内存，自己new的就要自己释放，否则会造成内存泄漏。
    vector<conf*>::iterator pos;
    for (pos = conflist.begin(); pos != conflist.end(); ++pos)
    {
        //这里只是释放了容器中每个指针指向的内存空间，并没有删除容器中的指针元素。
        delete (*pos);  //*pos 才是指针（pos是迭代器）
    }
    cout << "容器中元素个数：" << conflist.size() << endl;
    pos = conflist.begin();
    cout << "此时容器中的第1个数据：" << (*pos)->itemname << endl;  // 此时内存中数据是乱码（不可用了）
    cout << "-------" << endl;
    conflist.clear();
    cout << "容器中元素个数：" << conflist.size() << endl;


    cout << "-------------------------------------------------------" << endl;

    return 0;
}