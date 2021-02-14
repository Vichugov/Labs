#include <fstream>
#include <iostream>
using namespace std;

void Set(){
	const int fon = system("Color F0");
	system("chcp 1251>nul");
}

int main(){
Set();	
int max=100,n1=0,n2=0,c=0,s=0,e=0,g=0,z=0;
char b [max];
bool a=false;
ifstream inf("filei.txt");
ofstream ouf("fileo.txt");
if (inf.is_open()) cout << "Файл успешно открыт для чтения. " << endl;
else cout << "Не удалось открыть файл. " << endl;
cout << "Введите номера пограничных строк. " << endl;
while (n1>=n2||n2-n1<2){
cin >> n1 >> n2;
if (n1>=n2||n2-n1<2) cout << "Неверный ввод! Введите значения повторно. " << endl;
}
while(!inf.eof()){
c++;
a=false;
inf.getline(b,max);
if (c>n1&&c<n2){
for (int i=0;i<max;i++) if (b[i]=='A'||b[i]=='a') a=true;
if (a==false){
cout << ++z <<". " <<  b << endl;
ouf << b << endl;
}
} 
}
inf.close();			
ouf.close();
ifstream two("fileo.txt");
if (two.is_open()) cout << "Второй файл успешно открыт для чтения. " << endl;
else cout << "Второй файл не удалось открыть для чтения. " << endl;
c=0;
while (!two.eof()){
	e=0;
	c++;
	two.getline(b,max);
	for (int i=0;i<max;i++)	if (b[i]=='a'||b[i]=='A'||b[i]=='e'||b[i]=='E'||b[i]=='I'||b[i]=='i'||b[i]=='o'||b[i]=='O'||b[i]=='q'||b[i]=='Q'||b[i]=='u'||b[i]=='U'||b[i]=='y'||b[i]=='Y') e++;
	if (e>s){
	s=e;
	g=c;
}
}
if (s!=0&&z!=0) cout << "Строка под номером " << g << " имеет наиобльшее количество гласных букв. " << endl;
else cout << "В строках данного файла отсутствуют гласные буквы. " << endl;
}
