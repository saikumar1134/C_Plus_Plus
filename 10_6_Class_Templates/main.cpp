#include<iostream>

using namespace std;

//Template parameter, Non template parameter
template<class T, int size>
class Stack
{
	int top;
	T arr[size];
public:
	//1. Default constructor
	Stack();
	
	//2.Create Instance, to know the concept of long-hand notation
	static Stack createInstance();
	
	//3. Copy constructor, to know the concept of short-hand notation
	//Here we create a copy of stack into another stack
	Stack(const Stack &obj)
	{
		top = obj.top;
		for(int i=0;i<=top;++i)
		{
			arr[i] = obj.arr[i];
		}
	}
	
	void push(T val);
	void pop();
	T peek();
	bool isEmpty();
	bool isFull();
	void print();
};

//1. Initialization
template<class T, int size>
Stack<T, size>::Stack()
{	
	top = -1;	
}

//2. Long-hand notation : Definining outside of the class
template<class T, int size>
Stack<T,size> Stack<T,size>::createInstance()
{
	return Stack<T,size>();
}


//4. Push
template<class T, int size>
void Stack<T, size>::push(T val)
{	
	if(!isFull())
	{
		++top;
		arr[top] = val;
	}
	return;
}

//5. Pop
template<class T, int size>
void Stack<T, size>::pop()
{	
	--top;
}

//6. isEmpty()
template<class T, int size>
bool Stack<T, size>::isEmpty()
{	
	return (top == -1)?true:false;
}

//7. isFull()
template<class T, int size>
bool Stack<T, size>::isFull()
{	
	return (top == size)?true:false;
}

//8. peek()
template<class T, int size>
T Stack<T, size>::peek()
{	
	return arr[top];
}

//9. print()
template<class T, int size>
void Stack<T, size>::print()
{
	while(!isEmpty())
	{
		cout<<peek()<<"\t";
		pop();
	}
	cout<<endl;
}

int main()
{
	Stack<double, 10> s = Stack<double, 10>::createInstance();
	s.push(1.1);
	s.push(1.2);
	s.push(1.3);
	s.pop();
	s.push(1.4);
	auto s2(s);
	s2.print();
	s.print();
	return 0;
}