// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber( int n, int d ) {
聽numerator = n;
聽denominator = d;
聽reduction();
}


RationalNumber RationalNumber::operator+( const RationalNumber &a ) const{
聽RationalNumber t;
聽t.numerator = a.numerator * denominator;
聽t.numerator += a.denominator * numerator;
聽t.denominator = a.denominator * denominator;
聽t.reduction();
聽return t;
}


RationalNumber RationalNumber::operator-( const RationalNumber &s ) const{
聽RationalNumber t;
聽t.numerator = s.denominator * numerator;
聽t.numerator -= denominator * s.numerator;
聽t.denominator = s.denominator * denominator;
聽t.reduction();
聽return t;
}


RationalNumber RationalNumber::operator*( const RationalNumber &m ) const{
聽聽聽 RationalNumber t;
聽t.numerator = m.numerator * numerator;
聽t.denominator = m.denominator * denominator;
聽t.reduction();
聽return t;
}


RationalNumber RationalNumber::operator/( const RationalNumber &v ) const{
聽RationalNumber t;
聽t.numerator = v.denominator * numerator;
聽t.denominator = denominator * v.numerator;
聽t.reduction();
聽return t;
}


bool RationalNumber::operator==( const RationalNumber &a ) const{
聽聽聽 if ( numerator == a.numerator && denominator == a.denominator)
聽聽聽聽聽聽聽 return true;
聽聽聽 else
聽聽聽聽聽聽聽 return false;
}


bool RationalNumber::operator!=( const RationalNumber &b ) const{
聽if ( numerator != b.numerator || denominator != b.denominator)
聽聽聽 聽return true;
聽聽聽 else
聽聽聽聽聽聽聽 return false;
}


bool RationalNumber::operator<( const RationalNumber &c ) const{
聽聽聽 if ( numerator / denominator < c.numerator / c.denominator)
聽聽聽聽聽聽聽 return true;
聽聽聽 else
聽聽聽聽聽聽聽 return false;
聽聽聽聽
}


bool RationalNumber::operator<=( const RationalNumber &d ) const{
聽聽聽 if ( numerator / denominator <= d.numerator / d.denominator)
聽聽聽聽聽聽聽 return true;
聽聽聽 else
聽聽聽聽聽聽聽 return false;
}


bool RationalNumber::operator>( const RationalNumber &e ) const{
聽if ( numerator / denominator > e.numerator / e.denominator)
聽聽聽聽聽聽聽 return true;
聽聽聽 else
聽聽聽聽聽聽聽 return false;
}


bool RationalNumber::operator>=( const RationalNumber &f ) const{
聽if ( numerator / denominator >= f.numerator / f.denominator)
聽聽聽聽聽聽聽 return true;
聽聽聽 else
聽聽聽聽聽聽聽 return false;
聽}
聽
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator
/* Write definition for overloaded operator + */

// overloaded - operator
/* Write definition for overloaded operator - */

// overloaded * operator
/* Write definition for overloaded operator * */

// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
/* Write definition for operator > */

// overloaded < operator
/* Write definition for operator < */

// overloaded >= operator
/* Write definition for operator >= */

// overloaded <= operator
/* Write definition for operator <= */

// overloaded == operator
/* Write definition for operator == */

// overloaded != operator
/* Write definition for operator != */

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

