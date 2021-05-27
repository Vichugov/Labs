#include <iostream>
using namespace std;
struct S{
	int val;
	S *sled, *pred;
};
class Lister{
	public:
		S *first, *last;
		int len;
		Lister();
		Lister(S *f, S *l);
		Lister(Lister &l);
		~Lister();
		void Create(int r);
		int operator [](int index);
		int operator ()();
		void operator *(int n);
		friend ostream& operator <<(ostream& ost, Lister &l);
};
class Iterator{
	public:
	Lister *list;
	S *cur;
	Iterator();
	Iterator(Lister *l);
	Iterator(Iterator &i);
	~Iterator();
	S* operator -(int n);
	S* operator --();
	S* operator ++();
};
