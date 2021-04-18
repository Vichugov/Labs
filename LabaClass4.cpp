#include "LabaClass4.h"
int Person::RAge() {return age;}
string Person::RName(){return name;}
string Teacher::RPred(){return pred;}
int Teacher::RHour(){return hours;}
Person::Person(){
	name = "No name";
	age=0;
}
Person::Person(string n, int a){
	name=n;
	age=a;
}
Person::Person(Person &p){
	name=p.RName();
	age=p.RAge();
}
Person::~Person(){}
void Person::Init(string n, int a){
	name=n;
	age=a;
}
void Person::Show(){
	cout << "Name: " << name << endl << "Age: " << age << endl;
}

Person& Person::operator =(Person &p){
	name=p.RName();
	age=p.RAge();
}
Teacher::Teacher(){
	pred="No subjects. ";
	hours=0;
}
Teacher::Teacher(string pr, int h){
	pred=pr;
	hours=h;
}
Teacher::Teacher(Teacher &t){
	pred=t.RPred();
	hours=t.RHour();
}
Teacher::~Teacher(){}
void Teacher::TInit(){
		cout << "Input subjects: ";
		cin >> pred;
		cout << "Input hours (int): ";
		cin >> hours;	
	while (cin.fail()){
		cin.clear();
		cin.ignore(5,'\n');
		cout << "Incorrect input! Please, repeat. " << endl;
		cout << "Input hours (int): ";
		cin >> hours;
	}
}
void Teacher::Show() {
	cout << "Name: " << name << endl << "Age: " << age << endl << "Subjects: " << pred << endl << "Hours: " << hours << endl;
} 
Teacher& Teacher::operator =(Person &p){
	name=p.RName();
	age=p.RAge();
}
