#include "CIntN.h"

CIntN::CIntN()//конструктор по умолчанию
{
    N = 0;
    value = NULL;
    FileName = "f";
    num = " ";
}

CIntN::CIntN(string file_name, size_t N_, string num_)//конструктор
{
    if(num_[0]=='-' && num_.size() != N_+1 || num_[0] != '-' && num_.size()!= N_)
        throw - 1;

    N = N_;
    num = num_;
    FileName = file_name;

    value = (int*)malloc(N * sizeof(int));
    int fl = 1;
    for (size_t i = 0; i < N; i++)
    {
        if (i == 0)
            if (num[i] == '-')
                fl = -1;
        if (fl == -1)
        {
            if (num[i + 1] >= '0' && num[i + 1] <= '9')//цифра ли
            {
                if (i == 0)
                    value[i] = -1 * (num[i + 1] - '0');
                else
                    value[i] = num[i + 1] - '0';
            }
            else
                throw - 1;
        }
        else
        {
            if (num[i] >= '0' && num[i] <= '9')//цифра ли
            {
                value[i] = num[i] - '0';
            }
            else
                throw - 1;
        }
    }
}

CIntN::CIntN(const CIntN& other)//конструктор копирования
{
    N = other.Get_N();
    num = other.Get_num();
    FileName = other.Get_FileName();

    value = (int*)malloc(N * sizeof(int));
    for (size_t i = 0; i < N; i++)
    {
        value[i] = other.Get_val_i(i);
    }
}

CIntN::~CIntN()//деструктор
{
    delete[] value;
}
CIntN1::~CIntN1()//деструктор
{}
CIntN0::~CIntN0()//деструктор
{}

//операторы
CIntN& CIntN::operator=(const CIntN& other)
{
    N = other.Get_N();
    num = other.Get_num();
    FileName = other.Get_FileName();

    value = (int*)malloc(N * sizeof(int));
    for (size_t i = 0; i < N; i++)
    {
        value[i] = other.Get_val_i(i);
    }
    return *this;
}

//функции
size_t CIntN::Get_N() const
{
    return N;
}

string CIntN::Get_FileName() const
{
    return FileName;
}

string CIntN::Get_num() const
{
    return num;
}

int CIntN::Get_val_i(int i) const
{
    return value[i];
}

void CIntN::print_num()
{
    for (size_t i = 0; i < N; i++)
    {
        cout << value[i];
    }
    cout << "\n";
}

void CIntN0::output()
{
    ofstream fout(FileName); 
    for (size_t i=0; i < N; i++)
    {
        fout << value[i]; // запись строки в файл
    }
    fout.close();
}
void CIntN1::output()
{
    ofstream fout(FileName); 
    for (size_t i=0; i < N; i++)
    {
        fout << value[i]<<'\n'; // запись столбца в файл
    }
    fout.close();
}


//операторы наследника0
CIntN0 operator+(const CIntN& first, const CIntN& second)
{
    if (first.Get_N() != second.Get_N())//только меж объектами одного типа
        throw - 1;

    string s1 = first.Get_num();
    string s2 = second.Get_num();
    int N = first.Get_N();

    string s3, vr, ss;
    int t1, t2, t3, flag=0, flag_=0, minus=0;

    if (s1[0] != '-' && s2[0] == '-') //2 + -3
    {
        ss = s1;
        s1 = s2;
        s2 = ss;
    }
    if (s1[0] == '-' && s2[0] != '-')//-2 + 3 
    {
        if (s1[1] > s2[0])//-3+2=-1 <0
        {
            for (int i = N; i > 0; i--)
            {
                t1 = int(s1[i] - '0');
                t2 = int(s2[i-1] - '0');
                if (t1 - t2 + flag_ < 0)
                {
                    t3 = (t1 + 10 + flag_)- t2;
                    flag_ = -1;
                }
                else
                {
                    t3 = t1 - t2 + flag_;
                    flag = 0;
                }
                if (t3==0 && i == 0)// 533-509=24
                    throw - 1;

                auto ss = to_string(t3);//t3 типа инт в string
                s3.insert(0, ss);
            }
            s3.insert(0, "-");
        }
        else//-2+3=1 >0
        {
            for (int i = N; i > 0; i--)
            {
                t1 = int(s1[i] - '0');
                t2 = int(s2[i - 1] - '0');
                if (t2 - t1 + flag_ < 0)
                {
                    t3 = (t2 + 10 + flag_) - t1;
                    flag_ = -1;
                }
                else
                {
                    t3 = t2 - t1 + flag_;
                    flag = 0;
                }
                if (t3 == 0 && i == 0)// 533-509=24
                    throw - 1;

                auto ss = to_string(t3);//t3 типа инт в string
                s3.insert(0, ss);
            }
        }
        
    }
    if (s1[0] == '-' && s2[0] == '-')//-2-3=-5 один знак -
    {
        for (int i = N ; i > 0; i--)
        {
            t1 = int(s1[i] - '0');
            t2 = int(s2[i] - '0');
            if (t1 + t2 + flag > 9)
            {
                t3 = (t1 + t2 + flag) % 10;
                flag = 1;
            }
            else
            {
                t3 = t1 + t2 + flag;
                flag = 0;
            }
            if (flag == 1 && i == 0)// 85+16=101
                throw - 1;

            auto ss = to_string(t3);//t3 типа инт в string
            s3.insert(0, ss);
        }
        s3.insert(0, "-");
    }
    if (s1[0] != '-' && s2[0] != '-' )//2+3=5 один знак +
    {
        for (int i = N-1 ; i >= 0; i--)
        {
            t1 = int(s1[i] - '0');
            t2 = int(s2[i] - '0');
            if (t1 + t2 + flag > 9)
            {
                t3 = (t1 + t2 + flag) % 10;
                flag = 1;
            }
            else
            {
                t3 = t1 + t2 + flag;
                flag = 0;
            }
            if (flag == 1 && i == 0)// 85+16=101
                throw - 1;

            auto ss = to_string(t3);//t3 типа инт в string
            s3.insert(0, ss);
        }
    }

    CIntN0 v(first.Get_FileName(), N, s3);
    return v;
}

CIntN0 operator-(const CIntN& first, const CIntN& second)
{
    if (first.Get_N() != second.Get_N())//только меж объектами одного типа
        throw - 1;

    string s1 = first.Get_num();
    string s2 = second.Get_num();
    int N = first.Get_N();

    string s3, vr, ss;
    int t1, t2, t3, flag = 0, flag_ = 0, minus = 0;

    if (s1[0] != '-' && s2[0] != '-') //2 - +3
        s2.insert(0, "-");
    else if (s1[0] == '-' && s2[0] == '-')//-2 - -3
        s2.erase(0,1);
    else if (s1[0] == '-' && s2[0] != '-')//-2 - +3 
        s2.insert(0, "-");
    else if (s1[0] != '-' && s2[0] == '-')//2 - -3 
        s2.erase(0, 1);

    CIntN0 ob(second.Get_FileName(), second.Get_N(), s2);

    return first+ob;
}
