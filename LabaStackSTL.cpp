#include <iostream>
#include <stack>
using namespace std;

stack <char> s, b;
int n;
char e;
void Create(){
	cout << "����������� �����: " << endl;
	cin >> n;
	while (n<1||cin.fail()){
		cin.clear();
		cin.ignore(30,'\n');
		cout << "����������� ����� ������ �������� ������ � ����� �������� �� ����� 1! ��������� ����: ";
		cin >> n;
	}
	for (int i=0;i<n;i++){
	cout << i+1 << "-� �������: ";
	cin >> e;
	while (cin.fail()){
		cout << "������� ������ ��������� ������ 1 ������! ��������� ����! " << endl;
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
	cout << "����� ������������ ��������, ������� � ������� ����������: ";
	cin >> p;
	while (p>n+1||p<1||cin.fail()){
		cin.clear();
		cin.ignore(30,'\n');
		cout << "����� ������������ �������� ������ ����� ��������� ��������, ���� ������������� � �� ������ ��������� ����������� ����� ����� ��� �� 1! ��������� ����: ";
		cin >> p;
	}
	for (int i=0;i<n-p+1;i++){
		b.push(s.top());
		s.pop();
	}
	cout << "�������� ������ ��������: " ;
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
