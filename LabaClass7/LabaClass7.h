#include <iostream>
using namespace std;
struct I{
	int val;
	I *sled;
};
struct D{
	double val;
	D *sled;
};
struct C{
	char val;
	C *sled;
};
class Para{
	public:
		double val;
		int cel;
		double drob;
		Para *sled;
		void Complete(){cel=val;drob=val-cel;Show();}
		void Show(){cout << cel << ":" << drob << " ";}
};
template <class T> class Lister{
public:
	T *first;
	int len;
	Lister(){len=0;first=NULL;}
	Lister(T *f, int l){first=f;len=l;}
	Lister(Lister &l){first=l.first;len=l.len;}
	~Lister(){}
	double operator [](int index){
	bool b=0;
	T *cur=first;
	if(len>0){
	for (int i=0;i<index;i++){
		if (cur->sled!=NULL){
			cur=cur->sled;
		}
		else b=1;
	}
	}
	else b=1;
	if(b) return 0;
	else return cur->val;
}
int operator ()(){
	return len;
}
void operator *(int n){
		if(len>0){
	T *cur=first;
	while (cur->sled!=NULL){
		cur->val*=n;
		cur=cur->sled;
	}
	cur->val*=n;
}
}
	void Create(int r){
		if (r>0){
			len=1;
			first = new T;
			T *cur, *nov;
			cur=first;
			cur->sled=NULL;
			cout << "1: ";
			cin >> cur->val;
			for (int i=1;i<r;i++){
				len++;
				nov = new T;
				nov->sled=NULL;
				cur->sled=nov;
				cur=nov;
				cout << i+1 << ": ";
				cin >> cur->val;
			}
		}
	}
	void Show(){
		T *c=first;
		while (c->sled!=NULL){
			cout << c->val << " ";
			c=c->sled;
		}
		cout << c->val << endl;
	}
	void PShow(){
	T *c=first;
	while (c->sled!=NULL){
		c->Complete();
		c=c->sled;
	}
	c->Complete();
	}
};
