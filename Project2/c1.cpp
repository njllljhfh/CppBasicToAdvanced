#include <iostream>
using namespace std;

//void copystr(char from[], char to[])
void copystr(char* from, char* to)
{
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        //*to = *from;
        i++;
        //to++;
        //from++;
    }
    to[i] = '\0';
}

int mainc1()
{
    //char mystr1[] = "I Love China!";
    //char mystr2[] = "I Love China!";

    //const char* pmystr1 = "I Love China!";
    //const char* pmystr2 = "I Love China!";
    //if (pmystr1 == pmystr2)
    //{
    //    cout << 666 << endl;
    //}
    //char a[] = "I Love China!";
    //char b[100];

    //int i;
    //for (i = 0; *(a + i) != '\0'; i++)
    //{
    //    *(b + i) = *(a + i);
    //}
    //*(b + i) = '\0';
    // -----
    //char* p1;
    //char* p2;
    //p1 = a;
    //p2 = b;
    //for (; *p1 != '\0'; p1++, p2++)
    //{
    //    *p2 = *p1;
    //}
    //*p2 = '\0';

    //printf("string a is %s\n", a);
    //printf("string b is %s\n", b);

    char a[] = "this is source content";
    char b[] = "this is a special test hehe, look carefully";
    printf(" a is %s\n", a);
    printf(" b is %s\n", b);

    copystr(a, b);

    printf(" a is %s\n", a);
    printf(" b is %s\n", b);

    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;

    if (a == b)
    {
        cout << "a == b" << endl;
    }

    int a11[] = { 1,2,3 };
    int* p11 = a11;
    return 0;
}