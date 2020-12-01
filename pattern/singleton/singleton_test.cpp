#include <iostream>
#include <string>
#include "Singleton.hpp"

using namespace std;
class A
{
    public:
    A(const string &p):name_(p)   {cout<<"class A lvalue constructor"<<endl;}
    A(const string &&p):name_(p)  {cout<<"class A rvalue constructor"<<endl;}    
    void test() {cout<<"class A  test name_ is "<<name_<<endl;}

    private:
    string name_;

};

class B
{
    public:
    B(const string& p):name_(p) {cout<<"class B lvalue constructor"<<endl;}
    B(string&& x):name_(x)   {cout<<"class B rvalue constructor"<<endl;}
    /* data */

    void test() {cout<<"class B  test name_ is "<<name_<<endl;}

    private:
    string name_;
};

class C
{
    public:
    C(int x,double y):x_(x),y_(y)  {  cout<<"class C constructor"<<endl;  }
    void func() {cout<<"test:"<<x_<<","<<y_<<endl;}
    /* data */

    private:
    int x_;
    double y_;
};

int main()
{
    string str = "aaa";
    auto ptr_a = Singleton<A>::Instance(str);
    ptr_a->test();

    string str2 = "bbb";
    auto ptr_b = Singleton<A>::Instance(str);
    ptr_b->test();

    string str3 = "ccc";
    auto prt_c = Singleton<B>::Instance(std::move(str3));
    prt_c->test();

    auto ptr_d = Singleton<C>::Instance(1,3.14);
    ptr_d->func();

    Singleton<A>::DestroyInstance();
    Singleton<B>::DestroyInstance();
    Singleton<C>::DestroyInstance();
}


