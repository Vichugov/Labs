#include "LabaClass5.cpp"
istream& operator >>(istream &ist, Person *obj){
	obj->Init(ist);
}
ostream& operator <<(ostream &ost, Person *obj){
	obj->Show(ost);
}
istream& operator >>(istream &ist, Vector &v){
	v.obj->Init(ist);
}
ostream& operator <<(ostream &ost, Vector &v){
	v.obj->Show(ost);
}
main(){
	Teacher fteacher;
	cout << &fteacher;
	cin>>&fteacher;
	Vector v(fteacher);
	cout << v;
	Sportsman fs;
	v.obj=&fs;
	cin >> v;
	cout << v;
	return 0;
}
