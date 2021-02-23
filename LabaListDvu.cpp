#include <iostream>
using namespace std;
struct List{
	int data;
	List* pred,*next;
};
List* Create(int n){
	List* first = new List,*cur,*nov;
	first->pred=NULL;
	first->next=NULL;
	cout << "Значение 1-го элемента: " << endl;
	cin >> first->data;
			while (cin.fail()){
			cout << "Должно быть введено число! Повторите ввод: " << endl;
			cin.clear();
			cin.ignore(30,'\n');
			cin >> first->data;
		}
	cur = first;
	for (int i=1;i<n;i++){
		nov = new List;
		cur->next=nov;
		nov->pred=cur;
		cur=nov;
		cout << "Значение " << i+1 << "-го элемента: " << endl;
		cin >> cur->data;
		while (cin.fail()){
			cout << "Должно быть введено число! Повторите ввод: " << endl;
			cin.clear();
			cin.ignore(30,'\n');
			cin >> cur->data;
		}
		cur->next=NULL;
	}
	return first;
}
void Observe(List* first){
	List * cur=first;
	int i=1;
	while (cur->next!=NULL){
		cout << i++ << ". " << cur->data << endl;
		cur=cur->next;
	}
	cout << i++ << ". " << cur->data << endl;
}
List* Ubral(List* first){
	List* cur=first;
	while (cur->next!=NULL) cur=cur->next;
	while (cur->data%2!=0&&cur->pred!=NULL)	cur=cur->pred;
	if (cur==first&&cur->data%2==0){
		 first=cur->next;
		 delete cur;
	}
	else if (cur==first) cout << "Чётный элемент не обнаружен! " << endl;
	else{
		cur->pred->next=cur->next;
		delete cur;
	}
	return first;
}
void Set(){
	const int fon = system("Color F0");
	system("chcp 1251>nul");
}
int main(){
	Set();
	List* o,*u;
	int n;
	cout << "Введите количество элементов списка: " << endl;
	cin >> n;
	while(n<2){
		cout << "Неверный ввод! Список должен состоять минимум из 2-х элементов! Повторите ввод: " << endl;
		cin.clear();
		cin.ignore(30,'\n');
		cin >> n;
	}
	o=Create(n);
	Observe(o);
	o=Ubral(o);
	cout << "Обновлённый список (удалён последний чётный элемент): " << endl;
	Observe(o);
	while (o->next!=NULL){
	u=o;
	o=o->next;
	delete u;
}
delete o;
	system("pause");
}
