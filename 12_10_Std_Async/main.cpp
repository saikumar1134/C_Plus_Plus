//http://cpp.sh/6kjdh
#include<iostream>
#include<thread>
#include<future>

using namespace std;

//Type aliasing
using ull = unsigned long long;

ull oddSum(ull start, ull end)
{
    cout<<"Thread2 is:"<<this_thread::get_id()<<endl;
    ull os{};
    while(start<=end)
    {
        os += start;
        ++start;
    }
    return os;
}


int main()
{
    cout<<"Thread1 is:"<<this_thread::get_id()<<endl;
    ull start = 0, end = 1900000000;
	
    cout<<"***launch::async***"<<endl;
    future<ull> fobj = async(launch::async, oddSum, start, end);
    cout<<"Waiting for the result"<<endl;
    cout<<"Odd Sum is:"<<fobj.get()<<endl;
    cout<<"Got the result, wait completed"<<endl;
	
    cout<<endl<<endl;
	
    cout<<"***launch::deferred***"<<endl;
    future<ull> fobj1 = async(launch::deferred, oddSum, start, end);
    cout<<"Waiting for the result"<<endl;
    cout<<"Odd Sum is:"<<fobj1.get()<<endl;
    cout<<"Got the result, wait completed"<<endl;
	
    return 0;
}