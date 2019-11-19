// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n,int d)
{
    numerator=n;
    denominator=d;
}
// overloaded + operator
RationalNumber RationalNumber::operator+(const RationalNumber &ra)
{
    int i;
    RationalNumber temp;
    i=denominator*ra.denominator;
    temp.numerator=numerator*ra.denominator+ra.numerator*denominator;
    temp.denominator=i;
    temp.reduction();
    return temp;
}
// overloaded - operator
RationalNumber RationalNumber::operator-(const RationalNumber &ra)
{
    int i;
    RationalNumber temp;
    i=denominator*ra.denominator;
    temp.numerator=numerator*ra.denominator-ra.numerator*denominator;
    temp.denominator=i;
    temp.reduction();
    return temp;
}
// overloaded * operator
RationalNumber RationalNumber::operator*(const RationalNumber &ra)
{
    RationalNumber temp;
    temp.numerator=numerator*ra.numerator;
    temp.denominator=denominator*ra.denominator;
    temp.reduction();
    return temp;
}

// overloaded / operator
RationalNumber RationalNumber::operator/(const RationalNumber &ra)
{
    if(numerator!=0)
    {
        RationalNumber temp;
        temp.numerator=numerator*ra.denominator;
        temp.denominator=denominator*ra.numerator;
        temp.reduction();
        return temp;
    }
    else
        cout<<"除分数为0，不可相除\n";
}
// overloaded > operator
bool RationalNumber::operator>(const RationalNumber &ra)
{
    int i;
   i=denominator*ra.denominator;
    if(numerator*ra.denominator>ra.numerator*denominator)
        return 1;
    else
        return 0;
}
// overloaded < operator
bool RationalNumber::operator<(const RationalNumber &ra)
{
    int i;
    i=denominator*ra.denominator;
    if(numerator*ra.denominator<ra.numerator*denominator)
        return 1;
    else
        return 0;
}
// overloaded >= operator
bool RationalNumber::operator>=(const RationalNumber &ra)
{
    int i;
    i=denominator*ra.denominator;
    if(numerator*ra.denominator>=ra.numerator*denominator)
        return 1;
    else
        return 0;
}
// overloaded <= operator
bool RationalNumber::operator<=(const RationalNumber &ra)
{
    int i;
    i=denominator*ra.denominator;
    if(numerator*ra.denominator<=ra.numerator*denominator)
        return 1;
    else
        return 0;
}
// overloaded == operator
bool RationalNumber::operator==(const RationalNumber &ra)
{
    int i;
    i=denominator*ra.denominator;
    if(numerator*ra.denominator==ra.numerator*denominator)
        return 1;
    else
        return 0;
}
// overloaded != operator
bool RationalNumber::operator!=(const RationalNumber &ra)
{
    int i;
    i=denominator*ra.denominator;
    if(numerator*ra.denominator!=ra.numerator*denominator)
        return 1;
    else
        return 0;
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
