#include"Classes.h"
Car car;
Garage gar;
Service ser;
Showrooms roomm;
fstream cust;

int LoginId = 0;

Customer::Customer()
{
	ID = 0;
	username = "";
	password[15] = {};
	phone = NULL;
}


void Customer::SignUp()
{
	system("cls");
	int index = 0;
	char ch = NULL;

	cout << "Enter Your Name: ";
	cin.ignore();
	getline(cin, username);

	cout << "Enter Your ID: ";
	cin >> ID;

	cout << "Enter Your Phone: ";
	cin >> phone;

	cout << "Enter Your Password: ";
	ch = _getch();
	while (ch != '\r')
	{

		password[index] = ch;
		cout << "*";
		index++;
		ch = _getch();
	}

	system("cls");
	cout << "                   Account Created Successfully\n";
	cout << "                       Login to complete \n\n";




	cust.open("Database.txt", ios::app);
	if (cust.is_open())
	{
		cust << "UserName:" << username << endl;

		cust << "Password:";
		for (int i = 0; i < index; i++)
			cust << password[i];
		cust << endl;

		cust << "ID:" << ID << endl;
		cust << "Phone:" << phone << endl;
		cust << "----------" << endl;

		cust.close();
	}
}


void Customer::Login() {
	Customer C;
	int line = 1;
	char namedb[25], pass[25], ch, Pn[25];
	char Cid[25];
	string username = "", password = "";
	bool flag = false;

	cout << "                                  Don't have an account?SignUp (y/n)\n\n\n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		SignUp();



	cout << "Username: ";
	cin.ignore();
	getline(cin, username);
	cout << "Password: ";
	cin >> password;



	cust.open("Database.txt", ios::in);
	while (!cust.eof()) {
		line++;
		cust.getline(namedb, 30, ':');
		cust.getline(namedb, 30);
		cust.getline(pass, 30, ':');
		cust.getline(pass, 30);

		cust.getline(Cid, 30, ':');
		cust.getline(Cid, 30);

		cust.getline(Pn, 30, ':');
		cust.getline(Pn, 30);
		

	//	if (line % 2 == 0) {
			if (namedb == username && pass == password) {
				LoginId = atoi(Cid);
				cout << "Login Successful";
				customer_page();
			//	exit(0);
				//	break;
			}

	//	}

	}

	cout << "\nLOGIN ERROR\nPlease check your username and password\n";
	int menu;
	cout << "\npress 1 to login again\n";
	cin >> menu;
	if (menu == 1) {
		Login();
	}
	else
		exit(0);


	cust.close();




}


void Customer::customer_page() {

	int IDCustomer = LoginId;

	system("cls");
	int choice;
	cout << "                       \n       \t\t WELCOME User\n\n\n";
	cout << "                                   \t    MENU\n\n\n";

	cout << "Would you like to Buy/Rent a Car or Repair your own Car\n";
	cout << "1.Buy/Rent" << endl;
	cout << "2.Repair" << endl;
	cout << "3.LOGOUT" << endl; 
	cout << "\nEnter your choice :";
	cin >> choice;

	switch (choice) {
	case 1:
		roomm.view(LoginId);

	case 2:
		gar.view();
	
	default:
		exit(0);
	}

}