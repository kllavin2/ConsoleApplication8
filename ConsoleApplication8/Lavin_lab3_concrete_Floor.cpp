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


void welcome();//Welcomes the user

void getInfo(string &, string &); //Gets their name and number

int selectShape();//asks for the shape of the floor

//For Rectangle Calculations
void getLenWid(double&len, double&wid);//Gets length and width
double calcSqFeet(double, double);//calculates square feet of rectangle

//For Circle Calculations
const double Pi = 3.14;//Pi
double getDiam();//gets diameter
double calcSqFeet(double);//Square feet of the cirle, this is an overload function

const double StdPrice = 41.50;//Cost of standard price
const double PremPrice = 63.75;//Cost of Premium price
int selectFloorGrade();//selects the grade of the floor

double calcTotalPrice(int, double);//calculates the total price

void displayEstimate(string, string, double, int, double);//Will display the estimate

void goodBye();//Ends the program


int main()
{
	char again; //Asks if they want a new quote
	string name;//User name
	string	phoneNumber;//user phone number
	welcome();
	getInfo(name, phoneNumber);

	//Get the floor shape choice
	double len, wid, diam;
	int choice;
	int floorGradeChoice;
	double sqFt;
	double total;
	double estimate;
	

	do//loop to determine shape, concrete grade, and cost
	{
		choice = selectShape();//gets shape from user
		if (choice==1)
		{
			getLenWid(len, wid);
			sqFt=calcSqFeet(len, wid);
		}
		else
		{
			diam = getDiam();
			sqFt=calcSqFeet(diam);
		}
		floorGradeChoice = selectFloorGrade();//calls function for grade of concrete
		total=calcTotalPrice(floorGradeChoice, sqFt);//calls function for price
		displayEstimate(name, phoneNumber,sqFt,floorGradeChoice,total);//calls function for estimate

		cout << "\t Would you like another estimate? [Y or N]";
		cin >> again;
		while (again!='Y' && again!='N' && again!='n'&& again!='y')
		{
			cout << "Invalid entry.\n";
			cout<< "\t Would you like another estimate? [Y or N] ";
			cin>> again;
		}
		
	} while (again == 'Y' || again == 'y');//If user is done getting estimates loop ends
	
		goodBye();
		system("Pause");
		return 0;
	
	

}

void welcome()//Welcomes customer 
{
	cout << "\tWelcome to Lavin Concrete Suppliers\t\n";
	cout << "\tConcrete is our business!\t\n\n";
}


void getInfo(string &customerName, string &customerPhoneNumber)//Get the customers name and number
{
	
	cout << "Please enter your full name: ";//Customer name
	getline(cin, customerName);

	cout << "Please enter your telephone number: (ex:555.555.5555) ";//Customer telephone number
	getline(cin, customerPhoneNumber);
	
}

int selectShape()//Gets the shape circle or rectangle
{
	const int rectangle = 1;
	const int circle = 2;
	int choice;
	
		cout << "\n\tEstimate\t\n\n";
		cout << "To describe the shape of the floor, please select shape 1 or 2:\n";
		cout << "1. Rectangular\n";
		cout << "2. Circular\n\n";
		cout << "Selection: ";
		cin >> choice;
		while (choice < rectangle || choice > circle)
		{
			cout << "The choice you have selected is incorrect please try again.\n\n";
			cout << "1. Rectangular\n";
			cout << "2. Circular\n";
			cout << "Selection: ";
			cin >> choice;
		}
	
	return choice;
}


// IF Rectangle was picked

void getLenWid(double&len, double&wid)
{	
	cout << "\nPlease input the length of your floor\n";
	cout <<"    "<< "(rounding up to the nearest half foot ex: 11.5): ";
	cin >> len;
	while (len <= 0)
	{
		cout << "The input you have entered is not valid.\n";
		cout << "\nPlease input the length of your floor\n";
		cout << "    " << "(rounding up to the nearest half foot ex: 11.5): ";
		cin >> len;
	}

	cout << "\nPlease input the width of your floor\n";
	cout << "    "<<"(rounding up to the nearest half foot ex: 11.5): ";
	cin >> wid;
	while(wid <= 0)
	{
		cout << "\nThe input you have entered is not valid.\n";
		cout << "\nPlease input the width of your floor\n";
		cout << "    " << "(rounding up to the nearest half foot ex: 11.5): ";
		cin >> wid;
	}

}

//Calculates SqFt of a rectangle
double	calcSqFeet(double len, double wid)
{
	double recSqFt = len*wid;
	return recSqFt;
}

//If floor picked is a circle
double getDiam()//Get size of the circle
{
	double diam;
	cout << "\n\n Please enter the diameter of your floor: ";
	cin >> diam;
	while (diam <= 0)
	{
		cout << "\nThe input you have entered is not valid.\n";
		cout << "Please input the diameter of your floor: ";
		cin >> diam;
	}

	return diam;
}

//Calculates the sqft of the circle
double calcSqFeet(double diam)
{
	double rad = diam / 2;
	double circSqFt;
	circSqFt = Pi*(pow(rad, 2));
	return circSqFt;
}

//Menu for selecting floor grade
int selectFloorGrade()
{
	int floorGradeChoice;
	int Std = 1;
	int Prem = 2;
	cout << setprecision(2) << fixed;
	cout << "\n\nThere are 2 grades of floor that are available.\n";
	cout << "All prices are based on square feet.\n";
	cout << "1. Standard grade  " <<"      4 inches thick	    $"<<StdPrice << endl;
	cout << "2. Premium grade	" <<" 6 inches thick	    $"<< PremPrice << endl;
	cout << "\nTo select the type of floor, please enter 1 or 2: ";
	cin >> floorGradeChoice;
	while (floorGradeChoice != Std && floorGradeChoice != Prem)
	{
		cout << "\n\The input you have entered is not valid\n";
		cout << "There are 2 grades of floor that are available.\n";
		cout << "All prices are based on square feet.\n";
		cout << "1. Standard grade	  4 inches thick     $" << StdPrice << endl;
		cout << "2. Premium grade	  6 inches thick     $" << PremPrice << endl;
		cout << "\nTo select the type of floor, please enter 1 or 2: ";
		cin >> floorGradeChoice;
	}
	return floorGradeChoice;
}

//Calculates the total price 
double calcTotalPrice(int grade,double sqFt)
{
	double totalPrice;
	if (grade==1)
	{
		totalPrice = StdPrice*sqFt;
	}
	else
	{
		totalPrice = PremPrice*sqFt;
	}
	


	return totalPrice;
}

//Displays the estimate based on user choice
void displayEstimate(string name, string phoneNumber, double sqFt, int floorGradeChoice, double total)
{

	cout << "\n\t Estimate\t\n";
	cout << "Customer Name: " << name << endl;
	cout << "Telephone Number: " << phoneNumber << endl;
	cout << "\nSquare Feet: " << sqFt << endl;
	cout << "Floor Grade: ";
	if (floorGradeChoice==1)
	{
		cout << "Standard" << "\tPrice per square foot $" << StdPrice << endl;
	}
	else if (floorGradeChoice==2)
	{
		cout << "Premium" << "\tPrice per square foot $" << PremPrice << endl;
	}
	cout << "\n\t Total Cost:  $ " << total << endl;
	cout << "\nDate: March 14, 2017\n";
	cout << "This estimate is valid for 30 days from the above date.\n";
	
}

//Good bye to user
void goodBye()
{
	cout << "\n\t Thank you for visiting Lavin Concrete Suppliers\n";
	cout << "Please call 301-876-5309 to schedule an on-site appointment.\n";
}

