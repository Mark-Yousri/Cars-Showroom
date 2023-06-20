#include"Classes.h"

fstream myFile;

void Garage::addGarages() {

	system("CLS");

	myFile.open("Garages.txt", ios::app);
	cout << "Garage ID: ";
	cin >> ID;
	cout << "Garage Name: ";
	cin >> Name;
	cout << "Phone Number: ";
	cin >> phoneNumber;
	cout << "Garage Location: ";
	cin >> Location;

	if (myFile.is_open()) {
		myFile << "Garage ID :" << ID << endl;
		myFile << "Garage Name :" << Name << endl;
		myFile << "Phone Number :" << phoneNumber << endl;
		myFile << "Garage Location :" << Location << endl;
		myFile << endl;
		myFile.close();
	}
}

void Garage::updateGarages() {



	char key[25], IdInfo[25], GarageName[25], GarageNumber[25], GarageLocation[25];
	fstream newf;
	fstream temp;
	newf.open("Garages.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Garage ID that you want to change it's Data " << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(GarageName, 25, ':');
			newf.getline(GarageName, 25);
			newf.getline(GarageNumber, 25, ':');
			newf.getline(GarageNumber, 25);
			newf.getline(GarageLocation, 25, ':');
			newf.getline(GarageLocation, 25);


			if (IdInfo[0] != 0)
			{
				if (strcmp(key, IdInfo) == 0) {
					//check Garage exist
					cout << "please enter 1 to change Garage Name" << endl;
					cout << "please enter 2 to change Garage Number" << endl;
					cout << "please enter 3 to change Garage Location" << endl;
					cin >> Choice;

					switch (Choice) {
						// use same format instead of variables to ensure file consistency
					case 1:

						cout << "please enter new Name" << endl;
						cin >> Value_Up;

						temp << "Garage ID :" << IdInfo << endl;
						temp << "Garage Name :" << Value_Up << endl;
						temp << "Garage Number :" << GarageNumber << endl;
						temp << "Garage Location :" << GarageLocation << endl;
						temp << endl;

						break;
					case 2:
						cout << "please enter new Number" << endl;
						cin >> Value_Up;
						temp << "Garage ID :" << IdInfo << endl;
						temp << "Garage Name :" << GarageName << endl;
						temp << "Garage Number :" << Value_Up << endl;
						temp << "Garage Location :" << GarageLocation << endl;
						temp << endl;
						break;
					case 3:
						cout << "please enter new Location" << endl;
						cin >> Value_Up;
						temp << "Garage ID :" << IdInfo << endl;
						temp << "Garage Name :" << GarageName << endl;
						temp << "Garage Number :" << GarageNumber << endl;
						temp << "Garage Location :" << Value_Up << endl;
						temp << endl;
						break;



					}




				}

				else {

					temp << "Garage ID :" << IdInfo << endl;
					temp << "Garage Name :" << GarageName << endl;
					temp << "Garage Number :" << GarageNumber << endl;
					temp << "Garage Location :" << GarageLocation << endl;
					temp << endl;

				}
			}

		}
	}
	temp.close();
	newf.close();

	newf.open("Garages.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {



			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(GarageName, 25, ':');
			temp.getline(GarageName, 25);
			temp.getline(GarageNumber, 25, ':');
			temp.getline(GarageNumber, 25);
			temp.getline(GarageLocation, 25, ':');
			temp.getline(GarageLocation, 25);




			if (IdInfo[0] != 0)
			{
				newf << "Garage ID :" << IdInfo << endl;
				newf << "Garage Name :" << GarageName << endl;
				newf << "Garage Number :" << GarageNumber << endl;
				newf << "Garage Location :" << GarageLocation << endl;
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

void Garage::deleteGarages() {


	char key[25],
		IdInfo[25],
		GarageName[25],
		GarageNumber[25],
		GarageLocation[25];
	fstream newf;
	fstream temp;
	newf.open("Garages.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Garage ID that you want to delete" << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(GarageName, 25, ':');
			newf.getline(GarageName, 25);
			newf.getline(GarageNumber, 25, ':');
			newf.getline(GarageNumber, 25);
			newf.getline(GarageLocation, 25, ':');
			newf.getline(GarageLocation, 25);


			if (IdInfo[0] != 0) {

				if (strcmp(key, IdInfo) == 0) {
					//transfer data to temp !EXCEPT! for the data we want to delete
					continue;
				}

				else {
					temp << "Garage ID :" << IdInfo << endl;
					temp << "Garage Name :" << GarageName << endl;
					temp << "Garage Number :" << GarageNumber << endl;
					temp << "Garage Location :" << GarageLocation << endl;
					temp << endl;
				}
			}
		}
	}
	temp.close();
	newf.close();

	newf.open("Garages.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {

			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(GarageName, 25, ':');
			temp.getline(GarageName, 25);
			temp.getline(GarageNumber, 25, ':');
			temp.getline(GarageNumber, 25);
			temp.getline(GarageLocation, 25, ':');
			temp.getline(GarageLocation, 25);


			if (IdInfo[0] != 0) {
				newf << "Garage ID :" << IdInfo << endl;
				newf << "Garage Name :" << GarageName << endl;
				newf << "Garage Number :" << GarageNumber << endl;
				newf << "Garage Location :" << GarageLocation << endl;
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

void Garage::search(){
}

void Garage::view() {
}