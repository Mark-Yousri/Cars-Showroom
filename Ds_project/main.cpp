#include"Classes.h"
int main()
{

	Car c;
	Garage g;
	Service s;
	Showrooms room;
	Customer Cust;
	Admin a;


	int role;
	


	
	
	cout << "                       \n\t\t \t\t\t WELCOME TO CAR SHOWROOMS & REPAIR SHOPS\n\n\n";
	cout << "                                     \t      PRESS ENTER TO CONTINUE....\n\n";
	if (cin.get() == '\n') {
		system("cls");

		cout << "Who are You?" << endl;
		cout << "1. Admin" << endl;
		cout << "2. User" << endl;
		cout << endl << "Enter Your Option Or Press any Key to Exit" << endl;
		cin >> role;

		if (role == 1)
		{
			a.login();

		}
		else if (role == 2)
		{
			system("cls");
			cout << "                                  WELCOME USER" << endl << endl;
			Cust.Login();
		}
		return 0;

	}

}