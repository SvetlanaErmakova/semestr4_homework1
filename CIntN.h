#ifndef CINTN
#define CINTN

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class CIntN
{
protected:
    int* value;
    size_t N;
    string FileName;
    string num;
public:
    CIntN();//конструктор по умолчанию
    CIntN(string file_name, size_t N, string num);//конструктор 
    CIntN(const CIntN& other);//конструктор копирования

    //фции
    virtual void output() = 0; // pure virtual
    void print_num();

    size_t Get_N() const;
    string Get_FileName() const;
    string Get_num() const;
    int Get_val_i(int i) const;
    //операторы
    CIntN& operator=(const CIntN& other);

    virtual ~CIntN();//деструктор
};

class CIntN0 : public CIntN
{
public:
    CIntN0(string file_name, size_t N, string num) :CIntN(file_name, N, num) {}//констурктор
    CIntN0() :CIntN() {}//конструктор по умолчанию
    CIntN0(const CIntN& other) :CIntN(other) {}//конструктор копирования

    using CIntN::operator=;

    void output() override final;

    friend CIntN0 operator+(const CIntN& first, const CIntN& second);// friend - может пользоваться приватными полями
    friend CIntN0 operator-(const CIntN& first, const CIntN& second);

    ~CIntN0();
};

class CIntN1 : public CIntN
{
public:
    CIntN1(string file_name, size_t N, string num) : CIntN(file_name, N, num) {}
    CIntN1() :CIntN() {}
    CIntN1(const CIntN& other) :CIntN(other) {}

    using CIntN::operator=;

    void output() override final;

    ~CIntN1();
};

#endif


