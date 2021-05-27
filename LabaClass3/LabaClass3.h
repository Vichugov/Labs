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
		Para& operator =(Para &p); // ������� ���������� �������� ������������, ������� ���������� ������ ������� ������ Para � ��������� � �������� ��������� ������ ����� ������.
		friend istream& operator >>(istream &ist, Para &p); // ���������� ������ ������ istream (��������, cin) � ��������� ������ ����� ������, � ����� ������ ������ Para.
		friend ostream& operator <<(ostream &os, Para &p); // ��� ���������� � ������ ��� ����� ������� ������ ostream, ������ ��� ����� ���� ������������ cout.
		bool operator !=(Para &p); // ��� ������� ����� ��������� ������ ������ Para  ���������� ��� ���� � ������ this �������. ���� ���� �� �����, �� ����� 1, ����� 0.
		bool operator ==(Para &p);
		Para& operator -(int value);
		Para& operator -(float value);
		~Para();
};
