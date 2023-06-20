#include"Classes.h"
fstream PFile;
int counter = 1;

Buy_Rent_process::Buy_Rent_process()
{
	customer_id, money,process_id= 0;
	Date, ChosenCar,Processtype = " ";

}

void Buy_Rent_process::Process(int SID, int CustomerId)
{
	
	
	char c;
	Showrooms s;
	list<Showrooms> ::iterator it;
	int i = 0;
	bool vaild = false;
	char CarID[25];
	s.LoadShowRoom();

	for (it = s.Slist.begin(); it != s.Slist.end(); it++)
	{
		if (it->ID == SID)
		{

			while (i < it->RoomCarList.size())
			{
				if (it->RoomCarList[i].ShowRoomId == SID)
				{
					cout << "Car ID: " << it->RoomCarList[i].ID << endl;
					cout << "Car Make: " << it->RoomCarList[i].Make << endl;
					cout << "Car Model:" << it->RoomCarList[i].Model << endl;
					cout << "Car Year: " << it->RoomCarList[i].Year << endl;
					cout << "Car Price: " << it->RoomCarList[i].price << endl;
					vaild = true;

				}
				i++;

				cout << endl;
			}

		}
	}

	cout << "Do You Want to Buy or Rent B/R" << endl;
	cin >> c;

	while (true)
	{
		if (c == 'B' || c == 'b')
		{
			Processtype = "Buy";
			break;
		}

		else if (c == 'R' || c == 'r')
		{
			Processtype = "Rent";
			break;
		}

		else
		{
			cout << "Re-Enter Your Choice B/R" << endl;
			cin >> c;
		}
	
	}

	vaild = false;
	i = 0;
	cout << "Enter Car Id you want to " << Processtype << endl;
	cin >> CarID;

	s.LoadShowRoom();
	for (it = s.Slist.begin(); it != s.Slist.end(); it++)
	{
		if (it->ID == SID)
		{
			while (i < it->RoomCarList.size())
			{
				if (it->RoomCarList[i].ID == atoi(CarID))
				{
					if (Processtype == "Buy")
						money = (it->RoomCarList[i].price);
					else
						money = (it->RoomCarList[i].price) / 2;

					vaild = true;
				}
				i++;
				if (vaild)
					break;
			}
			if (vaild)
				break;

		}
	}


	process_id = counter++;
	DisplayData(CarID, CustomerId);

}

void Buy_Rent_process:: DisplayData(char CarId[25], int Cid)
{ 
	Car car;
	char choice;
	car.deleteCars(CarId);
	system("CLS");
	cout <<  "                            Process is Done Succesfully" << endl << endl;
	cout << "Customer Id: " << Cid << endl;
	cout << "Process Id: " << process_id << endl;
	cout << "Car ID: " << atoi(CarId) << endl;
	cout << "Cost: " << money << endl;
	
	Customer c;
	cout << "Press M to Main Menu or E to Exit" << endl;
	cin >> choice;


	if (choice == 'M' || choice == 'm')
		c.customer_page();
	else
		exit(0);
}
	
