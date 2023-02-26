//add include statements

#include "dna.h"

//add function(s) code here

long long int factorial(int num)
{
    auto result=1;
    while (num > 0)
    {
        result*=num;
        num--;
    }
    return result;
}

int gcd(int num, int num1)
{
    auto remainder= 0;
    while (num1 != 0)
    {
        remainder=num % num1;
        num= num1;
        num1= remainder;
    }    
    return num;
}

void main_menu()
{
    int choice;
	int num, num1;
    char confirm = 'N';
	do
	{
		cout<<"Menu:\n";
		cout<<"1- Factorial\n";
		cout<<"2- Greatest Common Divisor\n";
		cout<<"3- Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			    cout<<"Enter positive integer:\n";
			    cin>>num;
			    cout<<"Factorial of "<<num<<" is "<<factorial(num)<<"\n";
			    break;

			case 2:
			    cout<<"Enter 2 positive integers:\n";
			    cin>> num >>num1;
			    cout<<"GCD of "<<num<<" and "<<num1<<" is "<<gcd(num,num1)<<"\n";
			    break;
			
			case 3:
			    cout<<"Are you sure you want to exit? Y/N: ";
			    cin>>confirm;
			    if (confirm == 'Y' || confirm == 'y')
			    {
				    cout<<"Program ended.\n";
			    }
                break;

			default:
                if (choice != 'N' && choice != 'n')
                {
                    cout<<"Invalid choice. Please enter valid choice.\n";
                }
            
            
			    break;

		}

	} while (choice != 3 || confirm == 'N' || confirm == 'n');
    

}