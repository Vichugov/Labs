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
	cout << "�������� 1-�� ��������: " << endl;
	cin >> first->data;
			while (cin.fail()){
			cout << "������ ���� ������� �����! ��������� ����: " << endl;
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
		cout << "�������� " << i+1 << "-�� ��������: " << endl;
		cin >> cur->data;
		while (cin.fail()){
			cout << "������ ���� ������� �����! ��������� ����: " << endl;
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
	else if (cur==first) cout << "׸���� ������� �� ���������! " << endl;
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
	cout << "������� ���������� ��������� ������: " << endl;
	cin >> n;
	while(n<2){
		cout << "�������� ����! ������ ������ �������� ������� �� 2-� ���������! ��������� ����: " << endl;
		cin.clear();
		cin.ignore(30,'\n');
		cin >> n;
	}
	o=Create(n);
	Observe(o);
	o=Ubral(o);
	cout << "���������� ������ (����� ��������� ������ �������): " << endl;
	Observe(o);
	while (o->next!=NULL){
	u=o;
	o=o->next;
	delete u;
}
delete o;
	system("pause");
}
