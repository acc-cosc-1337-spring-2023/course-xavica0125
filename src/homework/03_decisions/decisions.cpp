//write include statement for decisions header
#include"decisions.h"


//Write code for function(s) code here

char get_letter_grade_using_if(int grade)
{
    if (grade >= 90 && grade <= 100)
    {
        return 'A';
    }
    else if (grade < 90 && grade >=80)
    {
        return 'B';
    }
    else if (grade < 80 && grade >= 70)
    {
        return 'C';
    }
    else if (grade < 70 && grade >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

char get_letter_grade_using_switch(int grade)
{
    grade= grade/10;
    switch (grade)
    {
        case 10:
        case 9:
            return 'A';
        break;
        case 8:
            return 'B';
        break;
        case 7: 
            return 'C';
        break;
        case 6:
            return 'D';
        break;
        default:
            return 'F';
        break;
    }
}