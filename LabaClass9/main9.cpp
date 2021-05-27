#include "LabaClass9.cpp"
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
	try{	
	Lister l;
	int n;
	cout << "Enter the size of container: "; cin >> n; if (cin.fail()||n<1) throw 1;
	l.Create(n);
	cout << l() << endl;
	cout << l[3] << endl;
	cout << l << endl;
	}
	catch (int){
		cout << "Error was detected. " << endl;
		return 0;
	}
	catch(Error e){
		cout << e.s << endl;
		return 0;
	}
	catch(Err e){
		e.Er();
		return 0;
	}
}
