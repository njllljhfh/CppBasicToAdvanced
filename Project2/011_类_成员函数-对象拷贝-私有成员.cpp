#include <iostream>
#include <string>
#include "011_Time.h"
using namespace std;


class Student011
{
public:
    int number;
    char name[100];
};

// c���Գ�ʼ���ķ�ʽ
void initTime(Time011& stmptime, int tmphour, int tmpminute, int tmpsec)
{
    stmptime.Hour = tmphour;
    stmptime.Minute = tmpminute;
    stmptime.Secend = tmpsec;
}

int main011()
{
    //C++�ӻ���������-��Ƶ-11
    cout << "011_��_��Ա����-���󿽱�-˽�г�Ա" << endl;
    /*
        һ��������
            - ��ʹ�����Զ������������
            - �����ʱҪ���ǵĽǶȣ�
                1. վ����ƺ�ʵ���ߵĽǶ������ǡ�
                2. վ��ʹ���ߵĽǶ������ǡ�
                3. ���ࡢ����ĽǶȡ�

    */

    /*
        ���������
            1. һ������ǿ������Զ�����������ͣ����԰��������һ�������ռ䣬����һ�Ѷ�������Ա��������Ա������
            2. һ����Ĺ��ɣ� ��Ա��������Ա�������кܶ������Ա�����������������⣩��
            3. ͨ���������ʳ�Ա���﷨��
                - �����.��Ա��
            4. ͨ��������ָ����ʳ�Ա���﷨��
                - ָ����->��Ա��
            5. public ��Ա�ṩ�ӿڣ���¶����磬�������á�private ��Ա�ṩ����ʵ���๦�ܵ�ϸ�ڷ���������¶����磬����޷�ʹ�á�
            6. class��Ա��Ĭ��Ȩ�� private��struct��Ա��Ĭ��Ȩ���� public��
                - struct A{...} �ȼ��� class A{public:...}
    */
    cout << "���������" << endl;
    Student011 someone;  //������Ķ���
    someone.number = 1000; //ͨ���������ʳ�Ա
    Student011* psomeone = &someone;
    psomeone->number = 1005; //ͨ��������ָ����ʳ�Ա
    cout << someone.number << endl;
    cout << "-------------------------------------------------------" << endl;

    /*
        ������Ա����
    */
    cout << "������Ա����" << endl;
    Time011 myTime; // �����
    initTime(myTime, 11, 14, 5); // c���Է��ĳ�ʼ���ķ�ʽ
    cout << myTime.Hour << endl;
    cout << myTime.Minute << endl;
    cout << myTime.Secend << endl;
    cout << "----------" << endl;

    Time011 myTime2;
    myTime2.initTime(11, 14, 5);
    cout << myTime2.Hour << endl;
    cout << myTime2.Minute << endl;
    cout << myTime2.Secend << endl;

    cout << "-------------------------------------------------------" << endl;

    /*
        �ġ����󿽱�
            - �������ǿ��Կ�����
            - Ĭ������£����������Ŀ�������ÿ����Ա�������������
                - ��������ж����ʵ��� ��ֵ����������ܹ����ƶ�������ֿ�����Ϊ��
    */
    cout << "�ġ����󿽱�" << endl;
    Time011 myTime3;
    myTime3.Hour = 12;
    myTime3.Minute = 15;
    myTime3.Secend = 40;
    // ���µ�д�����Ƕ��󿽱�
    Time011 myTime4 = myTime3;
    Time011 myTime5(myTime3);
    Time011 myTime6{ myTime3 };
    Time011 myTime7 = { myTime3 };
    myTime7.Hour = 8;
    cout << "-------------------------------------------------------" << endl;
    /*
        �塢˽�г�Ա
    */
    cout << "�塢˽�г�Ա" << endl;
    Time011 myTime8;
    //myTime8.Millisecond = 1000;  //���ܷ���˽�г�Ա�������޷����� private ��Ա
    //myTime8.initMillTime(1);  //���ܷ���˽�г�Ա�������޷����� private ��Ա
    myTime8.initTime(1, 2, 3);
    cout << "-------------------------------------------------------" << endl;

    return 0;
}
