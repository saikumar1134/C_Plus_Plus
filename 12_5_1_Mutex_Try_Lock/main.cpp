//http://cpp.sh/2fufv
#include<iostream>
#include<thread>
#include<mutex>
#include<list>
using namespace std;

//Common data / shared data
list<int> l;
mutex m;

void Insert()
{
	//critical section
    for(int i = 0; i<1000; ++i)
		//How it works?
		//Consider thread t1 able to acquire try_lock on mutex, that means t2 will not wait here,
		//But, it keeps on try to acuire try_lock. So the following things may happen
		//1) Consider t1 is has lock, t2 returns with false->hence 'i' value increments without even inserting into list
		//2) Consider t1 is released, t2 acquires the lock->point 1 may repeated
		//So, at final the size of the list will be any random number less than 2000
        if(m.try_lock())
        {
            l.push_back(i);
            m.unlock();
        }
    
}

int main()
{
    thread t1(Insert);
    thread t2(Insert);
    t1.join();
    t2.join();
    cout<<"size is:"<<l.size()<<endl;
    return 0;
}

//Program 2 - Without for loop
/*
#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<chrono>
using namespace std;
using namespace std::chrono;

//Common data / shared data
list<int> l;
mutex m;

void Insert()
{
        if(m.try_lock())
        {
            l.push_back(1);
            this_thread::sleep_for(chrono::seconds(1));
            m.unlock();
        }
    
}

int main()
{
    thread t1(Insert);
    thread t2(Insert);
    t1.join();
    t2.join();
    cout<<"size is:"<<l.size()<<endl;
    return 0;
}
*/