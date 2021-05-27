#include "LabaClass2.cpp"
#include <iostream>
using namespace std;
void Initer(Bank &b){
	int i;
	double c, m;
	cout << "New data: " << endl;
	cout << "ID: "; cin >> i;
	while(cin.fail()){
		cin.clear();cout << "Incorrect input! Repeat: "; cin.ignore(5,'\n');  cin >> i;
	} 
	cout << "Count: "; cin >> c;
	while(cin.fail()){
		cin.clear(); 
		cin.ignore(5,'\n'); 
		cout << "Incorrect input! Repeat: "; 
		cin >> c;
	} 
	cout << "Limit: "; cin >> m;
	while(cin.fail()){
		cin.clear(); 
		cin.ignore(5,'\n'); 
		cout << "Incorrect input! Repeat: "; 
		cin >> m;
	}
	b.Init(i, c, m);
	cout << endl << "Init B: " << endl;
	b.Show();
}
Bank Abonent(){
	Bank d;
	d.Init(305, 12823.06, 32000);
	cout << endl << "D: " << endl;
	d.Show();
	return d;
}
main(){
	cout.precision(10);
	Bank a;
	cout << "A: " << endl;
	a.Show();
	Bank b(524, 650248.32, 50000.0);
	cout << endl << "B: " << endl;
	b.Show();
	Bank c=b;
	cout << endl << "C: " << endl;
	c.Show();
	Bank d;
	d=Abonent();
	Initer(b);
	Bank e(b);
	cout << endl << "E: " << endl;
	e.Show();
	return 0;
}
