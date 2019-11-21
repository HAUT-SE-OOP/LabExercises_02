// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;
#include "RationalNumber.h"
#include <cctype>
// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber(int a,int b)
  {
        numerator=a; // private variable numerator
        denominator=b;
        reduction();
  }
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber& a)
{
    RationalNumber op;
    op.numerator=this->numerator*a.denominator+this->denominator*a.numerator;
    op.denominator=this->denominator*a.denominator;
    op.reduction();
    return op;
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber& a)
{
    RationalNumber op;
    op.numerator=this->numerator*a.denominator-this->denominator*a.numerator;
    op.denominator=this->denominator*a.denominator;
    op.reduction();
    return op;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber& a)
{
    RationalNumber op;
    op.numerator=this->numerator*a.numerator;
    op.denominator=this->denominator*a.denominator;
    op.reduction();
    return op;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to di#include <cctype> vide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber& a)
{
    RationalNumber op;
    op.numerator=this->numerator*a.denominator;
    op.denominator=this->denominator*a.numerator;
    op.reduction();
    return op;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>( const RationalNumber &a) const
{
    return (*this<=a)?0:1;
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<( const RationalNumber &a) const
{
    return (numerator*a.denominator<denominator*a.numerator)?1:0;
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=( const RationalNumber &a) const
{
    return (*this<a)?0:1;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &a)const
{
    return (*this<a&&*this==a)?1:0;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==( const RationalNumber &a ) const
{
    return (numerator*a.denominator==denominator*a.numerator)?1:0;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=( const RationalNumber &a ) const
{
    return (*this==a)?0:1;
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
