#include "CIntN.h"
#include "Autotest.h"
int main()
{
    if (Autotest() != 1)
    {
    	cout << "Error! Tests not passed!\n";
    	return -1;
    }

    try
    {
        cout << "Input file name: \n";
        string file_name;
        cin >> file_name;

        ifstream inp(file_name);
        if (!inp)
        {
            cout << "Error!Cannot open file!\n";
            throw - 1;
        }

        size_t strok=0;
        string line;
        while (getline(inp, line)) //сколько строк
            strok ++ ;
        inp.close();

        CIntN** arr = (CIntN**)malloc(sizeof(CIntN*)*strok);

        int I;
        size_t N;
        string name_f, num;
        size_t i = 0;

        inp.open(file_name);

        while (!inp.eof())
        {
            inp >> I;
            inp >> name_f;
            inp >> N;
            inp >> num;

            if (I == 0)
            {
                if (i < strok)
                {
                    arr[i] = new CIntN0(name_f, N, num); 
                }
            }
            else if (I == 1)
            {
                if (i < strok)
                {
                    arr[i] = new CIntN1(name_f, N, num);
                }
            }

            i++;
        }
        inp.close();

        for (size_t i = 0; i < strok; i++)
        {
            arr[i]->output();
            arr[i]->print_num();
        }

        CIntN0 v1("data_out1.txt", 3, "101");
        CIntN1 v2("data_out2.txt", 3, "-555");
        CIntN0 v3 = v1 + v2;
        CIntN0 v4 = v1 - v2;
        v3.print_num();
        v4.print_num();

        for (size_t i = 0; i < strok; i++)
        {
            delete arr[i];
        }
        delete [] arr;
    }
    catch (...) { cout << "\nIncorrect for this class!" << endl; }

    return 0;
}

