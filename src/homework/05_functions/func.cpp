//add include statements
#include "func.h"
//add function code here
double get_gc_content(const string& dna)
{
    double gc_count= 0;
    
    for(char c : dna)
    {
        if (c == 'G' || c == 'C')
        {
            gc_count++;
        }
    }

    return gc_count/dna.length();
}

string get_dna_complement(string& dna)
{
    string reversed_dna= get_reverse_string(dna);
    
    for (char& c: reversed_dna)
    {
        switch (c)
        {
            case 'A':
                c = 'T';
                break;
            case 'T':
                c = 'A';
                break;
            case 'C':
                c = 'G';
                break;
            case 'G':
                c = 'C';
                break;
        }
    }
    return reversed_dna;
}



string get_reverse_string(string& dna)
{
    int length= dna.length();
    for (int i= 0; i<length/2; i++)
    {
        char temp= dna[i];
        dna[i] = dna[length-i-1];
        dna[length-i-1] = temp;

    }
    return dna;
}

void main_menu()
{
    int choice;
    do
    {
        string input_dna;
        cout<<"Main Menu\n";
        cout<<"1- Get GC Content\n2- Get DNA Complement\n3- Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            case 2:
                cout<<"Enter DNA string: ";
                cin>>input_dna;
                switch (choice)
                {
                    case 1:
                        cout<<"GC Content of DNA is: "<<get_gc_content(input_dna)<<"\n";
                        break;
            
                    case 2:
                        cout<<"DNA Complement is: "<<get_dna_complement(input_dna)<<"\n";
                        break;
                }
                break;

            case 3:
                cout<<"Exiting...\n";
                break;


        }

    }
    while (choice != 3);
    
}