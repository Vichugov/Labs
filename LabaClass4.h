#include <iostream>
#include <string>
using namespace std;
class Person{
	public:	
	string name;
	int age;
		Person();
		Person(string n, int a);
		Person(Person &p);
		~Person();
		void Init(string n, int a);
		virtual void Show();
		string RName();
		int RAge();
		friend istream& operator >>(istream &ist, Person &p);
		friend ostream& operator <<(ostream &ost, Person &p);
		Person& operator =(Person &p);
};
class Teacher: public Person{
	private: 
	string pred;
	int hours;
	public:
	Teacher();
	Teacher(string pr, int h);
	Teacher(Teacher& t);
	~Teacher();
	string RPred();
	int RHour();
	void TInit();
	void Show();
	Teacher& operator =(Person &p);
};
