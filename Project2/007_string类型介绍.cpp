#include <iostream>
#include <string>
using namespace std;

int main007()
{
    //C++�ӻ���������-��Ƶ-07

    cout << "007_string���ͽ���" << endl;
    cout << "-------------------------------------------------------" << endl;
    /*
        һ��ǰ��
            c++�������ͣ�int��float��char �ȡ�
            c++��׼�⣺string��vector(һ�ּ��ϻ��������ĸ���) �ȡ�
    */

    /*
        ����string���ͼ�飺c++��׼���е����ͣ�����һ���ɱ䳤�ַ�����
            - string���� �� �ַ����� �����໥ת����������ѧ������
            - string �Ǹ��࣬λ�� std �����ռ��С�
    */
    char str[100] = "I Love China"; //c�����е��÷�

    /*
        �������� �� ��ʼ�� string ����
    */
    string s1; // Ĭ�ϳ�ʼ����s1=""�����ַ�����
    string s2 = "I Lovee China!";  // ���ַ������ݿ������� s2�����һ���ڴ��С�����ʱ������ĩβ��'\0'��
    string s3("I Love China");  //��s2��д��Ч��һ����
    string s4 = s2; //����ʱ��ʼ������s2�е����ݿ������� s4�������һ���ڴ��С�

    int num = 6;
    string s5(num, 'a');//s5="aaaaaa"����s5��ʼ��Ϊ����num���ַ�'a'��ɵ��ַ��������ַ�ʽ��̫�Ƽ�����Ϊ����ϵͳ�ڲ�������ʱ����

    /*
        �ġ�string�����ϵĲ���
    */
    cout << "�ġ�string�����ϵĲ���" << endl;
    cout << "1.�ж��Ƿ�Ϊ�� empty()�����ز���ֵ��" << endl;
    string s6;
    if (s6.empty())
    {
        cout << "s6Ϊ��" << endl;
    }
    cout << "-------------" << endl;

    cout << "2. size()/length()�������ֽ�/�ַ����� ������ַ����ĳ��ȣ�unsigned int����" << endl;
    string s7;
    cout << s7.size() << endl; //0
    cout << s7.length() << endl; //0
    cout << "------" << endl;
    string s8 = "�Ұ��й�";
    cout << s8.size() << endl; //8
    cout << s8.length() << endl; //8
    cout << "------" << endl;
    string s9 = "I Love China!";
    cout << s9.size() << endl; //13
    cout << s9.length() << endl; //13
    cout << "-------------" << endl;

    cout << "3. s[n]������s�еĵ�n���ַ���0 <= n <= size() - 1����" << endl;
    //����±�n���������Χ������s�ǿ��ַ�����s[n]��������ʱ�����������Ԥ��Ľ����
    string s10 = "I Love China!";
    if (s10.size() > 4)
    {
        cout << s10[4] << endl;  //v
        s10[4] = 'w';
    }
    cout << s10 << endl;  //I Lowe China!
    cout << "-------------" << endl;

    cout << "4. s1 + s2���ַ��������ӣ��������Ӻ�Ľ����" << endl;
    string s11 = "abcd";
    string s12 = "hijk";
    string s13 = s11 + s12; //abcdhijk
    cout << s13 << endl;
    cout << "-------------" << endl;

    cout << "5. s1 = s2���ַ�������ֵ����s2��ߵ�����ȡ��ԭ����s1������ݡ�" << endl;
    string s14 = "abcd";
    string s15 = "de";
    s14 = s15;
    cout << s15 << endl;  //de
    cout << "-------------" << endl;

    cout << "6. s1 == s2���ж������ַ����Ƿ���ȣ���Сд���У���" << endl;
    // ��ȣ�������ͬ�������ַ�ȫ��ͬ��
    string s16 = "abc";
    string s17 = "abc";
    if (s16 == s17)
    {
        cout << "s16 == s17" << endl;
    }
    cout << "-------------" << endl;

    cout << "7. s1 != s2���ж������ַ����Ƿ���ȣ���Сд���У���" << endl;
    // ��ȣ�������ͬ�������ַ�ȫ��ͬ��
    string s18 = "abc";
    string s19 = "abC";
    if (s18 != s19)
    {
        cout << "s18 != s19" << endl;
    }
    cout << "-------------" << endl;

    cout << "8. s.c_str()������һ���ַ���s�е�����ָ�롣" << endl;
    // ����һ��ָ�������c�����ַ����� ����ָ�룬Ҳ������'\0'��β�ġ�
    // ���������������Ϊ����c���Լ��ݣ�c������û��string���ͣ�����ͨ��string������c_str()��Ա��������string����ת����c�����е��ַ�����ʽ��
    string s20 = "abC";
    const char* p20 = s20.c_str(); //abC
    char str20[100];
    strcpy_s(str20, sizeof(str20), p20);
    cout << str20 << endl; //abC

    string s21(s20);  //��c���Ե��ַ����飬��ʼ��string���͡�
    cout << "-------------" << endl; 

    cout << "9. ��дstring����" << endl;
    //string s22;
    //cin >> s22; //�Ӽ�������
    //cout << s22 << endl;
    cout << "-------------" << endl;

    cout << "10. ����ֵ �� string ��ӡ�" << endl;
    string s23 = "abc";
    string s24 = "defg";
    string s25 = s23 + " and " + s24 + 'e';  //��������ʽ����ת���������м���̻�������ʱ�����������γ̻��н���
    cout << s25 << endl;

    //string s26 = "abc" + "def"; //�﷨���������ַ������������ܰ�����ӣ�����������֪�������ת������
    cout << "-------------" << endl;

    cout << "11. ��Χ for ��� string ��ʹ�á�" << endl;
    //c++���ṩ�˷�Χfor���ܹ�����һ�������е�ÿһ��Ԫ��
    //string���Կ�����һ�� �ַ�����
    string s26 = "I Love China!";
    for (auto c : s26)  // auto�����������Զ��ƶ�
    {
        cout << c << endl;
    }
    cout << "-----" << endl;

    string s27 = "I Love China!";
    for (auto& c : s27)  // c������
    {
        //toupper()��Сд�ַ�ת�ɴ�д����д�ַ�û�仯��
        c = toupper(c); //��Ϊc��һ�����ã���������ı���s27�е�ֵ
    }
    cout << s27 << endl;
    cout << "-------------" << endl;
    return 0;
}