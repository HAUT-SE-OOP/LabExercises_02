#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
   RationalNumber::RationalNumber(int n,int d):
      numerator(n),
      denominator(d)
   {

   }
// overloaded + operator
/* Write definition for overloaded operator + */
   RationalNumber RationalNumber::operator+(const RationalNumber &op2) const
   {
       if(denominator==op2.denominator)
       return RationalNumber(numerator+op2.numerator,denominator);
       else
       return RationalNumber(numerator*op2.denominator+op2.numerator*numerator,denominator*numerator);

   }

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &op2) const
   {
       if(denominator==op2.denominator)
       return RationalNumber(numerator-op2.numerator,denominator);
       else
       return RationalNumber(numerator*op2.denominator-op2.numerator*numerator,denominator*numerator);

   }
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &op2) const
   {
       return RationalNumber(numerator*op2.numerator,denominator*op2.denominator);
   }
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &op2) const
   {
       return RationalNumber(numerator*op2.denominator,denominator*op2.numerator);
   }
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(RationalNumber &op2)
{
    if(denominator==op2.denominator)
    {
        if(numerator>op2.numerator)
            return true;
    }
    else if(numerator*op2.denominator>op2.numerator*numerator)
        return true;
    return !(*this<=op2);
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(RationalNumber &op2)
{
    if(denominator==op2.denominator)
    {
        if(numerator<op2.numerator)
            return true;
    }
    else if(numerator*op2.denominator<op2.numerator*numerator)
        return true;
        return !(*this>=op2);
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(RationalNumber &op2)
{
    if(denominator==op2.denominator)
    {
        if(numerator>op2.numerator||numerator==op2.numerator)
            return true;
    }
    else if(numerator*op2.denominator>op2.numerator*numerator||numerator*op2.denominator==op2.numerator*numerator)
        return true;
        return !( *this <op2 );
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(RationalNumber &op2)
{
    if(denominator==op2.denominator)
    {
        if(numerator<=op2.numerator)
            return true;
    }
    else if(numerator*op2.denominator<=op2.numerator*numerator)
        return true;
         return !( op2 < *this );
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(RationalNumber &op2)
{
    if(numerator*op2.denominator==op2.numerator*denominator)
      return true;
       return !(op2!=*this);
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(RationalNumber &op2)
{
    if(numerator*op2.denominator!=op2.numerator*denominator)
        return true;
    return !( op2 == *this );

}
// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else if(denominator==0)
        cout<<"error!";
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

