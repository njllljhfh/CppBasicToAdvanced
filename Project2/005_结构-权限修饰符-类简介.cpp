#include <iostream>
#include "005_student.h"
using namespace std;

struct student 
{
public: //�ṹ��ԱĬ�϶���public��Ȩ�ޣ����Կ��Բ���public�����ڿ��Է��ʣ�����Ҳ���Է��ʡ�
    // ��Ա����
    int number; //ѧ��
    char name[100]; //ѧ����
    void func() // ��Ա������Ҳ�з�����
    {
        numAddOne();
    }
private: //���ڿ��Է��ʣ����ⲻ���Է��ʣ����಻���Է���
    void numAddOne()
    {
        number++;
    }
};

// �β��ýṹ������ֵ���ݣ�
void func(student tmpstu)
{
    tmpstu.number = 2000;
    strcpy_s(tmpstu.name, sizeof(tmpstu.name), "who");
    return;
}

// �β������ã���ַ���ݣ�
void func2(student& tmpstu)
{
    tmpstu.number = 2000;
    strcpy_s(tmpstu.name, sizeof(tmpstu.name), "who2");
    return;
}

// ��ָ��ṹ���ָ����������������ַ���ݣ�
void func3(student* ptmpstu)
{
    ptmpstu->number = 3000;  // -> ָ�������
    strcpy_s(ptmpstu->name, sizeof(ptmpstu->name), "who3");
    return;
}

int main005()
{
    //C++�ӻ���������-��Ƶ-05

    cout << "005_�ṹ-Ȩ�����η�-����" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "һ���ṹ�ع�" << endl;
    /*
        һ���ṹ��ع�
            �ṹ�壺�Զ������������
            c++�еĽṹ�� �� c�еĽṹ�� ��ʲô�����أ�
                - c++�еĽṹ����߱���c�нṹ������й����⣬�������˺ܶ���չ���ܣ�
                    - c++�еĽṹ�岻�����г�Ա�����������������ж����Ա������
    */
    student student1; //����ṹ�������������ʡ�� struct �ؼ��֣�ֱ���ýṹ�� student��
    student1.number = 1001;
    strcpy_s(student1.name, sizeof(student1.name), "zhangsan");
    cout << student1.number << endl;
    cout << student1.name << endl;
    cout << "---------" << endl;

    cout << "�β��ýṹ������ֵ���ݣ���" << endl;
    func(student1); //Ч�ʵͣ���Ϊʵ�δ��ݸ��β�ʱ�����������ݿ���
    cout << student1.number << endl;  //ֵû�б������ı�
    cout << student1.name << endl;  //ֵû�б������ı�
    cout << "---------" << endl;

    cout << "�β������ã���ַ���ݣ���" << endl;
    func2(student1);
    cout << student1.number << endl;  //ֵ�������ı�
    cout << student1.name << endl;  //ֵ�������ı�
    cout << "---------" << endl;

    cout << "��ָ��ṹ���ָ����������������ַ���ݣ���" << endl;
    func3(&student1);
    cout << student1.number << endl;  //ֵ�������ı�
    cout << student1.name << endl;  //ֵ�������ı�
    cout << "---------" << endl;

    cout << "��Ա������" << endl;
    student1.func();
    cout << student1.number << endl;  //3001

    cout << "-------------------------------------------------------" << endl;

    cout << "����Ȩ�����η�" << endl;
    /*
        ����Ȩ�����η���public(����)��private(˽��)��protected(����)�����ڿ�̸ֻ public��private��
            public����������˼���������ε� ��Ա���� �� ��Ա���� ���Ա������ʡ�
            private��˽�е���˼���������ε� ��Ա���� �� ��Ա���� ֻ�ܱ��ڲ�����ĳ�Ա����ʹ�ã����಻�ɷ��ʡ�
    */
    cout << "-------------------------------------------------------" << endl;
    cout << "��������" << endl;
    /*
        �������飺��Ҳ���û��Զ��������
            �ṹ�� �� �� ��ʲô����
                1. c++�в�����ĸ��c��û����ĸ��
                    - �ṹ���� struct ���壬���� class ���塣
                    - ��c�У�����һ������Ϊĳ���ṹ��ı�������֮Ϊ �ṹ������
                    - ��c++�У�����һ������Ϊĳ����ı�������֮Ϊ ����
                    - �ṹ���� �� ��Ķ��� ���Ƕ���һ���ܹ��洢���ݣ����Ҿ���ĳ�����͵��ڴ�ռ䡣
                2. c++�У��ṹ�� �� �� �����ƣ����������㣺
                    2.1
                        - c++�ṹ���ڲ��� ��Ա���� �Լ� ��Ա���� Ĭ�ϵ�Ȩ���� public��
                        - c++���ڲ��� ��Ա���� �Լ� ��Ա���� Ĭ�ϵ�Ȩ���� private��
                    2.2
                        - c++�ṹ��̳�Ĭ����public������ļ̳�Ĭ���� private��

        ����˵����
            1. ��׼c++������������ḻ����ͺ��������� string����
            2. д���뾡����װ���ࡣ
    */
    cout << "-------------------------------------------------------" << endl;

    cout << "�ġ������֯����д�淶��" << endl;
    /*
        �ġ������֯����д�淶����
            ��Ķ���������һ�� .h ��ͷ�ļ��У�ͷ�ļ������Ը����ļ�����ͬ��
            ��ľ���ʵ�ִ��룬����һ�� .cpp �ļ��С�
    */
    Student2 stu;
    stu.number = 110;
    strcpy_s(stu.name, sizeof(stu.name), "lisi");
    cout << "number: " << stu.number << endl;
    cout << "name: " << stu.name << endl;
    stu.func();
    cout << "number: " << stu.number << endl;

    cout << "-------------------------------------------------------" << endl;

    return 0;
}