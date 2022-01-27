#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;
using namespace std::chrono;

//Common data
int val = 0;
timed_mutex m;

void Increment(int tid)
{
    //actual timeout is 2 seconds
    if(m.try_lock_for(chrono::seconds(2)))
    {
        ++val;    
        //Here thread is waiting for 3 seconds, but actual timeout is 2 sec, so another thread cannot enter into this
        //this_thread::sleep_for(chrono::seconds(3));
        
        //Here thread is waiting for 1 seconds, but actual timeout is 2 sec, so this other thread has more time, hence another thread can enter into this
        this_thread::sleep_for(chrono::seconds(1));
        
        cout<<"thread"<<tid<<" entered"<<endl;
        m.unlock();
    }
    else
    {
        cout<<"thread"<<tid<<" could not enter"<<endl;
    }    
    
}

int main()
{
    thread t1(Increment, 1);
    thread t2(Increment, 2);
    t1.join();
    t2.join();
    cout<<"value is: "<<val<<endl;
    
    return 0;
}


//Program 2: STD::TIMED_MUTEX::TRY_LOCK_UNTIL
//Here it waits from 
/*
#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;
using namespace std::chrono;

//Common data
int val = 0;
timed_mutex m;

void Increment(int tid)
{
    auto now = chrono::steady_clock::now();
    //actual timeout is 2 seconds
    if(m.try_lock_until(now + chrono::seconds(2)))
    {
        ++val;    
        //Here thread is waiting for 3 seconds, but actual timeout is 2 sec, so another thread cannot enter into this
        //this_thread::sleep_for(chrono::seconds(3));
        
        //Here thread is waiting for 1 seconds, but actual timeout is 2 sec, so this other thread has more time, hence another thread can enter into this
        this_thread::sleep_for(chrono::seconds(1));
        
        cout<<"thread"<<tid<<" entered"<<endl;
        m.unlock();
    }
    else
    {
        cout<<"thread"<<tid<<" could not enter"<<endl;
    }    
    
}

int main()
{
    thread t1(Increment, 1);
    thread t2(Increment, 2);
    t1.join();
    t2.join();
    cout<<"value is: "<<val<<endl;
    
    return 0;
}
*/