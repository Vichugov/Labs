#include <iostream>
#include "LabaClass1.cpp"
using namespace std;
Para Maker(int c, float d){
	Para a;
	a.Init(c,d);
	return a;
}
main(){
	Para b = Maker(2,0.5);
	b.Show();
 Para p;
 p.Read();
 p.Show();
 p.Calc(5);
 return 0;
}
