#include <iostream>
#include "LabaClass2.h"
using namespace std;
void Bank::Init(int i, double c, double m){
	id = i;
	count=c;
	max=m;
}
void Bank::Show(){cout << "ID: " << id << endl << "Count: " << count << endl << "Limit: " << max << endl;}
int Bank::BI(){return id;}
double Bank::BC(){return count;}
double Bank::BM(){return max;}
Bank::Bank(){
	s=NULL;
	id=0;
	count=10;
	max=5;
}
Bank::Bank(int i, double c, double m){
	id=i;
	count=c;
	max=m;
	s=NULL;
}
Bank::Bank(Bank &b){
	count=b.BC();
	max=b.BM();
	id=b.BI();
	s=NULL;
}
Bank::~Bank(){
	delete s;
}
