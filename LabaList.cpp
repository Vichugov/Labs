#include <iostream>
using namespace std;
struct List{
	char data[30];
	List* next;
};
List* Create(int n){
	List* cur,*nlist;
	List* first = new List;
cur=first;
	for (int i=0;i<n;i++){
		nlist = new List;
		cout << "������ " << i+1 << "-�� �������� ������: " << endl;
		cin >> cur->data;
		cur->next=nlist;
		cur=nlist;
		cur->next=NULL;
	}
	return first;
}
void Observe(List* first){
	List* cur = first;
	int i=1;
	while (cur->next!=NULL){
		cout << i << ". " << cur->data << endl;
		cur=cur->next;
		i++;
	}
}
void Set(){
	const int fon = system("Color F0");
	system("chcp 1251>nul");
}
List* Dobav(List* first,int n){
	List * current=first, *nov=new List,*sled;
	cout << "������ ������ ��������: " << endl;
	cin >> nov->data;
	if (n==1){
	 nov->next=first;
	 return nov;
	}
	else{
	for (int i=2;i<n;i++)	current=current->next;
	if (current->next!=NULL){
	sled=current->next;
	current->next=nov;
	nov->next=sled;
}
else{
	current->next=nov;
	nov->next=NULL;
}
	return first;
}
}
int main(){
	Set();
	int n,d;
	List* o, *u;
	cout << "������� ���������� ��������� ������. " << endl;
	cin >> n;
	while (n<1){
		if (cin.fail()){
		cin.clear();
		cin.ignore(30,'\n');
		} 
		cout << "�������� ����! ������ ������ ����� ������� 1 �������! ��������� ����. " << endl;
		cin >> n;
	}		
	
o=Create(n);
Observe(o);
cout << "������� ���������� ����� ������������ ��������. " << endl;
cin >> d;
while (d<1||d>n+1){
	if (cin.fail()){
		cin.clear();
		cin.ignore(30,'\n');
	}
	cout << "����� �������� ������ ���� ������ 0 � �� ������ ��������� ���������� ��������� � ������ ����� ��� �� 1. ��������� ����. " << endl;
	cin >> d;
}
o=Dobav(o, d);
Observe(o);
while (o->next!=NULL){
	u=o;
	o=o->next;
	delete u;
}
delete o;
system("pause");
return 0;
}
