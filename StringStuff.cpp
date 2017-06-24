#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std; 

void len();//strlen example
void cat();//strcat example
void copy();//strcpy example
void cat2();//strncat example
void copy2();//strncpy example
void strstr();//strstr example
void compare();//strcmp example

int main()
{
	/*const int size = 70;
	char happiness[size]="The length of the string of happiness is: ";//String 1
	char happinessPlus[] = "whatever you want!";//String2*/
	
	len();//function for strlen example
	cat();//function for strcat example
	copy();//strcpy example
	cat2();//strncat example
	copy2();//strncpy example
	strstr();//strstr example
	compare();//strcmp example

	system("Pause");
	return 0;
}


//Strlen example
void len()
{

	char str1[] = "The length of the string of happiness is: ";//String 1
	char str2[] = "whatever you want!";//String2

	cout << "Strlen is used the length of the c-string "
		<< "but doesn't include the null terminator\n"
		<< "The length of the c-string one is " << strlen(str1) << endl;
	cout <<"The lenght of c-string two is " << strlen(str2) << endl << endl;


}

//strcat example
void cat()
{
	const int size = 70;
	char str1[size] = "The length of the string of happiness is: ";//String 1
	char str2[] = "whatever you want!";//String2

	
	cout << "Strcat accepts two c-strings and \n"
		<< "appends the second string \n"
		<< "to the first string; the first string is altered \n"
		<< "and the second is not.\n";
	strcat_s(str1, str2);
	cout << "String two will be appended to string one:\n " << str1 << endl << endl;

}

void copy()
{
	//Strcpy
	char str1[] = "The length of the string of happiness is: ";//String 1
	char str2[] = "whatever you want!";//String2
	cout << "Strcpy accepts two c-strings and \n"
		<< "copies the second string \n"
		<< "to the first string; the second string is \n"
		<< "and left unchanged.\n";
	strcpy_s(str1,str2);
	cout << "String two will be copied to string one:\n " << str1 << endl << endl;


}

void cat2()
{
	const int size = 70;
	char str1[size] = "The length of the string of happiness is: ";//String 1
	char str2[] = "whatever you want!";//String2
	//Strncat
	cout << "Strncat accepts two c-strings to two C-strings as arguments\n"
		<< "and an integer argument. The third argument,an integer\n"
		<< "indicates the maximum number of characters to copy from the second\n"
		<< "c-string to the first c-string.\n";
	strncat_s(str1, str2, 8);
	cout << "The number of characters copied is 8: " << str1 << endl << endl;
}

//Example of strncpy
void copy2()
{
	//Strncpy
	char str1[] = "The length of the string of happiness is: ";//String 1
	char str2[] = "whatever you want!";//String2
	cout << "Strcpy accepts two c-strings and \n"
		<< "copies the second string and the thrid argument incidates \n"
		<< "the max num of characters to copy  \n"
		<< "to the first string; the second string is.\n";
	strncpy_s(str1, str2, 4);
	cout << "8 char of String two will be copied to string one:\n " << str1 << endl << endl;

}

//Example of strstr
void strstr()
{
	char str1[] = "The length of the string of happiness is: ";//String 1
	char*strPtr = nullptr;
	strPtr=strstr(str1, "happiness");
	
	cout << "Strstr accepts two c-strings and \n"
		<< "And searches for the first occurence of string 2 in string 1.\n"
		<< "If string 2 is found in string 1 the function returns a pointer.\n"
		<< "Otherwise it returns a nullptr(address0).\n";
	cout <<"We located: " << strPtr << ", within the first string"<<endl << endl;

}

//Using string compare and the == and != comparison functions
void compare()
{
	//Strcmp
	char str1[] = "The length of the string of happiness is: ";//String 1
	char str2[] = "whatever you want!";//String2

	cout << "String 1 is: " << str1 << endl;
	cout << "String 2 is: " << str2 << endl;

	cout << "Strcmp accepts two c-strings to two c-string arguments.\n"
		<< "If string 1 and string 2 are the same the function returns 0.\n"
		<< "If string is alphabetically greater than string 1 it returns a neg number. \n"
		<< "If string is alphabetically less than string 1 it returns a pos number.\n\n";
	
	if (strcmp(str1,str2)==0)
	{
		cout << "You have entered the same string twice.\n\n";
	}
	else
	{
		cout << "The strings are not the same.\n\n";
	}

	cout << "If != is used of == the result will be:\n\n";


	if (strcmp(str1, str2) != 0)
	{

		cout << "The strings are not the same.\n\n";
	}
	else
	{
		cout << "You have entered the same string twice.\n\n";
	}



}