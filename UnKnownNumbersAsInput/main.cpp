// CPP program to take unknown number
// of integers from user.
#include <iostream>
using namespace std;
int main()
{
	float input;
	int count = 0;
	cout << "To stop enter any character";
	cout << "\nEnter Your Input::";

	// cin returns false when a character
	// is entered
	while (cin >> input)
		count++;
	
	cout << "\nTotal number of inputs entered: "
		<< count;
	return 0;
}