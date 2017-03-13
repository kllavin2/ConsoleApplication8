/*
Kristi Lavin
3/9/17
Lab 3

This program simulates the purchase of a concrete floor.  

*/

#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>

using namespace std;

const double Pi = 3.14;//Pi

void welcome();//Welcomes the user

void getInfo(string &, string &); //Gets their name and number

int selectShape();//asks for the shape of the floor

double calcSqFeet(double, double);//calculates square feet

//Prototypes if the floor is circular
double getDiam();//gets diameter
double calcSqFeet(double);//Square feet of the cirle, this is an overload function

int selectFloorGrade();//selects the grade of the floor

double calcTotalPrice(int, double);//calculates the total price

void displayEstimate(string, string, double, int, double);//Will display the estimate

void goodBye();//Ends the program


int main()
{
	string again; //Asks if they want a new quote
	string name;//User name
	string	phoneNumber;//user phone number

	//Get the floor shape choice


	
	welcome();
	getInfo(name, phoneNumber);
	
	do
	{
		selectShape();
	} while (again=="Y" || again=="y"||again=="Yes"||again=="yes");
	
	//Step 5: Use an if/else statement to call functions that will:
	//Get the dimension of the floor and calc sq ft
	/*
	Ask if they want another esitmate. Yes:Begin with selecting floor shape, etc.
	If No: the do/while loop ends and a goodby function is called
	*/
	goodBye();
	system("Pause");
	return 0;

}

void welcome() 
{
	cout << "\tWelcome to Lavin Concrete Suppliers\t\n";
	cout << "\tConcrete is our business!\t\n";
}


void getInfo(string &customerName, string &customerPhoneNumber)//Get the customers name and number
{
	
	cout << "Please enter your full name: " << endl;
	getline(cin, customerName);
	while (customerName.size()<3 || customerName.size()>50000000)
	{
		cout << "Please enter a valid name.\n";
		cout << "Please enter your full name: " << endl;
		getline(cin, customerName);
	}

	cout << "Please enter your telephone number: (ex:555.555.5555)" << endl;
	getline(cin, customerPhoneNumber);
	while (customerPhoneNumber.size()<10 || customerPhoneNumber.size()>12)
	{
		cout << "Please enter a valid telephone number : (ex:555.555.5555)\n";
		getline(cin, customerPhoneNumber);
	}
	
}

int selectShape()
{
	int choice;
	do
	{
		cout << "\tEstimate\t\n";
		cout << "To describe the shape of the floor, please select shape 1 or 2:\n";
		cout << "1. Rectangular\n";
		cout << "2. Circular\n";
		cin >> choice;
		if (choice != 1 || choice != 2)
		{
			cout << "The choice you have selected is incorrect please try again.\n";
			continue;
		}
		else if (choice==1)
		{
			cout << " ";
		}

	} while (true);
	



//Steps 4:A menu is presented. The user selects the shape of the floor (rec or circ).
//Use local variables and return the variable back to the main function 
//If the customer selects the get another estimate menu option, 
//the code should call the function selectShape directly.  There is no need to ask for name and number again.
	return 69;
}


//Rectangle was picked
void getLenWid(double&, double&)
{

}
double	calcSqFeet(double, double)
{
	return 69.88;
}
//If floor picked is a circle


double getDiam()
{
	return 69.99;
}
double calcSqFeet(double)//calcSqFeet is an overloaded function!
{
	//Radius will be a local variable
	return 69.69;
}
const double StdPrice = 41.50;
const double PremPrice = 63.70;
int selectFloorGrade()
{
//Menu for selecting floor grade. 
//Use local variables that are returned to the main function5
	return 69;
}

double calcTotalPrice(int,double)
{
//Accepts floor grade and sqft and multiples the correct values to get a final price
//Return results to main use constants
	return 69.69;
}

void displayEstimate(string, string, double, int, double)
{
//Accepts cust name, num, calc sqft, floor grade, total price and prints the estimate.
//Use sample out for the complete est and formatting.
//Use constants, a message regarding a "valid for 30 days", and the date of program submission in the estimate
	
}

void goodBye()
{
//Creative ending
}

