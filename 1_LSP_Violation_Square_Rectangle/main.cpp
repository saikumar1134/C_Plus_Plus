//LSP DEF : every subclass object should replace base class object, 
//without affecting the functionality (as done only with base class object)
//In our example, whereever rectangle object is used, it should be replaced with square object
//
#include<iostream>
#include<cassert>
using namespace std;

class Rectangle
{
protected:
	int m_Width, m_Height;
public:
	Rectangle(int w, int h) { this->m_Width = w; this->m_Height = h;}
	
	virtual void setWidth(const int w) { this->m_Width = w; }
	virtual void setHeight(const int h){ this->m_Height = h; }
	
	int getWidth() const { return this->m_Width; }
	int getHeight() const { return this->m_Height; }
	
	int area() { return (this->m_Width * this->m_Height); }
};

class Square : public Rectangle
{
public:
	Square(int w, int h):Rectangle(w,h) {}
	void setWidth(const int w) override { this->m_Width = this->m_Height = w; }
	void setHeight(const int h) override { this->m_Height = this->m_Width = h; }
};

//Explanation for violation of LSP
//We are trying to replace rectangle with square object here, and there is no problem in that
//the problem is, in this function assert() doesn't work for square i.e., the result/area of Rectangle and Square are different here 
//(of course they should be different, but as per LSP subclass object produces the same result as base class object when it is replaced)
//that means "post-condition method" has been violated here. Hence, Square is not a perfect subtype of Rectangle
void Transform(Rectangle &r)
{
	int w = r.getWidth();
	r.setHeight(10);
	
	//Successful for rectangle
	//Fail for Square
	assert((w * 10) == r.area()); 
 }

int main()
{	
	Rectangle rect{5,5};
	Square sq{5,5};

	Transform(rect);
	//Transform(sq); //This gives error 
	cout<<"Area of rectangle is:"<<rect.area()<<endl;
	cout<<"Area of square is:"<<sq.area()<<endl;
	return 0;
}