//http://cpp.sh/24asd
#include<iostream>
#include<thread>
#include<mutex>
#include<future>

using namespace std;

//shared data
using ull = unsigned long long;

void thread1(promise<ull> &&odd_sum, ull start, ull end)
{
    ull os = 0;
    while(start<=end)
    {
        if((start&1)==1)
        {
            os += start;
        }
        ++start;
    }
    odd_sum.set_value(os);
}

int main()
{
    ull start = 0, end = 190000000;
    promise<ull> oddsum;
    future<ull> oddFuture= oddsum.get_future();
    thread t1(thread1, move(oddsum), start, end);
    cout<<"Waiting for the result"<<endl;
    cout<<"result is:"<<oddFuture.get()<<endl;
    t1.join();
    
}