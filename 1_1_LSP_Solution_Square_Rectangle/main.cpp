//LSP DEF : every subclass object should replace base class object, 
//without affecting the functionality (as done only with base class object)
//In our example, whereever rectangle object is used, it should be replaced with square object
#include<iostream>
#include<cassert>

using namespace std;
class Shape
{
public:
	virtual int area() const = 0;
};

class Rectangle : public Shape
{
protected:
	int m_Width, m_Height;
public:
	Rectangle(int w, int h) { this->m_Width = w; this->m_Height = h;}
	
	virtual void setWidth(const int w) { this->m_Width = w; }
	virtual void setHeight(const int h){ this->m_Height = h; }
	
	int getWidth() const { return this->m_Width; }
	int getHeight() const { return this->m_Height; }
	
	int area() const override { return (this->m_Width * this->m_Height); }
};

class Square : public Shape
{
	int m_Size;
public:
	Square(int length) { this->m_Size = length; }
	void setSize(const int s) { this->m_Size = s; }
	int area() const override {return this->m_Size * this->m_Size; }
};

void Transform(Shape &s)
{
	cout<<"Area is:"<<s.area()<<endl;
}

int main()
{	
	Rectangle rect{10,2};
	Square sq{5};

	Transform(rect);
	Transform(sq); 
	return 0;
}