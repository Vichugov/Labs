#include "LabaClass1.h"
#include <iostream>
using namespace std;
void Para::Init(int f, float s){
	first=f;
	secnd=s;
}
void Para::Read(){
	int f=0;
	float s=0.0;
	cout << "First (integer): ";
	cin >> f;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10,'\n');
		cout << "Incorrect input. Repeat, please: " << endl;
		cin >> f;
	}
	cin.ignore(10,'\n');
	cout << "Second (float): ";
	cin >> s;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10,'\n');
		cout << "Incorrect input. Repeat< please: " << endl;
		cin >> s;
	}
	cout << endl;
	Init (f,s);
}
void Para::Show(){cout << "Number: " << first+secnd << endl;}
void Para::Calc(int k){
	float third=first+secnd;
	cout << "Result: " << third*k << endl;
}
