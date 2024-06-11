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
    //C++�ӻ���������-��Ƶ-00

    cout << "008_vector���ͽ���" << endl;
    /*
        һ��vector���ͼ��
            �����ڱ�׼�⣬���ϻ��߶�̬���顣���԰����ɶ��������ߡ�
            vectorҲ����Ϊ�������ܰ���������װ��ȥ��
    */
    // <int>����ģ�壬vector������Ǹ���ģ�壬<int>ʵ���Ͼ�����ģ��ʵ�����Ĺ��̡�
    // vector�������� ���ͣ���ȱ���� ���ͣ�
    // vector<int>����vector֮���һ��<>��<>�ڲ�����������Ϣ���������� ���ͣ�
    vector<int> vjihe;  //��ʾvjihe ���汣�����int�����ݣ�
    vector<Student008> stulist;
    vector<vector<string>> strchuan; //���ԣ��ü����е�ÿһ��Ԫ������һ�� vector<string> ���� �����׼��ϡ�
    vector<int*> vjihe2;
    // ������ vector ��װ���á�
    //vector<int&> vjihe3; //�����Ǹ����������Ǹ����󡣲��Ƕ�������vector��߷š�
    cout << "-------------------------------------------------------" << endl;

    /*
        ��������ͳ�ʼ��vector����
    */
    cout << "��������ͳ�ʼ��vector����" << endl;
    cout << "1. �����vector���Ƚϳ��ã�" << endl;
    vector<string> mystr;  //������һ��string���͵Ŀյ�vector����Ŀǰmystr�ﲻ�����κ�Ԫ�ء�
    mystr.push_back("abcde");
    mystr.push_back("def");
    cout << "-------------" << endl;
    
    cout << "2. Ԫ�ؿ����ĳ�ʼ����ʽ" << endl;
    vector<string> mystr2(mystr); //�� mystr ��Ԫ�ؿ������� mystr2
    vector<string> mystr3 = mystr; //�� mystr ��Ԫ�ؿ������� mystr3
    cout << "-------------" << endl;

    cout << "3. c++11��׼�У��� �б��ʼ�� ���� ��ֵ����{}������" << endl;
    vector<string> mystr4 = { "aaa","bbb","ccc" };
    cout << "-------------" << endl;

    cout << "4. ����ָ��������Ԫ�ء���Ԫ����������Ķ�����һ�����Բ���š�" << endl;
    vector<int> ijihe(15, -200); // ����15��int���͵�Ԫ�أ�ÿ��Ԫ�ص�ֵ��-200��
    vector<string>mystr5(5, "hello"); //����5��string���͵�Ԫ�أ�ÿ��Ԫ�ص�ֵ��"hello"��
    vector<int> ijihe2(20); //20��Ԫ�أ�ÿһ��Ԫ��Ĭ��ֵ��0��
    vector<string> mystr6(5);  //5��Ԫ�أ�ÿ��Ԫ��Ĭ��ֵ�ǿ��ַ�����
    cout << "-------------" << endl;

    cout << "5. ���ֳ�ʼ����ʽ" << endl;
    /*
        һ����ɣ���������:
            1. ()��һ���ʾ vector���� �� Ԫ������
            2. {}��һ���ʾ vector���� �� Ԫ������

        Ҫ������ͨ��{}���г�ʼ������ô{}���ֵ�����ͣ�����Ҫ��vector�����<>�е�������ͬ��
    */
    vector<int> i1(10); //��ʾ10��Ԫ�أ�ÿ��Ԫ��Ĭ����0
    vector<int> i2{ 10 }; //��ʾֻ��һ��Ԫ�أ�Ԫ��ֵ��10
    vector<string> mystr7{ "hello" };
    vector<string> mystr8{ 10 }; //��ʾ10��Ԫ�أ�ÿ��Ԫ��Ĭ����0�������Ƽ���ôд��
    vector<string> mystr9{ 10, "hello" }; //��ʾ10��Ԫ�أ�ÿ��Ԫ�ص�ֵ��"hello"
    vector<int> i3(10, 1); //10��Ԫ�أ�ÿ��Ԫ�ص�ֵ��1
    vector<int> i4{ 10, 1 };//2��Ԫ�أ���һ����10���ڶ�����1����ͬ���� �б��ʼ����
    cout << "-------------------------------------------------------" << endl;

    /*
        ����vector�����ϵĲ���
            - ��õ��ǲ�֪�� vector ���ж���Ԫ�ء���Ҫ��̬����/���١����ԣ�һ���ȴ�����vector��
            - vector �ܶ������ string �����ơ�
    */
    cout << "1. �ж��Ƿ�Ϊ�� empty()�����ز���ֵ" << endl;
    vector<int> ivec;
    if (ivec.empty())
    {
        cout << "ivecΪ��" << endl;
    }
    cout << "-------------" << endl;

    cout << "2. push_back�����÷�������vector��ĩβ����һ��Ԫ��" << endl;
    ivec.push_back(1);
    ivec.push_back(2);
    for (int i = 3; i <= 100; i++)
    {
        ivec.push_back(i);
    }
    cout << "-------------" << endl;

    cout << "3. size������Ԫ�ظ���" << endl;
    cout << ivec.size() << endl;
    cout << "-------------" << endl;

    cout << "4. clear���Ƴ�����Ԫ�أ����������" << endl;
    //ivec.clear();
    //cout << ivec.size() << endl;
    cout << "-------------" << endl;

    cout << "5. v[n]�����ص�n��Ԫ�أ������ã�" << endl;
    // ����±�nԽ�磬��ô���������Ԥ��Ľ�������������ֲ��ˡ�
    cout << ivec[1] << endl;
    cout << "-------------" << endl;

    cout << "6. = ��ֵ" << endl;
    vector<int> ivec2;
    ivec2.push_back(111);
    ivec2 = ivec;  //ivec2�õ���ivec�е�100��Ԫ�أ�ivec2ԭ����Ԫ�ر�ɾ�����ˡ�
    ivec2 = { 12,13,14,15 };  // ��{}�е�ֵȡ����ivec2ԭ�е�ֵ��
    cout << ivec2.size() << endl;
    cout << "-------------" << endl;

    cout << "7. ==��!=   ��ȣ������" << endl;
    //����vector��ȣ�Ԫ��������ͬ����Ӧλ�õ�Ԫ��ֵҲҪ���尺��������ǲ��ȡ�
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

    cout << "8. ��Χfor��Ӧ��" << endl;
    vector<int> vecvalue{ 1,2,3,4,5 };
    for (auto& vecitem : vecvalue)
    {
        vecitem *= 2; //ÿ��Ԫ������һ��
    }
    for (auto& vecitem : vecvalue)
    {
        cout << vecitem << endl;
    }
    cout << "------" << endl;

    /*
        ��Χfor��һ������
            - auto vecitem ÿ��ѭ������ִ��
            - ��һ��ѭ��ʱ���¼ vecvalue �Ľ�����ַ
            - ������ vecvalue �Ľ�����ַ��ѭ���ͽ���
            - ����/ɾ�����ݣ��ᵼ�� vecvalue �Ľ���λ�ñ��

        ���ۣ���for����У�����һ�����������ƵĲ����У�ǧ��Ҫ�Ķ� vector ����������������/ɾ���������ԡ�
    */
    for (auto vecitem : vecvalue)
    {
        vecvalue.push_back(888); //�������ݴ��ң�ǧ��Ҫ��ô�ɡ�
        cout << vecitem << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    return 0;
}