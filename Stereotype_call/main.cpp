#include <iostream>
using namespace std;

class Target
{
    public:
        void printTarget()
        {
            cout<<"I am from Target class"<<endl;
        }
};

class Source
{
    public:
        void printTargetFromSource(Target &t1)
        {
            cout<<"Source invoking target's method"<<endl;
            t1.printTarget();
        }
};

int main()
{
    Target tObj;
    tObj.printTarget();
    
    Source sObj;
    sObj.printTargetFromSource(tObj);
    return 0;
}
