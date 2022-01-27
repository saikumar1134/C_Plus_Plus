//http://cpp.sh/9mcjb
#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

//common data
int val = 0;
recursive_mutex m;

void Increment(int tid, int loopfor)
{
    if(loopfor<=0)
        return;
    //Here we ca have direct recursive_mutex lock as well
	//m.lock();
    if(m.try_lock())
    ++val;
    --loopfor;
    cout<<"Thread "<<tid<<"\t"<<val<<endl;
    Increment(tid, loopfor);
    m.unlock();
    cout<<"Unlocked"<<endl;
    
}

int main()
{
    thread t1(Increment, 1, 2);
    thread t2(Increment, 2, 2);
    t1.join();
    t2.join();
    cout<<"value is:"<<val<<endl;
    return 0;
}