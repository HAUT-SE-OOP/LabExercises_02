// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;
#include <stdexcept>
#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber( int d, int c )
:denominator(c)
{
    if(d<0)//Validate d first to ensure that it is a positive number and set it to 1 if not
        numerator=1;
    else
        numerator=d;
    reduction();//to Simplify the  RationalNumber
}//end constructor
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator +(RationalNumber &object2)
{
    RationalNumber temp;//to store the number
    temp.numerator=numerator*object2.denominator+object2.numerator*denominator;
    temp.denominator=denominator*object2.denominator;//to ensure the two object have the same denominator
    temp.reduction();//to simplify the result
    return temp;//return the result
}//end function operator +
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator -(RationalNumber &object2)
{
    RationalNumber temp;
    temp.numerator=numerator*object2.denominator-object2.numerator*denominator;
    temp.denominator=denominator*object2.denominator;//to ensure the two object have the same denominator
     temp.reduction();//to simplify the result
    return temp;//return the result
}//end function operator -
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator *(RationalNumber &object2)
{
    RationalNumber temp;
    temp.numerator=numerator*object2.numerator;
    temp.denominator=denominator*object2.denominator;
    temp.reduction();//to simplify the result
    return temp;//return the result
}//end function operator *
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator /(RationalNumber &object2)
{
    RationalNumber temp;
    if(object2.numerator==0)
    {
        throw invalid_argument("The denominator is zero");
    }
        //std::cout<<"The denominator is zero"<<endl;
        //return (*this);//the denominator is zero and return the this object

    temp.numerator=numerator*object2.denominator;
    temp.denominator=denominator*object2.numerator;
    temp.reduction();//return the result
    return temp;//return the result
}//end function operator /
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator >(RationalNumber &object2)
{
    if(numerator/denominator>object2.numerator/object2.denominator)
        return true;
    else
        return false;
}//end function operator >
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator <(RationalNumber &object2)
{
    if((*this)==object2||(*this)>object2)
        return false;
    else
        return false;
}//end function operator <
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator >=(RationalNumber &object2)
{
    if((*this)<object2)
        return false;
    else
        return false;
}//end function operator >=
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator <=(RationalNumber &object2)
{
    if((*this)>object2)
        return false;
    else
        return false;
}//end function operator <=
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator ==(RationalNumber &object2)
{
    if(numerator/denominator==object2.numerator/object2.denominator)
    return true;
}//end function operator ==
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator !=(RationalNumber &object2)
{
    if((*this)==object2)
    return false;
    else
        return true;
}//end function operator £¡=
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

