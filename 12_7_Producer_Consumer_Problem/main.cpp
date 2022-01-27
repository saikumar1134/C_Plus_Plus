//http://cpp.sh/7cmth
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<stack>

using namespace std;

//global data
stack<int> buffer;
mutex m;
condition_variable cv;
const unsigned int buffer_size = 50;

void producer(int loop_for)
{
    while(loop_for)
    {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [](){return buffer.size()<buffer_size;});
        buffer.push(loop_for);
        cout<<"Inserted"<<loop_for<<endl;
        --loop_for;
        ul.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    while(true)
    {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [](){return buffer.size() > 0;});
        buffer.pop();
        cout<<"consumed"<<endl;
        ul.unlock();
        cv.notify_one();
    }
}

int main()
{
    thread t1(producer, 5);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}