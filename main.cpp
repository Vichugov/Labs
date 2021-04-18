#include <iostream>
#include "LabaClass1.cpp"
using namespace std;
Para Maker(){
	Para a;
	a.Init(2,0.5);
	return a;
}
main(){
	Para b = Maker();
	b.Show();
 Para p;
 p.Read();
 p.Show();
 p.Calc(5);
 return 0;
}
