#include "LabaClass6.cpp"
ostream& operator << (ostream& ost, Lister &l){
	S* cur=l.first;
	while(cur->sled!=NULL){
		ost << cur->val << " ";
		cur=cur->sled;
	}
	ost << cur->val << endl;
	return ost;
}
main(){
	Lister cont;
	cont.Create(-7);
	cont.Create(5);
	cout << cont;
	cout << cont[3] << endl;
	cout << "Length: " << cont() << endl;
	Iterator ter(&cont);
	++ter;
	cout << ter.cur->val << endl;
	--ter;
	cout << ter.cur->val << endl;
	++ter;
		++ter;
			++ter;
				++ter;
	ter-2;
	cout << ter.cur->val << endl;
	return 0;
}
