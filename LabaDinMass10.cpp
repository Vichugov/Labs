#include <iostream>
#include <cstdlib>
using namespace std;
void Set(){
	const int fon = system("Color F0");
	setlocale (LC_ALL, "Russian");
}
int main(){
	Set();
	int n,m,a=100,d,c,j=0,z=0;
	cout << "Введите количество строк и столбцов массива. " << endl;
	cin >> n >> m;
	while (n<2||m<2){
	cout << "Количество строк и столбцов должно быть больше 1! Повторите ввод. " << endl;
	cin >> n >> m;
	}
	int **mass = new int *[n];
	for (int i=0;i<n;i++) mass[i] = new int [m];
	for (int i=0;i<n;i++){
		for (int e=0;e<m;e++){
			mass[i][e]=rand()%100;
			cout << mass[i][e] << " ";
			if (mass[i][e]<10) cout << " ";
			if (mass[i][e]<a){
				d=i;
				c=e;
				a=mass[i][e];
			}
		}
		cout << endl;
	}
	cout << "Минимальный элемент: " << a << " Строка: " << d+1 << " Столбец: " << c+1 << endl;
	int **bass = new int *[n-1];
	for (int i=0;i<n-1;i++) bass[i]=new int [m-1];
	for (int i=0;i<n;i++){
		for (int e=0;e<m;e++){
			if(e!=c&&i!=d){
			bass[j][z]=mass[i][e];
			z++;
		}
		}
		if(i!=d) j++;
		z=0;
	}
	cout << "Изменённый массив: " << endl;
	for (int i=0;i<n-1;i++){
		for (int e=0;e<m-1;e++){
			cout << bass[i][e] << " ";
			if (bass[i][e]<10) cout << " ";
		}
		cout << endl;
	}
	for (int i=0;i<n;i++) delete mass[i];
	delete[] mass;
	for (int i=0;i<n-1;i++) delete bass[i];
	delete[]bass;
	cout << "Память освобождена. " << endl;
}
