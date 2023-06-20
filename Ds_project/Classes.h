#pragma once
#include<iostream>
#include <fstream>
#include<conio.h>
#include<string>
#include<vector>
#include<list>

using namespace std;
class Admin
{
	int ID;
	string username, password;
public:
	void login();
	void admin_page();


};

class Customer
{
	int ID, phone;
	string username;
	char password[15];

public:
	Customer();
	void SignUp();
	// buy/rent/repair
	void Login();
	void customer_page();
	void search();
	void view();
};

class Car
{
public:
	int ID, Year, ShowRoomId;
	string Make, Model;
	float price;
	//installment

public:
	list<Car>Clist;
		Car();
	void addCars();
	void updateCars();
	void deleteCars(char id[]);
	void search();
	void LoadCars();


};

class Showrooms
{
public:
	int ID, phoneNumber;
	string Name, Location;
	vector<Car> RoomCarList;


	list<Showrooms> Slist;
	void addShowrooms();
	void updateShowrooms();
	void deleteShowrooms();
	int search();
	void view(int id);
	void LoadShowRoom();
};



class Buy_Rent_process
{
	int process_id, customer_id;
	string Date, ChosenCar;
	float money;
	string Processtype;

public:
	void Process( int CarID, int Customerid);
	void AddProcessData(char Carid[25], int Cid);
	void DisplayData(char Carid[25], int Cid);
	Buy_Rent_process();
};

class Garage
{
	int ID, phoneNumber;
	string Name, Location;
	//list of services

public:
	void addGarages();
	void updateGarages();
	void deleteGarages();
	void search();
	void view();

};

class Service
{
	int ID;
	string Name,time;
	float price;


public:
	void addServices();
	void updateServices();
	void deleteServices();
	void search();


};

class service_process
{
	int process_id, customer_id;
	string Date, choosen_service;
	float money;

};

