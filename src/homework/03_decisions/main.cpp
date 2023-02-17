//write include statements
#include<iostream>
#include "decisions.h"

using std::cout; using std::cin;


int main() 
{	
	int menu_option;
	cout<<"MAIN MENU"<<"\n";
	cout<<"1-Letter grade using if"<<"\n";
	cout<<"2-Letter grade using switch"<<"\n";
	cout<<"3-Exit"<<"\n";
	cout<<"Select Menu Option: ";
	cin>>menu_option;
	if (menu_option == 1 || 2)
	{
		int grade_number;
		cout<<"Enter number 0-100: ";
		cin>>grade_number;
		if(grade_number < 0 || grade_number > 100)
		{
			cout<<"Number is out of range."<<"\n";
			
		}
		else
		{
			switch(menu_option)
			{
				case 1:
					cout<<get_letter_grade_using_if(grade_number)<<"\n";
				break;
				case 2:
					cout<<get_letter_grade_using_switch(grade_number)<<"\n";
				break;
		
			}
		}
	}



	return 0;
}