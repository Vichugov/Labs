#include <iostream>
#include <string>
using namespace std;
class Person{
	public:
	string name;
	int age;
	virtual void Init(istream& stream)=0;
	virtual void Show(ostream& stream)=0;
};
class Teacher:public Person{
	public:
		string subject;
		int hours;
		Teacher();
		Teacher(string n, string s, int a, int i);
		Teacher(Teacher &t);
		void Init(istream& stream);
		void Show(ostream& stream);
};
class Sportsman:public Person{
	public:
		string sport;
		int massa;
		Sportsman();
		Sportsman(string n, string s, int a, int i);
		Sportsman(Sportsman &s);
		void Init(istream& stream);
		void Show(ostream& stream);
};
class Vector{
	public:
	Person *obj;
	Vector();
	Vector(Person &p);
	friend istream& operator >>(istream& ist, Vector &v);
	friend ostream& operator <<(ostream &ost, Vector &v);
};
