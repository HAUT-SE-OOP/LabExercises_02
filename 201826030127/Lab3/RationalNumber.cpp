// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;
#include<string.h>

#include "Rational Numbers.h"

// RationalNumber constructor sets n and d and calls reduction
    RationalNumber::RationalNumber(int a,int b)
    :   numerator(a),denominator(b)
        {

        }
// overloaded + operator
    RationalNumber  RationalNumber::operator + ( const RationalNumber &num)
    {
        RationalNumber temp;
        temp.numerator= num.numerator;
        temp.denominator=num.denominator;
        temp.reduction();
        return RationalNumber(temp.numerator+numerator,temp.denominator);

    }
// overloaded - operator
RationalNumber  RationalNumber::operator - (const RationalNumber &num)
    {
        RationalNumber temp;
        temp.numerator=num.numerator;
        temp.denominator=num.denominator;
        temp.reduction();

        temp.numerator=numerator-temp.numerator;
        temp.denominator=temp.denominator;
        temp.reduction();
        return RationalNumber(temp.numerator,temp.denominator);

    }

// overloaded * operator
RationalNumber  RationalNumber::operator * (const RationalNumber &num)
    {
        RationalNumber temp;
        temp.numerator=numerator * num.numerator;
        temp.denominator=denominator * num.denominator;
        temp.reduction();
        return RationalNumber(temp.numerator,temp.denominator);
    }
// overloaded / operator
RationalNumber  RationalNumber::operator / (const RationalNumber &num)
    {
           RationalNumber temp;
        if(num.numerator == 0 || numerator == 0)
            throw
            invalid_argument("Denominator is not equal to 0");

        temp.numerator=numerator * num.denominator;
        temp.denominator=denominator * num.numerator;
        temp.reduction();

        return RationalNumber(temp.numerator,temp.denominator);

    }
// overloaded > operator
bool  RationalNumber::operator > (const RationalNumber &num)
{
    if(numerator > num.numerator)
        return true;
    else
        return false;
}

// overloaded < operator
bool  RationalNumber::operator < (const RationalNumber &num)
{
    reduction();
    if(numerator < num.numerator)
        return true;
    else
        return false;
}


// overloaded >= operator
bool  RationalNumber::operator >= (const RationalNumber &num)
{
    reduction();
    if(numerator > num.numerator || numerator == num.numerator)
        return true;
    else
        return false;
}


// overloaded <= operator
bool  RationalNumber::operator <= (const RationalNumber &num)
{
    reduction();
    if(numerator < num.numerator || numerator == num.numerator)
        return true;
    else
        return false;
}

// overloaded == operator
bool  RationalNumber::operator == (const RationalNumber &num)
{
    reduction();
    if(numerator == num.numerator)
        return true;
    else
        return false;
}

// overloaded != operator
bool  RationalNumber::operator != (const RationalNumber &num)
{
    if(numerator != num.numerator)
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
