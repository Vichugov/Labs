#include "LabaClass4.cpp"
istream& operator >>(istream &ist, Person &p){
	cout << "Input name: ";
	ist >> p.name;
	ist.clear();
	ist.ignore(5,'\n');
	cout << "Input age: ";
	ist >> p.age;
	while (ist.fail()){
	ist.clear();
	ist.ignore(5,'\n');
	cout << "Incorrect input! Please, repeat. " << endl;
	cout << "Input age (int): ";
	ist >> p.age;
	}
	return ist;
}
ostream& operator <<(ostream &ost, Person &p){
	ost << "Name: " << p.name << endl << "Age: " << p.age << endl;
}
main(){
	Person pfirst("Andrey",18);
	pfirst.Show();
	Person psecond(pfirst);
	cout << psecond;
	Teacher tfirst;
	cout << tfirst;
	tfirst.Init("Vilson", 42);
	tfirst.TInit();
	tfirst.Show();
	Teacher tsecond("Yes", 52);
	tsecond=psecond;
	cout << tsecond;
	tsecond.Show();
}
