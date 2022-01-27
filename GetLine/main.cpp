#include <bits/stdc++.h>
using namespace std;

int main()
{
	//1. Using strings
	cout<<"What is your name:"<<endl;
	string str;
	getline(cin,str);
	cout<<"Your name is:"<<str<<endl;
	
	//2. Using char array
	char ch[80];
	cout<<"What is your name:"<<endl;
	cin.getline(ch, 80);
	cout<<"Your name is:"<<ch<<endl;

	
	//3. Using stringstream -Diving into words
	string S, T;
 
    getline(cin, S);
 
    stringstream X(S);
 
    while (getline(X, T, ' ')) {
        cout << T << endl;
    }
	
	return 0;
}