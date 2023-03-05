//write include statements
#include"data_types.h"
#include<iostream>


//write namespace using statement for cout
using std::cout; using std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	int num;
	cout<<"Enter value for num1: ";
	cin>>num;
	int result= multiply_numbers(num);
	cout<<result<<"\n";
	int num1= 4;
	result= multiply_numbers(num1);
	cout<<result<<"\n";

	return 0;
}
