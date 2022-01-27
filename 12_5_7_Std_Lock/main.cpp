//http://cpp.sh/5jzas
#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex m1, m2;

void thread1()
{
    while(true)
    {
        lock(m1, m2);
        cout<<"T1"<<endl;
        m1.unlock();
        m2.unlock();
    }
}

void thread2()
{
    while(true)
    {
        lock(m2, m1);
        cout<<"T2"<<endl;
        m1.unlock();
        m2.unlock();
    }
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);
    
    t1.join();
    t2.join();
    return 0;
}