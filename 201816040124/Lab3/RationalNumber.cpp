// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.

#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int a,int b)
{
    numerator=a;
    denominator=b;
    reduction();
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
// overloaded + operator
RationalNumber RationalNumber::operator+(const RationalNumber &right)
{
    RationalNumber temp;
    temp.numerator=numerator*right.denominator+denominator*right.numerator;
    temp.denominator=denominator*right.denominator;
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator + */

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &right)
{
    RationalNumber temp;
    temp.numerator=numerator*right.denominator-denominator*right.numerator;
    temp.denominator=denominator*right.denominator;
    temp.reduction();
    return temp;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &right)
{
    RationalNumber temp;
    temp.numerator=numerator*right.numerator;
    temp.denominator=denominator*right.denominator;
    temp.reduction();
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &right)
{
    RationalNumber temp;
    if(right.numerator!=0)
    {
        temp.numerator=numerator*right.denominator;
        temp.denominator=denominator*right.numerator;
        temp.reduction();
        return temp;
    }
    else
        cout<<"³ýÊý²»ÄÜÎª0"<<endl;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>( RationalNumber &right)
{
    if(denominator!=right.denominator)
    {
    numerator=numerator*right.denominator;
    right.numerator=right.numerator*denominator;
    denominator=denominator*right.denominator;
    right.denominator=denominator;
    }
    return bool(numerator>right.numerator);
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<( RationalNumber &right)
{
    if(denominator!=right.denominator)
    {
    numerator=numerator*right.denominator;
    right.numerator=right.numerator*denominator;
    denominator=denominator*right.denominator;
    right.denominator=denominator;
    }
    return bool(numerator<right.numerator);
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=( RationalNumber &right)
{
    if(denominator!=right.denominator)
    {
    numerator=numerator*right.denominator;
    right.numerator=right.numerator*denominator;
    denominator=denominator*right.denominator;
    right.denominator=denominator;
    }
    return bool(numerator>=right.numerator);
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=( RationalNumber &right)
{
    if(denominator!=right.denominator)
    {
    numerator=numerator*right.denominator;
    right.numerator=right.numerator*denominator;
    denominator=denominator*right.denominator;
    right.denominator=denominator;
    }
    return bool(numerator<=right.numerator);
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(RationalNumber &right)
{
    if(denominator!=right.denominator)
    {
    numerator=numerator*right.denominator;
    right.numerator=right.numerator*denominator;
    denominator=denominator*right.denominator;
    right.denominator=denominator;
    }
    return bool(numerator==right.numerator);
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=( RationalNumber &right)
{
    if(denominator!=right.denominator)
    {
    numerator=numerator*right.denominator;
    right.numerator=right.numerator*denominator;
    denominator=denominator*right.denominator;
    right.denominator=denominator;
    }

    return bool(numerator!=right.numerator);
}
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
}// end function reduction
