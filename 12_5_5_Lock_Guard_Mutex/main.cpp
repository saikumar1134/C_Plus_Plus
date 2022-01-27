//http://cpp.sh/4zooa
#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

//shared data / global
int val = 0;
mutex m;

void Increment(int tid)
{
    //This is the replacement of lock and unlock doing manually
    lock_guard<mutex> obj(m);
    ++val;
    cout<<"Thread"<<tid<<"\t"<<val<<endl;
}

int main()
{
    thread t1(Increment, 1);
    thread t2(Increment, 2 );
    t1.join();
    t2.join();
    cout<<"Value is:"<<val<<endl;
    return 0;
}