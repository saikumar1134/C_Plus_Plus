//http://cpp.sh/2ftgy
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
    m.lock();
	//critical section
    for(int i = 0; i<1000; ++i)
        l.push_back(i);
    m.unlock();
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