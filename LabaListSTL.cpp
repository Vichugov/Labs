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
	cout << "������� �������� ������. ����� ��������� ����, ������� 0. " << endl;
	while (d!=0){
	cout << i++ << "-� ������� ������: " << endl;
	 cin >> d;
	 while (cin.fail()){
	 	cin.clear();
	 	cin.ignore(30,'\n');
	 	cout << "������ ���� ������� �����! ��������� ����: " << endl;
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
	cout << "������: " << endl;
	copy(List.begin(), List.end(), 	ostream_iterator<int>(cout, " "));
	List.remove(u);
	cout << endl << "���������� ������ (����� ��������� ������ �������): " << endl;
	copy(List.begin(), List.end(), 	ostream_iterator<int>(cout, " "));
	system("pause");
	return 0;
}
