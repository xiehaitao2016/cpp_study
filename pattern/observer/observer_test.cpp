#include <iostream>
#include <string>
#include "Observer.hpp"

using namespace std;

class observer
{
    public:
    int a_,b_;

    public:
    observer(int a,int b):a_(a),b_(b)   {cout<<"observer is constructor\n";}
    observer() = default;
    observer(const observer &) = delete;
    observer& operator = (const observer &) = delete;
    void print(int a,int b) {cout<<"observer::print "<<a<<","<<b<<endl;}
    /* data */
};

void print(int a,int b) {cout<<"::print "<<a<<","<<b<<endl;}

int main(){
    Events<std::function<void(int,int)>> myevent;

    auto key = myevent.Connect(print);
    observer ob1(1,2);
    //observer ob2 = ob1;
    //observer ob3(ob1);
    auto lambdakey = myevent.Connect([&ob1](int a,int b){ob1.a_=a;ob1.b_=b;});

    std::function<void(int,int)> f = std::bind(&observer::print,&ob1,std::placeholders::_1,std::placeholders::_2);
    myevent.Connect(f);

    int a = 1, b = 2;
    myevent.Notify(a,b);

    myevent.Disconnect(key);

    return 0;
}

