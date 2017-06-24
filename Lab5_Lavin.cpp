#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

double average(double* score, int numScores);
int howManyAs(double* score, int numScores);


int main()
{
	int numScores;//number of tests
	double * score;//scores of each 

		
	cout << "Please enter the number of tests scores: ";//Ask user for number of test
	cin >> numScores; //User input

	while (numScores<0)//Validating user inpute is grt than zero
	{
		cout << "Please enter test scores: ";
		cin >> numScores;
	}
	
	score = new double[numScores];

	for (int i = 0; i < numScores; i++)//tests for scoring entered by the user
	{
		cout << "Please enter test scores for test " << i + 1 << " : ";
		cin >> score[i];
		if (score[i] < 0|| score[i] > 100)//Validating scores
		{
			cout << "A test score must be in the range of 0 to 100.";
			cout << " Please re-enter: ";
			cin >> score[i];
		}
	}
	
	
	average(score,numScores);//Average	
	
	howManyAs(score,numScores);//Number of As
	
	delete[] score;

	system("pause");
	return    0;

}

//Calculates the average
double average(double* score, int numScores)
{

	double total = 0;
	for (size_t i = 0; i < numScores; i++)
	{
		total = total + *(score + i);
	}
	cout << "The average test score is: ";
	cout << fixed << showpoint << setprecision(1) << total / numScores << endl;

	return total/numScores;
}

//Calculates the number of As
int howManyAs(double* score, int numScores)
{

	int Atotal = 0;
	for (size_t i = 0; i < numScores; i++)
	{
		if (score[i]>=90)
		{
			Atotal ++;
		}
	
	}
	cout << "The number of A grades is: ";
	cout << Atotal << endl;
	
	return Atotal;
}