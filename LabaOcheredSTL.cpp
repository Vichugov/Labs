#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
int n,e,u=-1;
int* a;
void Create(){
	cout << "Количество элементов очереди: " ;
	cin >> n;
	while (n<2||cin.fail()){
		cout << "Количество элементов должно являться числом и быть не менее 2-х. Повторите ввод: " ;
		cin.clear();
		cin.ignore(30,'\n');
		cin >> n;
	}
	a = new int [n];
	for (int i=0;i<n;i++){
		cout << i+1 << "-й элемент очереди: " << endl;
		cin >> e;
		while (cin.fail()){
			cout << "Введённое значение должно быть числом! Повторите ввод: " ;
			cin.clear();
			cin.ignore(30,'\n');
			cin >> e;
		}
		q.push(e); 
		a[i]=e;
		if (e%2==0) u=i;
	}
}
void Observe(){
	for (int i=0;i<n;i++){
		cout << i+1 << ". " << q.front() << endl;
		q.pop();
	}
}
void Ubral(){	 
	 for (int i=0;i<n;i++) if (i!=u) q.push(a[i]);
	 if (u==-1) cout << "В очереди отсутствуют чётные элементы. " << endl;
	 else n--;
}
	
void Set(){
	const int fon = system("Color F0");
	system ("chcp 1251>nul");
}
int main(){
	Set();
	Create();
	Observe();
	Ubral();
	cout << "Обновлённая очередь: " << endl;
	Observe();
}
