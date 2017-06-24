#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>


using namespace std;
//The program gets an author and three books they've written.



//Structure holding information about books
struct BookInfo
{
	string bookName;
	double bookPrice;

	
};

//Structure holding information about author(s)
struct Author
{
	string authorName;//Name of the author
	BookInfo authorsBooks[3];//Array that holds nested struct Bookinfo

};

void showInfo(Author a[], int size);//show input
void getInfo(Author a[], int size);//Get user inputs

int main()
{
	int index = 3;
	Author catalogue[3] = { "NONE", {"NONE",0,"NONE",0 ,"NONE",0 },
		"NONE",{ "NONE",0,"NONE",0 ,"NONE",0 },
		"NONE",{ "NONE",0,"NONE",0,"NONE",0 } };

	cout << "Here is the data after initialization\n";
	showInfo(catalogue, index);

	cout << "\nGet user's input";
	getInfo(catalogue, index);

	cout << "\nHere is the data after user's input\n";
	showInfo(catalogue, index);



	system("Pause");
	return 0; 
}

void showInfo(Author a[], int size)//Displays the information about the author and their books
{
	cout << fixed << showpoint << setprecision(2);//Sets the formatting used for doubles
	for (size_t i = 0; i < size; i++)
	{
		cout << "The author: " << a[i].authorName.c_str() << endl;
			for (size_t t = 0; t < size; t++)
			{
				cout<<"\tThe title: " << a[i].authorsBooks[t].bookName.c_str() <<", the price: $"<< a[i].authorsBooks[t].bookPrice << endl;
			}
	}
}

void getInfo(Author a[], int size)//Gets info from the user
{

	for (size_t i = 0; i < size; i++)
	{
		cout << "\nEnter the author's name: ";
		//cin.ignore();
		getline(cin, a[i].authorName);

		if (a[i].authorName == "NONE")
		{
			break;
		}			
		else
		{
			for (size_t j = 0; j < size; j++)
			{
				cout << "Enter title: " << j + 1 << ": ";
				//cin.ignore();
				getline(cin, a[i].authorsBooks[j].bookName);
				
				if (a[i].authorsBooks[j].bookName == "NONE")
					break;
				else
					cout << "Enter price: " << j + 1 << ": $";
				string temp;
				getline(cin, temp);
				a[i].authorsBooks[j].bookPrice = stod(temp);
			}
		}
	}
}

