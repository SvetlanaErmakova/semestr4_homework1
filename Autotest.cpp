#include "Autotest.h"

int Autotest1()
{
    int f = 0;

    CIntN0 v1("data_out1.txt", 3, "101");
    CIntN1 v2("data_out2.txt", 3, "555");

    if ((v1 + v2).Get_num() == "656")
    {
        f = 1;
        cout << "Test 1 passed...\n";
    }
    else
    {
        cout << "Test 1 failed!\n";
        f = 0;
    }

    return f;
}

int Autotest2()
{
    int f = 0;

    CIntN0 v3("data_out1.txt", 3, "101");
    CIntN1 v4("data_out2.txt", 3, "555");

    if ((v3 - v4).Get_num() == "-454")
    {
        f = 1;
        cout << "Test 2 passed...\n";
    }
    else
    {
        cout << "Test 2 failed!\n";
        f = 0;
    }

    return f;
}

int Autotest3()
{
    int f = 0;

    CIntN0 v1("data_out1.txt", 3, "101");
    CIntN1 v2("data_out2.txt", 3, "555");
    CIntN0 v3 = v1 + v2;

    if (v3.Get_num() == "656")
    {
        f = 1;
        cout << "Test 3 passed...\n";
    }
    else
    {
        cout << "Test 3 failed!\n";
        f = 0;
    }

    return f;
}


int Autotest()
{
    if (Autotest1() * Autotest2() * Autotest3() == 1)
        return 1;
    else
        return 0;
}