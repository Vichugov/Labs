#include <iostream> 
using namespace std;
struct Q{
	int data;
	Q* sled;
};
int u=-1;
Q* Create(){
	int n;
	Q* cur, *first,*nov;
	first = new Q;
	first->sled=NULL;
	cur=first;
	cout << "���������� ��������� �������: " << endl;
	cin >> n;
	while (n<2||cin.fail()){
	cin.clear();
	cin.ignore(30,'\n');
	cout << "�������� ����! ���������� ��������� ������ �������� ������ � ����� �������� �� ����� 2! ��������� ����: " << endl;
	cin >> n;
	}	
	cout << "�������� 1-�� ��������: " << endl;
	cin >> first->data;
	while (cin.fail()){
	cin.clear();
	cin.ignore(30,'\n');
	cout << "�������� ����! ������� ������ �������� ����� ������! ��������� ����: " << endl;
	cin >> first->data;;
	}	
	if (first->data%2==0) u=0;
	for (int i=1;i<n;i++){
		nov= new Q;
		cur->sled=nov;
		cur=nov;
		cur->sled=NULL;
		cout << "�������� " << i+1 << "-�� ��������: " << endl;
	cin >> cur->data;
	while (cin.fail()){
	cin.clear();
	cin.ignore(30,'\n');
	cout << "�������� ����! ������� ������ �������� ����� ������! ��������� ����: " << endl;
	cin >> cur->data;
	}	
	if (cur->data%2==0) u=i;
	}
	return first;
}
void Observe(Q* first){
	Q* cur=first;
	int i=1;
	while (cur->sled!=NULL){
		cout << i++ << ". " << cur->data << endl;
		cur=cur->sled;
	}
	cout << i << ". " << cur->data << endl;
	
}
Q* Ubral(Q* first){
	Q* cur = first,*del,*pred;
	if (u==-1){
		cout << "� ������� ����������� ������ ��������. " << endl;
		return first;
	}
	else{
		for (int i=0;i<u;i++){
		pred = cur;
		cur=cur->sled;
		} 
		del=cur;
		if (cur->sled!=0) {
			cur=cur->sled;
			delete del;
			if (u!=0) pred->sled=cur;
			else first=cur;
		}
		else {
			delete del;
			pred->sled=NULL;
		}
	}
	return first;
}
void Set(){
	const int fon = system("Color F0");
	system ("chcp 1251>nul");
}
int main(){
	Set();
	Q* o = Create();
	Observe(o);
	o=Ubral(o);
	cout << "���������� �������: " << endl;
	Observe(o);
	system("pause");
	return 0;
}
