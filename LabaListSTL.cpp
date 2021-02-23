#include <iostream>
#include <list>
#include <iterator>
using namespace std;
list <int> List;
list <int> Nlist;
list <int>::iterator iter;
int u=0;
void Set(){
	const int fon = system("Color F0");
	system("chcp 1251>nul");
}
void Create(){
	int d=1;
	int i=1;
	cout << "Введите элементы списка. Чтобы завершить ввод, введите 0. " << endl;
	while (d!=0){
	cout << i++ << "-й элемент списка: " << endl;
	 cin >> d;
	 while (cin.fail()){
	 	cin.clear();
	 	cin.ignore(30,'\n');
	 	cout << "Должно быть введено число! Повторите ввод: " << endl;
	 	cin >> d;
	 }
	 if (d!=0) List.push_back(d);
	 if (d!=0&&d%2==0) u=d;
}
}	
int main(){
	Set();
	Create();	
	int i=1;
	cout << "Список: " << endl;
	copy(List.begin(), List.end(), 	ostream_iterator<int>(cout, " "));
	List.remove(u);
	cout << endl << "Обновлённый список (удалён последний чётный элемент): " << endl;
	copy(List.begin(), List.end(), 	ostream_iterator<int>(cout, " "));
	system("pause");
	return 0;
}
