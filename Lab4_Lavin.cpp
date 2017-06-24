#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<fstream>

using namespace std;

//Global Constants for arrays
const int NUM_MONKEYS = 3;
const int NUM_Days = 7;

void getData(string (&mn)[NUM_MONKEYS], int (&fud)[NUM_MONKEYS][NUM_Days]);
void showData(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days]);
double averageIntake(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days]);
int dietMonkey(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days]);
int bulkingMonkey(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days]);

int main()
{
	string mn[NUM_MONKEYS];//1d Arrray for monkey names
	int fud[NUM_MONKEYS][NUM_Days];//2d array for food
	
	getData(mn, fud);
	showData(mn,fud);
	averageIntake(mn, fud);
	dietMonkey(mn, fud);
	bulkingMonkey(mn, fud);
	
	system("Pause");
	return 0;
}

void getData(string(&mn)[NUM_MONKEYS], int(&fud)[NUM_MONKEYS][NUM_Days])//Pulls data from text files
{
	

	ifstream inputFile;//Input file with monkey names

	inputFile.open("monkey_names.txt");//Opens the file

	if (inputFile.is_open())
	{
		for (size_t i = 0; i < NUM_MONKEYS; i++)//Get info from files
		{
			getline(inputFile, mn[i]);
		}

	}
	else//If there are problems opening the file
	{
		cout << "Error opening file.\n";
	}

	inputFile.close();//Closes the file


	ifstream myFile;//Input file with monkey names

	myFile.open("food.txt");//Opens the file for food

	if (myFile.is_open())
	{
		for (size_t i = 0; i < NUM_MONKEYS; i++)//getting info from files
		{
			for (size_t f = 0; f < NUM_Days; f++)
			{
				string s;
				getline(myFile, s);
				fud[i][f] = stoi(s);
			}
		}
	}
	else//If there is a problem opening the file
	{
		cout << "Error opening file.\n";
	}
	myFile.close();//Closes the file
}

void showData(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days])//Show the data pulled from the files in a chart
{

	cout << "Name\t" << "Day 1\t" << "Day 2\t" << "Day 3\t" << "Day 4\t" << "Day 5\t" << "Day 6\t"<<"Day 7\t\n";//Header

	for (size_t i = 0; i < NUM_MONKEYS; i++)//Gets Monkey names for chart
	{
		cout << mn[i]<<"\t";
		for (size_t f = 0; f < NUM_Days; f++)//Gets Daily totals of food for each monkey
		{
			cout << fud[i][f] << "\t";
		}
		cout << "\n\n";
	}

}

double averageIntake(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days])//Finds the avg food ea monkey ate daily
{
	double tot1 = 0;//total pound of food for each monkey
	double avg1;//holds the average amt of food for ea monkey

	cout << "Name\t" << "\t" << "Average daily intake in Pounds\n";

	for (int row= 0; row < NUM_MONKEYS; row++)
	{
		cout << mn[row] << "\t";
		tot1 = 0;
		for (int col = 0; col < NUM_Days; col++)
		{
			tot1 += fud[row][col];
			avg1 = tot1 / NUM_Days;
		}
		cout << setprecision(1) << fixed;
		cout << avg1 << "\t";
		cout << "\n\n";
	}
	
	return 0;
}

int dietMonkey(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days])
{
	
	int lowest = 9999;
	int m = -1;
	int d = 0;
	for (int monkey = 0; monkey < NUM_MONKEYS; monkey++)
	{
		for (int day = 0; day < NUM_Days; day++)
		{
			if (fud[monkey][day] < lowest)
			{
				lowest = fud[monkey][day];
				m = monkey;
				d = day;
			}
		}		
	}
	cout << "Least amount of food: " << mn[m] << " ate " << lowest << " pounds on day # " << d<<"\n";
	return 0;
}

int bulkingMonkey(string mn[NUM_MONKEYS], int fud[NUM_MONKEYS][NUM_Days])
{
	int highest = 0;
	int m = -1;
	int d = 0;
	for (int monkey = 0; monkey < NUM_MONKEYS; monkey++)
	{
		for (int day = 0; day < NUM_Days; day++)
		{
			if (fud[monkey][day] > highest)
			{
				highest = fud[monkey][day];
				m = monkey;
				d = day;
			}
		}
	}
	cout << "Most amount of food: " << mn[m] << " ate " << highest << " pounds on day # " << d<<"\n";
	return 0;

	return 0;
}