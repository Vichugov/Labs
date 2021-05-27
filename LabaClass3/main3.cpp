#include "LabaClass3.cpp"
void Init(Para& p, int c, float d){
p.a=c;
p.b=d;	
}
ostream& operator <<(ostream &os, Para &p){
os << "Operator \"<<\": " << endl << "Numbers: " << p.RetA() << ":" << p.RetB() << endl;
}
istream& operator >>(istream& ist, Para &p){
	cout << "Operator \'>>\': " << endl;
	cout << "First (int): "; ist >> p.a;
	while (ist.fail()){
		ist.clear();
		ist.ignore(10,'\n');
		cout << "Incorrect input. Repeat first (int): ";
		ist >> p.a;
	}
	ist.clear();
	ist.ignore(10,'\n');
	cout << "Second (float): "; ist >> p.b;
		while (ist.fail()){
		ist.clear();
		ist.ignore(10,'\n');
		cout << "Incorrect input. Repeat second (float): ";
		ist >> p.b;
	}
	ist.clear();
	ist.ignore(10,'\n');
}
main(){
	cout.precision(5);
	Para first(10, 50.53);
	cout << "First: " << endl;
	first.Show();
	Init(first, 18, 46.52);
	first.Show();
	cout << endl << "Second: " << endl;
	Para second;
	second.Show();
	if (second==first) cout << "Second == first. " << endl;
	if (second!=first) cout << "Second != first. " << endl;
	second=first;
	cout<<second;
	if (second==first) cout << "Second == first. " << endl;
	if (second!=first) cout << "Second != first. " << endl;
	cout << endl << "Third: " << endl;
	Para third;
	cout<<third;
	cin>>third;
	third.Show();
	cout << endl << "Substraction: " << endl;
	third=third-5;
	third.Show();
	third=third-0.7F;
	cout << third;
	return 0;
}
