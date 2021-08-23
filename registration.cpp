#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string path = "myFile.txt";
	ofstream fout;
	fout.open(path, ofstream::app);
	
	string vvodpolzovanelya;
	cout<<"Если вы зарегестрированы, то введите «зарегестрирован». Если вы ещё не зарегестрированы, то введите «‎не зарегестрирован»."<<endl;
	cin>>vvodpolzovanelya;
	if (vvodpolzovanelya=="не зарегестрирован")
	{
		cout<<"Придумайте пароль и логин."<<endl;
		cout<<"Пример: Логин:kombo2003 Пароль:12345678"<<endl;
		string a, b;
		cout<<"Придумайте логин: ";
		cin>>a;
		cout<<"Придумайте пароль: ";
		cin>>b;
		fout<<a+" "+b;
		fout<<"\n";
	}
	if (vvodpolzovanelya=="зарегестрирован")
	{
		string parol, login;
		cout<<"Введите логин: ";
		cin>>login;
		cout<<"Введите пароль: ";
		cin>>parol;
		ifstream fin;
		fin.open(path);
		int k=0;
		string str;
		
		while(!fin.eof()){
			str="";
			getline(fin,str);
			if (str==login+" "+parol)
			{
			    k++;
			    cout<<"Добро пожаловать в систему!" <<endl;
			}
		}
		if (k==0)
		    cout<<"Вы не зарегестрировались, обманщик!!!"<<endl;
		   
		fin.close();
	}
	
	
	fout.close();
	return 0;
}
