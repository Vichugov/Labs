#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Stadion{
	string name;
	string adres;
	string mest;
	string sports;
};
Stadion S[10];
int n=0;
string d;
bool b=false;
void Set(){
	const int fon = system("Color F0");
	system ("chcp 1251>nul");
}
void Vvod(){
cout << "������� ���������� ����������� ���������. " << endl;
while (n<2){
cin >> n;	
if (n<2) cout << "����� ��������� ������ ���� > 1! ��������� ����. " << endl;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i=0;i<n;i++){
		cout << "������� �������� ��������: " << endl;
		getline (cin, S[i].name);
		cout << "������� ����� ��������: " << endl;
		getline (cin, S[i].adres);
		while (b==false){
		b=true;
		cout << "������� ����������� ��������: " << endl;
		cin >> S[i].mest;		
		for (int z=0;z<S[i].mest.length();z++){
			if (S[i].mest[z]<'0' || S[i].mest[z]>'9') b=false;
		}
			if (b==false) cout << "�������� ����: ������� �� �����. " << endl;
		}
		b=false;
		cout << "������� ���������� ���� ������: " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline (cin, S[i].sports);
	}
}
void Vivod(int o){
	cout << "������ ���������: " << endl;
	for (int i=0;i<o;i++){
		cout << "��������: " << S[i].name << endl;
		cout << "�����: " << S[i].adres << endl;
		cout << "�����������: " << S[i].mest << endl;
		cout << "���������� ���� ������:" << S[i].sports << endl;
	}	
}
int main(){
	Set();
	Vvod();
	cout << "������� �������� ��������, ������ �������� ���������� ������� �� ������. " << endl;
	int e=0;
	getline (cin, d);	
	while (S[e].name!=d){
		e++;
	}
	for (int i=e; i<n; i++){
		S[i]=S[i+1];
	}
	Vivod(n-1);
	cout << "������� ���������� ����� ��������, ����� �������� � ������ ���������� �������� �������� (��������� ��������� ���������� � 0). " << endl;
	e=-1;	
	while (e<0||e>n-2){
		cin >> e;
		if (e<0||e>n-2) cout << "���������� ����� �������� ������ ���� ������ -1 � ������ ���������� ��������� � ������! ��������� ����. " << endl;
	}
	for (int i=n-2;i>e;i--){
		S[i+2]=S[i];
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ������ ����������� ���������: " << endl;
		for (int i=e+1;i<e+3;i++){
		cout << "������� �������� ��������: " << endl;
		getline (cin, S[i].name);
		cout << "������� ����� ��������: " << endl;
		getline(cin, S[i].adres);
		while (b==false){
		b=true;
		cout << "������� ����������� ��������: " << endl;
		cin >> S[i].mest;
		for (int z=0;z<S[i].mest.length();z++){
			if (S[i].mest[z]<'0' || S[i].mest[z]>'9') b=false;
		}
			if (b==false) cout << "�������� ����: ������� �� �����. " << endl;
		}
		b=false;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������� ���������� ���� ������: " << endl;
		getline(cin, S[i].sports);
	}
	Vivod(n+1);
}
