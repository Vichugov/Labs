#pragma once
using namespace std;
class Bank{
	int id;
	double count;
	double max;
	public:	
	int *s;
	Bank();
	Bank(int, double, double);
	Bank(Bank&);
	void Init(int, double, double);
	void Show();
	~Bank();
	int BI();
	double BC();
	double BM();
};

