#include<iostream>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
class Para{
	public:
		int a;
		double b;
		void Init(int i, double d) {a=i;b=d;}
		void Show(){cout << a << ':' << b << endl;}
		bool operator <(Para &p){if (a<p.a) return 1; else return 0;}
		Para& operator /=(Para &p){a/=p.a;b/=p.b;}
		Para& operator =(Para &p){a=p.a;b=p.b;}
};
template <class T> class Lister{
	public:
		T min,max,sred;
		typedef multiset <T> setter;
		setter s;
		typename setter::iterator i;
		Lister(){for (int e=0;e<10;e++) {s.insert(rand()*0.111);}}
		void Show(){cout << "Set: " << endl; for (i=s.begin();i!=s.end();i++) cout << *i << endl;}
		void Search(){
			i=s.begin();
			min=*i;
			max=*i;
			sred=0;
			for (i=s.begin();i!=s.end();i++){
				if (*i<min) min=*i;
				if (*i>max) max=*i;
				sred+=*i;
			}
			cout << "Minimum: " << min << endl;
			cout << "Maximum: " << max << endl;
		}
		void Pushmin(){s.insert(min);}
		void Lowsred(){
			sred/=s.size();
			cout << "Middle: " << sred << endl;
			i=s.begin();
			while(*i<sred){
				s.erase(i);
				i=s.begin();
			}
		}
		void Divide(){
			T temp;			
			for (i=s.begin();i!=s.end();i++){
				temp=*i/max;
				s.erase(i);
				s.insert(temp);
				i=s.begin();
				i=s.find(temp);
			}
			
		}
};
void One(){
	typedef multimap<int,float> maper;
	maper m;
	maper::iterator i;
	float min,max,sred;
	int e=1;
	for (int z=1;z<11;z++) m.insert(make_pair(z,rand()*0.36F));
	i=m.begin();
	min=i->second;
	max=i->second;
	for (i=m.begin();i!=m.end();i++){
		if(i->second<min){
			min=i->second;
			e=i->first;
		} 
		if(i->second>max) max=i->second;
		sred+=i->second;
		cout << i->second << endl;
	}
	cout << "Minimum: " << min << endl << "Maximum: " << max << endl;
	m.insert(make_pair(e,min));
	cout << "Multimap: " << endl;
	for (i=m.begin();i!=m.end();i++) cout << i->first << ' ' << i->second << endl;
	sred/=m.size();
	cout << "Middle: " << sred << endl;
	for (i=m.begin();i!=m.end();i++){
		if ((i->second)<sred){
		m.erase(i->first);	
		i=m.begin();
		} 
	}
	cout << "Multimap: " << endl;
	for (i=m.begin();i!=m.end();i++) cout << i->first << ' ' << i->second << endl;
	for (i=m.begin();i!=m.end();i++){i->second/=max;}	
	cout << "Multimap: " << endl;
	for (i=m.begin();i!=m.end();i++) cout << i->first << ' ' << i->second << endl;	
}
void Two(){
	typedef map<int,Para> maper;
	maper m;
	maper::iterator i;
	Para min,max,p;
	float sred;
	int position;
	for (int z=0;z<10;z++){
		p.Init(rand(),rand()*0.121);
		m.insert(make_pair(z,p));
		m[z].Show();
	} 
	i=m.begin();
	min=i->second;
	max=i->second;
	for (i=m.begin();i!=m.end();i++){
		if(i->second<min){
			min=i->second;
		} 
		if(max<i->second) max=i->second;
		sred+=i->second.a;
	}
	cout << "Minimum: "; min.Show(); cout << "Maximum: "; max.Show();
	cout << "Position (>size): "; cin >> position;
	while(cin.fail()||position<m.size()){
		cin.clear();
		cin.ignore(5,'\n');
		cout << "Position must be more than size of map. Repeat: "; cin >> position;
	}
	m.insert(make_pair(position,min));
	cout << "Map: " << endl;
	for (i=m.begin();i!=m.end();i++){
		cout << i->first << ' '; 
		i->second.Show();
	} 
	sred/=m.size();
	cout << "Middle: " << sred << endl;	
	for (i=m.begin();i!=m.end();i++){
		if ((i->second.a)<sred){
		m.erase(i->first);	
		i=m.begin();
		} 
	}	
	cout << "Map: " << endl;
	for (i=m.begin();i!=m.end();i++){
		cout << i->first << ' '; 
		i->second.Show();
	} 
	for (i=m.begin();i!=m.end();i++){i->second/=max;}	
	cout << "Map: " << endl;
	for (i=m.begin();i!=m.end();i++){
		cout << i->first << ' '; 
		i->second.Show();
	} 	
}
void Three(){
	Lister <double> l;
	l.Show();
	l.Search();
	l.Pushmin();
	l.Show();
	l.Lowsred();
	l.Show();
	l.Divide();
	l.Show();
}
main(){
	int s=1;
	while(s){
		cout << "1. Multimap; \n2. Map; \n3. Multiset with parameterized list. " << endl << "S: "; cin >> s;
		switch(s){
			case 1: One(); break;
			case 2: Two(); break;
			case 3: Three(); break;
		}
	}
	return 0;
}
