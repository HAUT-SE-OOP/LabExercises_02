// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"



RationalNumber::RationalNumber(int n,int d) // constructor sets n and d and calls reduction
{
    numerator = n;
    if(d > 0)
        denominator = d;
    else
        denominator = 1;
        reduction();
}

RationalNumber RationalNumber::operator+( RationalNumber &a) //definition for overloaded operator +
 {
      RationalNumber result;
      result.denominator=denominator;
      result.numerator=numerator+a.numerator;
      return result;
 }


RationalNumber RationalNumber::operator-(RationalNumber &a) //definition for overloaded operator -
 {
      RationalNumber result(numerator-a.numerator,denominator);
      reduction();
      return result;
 }

RationalNumber RationalNumber::operator*(RationalNumber &a) //definition for overloaded operator *
 {
      RationalNumber result;
      result.denominator=denominator*a.denominator;
      result.numerator=numerator*a.numerator;
      reduction();
      return result;
 }

RationalNumber RationalNumber::operator/(RationalNumber &a) //definition for overloaded operator /.
 {
      RationalNumber result(numerator*a.denominator,denominator*a.numerator);

      reduction();
      if(a.denominator==0)
        cout << "can't divided by zero!";
        return result;
 }

bool RationalNumber::operator>(RationalNumber &a) //definition for operator >
 {

    RationalNumber m;
    RationalNumber n;
    m.denominator = denominator*a.denominator;
    m.numerator = numerator*a.denominator;
    n.denominator = denominator*a.denominator;
    n.numerator = a.numerator*denominator;
    if(m.numerator>n.numerator)
        return true;
    else
        return false;

 }

bool RationalNumber::operator<(RationalNumber &a) //definition for operator <
 {

    RationalNumber m;
    RationalNumber n;
    m.denominator = denominator*a.denominator;
    m.numerator = numerator*a.denominator;
    n.denominator = denominator*a.denominator;
    n.numerator = a.numerator*denominator;
    reduction();
    if(m.numerator<n.numerator)
        return true;
    else
        return false;
 }

 bool RationalNumber::operator>=(RationalNumber &a) //definition for operator >=
 {

    RationalNumber m;
    RationalNumber n;
    m.denominator = denominator*a.denominator;
    m.numerator = numerator*a.denominator;
    n.denominator = denominator*a.denominator;
    n.numerator = a.numerator*denominator;
    reduction();
    if((m.numerator>n.numerator)||(m.numerator=n.numerator))
        return true;
    else
        return false;
 }

 bool RationalNumber::operator<=( RationalNumber &a) //definition for operator <=
 {
    RationalNumber m;
    RationalNumber n;
    m.denominator = denominator*a.denominator;
    m.numerator = numerator*a.denominator;
    n.denominator = denominator*a.denominator;
    n.numerator = a.numerator*denominator;
    reduction();
    if((m.numerator<n.numerator)||(m.numerator==n.numerator))
        return true;
    else
        return false;
 }

bool RationalNumber::operator==(RationalNumber &a) //definition for operator ==
 {
    RationalNumber m;
    RationalNumber n;
    m.denominator = denominator*a.denominator;
    m.numerator = numerator*a.denominator;
    n.denominator = denominator*a.denominator;
    n.numerator = a.numerator*denominator;
    reduction();
    if(m.numerator==n.numerator)
        return true;
    else
        return false;
 }

 bool RationalNumber::operator!=(RationalNumber &a) //definition for operator !=
 {
    RationalNumber m;
    RationalNumber n;
    m.denominator = denominator*a.denominator;
    m.numerator = numerator*a.denominator;
    n.denominator = denominator*a.denominator;
    n.numerator = a.numerator*denominator;
    reduction();
    if(m.numerator!=n.numerator)
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
}

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
}


/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
