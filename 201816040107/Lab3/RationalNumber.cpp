// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
#include<algorithm>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber(int a,int b)
{
    numerator=a;
    denominator=b;
    reduction();
}

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(RationalNumber &n)
{
    int temp2=denominator;
    int l=n.denominator*denominator/__gcd(n.denominator,denominator);
    int temp1=numerator*(l/n.denominator)+n.numerator*(l/denominator);
    temp2=l;
    return RationalNumber(temp1,temp2);
}
RationalNumber RationalNumber::operator-(RationalNumber &n)
{
    int temp1=n.denominator*denominator/__gcd(n.denominator,denominator);
    int temp2=numerator*(temp1/n.denominator)-n.numerator*(temp1/denominator);
    return RationalNumber(temp2,temp1);
}
RationalNumber RationalNumber::operator*(RationalNumber &n)
{
    int temp1=numerator*n.numerator;
    int temp2=denominator*n.denominator;
    return RationalNumber(temp1,temp2);
}
RationalNumber RationalNumber::operator/(RationalNumber &n)
{
    int temp1=numerator*n.denominator;
    int temp2=denominator*n.numerator;
    return RationalNumber(temp1,temp2);
}
bool RationalNumber::operator>(RationalNumber &n)
{
    int t=denominator*n.denominator/__gcd(denominator,n.denominator);
    int t1=numerator*(t/n.denominator);
    int t2=n.numerator*(t/denominator);
    if(t1>t2)
    {
        return true;
    }
    return false;
}
bool RationalNumber::operator<=(RationalNumber &n)
{
    return !(*this>n);
}
bool RationalNumber::operator<(RationalNumber &n)
{
    int t=denominator*n.denominator/__gcd(denominator,n.denominator);
    int t1=numerator*(t/n.denominator);
    int t2=n.numerator*(t/denominator);
    if(t1<t2)
    {
        return true;
    }
    return false;
}
bool RationalNumber::operator>=(RationalNumber &n)
{
    return !(*this<n);
}
bool RationalNumber::operator==(RationalNumber &n)
{
    if(numerator==n.numerator && denominator==n.denominator)
        return true;
    return false;
}
bool RationalNumber::operator!=(RationalNumber &n)
{
    return !(*this==n);
}

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



