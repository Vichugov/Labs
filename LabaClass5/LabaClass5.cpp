#include "LabaClass5.h"
Teacher::Teacher(){
	name="No name";
	age=0;
	subject="No subject";
	hours=0;
}
Teacher::Teacher(string n, string s, int a, int i){
	name=n;
	age=a;
	subject=s;
	hours=i;
}
Teacher::Teacher(Teacher &t){
	name=t.name;
	age=t.age;
	subject=t.subject;
	hours=t.hours;
}
void Teacher::Init(istream &stream){
	cout << "Input name: ";
	stream >> name;
	cout << "Input age: ";
	stream >> age;
	cout << "Input subject: ";
	stream >> subject;
	cout << "Input hours: ";
	stream >> hours;
}
void Teacher::Show(ostream &stream){
	stream << "Teacher: " << endl << "Name: " << name << endl << "Age: " << age << endl << "Subject: " << subject << endl << "Hours: " << hours << endl;
}
Sportsman::Sportsman(){
	name="No name";
	age=0;
	sport="No sport";
	massa=0;
}
Sportsman::Sportsman(string n, string s, int a, int i){
	name=n;
	age=a;
	sport=s;
	massa=i;
}
Sportsman::Sportsman(Sportsman &s){
	name=s.name;
	age=s.age;
	sport=s.sport;
	massa=s.massa;
}
void Sportsman::Init(istream &stream){
	cout << "Input name: ";
	stream >> name;
	cout << "Input age: ";
	stream >> age;
	cout << "Input sport: ";
	stream >> sport;
	cout << "Input weight of sportsman: ";
	stream >> massa;
}
void Sportsman::Show(ostream &stream){
	stream << "Sportsman: " << endl << "Name: " << name << endl << "Age: " << age << endl << "Sport: " << sport << endl << "Massa: " << massa << endl;
}
Vector::Vector(){
	obj=NULL;
}
Vector::Vector(Person &p){
	obj=&p;
}

