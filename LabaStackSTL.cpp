#include <iostream>
#include <stack>
using namespace std;

stack <char> s, b;
int n;
char e;
void Create(){
	cout << "Размерность стека: " << endl;
	cin >> n;
	while (n<1||cin.fail()){
		cin.clear();
		cin.ignore(30,'\n');
		cout << "Размерность стека должна являться числом и иметь значение не менее 1! Повторите ввод: ";
		cin >> n;
	}
	for (int i=0;i<n;i++){
	cout << i+1 << "-й элемент: ";
	cin >> e;
	while (cin.fail()){
		cout << "Элемент должен содержать только 1 символ! Повторите ввод! " << endl;
		cin.clear();
		cin.ignore(30,'\n');
		cin >> e;
	}
	s.push(e);
	}
}
void Observe(){
	int i=0;
	while (!s.empty()){
		cout << n-i++ << ". " << s.top() << endl;
		b.push(s.top());
		s.pop();
	}
	while (!b.empty()){
		s.push(b.top());
		b.pop();
	}
}
void Nov(){
	int p;
	cout << "Номер добавляемого элемента, начиная с первого пришедшего: ";
	cin >> p;
	while (p>n+1||p<1||cin.fail()){
		cin.clear();
		cin.ignore(30,'\n');
		cout << "Номер добавляемого элемента должен иметь численное значение, быть положительным и не должен превышать размерность стека более чем на 1! Повторите ввод: ";
		cin >> p;
	}
	for (int i=0;i<n-p+1;i++){
		b.push(s.top());
		s.pop();
	}
	cout << "Значение нового элемента: " ;
	cin >> e;
	s.push(e);
	for (int i=0;i<n-p+1;i++){
		s.push(b.top());
		b.pop();
	}
	n++;
}
void Set(){
	const int fon = system("Color F0");
	system("chcp 1251>nul");
}
int main(){
Set();
Create();
Observe();	
Nov();
Observe();
}
