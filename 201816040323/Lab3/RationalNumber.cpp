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
RationalNumber::RationalNumber(int n,int d)
{
    if((n<0&&d>0) || (n>0&&d<0))
    {
        numerator=1;
        denominator=1;
    }
    else
    {
        if(d==0)
    {
        throw invalid_argument("Wrong, the denominator cannot be zero");
    }
    else
    {
        numerator=n;
        denominator=d;
    }
    }
    reduction();
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+ ( const RationalNumber &a) const
{
    RationalNumber t;
    t.numerator=numerator*a.denominator+denominator*a.numerator;
    t.denominator=a.denominator*denominator;
    t.reduction();
    return t;
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator- ( const RationalNumber &a) const
{
    RationalNumber t;
    t.numerator=numerator*a.denominator-denominator*a.numerator;
    t.denominator=a.denominator*denominator;
    t.reduction();
    return t;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator* ( const RationalNumber &a) const
{
    RationalNumber t;
    t.numerator=numerator*a.numerator;
    t.denominator=a.denominator*denominator;
    t.reduction();
    return t;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/ ( const RationalNumber &a) const
{
    RationalNumber t;
    t.numerator=numerator*a.denominator;
    t.denominator=denominator*a.numerator;
    if(t.denominator==0)
        throw invalid_argument ("Wrong, the denominator cannot be zero");
    t.reduction();
    return t;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator> ( const RationalNumber &a) const
{
     if((double)numerator/denominator > (double)a.numerator/a.denominator)
        return true;
     else
        return false;
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator< ( const RationalNumber &a) const
{
     if((double)numerator/denominator < (double)a.numerator/a.denominator)
        return true;
     else
        return false;
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>= ( const RationalNumber &a) const
{
     if((double)numerator/denominator >= (double)a.numerator/a.denominator)
        return true;
     else
        return false;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<= ( const RationalNumber &a) const
{
     if((double)numerator/denominator <= (double)a.numerator/a.denominator)
        return true;
     else
        return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==( const RationalNumber &a) const
{
     if((double)numerator/denominator == (double)a.numerator/a.denominator)
        return true;
     else
        return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!= ( const RationalNumber &a) const
{
     if((double)numerator/denominator != (double)a.numerator/a.denominator)
        return true;
     else
        return false;
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
