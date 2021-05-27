#include "LabaClass10.cpp"
void Init(Para &p, int c, float d){
	p.a=c;
	p.b=d;
}
ifstream& operator >>(ifstream &ist, Para &p){
	int cel;
	char sim;
	float drob;
	ist >> cel >> sim >> drob;
	Init(p,cel,drob);
	return ist;
}
ofstream& operator <<(ofstream &ost, Para &p){
	ost << p.RetA() << ':' << p.RetB() << ' ';
}
void Infile(){
	Para para;
	para.Input();
	ifstream ifile("file.txt");
	char getter[100];
	ifile.getline(getter,100);
	ofstream ofile("file.txt", ios::ate);
	ofile << getter;
	ofile << para;
	ofile.close();
}
void Fromfile(){
	Para para;
	bool esho=1;
	ifstream ifile("file.txt");
	while(esho){
	ifile >> para;
	para.Show();
	cout << "Continue? (1/0) " << endl; cin >> esho;
	}
	ifile.close();
}
void Remove(){
	ifstream ifile("file.txt");
	ofstream ofile("file1.txt");
	Para para;
	char big[60];
	int a,b;
	cout << "From: "; cin >> a;
	cout << "To: "; cin >> b;
	b+=2;
	int i=1;
	while (i<a){
		ifile >> para;
		ofile << para;
		i++;
	}
	for (int e=a;e<b;e++) ifile.getline(big,50,' ');
	while(!ifile.eof()){
		ifile >> para;
		if(para.RetA()&&para.RetB())
		ofile << para;
	}
	ifile.close();
	ofile.close();
	ifile.open("file1.txt");
	ofile.open("file.txt");
	while(!ifile.eof()){
		ifile >> para;
		if(para.RetA()&&para.RetB())
		ofile << para;
	}
	ifile.close();
	ofile.close();
}
void Redaktor(){
	ifstream ifile("file.txt");
	ofstream ofile("file1.txt");
	Para para;
	while (!ifile.eof()){
		ifile >> para;
		para=para*2;
		if(para.RetA()&&para.RetB())
		ofile << para;
	}
	ifile.close();
	ofile.close();
	ifile.open("file1.txt");
	ofile.open("file.txt");
	while(!ifile.eof()){
		ifile >> para;
		if(para.RetA()&&para.RetB())
		ofile << para;
	}
	ifile.close();
	ofile.close();
}
main(){
	ofstream o("file.txt");
	o << '\r';
	o.close();
	int s=1;
	bool full=0;
	while(s){
		cout << "1. Output in file; \n2. Input from file; \n3. Remove elements; \n4. Edit elements; \n5. Close the programm. " << endl;
		cin >> s;
		switch(s){
			case 1: Infile(); full=1; break;
			case 2: if(full) Fromfile(); else cout << "File is empty! "; break;
			case 3: if(full) Remove(); else cout << "File is empty! "; break;
			case 4: if(full) Redaktor(); else cout << "File is empty! "; break;
			case 5: s=0;break;
			default: cout << "Command if not detected. Repeat the attempt. " << endl; break;
		}
	}
	return 0;
}
