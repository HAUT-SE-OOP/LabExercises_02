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
   RationalNumber::RationalNumber( int a, int b )
   {
       if(a>0)
       {
           numerator=a;
       }
       else
       {
           numerator=0;
       }
       if(b>0)
       {
           denominator= b ;
       }
       else
       {
           denominator= 1 ;
       }
       reduction();
   }

RationalNumber RationalNumber::operator+( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.denominator+denominator*a.numerator;
    temp.denominator=denominator*a.denominator;
    temp.reduction();
    return temp;
}
RationalNumber RationalNumber::operator-( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.denominator-denominator*a.numerator;
    temp.denominator=denominator*a.denominator;
    temp.reduction();
    return temp;
}
RationalNumber RationalNumber::operator*( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.numerator;
    temp.denominator=denominator*a.denominator;
    temp.reduction();
    return temp;
}
RationalNumber RationalNumber::operator/( const RationalNumber &a ) const
{
    RationalNumber temp;
    temp.numerator=numerator*a.denominator;
    temp.denominator=denominator*a.numerator;
    temp.reduction();
    return temp;
}

bool RationalNumber::operator!=(  RationalNumber &right )
{
    reduction();
    right.reduction();
    if(numerator==right.numerator &&denominator==right.denominator)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool RationalNumber::operator==(  RationalNumber &right )
{
    reduction();
    right.reduction();
    if(numerator==right.numerator &&denominator==right.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool RationalNumber::operator>=(  RationalNumber &right )
{
    reduction();
    right.reduction();
    RationalNumber temp1,temp2;
    temp1.numerator=numerator*right.denominator;
    temp2.numerator=denominator*right.numerator;
    if(temp1.numerator>=temp2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool RationalNumber::operator<=(  RationalNumber &right )
{

    reduction();
    right.reduction();
    RationalNumber temp1,temp2;
    temp1.numerator=numerator*right.denominator;
    temp2.numerator=denominator*right.numerator;
    if(temp1.numerator<=temp2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool RationalNumber::operator>(  RationalNumber &right )
{
    reduction();
    right.reduction();
    RationalNumber temp1,temp2;
    temp1.numerator=numerator*right.denominator;
    temp2.numerator=denominator*right.numerator;
    if(temp1.numerator>temp2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool RationalNumber::operator<(  RationalNumber &right )
{
    reduction();
    right.reduction();
    RationalNumber temp1,temp2;
    temp1.numerator=numerator*right.denominator;
    temp2.numerator=denominator*right.numerator;
    if(temp1.numerator<temp2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
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
