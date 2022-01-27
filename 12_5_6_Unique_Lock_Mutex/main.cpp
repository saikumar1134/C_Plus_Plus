//http://cpp.sh/8siyo
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
    unique_lock<mutex> obj(m,defer_lock);
    cout<<"Obj is yet to take an ownership"<<endl;
    obj.lock(); // Took ownership now
    
    unique_lock<mutex> obj1(move(obj)); //Move ownership from obj to obj1
    ++val;
    
    unique_lock<mutex> obj2(m, adopt_lock); //Adopted obj2 from obj1
    ++val;
    
    cout<<"Thread"<<tid<<"\t"<<val<<endl;
    
    obj2.unlock(); // I can unlock it even before destructor called, unlike lock_guard
    
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