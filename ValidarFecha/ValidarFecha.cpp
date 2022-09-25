// Adrian Alejandro Montes Mendoza

#include <iostream>
using namespace std;
#include <conio.h>
#include <string>
#include <sstream>

void split_str(string);

class Date {
private:
	unsigned int year = 0;
	unsigned int month = 0;
	unsigned int day = 0;
	string dateInString;
	
public:
	int valid_date = 0;
	operator const char* ()
	{
		ostringstream formattedDate; 
		formattedDate << day << " / " << month << " / " << year;
		dateInString = formattedDate.str();
		return dateInString.c_str();
	}
	// Unary increment operator (prefix)
	Date& operator ++ ()
	{
		
		day++;
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (day > 31)
			{
				day = 1;
				month++;
			}
				break;
		case 12:
			if (day > 31) {
				day = 1;
				month = 1;
				year++;
			}
				break;

		case 2: 
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day > 29)
				{
					day = 1;
					month++;
				}
			}
			else if (day > 28) {
				day = 1;
				month++;
			}

			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				day = 1;
				month++;
				}
			
			break;

		}


		return *this;
	}

	Date(int, int, int);
	void check_date(void);

};

//Constructor de la clase
Date::Date(int INPUT_YEAR, int INPUT_MONTH, int INPUT_DAY) {
	month = INPUT_MONTH;
	day = INPUT_DAY;
	year = INPUT_YEAR;
}

//Definicion del metodo validar fecha
void Date::check_date(void) {
	if (month >= 1 && month <= 12)
	{
		switch (month) {
		case  1:
		case  3:
		case  5:
		case  7:
		case  8:
		case 10:
		case 12: if (day < 1 || day > 31 || year < 1900 || year > 2100)
			valid_date = 0;
			   else valid_date = 1;
			break;

		case  4:
		case  6:
		case  9:
		case 11: if (day < 1 || day > 30 || year < 1900 || year > 2100)
			valid_date = 0;
			   else valid_date = 1;
			break;

		case  2: if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			if (day >= 1 && day <= 29)
				valid_date = 1;
		}
	
			   else
			if (day >= 1 && day <= 28)
				valid_date = 1;
		}
	}

	if (valid_date == 0) {
		cout << "Fecha incorrecta" << endl << endl;
	}
	else
	{
		cout << "Fecha correcta" << endl << endl;
	}
}
//Funcion para separar un string y convertirlo a int
void split_str(string _fulldate) {
	int nyear, nmonth, nday;
	string word = "";
	int i = 0;
	int size = 4;
	string array[4] = {};
	int date_numbers[4] = {};
	
	_fulldate += '-'; 
	for (auto x : _fulldate)
	{
		if (x == '-' || x == '/' || x == ' ' || x== '.')
		{
			i++;
			array[i] = word;
			date_numbers[i] = stoi(array[i]);
			word = "";		
		}
		else
		{
			word = word + x;
		}
		
	}
	
	nday = date_numbers[1];
	nmonth = date_numbers[2];
	nyear = date_numbers[3];	
	
	
	Date d1(nyear, nmonth, nday);
	d1.check_date();
	
	
	cout << "Sumando un dia a la fecha actual..." << endl << endl;
	++d1; //Sobrecarga de operadores ++
	cout << "La nueva fecha es: "<< d1; //sobrecarga de operadores << insercion


} 

int main()
{
	string full_date;
	cout << "Actividad Sobrecarga de operadores por |Adrian Alejandro Montes Mendoza| |22110135|" << endl;
	cout << "Ingrese una fecha con el formato 'dd-mm-aaaa' o 'dd/mm/aaaa': ";
	getline(cin, full_date);
	cout << endl;
	split_str(full_date);
	
}
