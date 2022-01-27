//http://cpp.sh/6ymwd
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

//Shared data b/w threads
mutex m1,m2;

void thread1()
{
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout<<"critical seciotn of thread1"<<endl;
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout<<"critical seciotn of thread1"<<endl;
    m1.unlock();
    m2.unlock();
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
