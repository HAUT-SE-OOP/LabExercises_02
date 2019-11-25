
// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
   RationalNumber:: RationalNumber( int a, int b )
   {
       setValues(a,b);
   }

  void RationalNumber::setValues(int a,int b)
  {
      setNumerator(a);
      setDenominator(b);
  }
  void RationalNumber::setNumerator(int a)
  {
      numerator=a;
  }
  void RationalNumber::setDenominator(int a)
  {
      denominator=a;
  }
  int RationalNumber::getNumerator()const
  {
      return numerator;
  }
  int RationalNumber::getDenominatorr()const
  {
     return denominator;
  }
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::  operator+( const RationalNumber &a) const
{
    RationalNumber temp;
    temp.denominator=this->denominator*a.denominator;
    temp.numerator=((this->numerator)*a.denominator)+(a.numerator*(this->denominator));
    temp.reduction();
    return temp;
}

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::  operator-( const RationalNumber &a) const
{
    RationalNumber temp;
    temp.denominator=this->denominator*a.denominator;
    temp.numerator=(this->numerator*a.denominator)-(a.numerator*this->denominator);
    temp.reduction();
    return temp;
}

// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::  operator*( const RationalNumber &a) const
{
    RationalNumber temp;
    temp.denominator=this->denominator*a.denominator;
    temp.numerator=this->numerator*a.numerator;
    temp.reduction();
    return temp;
}

// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
   RationalNumber RationalNumber:: operator/( const RationalNumber &a) const
{
    RationalNumber temp;
    if(a.numerator!=0)
    {
        temp.denominator=this->denominator*a.numerator;
        temp.numerator=this->numerator*a.denominator;
        temp.reduction();
        return temp;
    }
    else
      cout<<"the client is not attempting to divide by zero"<<endl;
}

// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &a)const
{
    int x=0,b=0;
    x=this->numerator*a.denominator;
    b=a.numerator*this->denominator;
    if(x > b)
        return true;
    else
        return false;
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber &a)const
{
   int x=0,b=0;
    x=this->numerator*a.denominator;
    b=a.numerator*this->denominator;
    if(x < b)
        return true;
    else
        return false;
}

// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber &a)const
{
    int x=0,b=0;
    x=this->numerator*a.denominator;
    b=a.numerator*this->denominator;
    if(x >= b)
        return true;
    else
        return false;
}

// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &a)const
{
   int x=0,b=0;
    x=this->numerator*a.denominator;
    b=a.numerator*this->denominator;
    if(x <= b)
        return true;
    else
        return false;
}

// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber &a)const
{
   int x=0,b=0;
    x=this->numerator*a.denominator;
    b=a.numerator*this->denominator;
    if(x == b)
        return true;
    else
        return false;
}

// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber &a)const
{
    int x=0,b=0;
    x=this->numerator*a.denominator;
    b=a.numerator*this->denominator;
    if(x != b)
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
