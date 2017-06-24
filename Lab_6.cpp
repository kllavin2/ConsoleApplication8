//Kristi Lavin
// 3/4/17
//Fuzzy Dice Lab
//This program allows users to buy items from the DecoCar and displays total.
#include<iostream>	
// #include<cmath>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	/*This contains the menu; allowing the user to buy: 
	Fuzzy Dice Mardi Gras beads and/or Bobble heads from the store.
	And 
	*/

	//Contants for the menu choices
	const int FuzzyDice = 1;
	const int MardiGrasBeads = 2;
	const int BobbleHeads = 3;
	const int	Quit_the_Program = 4;
	
	//Constants for item cost
	const double dice_ea = 6.25;
	const double beads_per_pack = 2.25;
	const double beads1_coupon_discount = 1.50;
	const double heads1_5_ea = 16.99;
	const double heads6_10_ea = 14.99;
	const double heads11_more_ea = 12.99;

	//Answer for coupon
	char answer;

	//String variable
	string coupon = "beads 1";
	string thanks = "Thank you for shopping with Decocars.";

	//Variables from user
	int choice; //Menu choice
	int numDice;//number of dice
	int numBeads;//number of beads
	int numBobbleHeads;//number of bobble heads
	double dice_total=0; //Cost totals initialized at 0
	double dice_running_total = 0;
	double beads_total=0;
	double beadsRunningTotal = 0;
	double bobble_head_total=0;
	double bobble_head_running_total = 0;
	double total=0;//final total


	//Make Header
	cout << "\tWelcome to Decocar\n";
	cout << "\tKristi Lavin, Owner\n";

	//Set up formatting for output
	cout << fixed << showpoint << setprecision(2);

	//Loop for menu choices
	do
	{
		//Display the menu
		cout << "\n\tOur Inventory:\n"
			<< "1. Fuzzy Dice\n"
			<< "2. Mardi Gras Beads\n"
			<< "3. Bobble Heads\n"
			<< "4. Quit the Program\n"
			<< "Please make a selection: \n";	
		cin >> choice;
		//Validate the menu choices
		if (choice<FuzzyDice || choice>Quit_the_Program)//Not choice 1-4
		{
			cout << "Sorry, we don't sell that item. \n";
			cout << "Please make another selection.\n";
			continue;
		} 
		//Process the users choice 1-3
		if (choice!=Quit_the_Program)
		{
			//Do data processing
			if (choice==1)//If the user selects Fuzzy dice
			{
				cout << "How many fuzzy dice would you like to buy?\n";
				cin >> numDice;
				if (numDice<1)//Number of fuzzy dice must not be negative
				{
					cout << "Please select a valid number of dice\n";
					continue;
				}
				dice_total = dice_ea*numDice;//calculate subtotal for fuzzy dice
				dice_running_total +=dice_total;
				cout << "The subtotal for dice is: $" << dice_running_total << endl;
				
			}
			
			else if (choice==2)//If the user selects beads
			{
				cout << "How many Mardi Gras Beads would you like to buy?\n";
				cin >> numBeads;
				if (numBeads < 1)//If the incorrect value is entered
				{
					cout << "Please select a valid number of beads\n";
					continue;
				}
				
				cout << "Do you have a coupon? y/n\n";//Checking for coupon
				cin >> answer;
				if (answer != 'y'&& answer != 'n')//user input if they have a coupon
				{
					cout << "Please enter either y or n\n";
					continue;
				}
				if (answer == 'y')//If they have a coupon
				{
					cout << "Please type in the coupon code:\n";
					cin >> coupon;
					if (coupon != "beads1")//If the coupon they entered was incorrect
					{
						cout << "The coupon code you enter was incorrect.\n";
						continue;
					}
					else//If the coupon code is correct lets the user know
					{
						cout << "Your coupon has been accepted.\n"
							<< "Your discount will now be applied.\n";

					}
					if (coupon == "beads1")//subtotal for beads with coupon
					{
						beads_total = beads1_coupon_discount*numBeads;
						beadsRunningTotal += beads_total;
						cout << "The subtotal for Mardi Grad bead(s) is: $" << beadsRunningTotal << endl;
						
					}
				}
				else if(answer == 'n')//If user selects n for coupon subtotal without discount
				{
					beads_total = numBeads*beads_per_pack;
					beadsRunningTotal += beads_total;
					cout << "The subtotal for Mardi Grad bead(s) is: $" << beadsRunningTotal << endl;
				}
			}
			else//Processes choice 3 bobble heads
			{
				cout << "How many bobble heads would you like to purchase?\n";
				cin >> numBobbleHeads;
				if (numBobbleHeads>=11)//Checks for 11 or greater bobble heads
				{
					bobble_head_total = numBobbleHeads*heads11_more_ea;
					bobble_head_running_total += bobble_head_total;
					cout << "The subtotal for Bobble Heads is: $" << bobble_head_running_total << endl;
					
				}
				else if (numBobbleHeads>=6&&numBobbleHeads<=10)//user had 6-10 bobble heads
				{
					bobble_head_total = numBobbleHeads*heads6_10_ea;
					bobble_head_running_total += bobble_head_total;
					cout << "The subtotal for Bobble Heads is: $" << bobble_head_running_total << endl;
					
				}
				else if (numBobbleHeads>0&&numBobbleHeads<=5)//user selects less than or equal to 5
				{
					bobble_head_total = numBobbleHeads*heads1_5_ea;
					bobble_head_running_total += bobble_head_total;
					cout << "The subtotal for Bobble Head(s) is: $" << bobble_head_running_total << endl;
					
				}
				else//if the number selected isn't 1 or greater
				{
					cout << "The number you have enter is invalid please make an appropriate selection." << endl;
					continue;
				}
				
			}
		}
		
	} while (choice!=Quit_the_Program);
	cout << thanks << endl;
	total = dice_total + beads_total + bobble_head_total;
	cout << "Your total is: $" << total << endl;// Print out total

	system("Pause");
	return 0;
}

