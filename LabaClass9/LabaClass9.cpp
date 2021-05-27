#include "LabaClass9.h"
#include <string>
class Error{
	public:
		string s;
		Error(string arg){s=arg;}
};
class Err{
	public:
		string s;
		void Er(){cout << s << endl;}
};
class RError:public Err{
	public:
		RError(){
			s="Incorrect size of list! ";
		}
};
class IntError:public Err{
	public:
		IntError(){
			s="No number entered! ";
		}
};
Lister::Lister(){len=0;first=NULL;last=NULL;}
Lister::Lister(S *f, S *l){first=f;last=l;}
Lister::Lister(Lister &l){first=l.first;last=l.last;len=l.len;}
Lister::~Lister(){}
void Lister::Create(int r){
	if (r<1) throw RError();
	else{
		len=1;
		first = new S;
		first->pred=NULL;
		first->sled=NULL;
		S* cur=first;
		S* nov=NULL;
		cout << "1: ";
		cin >> cur->val;
		if (cin.fail()) throw IntError();
	for (int i=1;i<r;i++){
		len++;
		nov = new S;
		nov->pred=cur;
		nov->sled=NULL;
		cur->sled=nov;
		cur=nov;
		cout << i+1 << ": ";
		cin >> cur->val;
		if (cin.fail()) throw IntError();
	}
	last=cur;
}
}
int Lister::operator()(){
return len;
}
int Lister::operator [](int index){
	bool b=0;
	S *cur=first;
	if(len>index){
	for (int i=0;i<index;i++){
		if (cur->sled!=NULL){
			cur=cur->sled;
		}
		else b=1;
	}
}
else b=1;
	if(b) throw Error("Error: the element with this index does not exist! ");
	else return cur->val;
}
void Lister::operator *(int n){
	if(len>0){
	S *cur=first;
	while (cur->sled!=NULL){
		cur->val*=n;
		cur=cur->sled;
	}
	cur->val*=n;
}
}
Iterator::Iterator(){list=NULL;cur=NULL;}
Iterator::Iterator(Lister *l){list=l;cur=l->first;}
Iterator::Iterator(Iterator &i){list=i.list;cur=i.cur;}
Iterator::~Iterator(){}
S* Iterator::operator -(int n){
	if (cur!=NULL)
	for (int i=0;i<n;i++){
		if(cur->pred!=NULL) cur=cur->pred;
	}
	return cur;
}
S* Iterator::operator --(){
	if (cur!=NULL&&cur->pred!=NULL) cur=cur->pred;
	return cur;
}
S* Iterator::operator ++() {
	if (cur!=NULL&&cur->sled!=NULL) cur=cur->sled;
	return cur;
}

