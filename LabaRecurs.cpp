#include <iostream>
#include <cmath>
using namespace std;

double Exponentor(double n, double e){
	   n--;
	if (n>0)
e=e*Exponentor(n,e);
	return e;
}

int main(){
	const int fon = system ("color F0");
	setlocale (LC_ALL, "Russian");
	double n,e;
	cout.precision(100);
	cout << "������� �������� ���������� (0<n<10001). " << endl;
	cin >> n;
	if (n>0&&n<10001){
	e=1+1/n;
	cout << "���������: e=" << Exponentor(n, e) << endl;;
}
else cout << "�������� ����! " << endl;
system("pause");
}
