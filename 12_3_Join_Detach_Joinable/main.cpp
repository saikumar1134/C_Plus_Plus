//http://cpp.sh/4a4gp
#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;

//1. join()
void JoinFun(int x)
{
    cout<<"x is:"<<x<<endl;
    //To illustrate join() better, we are waiting here for 3 seconds
    this_thread::sleep_for(chrono::seconds(3)); //Thread "t" waits for 3 seconds, before returing to main thread
}
void JoinThread()
{
    cout<<"***JOIN***"<<endl;
    thread t(JoinFun, 10); //Thread object t created
    if(t.joinable())
    {
        cout<<"I am joinable, since this is the first join"<<endl;
        t.join(); //Here main thread waits for child thread 't' to return from JoinFun()
    }
    //t.join(); - Double join, may end up program terminates, so what to do we do here, use joinable before every join
    if(t.joinable())
        t.join(); // This line will never be executed, since thread is already joined once
    cout<<"After Join"<<endl; //This statement prints, after 3 seconds of waiting of thread "t", before returning to main
}

//2. detach()

void DetachFun(int x)
{
    cout<<"x is:"<<x<<endl;
    //this_thread::sleep_for(chrono::seconds(2));
}

void DetachThread()
{
    cout<<"***DETACH***"<<endl;
    thread t(DetachFun, 20);
    if(t.joinable())
    {
        cout<<"I am Detachable, since this is the first detach"<<endl;
        t.detach();
    }
    //t.detach() - Double join, may end up program terminates, so what to do we do here, use joinable before every detach
    cout<<"After Detached"<<endl;
    if(t.joinable())
        t.detach(); // This line will never be executed, since thread is already detached once
    this_thread::sleep_for(chrono::seconds(2)); //If this line is not there, output will be differet x is:20 will not be printed
    cout<<"Waiting for 2 seconds , may be thread might be executed in that time"<<endl;
}

int main()
{
    JoinThread();
    DetachThread();
    
}
