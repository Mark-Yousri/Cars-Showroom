#include"Classes.h"
fstream myFilee;

void Service::addServices() {

	system("CLS");

	myFilee.open("Services.txt", ios::app);
	cout << "Service ID: ";
	cin >> ID;
	cout << "Service Name: ";
	cin >> Name;
	cout << "Service price: ";
	cin >> price;
	cout << "Service time: ";
	cin >> time;
	if (myFilee.is_open()) {
		myFilee << "Service ID :" << ID << endl;
		myFilee << "Service Name :" << Name << endl;
		myFilee << "Service price :" << price << endl;
		myFilee << "Service Time :" << time << endl;
		myFilee << endl;
		myFilee.close();
	}
}

void Service::updateServices() {




	char key[25], IdInfo[25], ServiceName[25], ServicePrice[25], ServiceTime[25];
	fstream newf;
	fstream temp;
	newf.open("Services.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Service ID that you want to change it's Data " << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(ServiceName, 25, ':');
			newf.getline(ServiceName, 25);
			newf.getline(ServicePrice, 25, ':');
			newf.getline(ServicePrice, 25);
			newf.getline(ServiceTime, 25, ':');
			newf.getline(ServiceTime, 25);



			if (IdInfo[0] != 0)
			{
				if (strcmp(key, IdInfo) == 0) {
					//check Service exist
					cout << "please enter 1 to change Service Name" << endl;
					cout << "please enter 2 to change Service Price" << endl;
					cout << "please enter 3 to change Service Time" << endl;

					cin >> Choice;

					switch (Choice) {
						// use same format instead of variables to ensure file consistency
					case 1:

						cout << "please enter new Name" << endl;
						cin >> Value_Up;

						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << Value_Up << endl;
						temp << "Service Price :" << ServicePrice << endl;
						temp << "Service Time :" << ServiceTime << endl;
						temp << endl;

						break;
					case 2:
						cout << "please enter new Price" << endl;
						cin >> Value_Up;
						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << ServiceName << endl;
						temp << "Service Price :" << Value_Up << endl;
						temp << "Service Time :" << ServiceTime << endl;

						temp << endl;
						break;

					case 3:
						cout << "please enter new Time" << endl;
						cin >> Value_Up;
						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << ServiceName << endl;
						temp << "Service Price :" << ServicePrice << endl;
						temp << "Service Time :" << Value_Up << endl;
						temp << endl;
						break;

					}




				}

				else {

					temp << "Service ID :" << IdInfo << endl;
					temp << "Service Name :" << ServiceName << endl;
					temp << "Service Price :" << ServicePrice << endl;
					temp << "Service Time :" << ServiceTime << endl;
					temp << endl;

				}
			}

		}
	}
	temp.close();
	newf.close();

	newf.open("Services.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {



			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(ServiceName, 25, ':');
			temp.getline(ServiceName, 25);
			temp.getline(ServicePrice, 25, ':');
			temp.getline(ServicePrice, 25);
			temp.getline(ServiceTime, 25, ':');
			temp.getline(ServiceTime, 25);





			if (IdInfo[0] != 0)
			{
				newf << "Service ID :" << IdInfo << endl;
				newf << "Service Name :" << ServiceName << endl;
				newf << "Service Price :" << ServicePrice << endl;
				newf << "Service Time :" << ServiceTime << endl;
				newf << endl;
			}
		}
	}
	temp.close();
	newf.close();

	system("CLS");
	cout << "       \tDONE!       " << endl;

	remove("temp.txt");






}

void Service::deleteServices() {



	char key[25],Id[25],
		 IdInfo[25],
		 ServiceName[25],
		 ServicePrice[25],
		 ServiceTime[25],
		 WorkerName[25];
	fstream newf;
	fstream temp;
	newf.open("Services.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter service ID that you want to delete" << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(Id, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(ServiceName, 25, ':');
			newf.getline(ServiceName, 25);
			newf.getline(ServicePrice, 25, ':');
			newf.getline(ServicePrice, 25);
			newf.getline(ServiceTime, 25, ':');
			newf.getline(ServiceTime, 25);
			newf.getline(WorkerName, 25, ':');
			newf.getline(WorkerName, 25);

			if (IdInfo[0] != 0) {

				if (strcmp(key, IdInfo) == 0) {
					//transfer data to temp !EXCEPT! for the data we want to delete
					continue;
				}

				else {
					temp << "Service Id :" << IdInfo << endl;
					temp << "ServiceName :" << ServiceName << endl;
					temp << "ServicePrice :" << ServicePrice << endl;
					temp << "ServiceTime :" << ServiceTime << endl;
					temp << "WorkerName :" << WorkerName << endl;
					temp << endl;
				}
			}
		}
	}
	temp.close();
	newf.close();

	newf.open("Services.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {

			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(ServiceName, 25, ':');
			temp.getline(ServiceName, 25);
			temp.getline(ServicePrice, 25, ':');
			temp.getline(ServicePrice, 25);
			temp.getline(ServiceTime, 25, ':');
			temp.getline(ServiceTime, 25);
			temp.getline(WorkerName, 25, ':');
			temp.getline(WorkerName, 25);

			if (IdInfo[0] != 0) {
				newf << "Service Id :" << IdInfo << endl;
				newf << "ServiceName :" << ServiceName << endl;
				newf << "ServicePrice :" << ServicePrice << endl;
				newf << "ServiceTime :" << ServiceTime << endl;
				newf << "WorkerName :" << WorkerName << endl;
				newf << endl;
			}
		}
	}
	temp.close();
	newf.close();

	system("CLS");
	cout << "       \tDONE!       " << endl;

	remove("temp.txt");

}

void Service::search() {
}