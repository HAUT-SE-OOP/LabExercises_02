#include <cstdlib>

#include <iostream>
#include "RationalNumber.h"
using namespace std;
RationalNumber::RationalNumber(int n, int b)
{
    numerator = n;  denominator = b;
    reduction();
}
RationalNumber RationalNumber::operator+(const RationalNumber &right) const
{  RationalNumber temp;
 temp.denominator = denominator * right.denominator;
 temp.numerator = numerator * right.denominator + denominator * right.numerator;
 temp.reduction();
 return temp;
 }
RationalNumber RationalNumber::operator-(const RationalNumber &right) const
{  RationalNumber temp;
 temp.denominator = denominator * right.denominator;
 temp.numerator = numerator * right.denominator - denominator * right.numerator;  temp.reduction();
 return temp;
}
RationalNumber RationalNumber::operator*(const RationalNumber &right) const
{  RationalNumber temp;
 temp.denominator = denominator * right.denominator;  temp.numerator = numerator * right.numerator;  temp.reduction();
 return temp;
}
RationalNumber RationalNumber::operator/(const RationalNumber &right) const
{  RationalNumber temp;
 temp.denominator = denominator * right.numerator;  temp.numerator = numerator * right.denominator;  temp.reduction();
 return temp;
}
bool RationalNumber::operator>(const RationalNumber &right) const
{
    if (numerator*right.denominator - right.numerator*denominator > 0)
        return true;
 else
return false;
}
bool RationalNumber::operator<(const RationalNumber &right) const
{  if (numerator*right.denominator - right.numerator*denominator < 0)
return true;
 else
return false;
}
bool RationalNumber::operator>=(const RationalNumber &right) const
{  if (numerator*right.denominator - right.numerator*denominator >= 0)
   return true;
   else
    return false;
}
bool RationalNumber::operator<=(const RationalNumber &right) const
{  if (numerator*right.denominator - right.numerator*denominator <= 0)
return true;
 else
return false;
}
bool RationalNumber::operator==(const RationalNumber &right) const

{
    if (numerator*right.denominator - right.numerator*denominator == 0)
        return true;
 else
return false; }

bool RationalNumber::operator!=(const RationalNumber &right) const
{
    if (numerator*right.denominator - right.numerator*denominator != 0)
        return true;
 else
return false;
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
