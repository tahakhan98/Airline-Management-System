#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <cstdlib>
using namespace std;
int mystrlen(char s[])
{
	int length = 0;
	for (int i = 0; s[i] != '\0'; i++)
		length++;
	return length;
}
void fightID_arr(int arr[])
{
	srand(time(0));
	int size = 11;
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
}
void flight_time(int size,int hours_arrival[], int minute_arrival[], int hours_departure[], int minute_departure[])
{
	int hours = 2;
	int minute = 15;
	for (int i = 0; i < size; i++){
		hours_arrival[i] = hours + 1;
		minute_arrival[i] = minute + 3;
		hours_departure[i] = hours;
		minute_departure[i] = minute;
		hours += 2;
		minute += 10;
		if (minute > 60 || minute == 60)
			minute = 0;
	}
}
void flight_class(int size, int bussiness_class[], int economic_class[])
{
	for (int i = 0; i < size; i++){
		bussiness_class[i] = i + 1;
		economic_class[i] = i + 9;
	}
}
void flightdetail(int flightnumber, int size, char flightname[], int flightID[], int bussiness_class[], int economic_class[], int hours_arrival[], int minute_arrival[], int hours_departure[], int minute_departure[])
{
	int j = 0; int k = 1; int l = 0;
	for (int i = 0; i < size; i++) {
		if (flightnumber == k)
			break;
		j = j + 2;
		k++;
		l = i;
	}
	l++;
	cout << "Flight Of Your selected is: " << flightname[j] << flightname[j + 1] << "-" << flightID[l] << endl;
	cout << "It's arrival time is: " << hours_arrival[l] << ":" << minute_arrival[l] << endl;
	cout << "It's Deparure time is: " << hours_departure[l] << ":" << minute_departure[l] << endl;
	cout << "Bussiness class seats: " << bussiness_class[l] << endl;
	cout<< "Economic class seats: " << economic_class[l] << endl;
}
void flightstatus(int size, char flightname[], int flightID[], int bussiness_class[], int economic_class[], int hours_arrival[], int minute_arrival[], int hours_departure[], int minute_departure[])
{
	int j = 0; int k = 1;
	for (int i = 0; i < 1; i++)
		cout << "FLIGHTNAME and FLIGHTID" << "         " << "ARRIVAL TIME" << "         " << "DEPARTURE TIME" << "         " << "BUSSINESS CLASS" << "         " << "ECONOMIC CLASS" << endl;
	for (int i = 0; i < size; i++) {
		cout << k << ". " << flightname[j] << flightname[j + 1] << "-" << flightID[i] << "                         " << hours_arrival[i] << ":" << minute_arrival[i] << "                   " << hours_departure[i] << ":" << minute_departure[i] << "                     " << bussiness_class[i] << "                     " << economic_class[i] << endl;
		j = j + 2;
		k++;
	}
}
void detailflightname()
{
	char flightname[100] = "EKSVEYFZGFPKQRSVTGTKWYAC";
	int i = 0;
	cout << "EMIRATES Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout << "Saudi Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout << "England Airlines     " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"Finland Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout << "Gawadar Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"Pakistan Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"Qatar Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"South Africa Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"Turkey Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"Thailand Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"West Indies Airlines    " << flightname[i] << flightname[i + 1] << endl;
	i = i + 2;
	cout<<"America Airlines    " << flightname[i] << flightname[i + 1] << endl;
}
bool flightpassport(int passport)
{
	if (passport == 1)
		return true;
	else
		return false;
}
void flightreservation(int size,int& age,int& travelchage, int& passport, char flightfly[], char passengername[], char destination[], char source[],char flightname[], int& passportnumber, int& dateoftravel, int& monthoftravel, int& yearoftravel)
{
	cin.ignore();
	cout << "ENTER PASSENGER NAME ";
	cin.getline(passengername, 100);
	cout << "ENTER YOUR DESTINATION ";
	cin.getline(destination, 100);
	cout << "Enter your Souce Area ";
	cin.getline(source, 100);
	cout << "ENTER FLIGHT ID IN WHICH YOU WANT TO FLY ";
	cin.getline(flightfly, 100);
	int j = 0; int count = 0;
	for (int i = 0; flightname[i] != '\0'; i++)
	{
		if (flightname[i] == flightfly[j])
		{
			count++;
			j++;
		}
	}
	if (count == mystrlen(flightfly)) {
		cout << "PROCEED YOUR FOLLOWING INSTRUCTION " << endl;
		cout << "PLEASE ENTER YOUR CHOICE FOR BUSSINESS ENTER 1 ELSE PRESS 2: ";
		cin >> passport;
		passport = flightpassport(passport);
		cout << "ENTER YOUR AGE: ";
		cin >> age;
		cout << "ENTER YOUR PASSPORT NUMBER: ";
		cin >> passportnumber;
		cout << "ENTER YOUR DATE OF TRAVEL: ";
		cin >> dateoftravel;
		monthoftravel = 5;
		yearoftravel = 2018;
		cout << endl;
	}
	else
		cout << "Sorry! Wrong Flight ID\n";
}
void flightcancel(int size, int& passport, char flightfly[], char passengername[], char destination[], char flightname[], int passportnumber, int dateoftravel, int monthoftravel, int yearoftravel)
{
	int cancelpassportnumber = 0; char feedback[100];
	cout << "Please Enter Your Passport Number: ";
	cin >> cancelpassportnumber;
	cin.ignore();
	cout << "Please Enter Your Flightname: ";
	cin.getline(flightname, 100);
	if (passportnumber == cancelpassportnumber)
	{
		cout << "Thanks For Cancel Your Flight";
		cin.ignore();
		cout << "Please Enter your Feedback and any Complain About Our service " << endl;
		cin.getline(feedback, 1000);
	}
}
int userpassportnumber(int passport)
{
	ifstream fin;
	fin.open("Passport.txt");
	while (!fin.eof())
	{
		fin >> passport;
	}
	return passport;
}
void printflightreservationdetails(int passport,int age, char flightfly[], char passengername[], char source[],char destination[], int travelcharge, int passportnumber, int dateoftravel, int monthoftravel, int yearoftravel)
{
	ofstream fout;
	fout.open("Passport.txt");
	system("cls");
	cout << "\n----------------------------------------------------------------------------------\n";
	cout << "          Whole Detail Of Your Flight Reservation\n";
	cout << "\n-------------------------------------------------\n";
	cout << "| Flight in which you Covered your wonderful Journey: " << flightfly;
	cout << "\n-------------------------------------------------\n";
	cout << "| Your Name: " << passengername;
	cout << "\n-------------------------------------------------\n";
	cout << "| Your Travel Charges: " ;
	if (age >= 40)
	{
		travelcharge = 800;
		cout << travelcharge << "$" << endl;
	}
	else
	{
		travelcharge = 1000;
		cout << travelcharge << "$";
	}
	cout << "\n-------------------------------------------------\n";
	cout << "| your Source Area: " << source;
	cout << "\n-------------------------------------------------\n";
	cout << "| Your PassportNumber: " << passportnumber;
	cout << "\n-------------------------------------------------\n";
	cout << "Your Destination: "<<destination;
	cout << "\n-------------------------------------------------\n";
	cout << "| Travel on " << monthoftravel << "-" << dateoftravel << "-" << yearoftravel;
	fout << passportnumber;
}
void mainreservation()
{
	int size = 11; char passengername[100], destination[100], flightname[100] = "EKSVEYFZGFPKQRSATGTKWYAC";
	int travelcharge = 0; int passportnumber = 0; char flightfly[100]; int passport = 0; int age = 0;
	int dateoftravel = 0, monthoftravel = 0, yearoftravel = 0; char source[100];
	int flightcode;
	cout << "If you want to See Flight code ID then Enter 1 else press 2\n";
	cin >> flightcode;
	if (flightcode == 1) {
		system("cls");
		detailflightname();
	}
	else {
		system("cls");
		flightreservation(size, age, travelcharge, passport, flightfly, passengername, destination,source, flightname, passportnumber, dateoftravel, monthoftravel, yearoftravel);
		printflightreservationdetails(passport, age, flightfly, passengername, source,destination, travelcharge, passportnumber, dateoftravel, monthoftravel, yearoftravel);
	}
}
void mainflightstatus()
{
	int flightnumber = 0; int size = 11;
	int arr[11];
	char flightname[100] = "EKSVEYFZGFPKQRSATGTKWYAC";
	int bussiness_class[11]; int economic_class[11];
	int hours_arrival[11]; int minute_arrival[11]; int hours_departure[11]; int minute_departure[11];
	fightID_arr(arr);
	flight_class(size, bussiness_class, economic_class);
	flight_time(size, hours_arrival, minute_arrival, hours_departure, minute_departure);
	flightstatus(size, flightname, arr, bussiness_class, economic_class, hours_arrival, minute_arrival, hours_departure, minute_departure);
}
void mainflightdetail()
{
	int flightnumber = 0; int size = 11;
	int arr[11];
	char flightname[100] = "EKSVEYFZGFPKQRSATGTKWYAC";
	int bussiness_class[11]; int economic_class[11];
	int hours_arrival[11]; int minute_arrival[11]; int hours_departure[11]; int minute_departure[11];
	fightID_arr(arr);
	flight_class(size, bussiness_class, economic_class);
	flight_time(size, hours_arrival, minute_arrival, hours_departure, minute_departure);
	cout << "Enter Your Flight Number: ";
	cin >> flightnumber;
	flightdetail(flightnumber, size, flightname, arr, bussiness_class, economic_class, hours_arrival, minute_arrival, hours_departure, minute_departure);
}
void mainflightcancel()
{
	int size=11, passport=0, passportnumber=0, dateoftravel=0, monthoftravel=5, yearoftravel = 18;
	char flightfly[100], passengername[100], destination[100], flightname[100];
	passportnumber=userpassportnumber(passport);
	flightcancel( size, passport,  flightfly,  passengername,  destination,  flightname,  passportnumber,  dateoftravel,  monthoftravel,  yearoftravel);
}
void adminintialize(char username[], char password[])
{
	cin.ignore();
	cout << "Admin Name: ";
	cin.getline(username, 100);
	cout << "Password: ";
	cin.getline(password, 100);
}
bool adminstration(char user_name[], char password[])
{
	char username[100] = "Muhammad Subhani";
	char Password[100] = "muhammad";
	int i = 0; int j = 0; int count = 0;
	while (username[i] != '\0') {
		if (username[i] == user_name[j]) {
			count++;
			j++;
		}
		i++;
	}
	i = 0; j = 0; int count1 = 0;
	while (Password[i] != '\0') {
		if (Password[i] == password[j]) {
			count1++;
			j++;
		}
		i++;
	}
	if ((mystrlen(user_name) == count) && (mystrlen(password) == count1))
		return true;
	else
		return false;
}
void checkadmin(char username[], char password[])
{
	string name[11]; string source[11]; string destination[11]; string flightID[11];
	int arr[11]; int i = 0;
	ifstream fin;
	fin.open("admin.txt");
	if (adminstration(username, password) == true) {
		system("cls");
		cout << "                                                      WECLOME";
		while (!fin.eof() && i < 11)
		{
			fin >> name[i] >> arr[i] >> source[i] >> destination[i] >> flightID[i];
			i++;
		}
		fin.close();
		cout << endl;
		for (int j = 0; j < 11; j++)
			cout << name[j] << " " << arr[j] << " " << source[j] << " " << destination[j] << " " << flightID[j] << endl;
	}
	else
		cout << "Sorry! try again";
}
void mainadmin()
{
	int person = 0;
	char username[100];
	char password[100];
	cout << "                                         Welcome to international airlines of World" << endl;
	cout << "Please Enter your identification by filling following information" << endl;
	adminintialize(username, password);
	checkadmin(username, password);
}
void flight()
{
	cout << "                                   WELCOME TO INTERNATIONAL AIRLINES" << endl;
	cout << "1. FLIGHT STATUS" << endl << "2. FLIGHT DETAIL" << endl << "3. RESERVED SEATS" << endl << "4. Cancel Seats" << endl << "5. ADMIN" << endl << "6. Flight Codes" << endl;
}
void flightmain()
{
	flight();
	int choice;
	cout << "\n\nEnter your choice: ";
	cin >> choice;
	char back;
	for (int i = 0; i >= 0; i++) {
		if (choice == 1) {
			system("cls");
			mainflightstatus();
		}
		else if (choice == 2) {
			system("cls");
			mainflightdetail();
		}
		else if (choice == 3) {
			system("cls");
			mainreservation();
		}
		else if (choice == 4) {
			system("cls");
			mainflightcancel();

		}

		else if (choice == 5) {
			system("cls");
			mainadmin();
		}
		else{
			system("cls");
			detailflightname();
		}
		cout << endl << "\n\nTO Go back To Main Menu Please Enter B\n";
		cin >> back;
		if (back == 'B') {
			system("cls");
			flight();
			cout << "\n\nEnter your choice: ";
			cin >> choice;
		}
	}
}
int main()
{
	flightmain();
	_getch();
}