#include "LabaClass7.h"
main(){
	Lister <I> Ilist;
	Lister <D> Dlist;
	Lister <C> Clist;
	Lister <Para> Plist;
	Ilist.Create(5);
	Dlist.Create(4);
	Clist.Create(3);
	Plist.Create(2);
	cout << Ilist[4] << " " << Dlist[3] << " " << Clist[2] << " " << Plist[1] << endl;
	cout << Ilist() << ' ' << Dlist() << ' ' << Clist() << ' ' << Plist() << endl;
	Ilist*3;
	Dlist*2;
	Plist*5;
	Ilist.Show();
	Dlist.Show();
	Clist.Show();
	Plist.PShow();
}
