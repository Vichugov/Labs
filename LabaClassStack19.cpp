#include<iostream>
using namespace std;
struct Element{
	char* string;
	Element *bottom;
};
class Stacker{
	public: 
	int volume;
	Element *top;
	Stacker(){volume=0;top=NULL;}
	Element* Top(){return top;}
	Element* Pop(){Element *temp;temp=top;top=top->bottom;delete temp;volume--;return top;}
	Element* Push(Element *get){get->bottom=top;top=get;volume++;return top;}
	void Show(){
	Element *current=top;
	while(current->bottom!=NULL){
		cout << current->string << endl;
		current=current->bottom;
	}
	cout << current->string << endl;
	}
};
void Add(Stacker *z){
	int number;
	Stacker *t = new Stacker;
	Element *e = new Element;
	cout << "Enter the number of added element: "; cin >> number;
	while(number<1||number>z->volume+1||cin.fail()){
		cout << "Number must be >0 and do not must exceed size of stack more then 1! Repeat input: "; cin.ignore(5,'\n');cin.clear();cin >> number;
	}
	number=z->volume-number+1;
	for (int i=0;i<number;i++){
		Element *k = new Element;
		k->string=(z->Top())->string;
		t->Push(k);
		z->Pop();
	}
	cout << "Field of element: "; 
	cin.ignore(5,'\n');
	e->string = new char[20];
	cin.getline(e->string,20);
	z->Push(e);
	for (int i=0;i<number;i++){
		Element *k = new Element;
		k->string=(t->Top())->string;
		z->Push(k);
		t->Pop();
	}
	z->Show();
}
main(){
	Stacker *s = new Stacker;
	int n;
	cout << "Size of stack: "; cin >> n;
		while(n<1||cin.fail()){
		cout << "Size of stack must be >0! Repeat input: "; cin.ignore(5,'\n');cin.clear();cin >> n;
	}
	cin.ignore(5,'\n');
	for (int i=0;i<n;i++){
		Element *e = new Element;
		cout << i+1 << ": ";
		e->string = new char[20];
		cin.getline(e->string,20);
		s->Push(e);
	}
	s->Show();
	Add(s);
	delete s;
}
