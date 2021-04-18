#include"LabaClass3.h"
Para::Para(){
	a=0;
	b=0.0F;
		u=NULL;
}
Para::Para(int c, float d){
	a=c;
	b=d;
	u=NULL;
}
Para::Para(Para &p){
 a=p.RetA();
 b=p.RetB();
 	u=NULL;
}
Para::~Para(){
	delete u;
}
int Para::RetA() {return a;}
float Para::RetB() {return b;}
void Para::Show(){cout << "Numbers: " << a << ":" << b << endl;}
Para& Para::operator =(Para &p){
	a=p.RetA();
	b=p.RetB();
	return *this;
}
bool Para::operator !=(Para &p){
	if (a!=p.RetA()&&b!=p.RetB()) return 1;
	else return 0;
}
bool Para::operator ==(Para &p){
	if (a==p.RetA()&&b==p.RetB()) return 1;
	else return 0;
}
Para& Para::operator -(int value) {a-=value;return *this;}
Para& Para::operator -(float value) {b-=value;return *this;}
