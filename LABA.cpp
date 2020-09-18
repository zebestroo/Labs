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
			cout << "Credit card number(Номер кредитной карты) : "; cin >> a.data.cardnum;
			for(int i = 0; i < 19; i++)
				if((a.data.cardnum[i] > 9 || a.data.cardnum[i] < 0) && a.data.cardnum[i] != ' ')
				{
					cout << "Incorrect number, try again(Невозможный номер, попробуйте снова)" << endl;
					cin >> a.data.cardnum;
				}
			cout << "Bank account(Номер банковского счёта) : "; cin >> a.data.banknum;
			cout << "- - - - - - - - - - - - - - -"<< endl;
		}

//		static void 

		static void personalread(customer a)
		{
			cout << "- - - - - - - - - - - - - - -"<< endl;
			cout << "Credit card number(Номер кредитной карты) : " << a.data.cardnum << endl;
			cout << "Bank account(Номер банковского счёта) : " << a.data.banknum << endl;
			cout << "- - - - - - - - - - - - - - -"<< endl;
		}
	};
	personal data;
	string firname;
	string secname;
	string patron;
	void set(customer a, bool r)
	{
		if(r)
		{
			cout << "First name : "; cin >> firname;
			cout << "Second name : "; cin >> secname;		
			cout << "Patronymic : "; cin >> patron;	
			cout << "Address : "; cin >> address;
			cout << "Phone : "; cin >> phone;
			int s = 1;
			while(s)
			{
				for(int i = 0; i < 13; i++)
					if(phone[0] == '+' && phone[1] == '3' && phone[2] == '7' && phone[3] == '5')
						s = 0;
					else
					{
						cout << "Incorrect number, please try again: ";
						cin >> phone;
					}
			}
		}
		else
		{
			cout << "Имя : "; cin >> firname;
			cout << "Фамилия : "; cin >> secname;		
			cout << "Отчество : "; cin >> patron;	
			cout << "Адрес : "; cin >> address;
			cout << "Телефон : "; cin >> phone;
			int s = 1;
			while(s)
			{
				for(int i = 0; i < 13; i++)
					if(phone[0] == '+' && phone[1] == '3' && phone[2] == '7' && phone[3] == '5')
						s = 0;
					else
					{
						cout << "Невозможный номер, попробуйте ещё раз: ";
						cin >> phone;
					}
			}
		}

		if(r)
			cout << "\nWould you confirm personal date? (Yes/No): "; 
		else
			cout << "\nХотите заполнить личные данные? (Да/Нет)";
		string k;
		cin >> k;
		if (k == "Yes" || k == "Да")
		{
			customer::personal::personalwrite(a);
			if(r)
				cout << "\nThank you for full registration!\n" << endl;
			else
				cout << "\nСпасибо за полную регистрацию\n" << endl;
		}
		else
			if(r)
				cout << "Okay!\n" << endl;
			else
				cout << "Хорошо\n" << endl;
	
	}
	void show(customer a, bool r)
	{
		if(r)
		{
			string one;
			string two;
			cout << "Write diaposon: " << endl;
			cin >> one;
			cin >> two;
			for(int i = 0; i < 19; i++)
				if(a.data.cardnum[i] >= one[i] || a.data.cardnum[i] <= two[i])
					get()
		}
		else
		{
			string one;
			string two;
			cout << "Введите диапозон: " << endl;
			cin >> one;
			cin >> two;
			for(int i = 0; i < 19; i++)
				if(a.data.cardnum[i] >= one[i] || a.data.cardnum[i] <= two[i])
		}

	}	
	void get()
	{
		cout << "\n" << secname << " " << firname << " " << patron << " " << endl;
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
	cout << "Select language(Eng/Rus):";
	string q;
	bool r;
	cin >> q;
	if(q == "Eng")
		r = 1;
	else
		r = 0;
	if(r)
		cout << "Hello!!! What is array fill type??? Please choose type (Write/Read): ";
	else
		cout << "Привет!!! Каким способом заполняем??? Пожалуйста выберите тип (Записывать/Читать)";
	string t;
	cin >> t;
	int n = 0;
	
	if(t == "Read" || t == "Читать")
	{
		string line;
		if(r)
			cout << "\nOriginal stream: " << endl;
		else
			cout << "\nИсходный поток: " << endl;
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
	for(int i = 0; i < n; i++)
		M[i].get();
	for(int i = 0; i < n; i++)
		F[i] = &M[i];
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
		if(r)
			cout << "\nWould you see a list of customers in new form?(Yes/No)";
		else
			cout << "\nВывести отсортированный список?(Да/Нет)";
		cin >> p;
		if(p == "Yes" || p == "Да")
			for(int i = 0; i < n; i++)
				M[i].get(F[i]);
		else
			if(r)
				cout << "\nDone!" << endl;
			else
				cout << "\nСделано!" << endl;
	}

	}
	else
	{
		if(r)
			cout << "\nWhat is your number of customers?   "; 
		else
			cout << "\nКакое число клиентов?   ";
		cin >> n;	
		customer M[n];
		customer *F[n];
		for(int i = 0; i < n; i++)
		{
			M[i].set(M[i], r);
			F[i] = &M[i];
		}
		cout << endl;
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
		if(r)
			cout << "\nWould you see a list of customers in new form?(Yes/No)"; 
		else
			cout << "\nВывести отсортированный список?(Да/Нет)";

		cin >> p;
		if(p == "Yes" || p == "Да")
			for(int i = 0; i < n; i++)
				M[i].get(F[i]);
		else
			if(r)
				cout << "\nDone!!" << endl;
			else
				cout << "\nСделано!" << endl; 
	}
	}
	for(int i = 0; i < n; i++)

	
	return 0;
}
