#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n,int d)
{
    if(n<0||d<0)
    {
        n=1;
        d=1;
    }
    else
    {
        numerator=n;
        denominator=d;
    }
    reduction();
}
// Implement the RationalNumber constructor. Validate d first to ensure that  it is a positive number and set it to 1 if not. Call the reduction utility function at the end
// overloaded + operator

// definition for overloaded operator +
RationalNumber RationalNumber::operator+( const RationalNumber &op1 ) const
{
    int n,d,c,b;
     n = numerator;
     d = denominator;
     c = op1.numerator;
     b = op1.denominator;
     return RationalNumber(n*b+d*c,d*b);

}

// overloaded - operator
RationalNumber RationalNumber:: operator -( const RationalNumber &op2) const
{
    int a,b ;
    int multiy ;
    multiy = op2.denominator * denominator ;
    a = numerator* op2.denominator  ;
    b= denominator * op2.numerator ;
    return RationalNumber(a-b,multiy);
}// definition for overloaded operator -

// overloaded * operator
RationalNumber RationalNumber:: operator *( const RationalNumber &op3) const
{
    int n,d,c,b;
     n = numerator;
     d = denominator;
     c = op3.numerator;
     b = op3.denominator;
    return RationalNumber(n*c,d*b);
}
// definition for overloaded operator
// overloaded / operator
RationalNumber RationalNumber:: operator /( const RationalNumber &op4) const
{
    int n,d,c,b;
     n = numerator;
     d = denominator;
     c = op4.numerator;
     b = op4.denominator;
    return RationalNumber(n*b,d*c);
}
//definition for overloaded operator /. Check if the client is attempting to divide by zero and report an error message if so

// overloaded > operator
bool RationalNumber::operator>( const RationalNumber &op5 ) const
{
    RationalNumber temp(numerator,denominator);
    temp = temp - op5;
    if ( temp.numerator > 0 )
    {
        return true;
    }
    else
    {
        return false;
    }

}
// definition for operator >
// overloaded < operator
bool RationalNumber::operator<( const RationalNumber &op6 ) const
{
    RationalNumber temp(numerator,denominator);
    temp = temp - op6;
    if ( temp.numerator < 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
// definition for operator <
// overloaded >= operator
bool RationalNumber::operator>=( const RationalNumber &op7 ) const
{
    RationalNumber temp(numerator,denominator);
    temp = temp - op7;
    if ( temp.numerator >= 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
// definition for operator >=
// overloaded <= operator
bool RationalNumber::operator<=( const RationalNumber &op8 ) const
{
    RationalNumber temp(numerator,denominator);
    temp = temp - op8;
    if ( temp.numerator <= 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
// definition for operator <=
// overloaded == operator
bool RationalNumber::operator==( const RationalNumber &op9 ) const
{
    RationalNumber temp(numerator,denominator);
     if (( temp.denominator == op9.denominator) && (temp.numerator == op9.numerator))
     {
         return true;
     }
     else
     {
         return false;
     }
}
// definition for operator ==
// overloaded != operator
bool RationalNumber::operator!=( const RationalNumber &op10 ) const
{
    RationalNumber temp(numerator,denominator);
     if (( temp.denominator != op10.denominator) || (temp.numerator != op10.numerator))
     {
         return true;
     }
     else
     {
         return false;
     }
}
// definition for operator !=
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
