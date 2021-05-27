#pragma once
#include<iostream>
using namespace std;
class Para{
	int a;
	float b;
	int *u;
	public:
		Para();
		Para(int c, float d);
		Para(Para &p);
		friend void Init(Para& p, int c, float d);
		void Show();
		int RetA();
		float RetB();
		Para& operator =(Para &p); // Объявил перегрузку операции присваивания, которая возвращает адресс объекта класса Para и принимает в качестве аргумента объект этого класса.
		friend istream& operator >>(istream &ist, Para &p); // Возвращает объект класса istream (например, cin) и принимает объект этого класса, а также объект класса Para.
		friend ostream& operator <<(ostream &os, Para &p); // Эту перегрузку я сделал без приёма объекта класса ostream, потому что точно буду использовать cout.
		bool operator !=(Para &p); // Эта функция будет принимать объект класса Para  сравнивать его поля с поляим this объекта. Если поля не равны, то вернёт 1, иначе 0.
		bool operator ==(Para &p);
		Para& operator -(int value);
		Para& operator -(float value);
		~Para();
};
