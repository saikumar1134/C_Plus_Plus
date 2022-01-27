//http://cpp.sh/2qksl
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

//Shared between threads
int balance = 0;
condition_variable cv;
mutex m;

void AddMoney(int money)
{
    lock_guard<mutex> lg(m);
    balance = balance + money;
    cout<<"Amount was added into account"<<endl;
    cv.notify_one();
}

void WithdrawMoney(int money)
{
    unique_lock<mutex> ul(m);
    cv.wait(ul, []{return (balance>0)?true:false;});
    if(balance < money)
    {
        cout<<"Insufficient balance in accout"<<endl;
    }
    else
    {
        balance = balance - money;
        cout<<"Amount "<<money<<" withdrawn"<<endl;
    }
}

int main()
{
    thread t1(WithdrawMoney, 500);
    thread t2(AddMoney, 500); //thread t2(AddMoney, 300); thread t2(AddMoney, 700);
    t1.join();
    t2.join();
    cout<<"Balance is:"<<balance<<endl;
    return 0;
}
