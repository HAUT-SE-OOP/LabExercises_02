// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber( int Numerator, int  Denominator)
{
    numerator=Numerator;
    if(Denominator>0)
    {
        denominator=Denominator;
    }

    else
    {
        denominator=1;throw invalid_argument("Denominator should be greater than 0");
    }

    reduction();
}//end function RationalNumber constructor
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator +(const RationalNumber &op2)
{
    RationalNumber x;
    x.numerator=op2.numerator*denominator+numerator*op2.denominator;
    x.denominator=denominator*op2.denominator;
    x.reduction();
    return x;
}//end function operator +


// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator -(const RationalNumber &op2)
{
    RationalNumber x;
    x.numerator=numerator*op2.denominator-op2.numerator*denominator;
    x.denominator=denominator*op2.denominator;
    x.reduction();
    return x;
}//end function operator -
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator *(const RationalNumber &op2)
{
    RationalNumber x;
    x.numerator=numerator*op2.numerator;
    x.denominator=denominator*op2.denominator;
    x.reduction();
    return x;
}//end function operator *
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator /(const RationalNumber &op2)
{
    RationalNumber x;
    x.numerator=numerator*op2.denominator;
    x.denominator=denominator*op2.numerator;
    x.reduction();
    return x;
}//end function operator /
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &op2) const
{
    int numerator1,numerator2;
    numerator1=numerator*op2.denominator;
    numerator2=op2.numerator*denominator;
    if(numerator1>numerator2)
        return true;
    return false;
}//end function operator >
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber &op2) const
{
    if(*this>=op2)
        return false;
    return true;
}//end function operator <
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber &op2) const
{
    if(*this>op2||*this==op2)
        return true;
    return false;
}//end function operator >=
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &op2) const
{
    if(*this>op2)
        return false;
    return true;
}//end function operator <=

// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber &op2) const
{
    int numerator1,numerator2;
    numerator1=numerator*op2.denominator;
    numerator2=op2.numerator*denominator;
    if(numerator1==numerator2)
        return true;
    return false;
}//end function operator ==

// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber &op2) const
{
    if(*this==op2)
        return false;
    return true;
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
} // end function reduction
