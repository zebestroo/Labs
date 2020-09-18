#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

class customer
{
	public:
	string address;
	string phone;
	class personal
	{
		public:
		string cardnum;
		string banknum;
		static void personalwrite(customer a)	
		{
			cout << "- - - - - - - - - - - - - - -"<< endl;
			cout << "Credit card number : "; cin >> a.data.cardnum;
			cout << "Bank account : "; cin >> a.data.banknum;
			cout << "- - - - - - - - - - - - - - -"<< endl;
		}

//		static void 

		static void personalread(customer a)
		{
			cout << "- - - - - - - - - - - - - - -"<< endl;
			cout << "Credit card number : " << a.data.cardnum << endl;
			cout << "Bank account : " << a.data.banknum << endl;
			cout << "- - - - - - - - - - - - - - -"<< endl;
		}
	};
	personal data;
	string firname;
	string secname;
	string patron;
	void set(customer a)
	{
		string k;
		cout << "First name : "; cin >> firname;
		cout << "Second name : "; cin >> secname;		
		cout << "Patronymic : "; cin >> patron;	
		cout << "Address : "; cin >> address;
		cout << "Phone : "; cin >> phone;
		int s = 1;
		while(s)
			for(int i = 0; i < 13; i++)
				if(phone[0] == '+' && phone[1] == '3' && phone[2] == '7' && phone[3] == '5')
					s = 0;
				else
				{
					cout << "Incorrect phone number, please try again. Be careful:) :";
					cin >> phone;
				}
		cout << "\nWould you confirm personal date? (Yes/No): "; cin >> k;
		if (k == "Yes")
		{
			customer::personal::personalwrite(a);
			cout << "\nThank you for full registration!\n" << endl;
		}
		else
			cout << "Okay!\n" << endl;
	
	}
	void show(customer a)
	{
		string k;
		cout << a.firname << " " << a.secname << " " << a.patron << endl;
		cout << a.address << endl;
		cout << "Would you see personal date? (Yes/No): "; cin >> k;
		if (k == "Yes")
		{
			char p[13];
			cout << "Okay, you need to confirm your phone number : "; 
			Metka:
			cin >> p;
			if(p == a.phone)
			{
				cout << "Okay!" << endl;
				customer::personal::personalread(a);
			}
			else 
			{
				cout << "Incorrect phone number. Access denied :(" << endl;
				goto Metka;
			}
		}
		else
			cout << "Okay!" << endl;
	}	
	void get()
	{
		cout << secname << " " << firname << " " << patron << " " << address << endl;
	}
	
	void parsing(char* k)
	{
//		getline(k, secname, ' ' );
	}
	
	void get(customer *a)
	{
		cout << a->secname << " " << a->firname << " " << a->patron << " " << a->address << endl;
	}
};


int main()
{
	cout << "Massive" << endl;
	cout << "Hello!!! What is array fill type??? Please choose type (Write/Read): ";
	
	string t;
	cin >> t;
	int n = 0;
	
	if(t == "Read")
	{
		string line;
		ifstream text("a.txt"); 
    		if (text.is_open())
    		{
        		while(getline(text, line, '\0'))
        		{
        			cout << line << endl;
        	 	}
   		}
    		text.close();
		int p  = 0;
		while(line[p] != '\0')
		{
			if(line[p] == '\n') 
			{
				n++;
				p++;
			}
			else p++;
		}
		customer *F[n];
		customer M[n];
		string str;
		ifstream text2("b.txt");
		for(int i = 0; i < n; i++)
		if(text2.is_open())
		{
			getline(text2, M[i].secname, ' ');
			getline(text2, M[i].firname, ' ');
			getline(text2, M[i].patron, ' ');
			getline(text2, M[i].address, ' ');
			getline(text2, M[i].phone, ' ');
			getline(text2, M[i].data.cardnum, ' ');
			getline(text2, M[i].data.banknum, '\n');
			
		}
		text2.close();
		cout << "N : " << n <<endl;
	for(int i = 0; i < n; i++)
		M[i].get();
	for(int i = 0; i < n; i++)
		F[i] = &M[i];
	cout << "Opa4a : " <<  M[0].firname << endl;
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(sizeof(M[i].secname) == sizeof(M[j].secname))
				for(int r = 0; r < sizeof(M[j].secname); r++)
					if(M[i].secname[r] == M[j].secname[r])
						continue;
					else if(M[i].secname[r] > M[j].secname[r])
					{
						customer *k;
						k = F[i];
						F[i] = F[j];
						F[j] = k;
						break;
					}
					else if(M[i].secname[r] < M[j].secname[r])
						break;
			else if(sizeof(M[i].secname) > sizeof(M[j].secname))
				for(int r = 0; r < sizeof(M[j].secname); r++)
					if(M[i].secname[r] == M[j].secname[r])
						continue;
					else if(M[i].secname[r] > M[j].secname[r])
					{
						customer *k;
						k = F[i];
						F[i] = F[j];
						F[j] = k;
						break;
					}
	{
		string p;
		cout << "Would you see a list of customers in new form?(Yes/No)"; cin >> p;
		if(p == "Yes")
			for(int i = 0; i < n; i++)
				M[i].get(F[i]);
		else
			cout << "Okay" << endl;
	}

	}
	else
	{
		cout << "What is your number of customers?   "; cin >> n;
		customer M[n];
		customer *F[n];
		for(int i = 0; i < n; i++)
		{
			M[i].set(M[i]);
			F[i] = &M[i];
		}
		cout << endl;
	cout << "Opa4a : " <<  M[0].firname[2] << endl;
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(sizeof(M[i].secname) == sizeof(M[j].secname))
				for(int r = 0; r < sizeof(M[j].secname); r++)
					if(M[i].secname[r] == M[j].secname[r])
						continue;
					else if(M[i].secname[r] > M[j].secname[r])
					{
						customer *k;
						k = F[i];
						F[i] = F[j];
						F[j] = k;
						break;
					}
					else if(M[i].secname[r] < M[j].secname[r])
						break;
			else if(sizeof(M[i].secname) > sizeof(M[j].secname))
				for(int r = 0; r < sizeof(M[j].secname); r++)
					if(M[i].secname[r] == M[j].secname[r])
						continue;
					else if(M[i].secname[r] > M[j].secname[r])
					{
						customer *k;
						k = F[i];
						F[i] = F[j];
						F[j] = k;
						break;
					}
	{
		string p;
		cout << "Would you see a list of customers in new form?(Yes/No)"; cin >> p;
		if(p == "Yes")
			for(int i = 0; i < n; i++)
				M[i].get(F[i]);
		else
			cout << "Okay" << endl;
	}
	}
	
	return 0;
}
