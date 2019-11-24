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
RationalNumber::RationalNumber(int a,int b)
{
    numerator=a;
    denominator=b;
}//end rational number constructor
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber &xyy)const
{
    RationalNumber temp;//define a temp data
    temp.denominator=denominator*xyy.denominator;//denominator = denominator*denominator
    temp.numerator=numerator*xyy.denominator+denominator*xyy.numerator;//numerator=numerator *denominator+denominator*numerator
    temp.reduction();
    return temp;
}//end function overloaded operator +
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &xyy)const
{
    RationalNumber temp;//define a temp data
    temp.denominator=denominator*xyy.denominator;//denominator = denominator*denominator
    temp.numerator=numerator*xyy.denominator-denominator*xyy.numerator;//numerator=numerator*denominator - denominator*numerator
    temp.reduction();
    return temp;

}//end function overloaded operator -
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &xyy)const
{
    RationalNumber temp;//define a temp data
    temp.denominator=denominator *xyy.denominator;//denominator=denominator*denominator
    temp.numerator=numerator*xyy.numerator;//numerator = numerator*numerator
    temp.reduction();
    return temp;
}//end function overloaded operator *
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &xyy)const
{
    RationalNumber temp;
    //if(denominator!=0)
        temp.denominator=denominator*xyy.numerator;//denominator =denominator*numerator
    //if(xyy.denominator!=0)
        temp.numerator=numerator*xyy.denominator;//numerator=numerator*denominator
    temp.reduction();
    return temp;
}//end function overloaded operator /
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &xyy)const
{
    if(numerator*xyy.denominator-xyy.numerator*denominator >0)
        return true;
    else
        return false;
}//end function overloaded operator >

// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber &xyy)const
{
    if(numerator*xyy.denominator-xyy.numerator*denominator<0)
        return true;
    else
        return false;
}//end function overloaded operator <
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber &xyy)const
{
    if(numerator*xyy.denominator-xyy.numerator*denominator>=0)
        return true;
    else
        return false;
}//end function overloaded operator >=

// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &xyy)const
{
    if(numerator*xyy.denominator-xyy.numerator*denominator<=0)
        return true;
    else
        return false;
}//end function overloaded operator<=
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber &xyy)const
{
    if(numerator*xyy.denominator-xyy.numerator*denominator==0)
        return true;
    else
        return false;
}//end function overloaded operator==

// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber &xyy)const
{
    if(numerator*xyy.denominator-xyy.numerator*denominator!=0)
        return true;
    else
        return false;
}//end function overloaded operator!=
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
