#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int d, r, *m,s;
bool est;
void RanCreate(){
	srand(time(0));
	for (int i=0;i<r;i++){
		m[i]=rand()%100;
		cout << m[i] << " ";
	}
	cout << endl;
	est=1;
}
void UserCreate(){
	for (int e=0;e<r;e++){
	cout << e+1 << "-� �������: ";
	cin >> m[e];
}
est=1;
}
void Shell(){
	int d=r/2, nom,min;
	while (d>0){
		for (int i=0;i<r;i+=d){
			min=m[i];
			nom=i;
			for (int e=i;e<r;e+=d){
				if (m[e]<min){
					min=m[e];
					nom=e;
				}
			}
			if (min<m[i]){
			m[nom]=m[i];
			m[i]=min;
			}
		}
		for (int i=0; i<r;i++)	cout << m[i] << " ";
		cout << endl;
		d/=2;
	}
}
void Hoar(int l, int ri){
	int h,sl=l,sr=ri,o=(ri-l)/2+l;
		if (l<ri){
		while (l!=ri&&ri-l>1){		
			while (m[l]<=m[o]&&l<o) l++;
			while (m[ri]>=m[o]&&ri>o) ri--;
			h=m[l];m[l]=m[ri];m[ri]=h;
			if ((ri==o||l==o)&&l!=ri) {
				l=sl;ri=sr;
			}
			for (int i=0; i<r;i++)	cout << m[i] << " ";
			cout << endl;
		}	
	if ((sr-sl)>1){
	Hoar(sl,o);
	Hoar(o,sr);
}
	}
}
void Set(){
	setlocale(LC_ALL, "Russian");
	const int fon = system("Color F0");
}
int main(){
	Set();
	cout << "����������� �������: ";
	cin >> r;
	while (cin.fail()||r<2){
		cout << "����������� ������� ������ ����� �������� �� ����� 2! ��������� ����: ";
		cin.ignore(30,'\n');
		cin.clear();
		cin >> r;
	}
	m= new int [r];
	s=1;
	while (s){
	cout << "0. ��������� ������ ���������; \n1. ������� ��������� ������; \n2. ������� ������ ��������������; \n3. ����������� ������ ������� �����; \n4. ����������� ������ ������� �����. " << endl;
	cin >> s;
	switch(s){
		case 0: return 0; break;
		case 1: RanCreate(); break;
		case 2: UserCreate(); break;
		case 3: if (est) Shell(); else cout << "������ �� ������. " << endl; break;
		case 4: if (est) Hoar(0,r-1); else cout << "������ �� ������. " << endl; break;
			default: cout << "�������� ����! " << endl; return 0;
	}
}
	delete[] m;
}
