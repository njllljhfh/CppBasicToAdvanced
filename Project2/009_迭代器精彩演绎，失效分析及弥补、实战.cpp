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


//ͨ�� itemname ��ȡ itemcontent
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
    //C++�ӻ���������-��Ƶ-09
    cout << "009_�������������ʧЧ�������ֲ���ʵս" << endl;
    /*
        һ�����������
            - ��������һ�ֱ���������Ԫ�ص� �������ͣ������������͸о��е���ָ�룬�������Ϊ����������ָ�������е�ĳ��Ԫ�ء�
            - ���� string��vector �������±����Ԫ�ء���c++�У������õķ��ʷ�ʽ���õ��������ʣ���ͨ�ã���
            - ͨ�������������Զ�ȡ�����е�Ԫ��ֵ��Ҳ�����޸�ĳ����������ָ���Ԫ��ֵ��
            - ���������Խ��� ++��-- ������
            - c++��׼��Ϊÿһ�������������������Ӧ�ĵ��������͡�
            - ��list,map��(������Ŀǰû��)��
            - Ҫѧ���õ����������������е�Ԫ�ء�
    */
    cout << "-------------------------------------------------------" << endl;

    /*
        ���������ĵ���������
    */
    vector<int> iv = { 100,200,300 };
    // ÿһ�����������ڲ���������� iterator ��Ա
    vector<int>::iterator iter;  //�� iv �����������Ҳ������ vector<int>
    cout << "-------------------------------------------------------" << endl;

    /*
        �������������� begin()/end() ��������������� rbegin()/rend()
    */
    // begin()/end() ���� ���� ���������͡�
    cout << "1. begin() ����һ������������" << endl;
    // �����������Ԫ�أ���begin���صĵ�����ָ����������еĵ�һ��Ԫ�ء�
    // �������Ϊ�գ���begin���� һ��������ı�־��
    // iter �൱�� ָ���� iv[0]
    iter = iv.begin();
    cout << "-------" << endl;

    cout << "2. end() ���صĵ��������������һ��Ԫ�ء��������һ��Ԫ�غ���Ľ�����ǣ�����β���ڱ�����" << endl;
    iter = iv.end();
    cout << "-------" << endl;

    cout << "3. ���һ������Ϊ�գ���ô begin() �� end() ���صĵ�������ͬ" << endl;
    vector<int> iv2;
    vector<int>::iterator iterbegin = iv2.begin();
    vector<int>::iterator iterend = iv2.end();
    if (iterbegin == iterend)
    {
        cout << "����iv2Ϊ��" << endl; //��������
    }
    cout << "-------" << endl;

    cout << "4. ��ͳ for �õ��������� ����" << endl;
    vector<int> iv3{ 100,200,300 };
    for (vector<int>::iterator iter = iv3.begin(); iter != iv3.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << "-------" << endl;

    cout << "5. ����������������������" << endl;
    // ������������������������rbegin()/rend()
    // rbegin()������һ�������������ָ�������е����һ��Ԫ�ء�
    // rend()������һ�������������ָ�������е�һ��Ԫ��ǰ���λ�ã�����ͷ���ڱ�����
    for (vector<int>::reverse_iterator riter = iv3.rbegin(); riter != iv3.rend(); riter++)
    {
        cout << *riter << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        �ġ������������
    */
    cout << "*iter�����ص����� iter ��ָ���Ԫ�ص����á����뱣֤ iter ָ����� ��Ч������Ԫ�أ�����ָ��end()/rend()��" << endl;
    // *iter�����ص����� iter ��ָ���Ԫ�ص����á����뱣֤ iter ָ����� ��Ч������Ԫ�أ�����ָ��end()/rend()��
    //vector<int>::iterator iterx = iv3.end();  // �������
    //vector<int>::reverse_iterator iterx2 = iv3.rend();  // �������
    vector<int>::iterator iterx = iv3.begin();  // ����
    cout << *iterx << endl;
    vector<int>::reverse_iterator iterx2 = iv3.rbegin(); // ����
    cout << *iterx2 << endl;
    cout << "-------" << endl;

    cout << "++iter��iter++���õ�����ָ����������һ��Ԫ��" << endl;
    // ++iter��iter++���õ�����ָ����������һ��Ԫ�ء��� iter�Ѿ�ָ��end()��ʱ�򣬾Ͳ����� ++ �ˡ�
    //vector<int>::iterator iter4 = iv3.end();
    //iter4++; // �������
    vector<int>::iterator iter4 = iv3.begin();
    iter4++;
    cout << *iter4 << endl;  // 200
    ++iter4;
    cout << *iter4 << endl;  // 200
    cout << "-------" << endl;

    cout << "--iter��iter--���õ�����ָ����������һ��Ԫ��" << endl;
    // �� iter �Ѿ�ָ�� begin() ��ʱ�򣬾Ͳ����� -- �ˡ�
    vector<int> iv4{ 100,200,300 };
    //vector<int>::iterator iter5 = iv4.begin();
    //iter5--; // �������
    vector<int>::iterator iter5 = iv4.end();
    iter5--;
    cout << *iter5 << endl; // 300

    //vector<int>::reverse_iterator iter6;
    //iter6 = iv4.rbegin();
    //iter6--; // �������
    vector<int>::reverse_iterator iter6;
    iter6 = iv4.rend();
    iter6--;
    cout << *iter6 << endl; // 100
    cout << "-------" << endl;

    cout << "iter1 -- iter2��iter1 != iter2 �ж������������Ƿ����" << endl;
    // �������������ָ�����ͬһ��Ԫ�أ����Ǿ���ȣ�����Ͳ��ȣ��ο�����forѭ�����������ӣ���
    cout << "-------------------------------------------------------" << endl;

    cout << "�õ�������ȡ�����е� �ṹ������ ��Ա��" << endl;
    vector<Student009> sv;
    Student009 mystu;
    mystu.num = 100;
    sv.push_back(mystu); //�Ѷ���mystu������sv������
    vector<Student009>::iterator iter7;
    iter7 = sv.begin();
    cout << (*iter7).num << endl;  //����д����Ҫ������
    cout << iter7->num << endl;

    /*
        ���������кܶ������÷��������ã����˴���׸���������Լ���һ��ѧϰ������������÷���
            - ������֮ǰ Ҳ�������Ӽ� ��ʾ����������֮��ľ��롣
            - ������ + n����ʾ����n��Ԫ�ء�
    */
    cout << "-------------------------------------------------------" << endl;

    /*
        �塢const_iterator ��������������������
            - const_iterator����������ʾ������ָ������Ԫ�ص�ֵ�����Ըı䣬���ǵ�������������ָ������Ԫ�ء�
            - ֻ�ܴ������ж�ȡԪ�أ�����ͨ�������������д�����е�Ԫ�ء������� ����ָ�롣
    */
    cout << "const_iterator ��������������������" << endl;
    //const vector<int> iv5 = { 100,200,300 };  // ���������������ó���������������
    vector<int> iv5 = { 100,200,300 };
    vector<int>::const_iterator iter8;
    for (iter8 = iv5.begin(); iter8 != iv5.end(); ++iter8)
    {
        //*iter8 = 4; //���뱨��
        cout << *iter8 << endl; // ����������
    }
    cout << "-------" << endl;

    cout << "cbegin() �� cend()" << endl;
    // cbegin() �� cend() 
    // c++11����������º������� begin()/end() ���ƣ�cbegin()/cend()���صĶ��ǳ�����������
    for (auto iter = iv5.cbegin(); iter != iv5.cend(); iter++)
    {
        //*iter8 = 4; //���뱨�����ܸ�������ֵ����˵��cbegin���ص��ǳ�����������
        cout << *iter << endl; // ����������
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        ����������ʧЧ
            - ��ʹ���˵�������ѭ�����У�ǧ��Ҫ�ı� ���� ��������Ҳ�����ڱ��������Ĺ����� ��Ҫ ���ӻ�ɾ�������е����ݡ�
            - �����������ӻ��ߴ�������ɾ��Ԫ�أ���Щ�������ܻ�ʹָ������Ԫ�ص�ָ�롢���á�������ʧЧ��ʧЧ��ʾ�����ٴ����κ������е�Ԫ�ء�
    */
    cout << "������ʧЧ" << endl;
    vector<int> vecvalue{ 1,2,3,4,5 };
    // ��Χfor��������(�ڲ�Ҳ�ǵ�����ʵ�ֵ�)
    for (auto vecitem : vecvalue)
    {
        //vecvalue.push_back(888); // ���ݴ���
        cout << vecitem << endl;
    }
    cout << "-------" << endl;

    // ��������������
    for (auto beg = vecvalue.begin(); beg != vecvalue.end(); ++beg)
    {
        //vecvalue.push_back(888); // �������
        cout << *beg << endl;
    }
    cout << "-------" << endl;

    // ���һ��Ҫ��ѭ���м����ݣ���ô��������break���ٿ�����һ��ѭ����������
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
        ���ѳ�����ʾ1
    */
    cout << "���ѳ�����ʾ1" << endl;
    vector<int> vecvalue2{ 1,2,3,4,5 };
    auto beg2 = vecvalue2.begin();
    auto end2 = vecvalue2.end();
    while (beg2 != end2)  // ÿ��ѭ����end2û�б��
    {
        cout << *beg2 << endl;
        // ������ֵ����һ������Ϊ����λ�ã��ڶ�������Ϊ�����Ԫ�ء����ز���λ�õĵ�������
        // �������϶��ᵽʱ������ʧЧ����������ʧЧ��ȷ������
        vecvalue2.insert(beg2, 80);
        break; // ������ֵ�󣬲������Ҫbreak������ע�͵�������������
        ++beg2; //��Ҫ����
    }
    cout << "-------" << endl;
    beg2 = vecvalue2.begin();
    end2 = vecvalue2.end();
    while (beg2 != end2)
    {
        cout << *beg2 << endl;
        ++beg2; //��Ҫ����
    }
    cout << "-------" << endl;

    cout << "�������ִ���ʵ������ѭ���в�������" << endl;
    vector<int> vecvalue3{ 1,2,3,4,5 };
    auto beg3 = vecvalue3.begin();
    int icount = 0;
    while (beg3 != vecvalue3.end()) //ÿ��ѭ�����������ж�ʱ������ִ�� vecvalue3.end() ����ȡ�µ�β����
    {
        // ����һ��Ҫ�� ������beg3 ���¸�ֵ��������������
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
        ++beg3; //��Ҫ����
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        ���ѳ�����ʾ2
    */
    cout << "���ѳ�����ʾ2" << endl;
    vector<int> iv6 = { 100,200,300 };
    //for (auto iter = iv6.begin(); iter != iv6.end(); ++iter)
    //{
    //    //erase�������Ƴ�iterλ���ϵ�Ԫ�أ�������һ��Ԫ��λ�á�
    //    iv6.erase(iter);  // �������
    //}
    cout << "-------" << endl;
    // ������߼���ɾ�������ڳ������һ��Ԫ�ص�����Ԫ��
    vector<int>::iterator iter9 = iv6.begin();
    icount = 0;
    int iv6Size = (int)iv6.size();
    cout << "iv6��Ԫ�ظ�����" << iv6.size() << endl;
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
        ++iter9; //��Ҫ����
    }
    cout << "iv6��Ԫ�ظ�����" << iv6.size() << endl;
    cout << "-------" << endl;

    cout << "��һ��ɾ����ʽ��" << endl;
    vector<int> iv7 = { 100,200,300 };
    while (!iv7.empty())
    {
        auto iter = iv7.begin();
        iv7.erase(iter);
    }
    if (iv7.empty())
    {
        cout << "iv7 Ϊ��" << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    /*
        �ߡ�������ʾ
    */
    cout << "�ߡ�������ʾ" << endl;
    cout << "7.1 �õ���������string��������" << endl;
    string str("I Love China!");
    for (auto iter = str.begin(); iter != str.end(); ++iter)
    {
        *iter = toupper(*iter);
    }
    cout << str << endl;
    cout << "-------" << endl;

    cout << "7.2 vector�������ò������ڴ��ͷ�" << endl;
    //ʵ������
    //ServerName = 1��  //����������
    //ServerID = 100000  //������ID
    conf* pconf1 = new conf;
    strcpy_s(pconf1->itemname, sizeof(pconf1->itemname), "ServerName");
    strcpy_s(pconf1->itemcontent, sizeof(pconf1->itemcontent), "1��");

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

    //new��������������󣬱���Ҫ�ͷ��ڴ棬�Լ�new�ľ�Ҫ�Լ��ͷţ����������ڴ�й©��
    vector<conf*>::iterator pos;
    for (pos = conflist.begin(); pos != conflist.end(); ++pos)
    {
        //����ֻ���ͷ���������ÿ��ָ��ָ����ڴ�ռ䣬��û��ɾ�������е�ָ��Ԫ�ء�
        delete (*pos);  //*pos ����ָ�루pos�ǵ�������
    }
    cout << "������Ԫ�ظ�����" << conflist.size() << endl;
    pos = conflist.begin();
    cout << "��ʱ�����еĵ�1�����ݣ�" << (*pos)->itemname << endl;  // ��ʱ�ڴ������������루�������ˣ�
    cout << "-------" << endl;
    conflist.clear();
    cout << "������Ԫ�ظ�����" << conflist.size() << endl;


    cout << "-------------------------------------------------------" << endl;

    return 0;
}