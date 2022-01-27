//http://cpp.sh/4qhcxz
#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<chrono>
using namespace std;
using namespace std::chrono;

//Common data / shared data
int x = 0, y = 0;

//Creating mutex locks only, for this example (But we can have any lockable objects here)
mutex m1, m2;


void Produce(int& XorY, mutex& m, const char* data)
{
    for(int i=0;i<3;++i)
    {
        m.lock();
        ++XorY;
        cout<<data<<"\t"<<XorY<<endl;
        m.unlock();
        //It allows the consumer thread to access the data
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void Consume()
{
   int XplusY = 0;
   int counter = 3; 
   while(1)
   {
        //trying to lock muterx m1 and m2
        if(try_lock(m1, m2) == -1)
        {
            if((x != 0) && (y != 0))
            {
                --counter;
                XplusY = XplusY + x + y;
                x = y = 0;
                cout<<"x plus y is:"<<XplusY<<endl;
            }
			m1.unlock();
			m2.unlock();
            if(counter == -1)
                    break;
        }
   }
}

int main()
{
    thread t1(Produce, ref(x), ref(m1), cref("X"));
    thread t2(Produce, ref(y), ref(m2), cref("Y"));
    thread t3(Consume);
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}