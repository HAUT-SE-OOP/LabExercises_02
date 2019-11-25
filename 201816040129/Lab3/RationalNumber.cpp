// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n1,int d1) // default constructor
{
    numerator=n1;
    denominator=d1;
    reduction();
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator
RationalNumber RationalNumber::operator+( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator=denominator*right.denominator;//denominator multiplication
    temp.numerator=numerator*right.denominator+right.numerator*denominator;//numerator multiplication
    temp.reduction();
    return temp;
};
/* Write definition for overloaded operator + */

// overloaded - operator
RationalNumber RationalNumber::operator-( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator=denominator*right.denominator;//denominator multiplication
    temp.numerator=numerator*right.denominator-right.numerator*denominator;//numerator multiplication
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator - */

// overloaded * operator
RationalNumber RationalNumber::operator*( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator=denominator*right.denominator;//denominator multiplication
    temp.numerator=numerator*right.numerator;//numerator multiplication
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator * */

// overloaded / operator
RationalNumber RationalNumber::operator/( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator=denominator/right.denominator;//denominator division
    temp.numerator=numerator/right.numerator;//numerator division
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
bool RationalNumber::operator>(RationalNumber &right)
{
    if(numerator*right.denominator>denominator*right.numerator)//if more than
        return true;
    else
        return false;
}
/* Write definition for operator > */

// overloaded < operator
bool RationalNumber::operator<(RationalNumber &right)
{
    if(numerator*right.denominator<denominator*right.numerator)//if less than
        return true;
    else
        return false;
}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator>=(RationalNumber &right)
{
    if(numerator*right.denominator<denominator*right.numerator)//if less than
        return false;
    else
        return true;
}
/* Write definition for operator >= */

// overloaded <= operator
bool RationalNumber::operator<=(RationalNumber &right)
{
    if(numerator*right.denominator>denominator*right.numerator)//if more than
        return false;
    else
        return true;
}
/* Write definition for operator <= */

// overloaded == operator
bool RationalNumber::operator==(RationalNumber &right)
{
    if(numerator*right.denominator==denominator*right.numerator)//if equal
        return true;
    else
        return false;
}
/* Write definition for operator == */

// overloaded != operator
bool RationalNumber::operator!=(RationalNumber &right)
{
    if(numerator*right.denominator==denominator*right.numerator)//if equal
        return false;
    else
        return true;
}
/* Write definition for operator != */

// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator: denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
} // end function reduction
