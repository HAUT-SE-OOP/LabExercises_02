// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction

RationalNumber::RationalNumber(int a,int b)
{
    numerator =a;
    if(b==0)
        denominator=1;
    else if(b>0)
        denominator=b;
    else if(b<0)
    {
        denominator=b*(-1);
        numerator=numerator*(-1);
    }
     reduction();

}
// overloaded + operator

 RationalNumber RationalNumber::operator+(const RationalNumber& rigth)
 {
     RationalNumber temp;
     temp.denominator=denominator*rigth.denominator;
     temp.numerator=(numerator*rigth.denominator)+(rigth.numerator*denominator);
     temp.reduction();
     return temp;
 }
// overloaded - operator

RationalNumber RationalNumber::operator-(const RationalNumber& rigth)
{
     RationalNumber temp;
     temp.denominator=denominator*rigth.denominator;
     temp.numerator=(numerator*rigth.denominator)-(rigth.numerator*denominator);
     temp.reduction();
     return temp;
}
// overloaded * operator

RationalNumber RationalNumber::operator*(const RationalNumber& rigth)
{
     RationalNumber temp;
     temp.denominator=denominator*rigth.denominator;
     temp.numerator=numerator*rigth.numerator;
     temp.reduction();
     return temp;
}
// overloaded / operator

RationalNumber RationalNumber::operator/(const RationalNumber& rigth)
{
     RationalNumber temp;
     temp.denominator=denominator*rigth.numerator;
     temp.numerator=numerator*rigth.denominator;
     if(temp.denominator==0)
        throw invalid_argument("error ,denominator can't be zero");
     temp.reduction();
     return temp;
}
// overloaded > operator

bool RationalNumber::operator>(const RationalNumber& rigth)
{
    RationalNumber temp1,temp2;
    temp1.denominator=denominator*rigth.denominator;
    temp2.denominator=denominator*rigth.denominator;
    temp1.numerator=numerator*rigth.denominator;
    temp2.numerator=rigth.numerator*denominator;
    if((temp1.numerator-temp2.numerator)>0)
        return true;
    return false;
}
// overloaded < operator

bool RationalNumber::operator<(const RationalNumber& rigth)
{
    RationalNumber temp1,temp2;
    temp1.denominator=denominator*rigth.denominator;
    temp2.denominator=denominator*rigth.denominator;
    temp1.numerator=numerator*rigth.denominator;
    temp2.numerator=rigth.numerator*denominator;
    if((temp1.numerator-temp2.numerator)<0)
        return true;
    return false;
}
// overloaded >= operator

bool RationalNumber::operator>=(const RationalNumber& rigth)
{
    if(RationalNumber::operator<(rigth))
        return false;
    return true;
}
// overloaded <= operator

bool RationalNumber::operator<=(const RationalNumber& rigth)
{
    if(RationalNumber::operator>(rigth))
        return false;
    return true;
}
// overloaded == operator

bool RationalNumber::operator==(const RationalNumber& rigth)
{
    RationalNumber temp1,temp2;
    temp1.denominator=denominator*rigth.denominator;
    temp2.denominator=denominator*rigth.denominator;
    temp1.numerator=numerator*rigth.denominator;
    temp2.numerator=rigth.numerator*denominator;
    if((temp1.numerator==temp2.numerator)&&(temp1.denominator==temp2.denominator))
        return true;
    return false;
}
// overloaded != operator

bool RationalNumber::operator!=(const RationalNumber& rigth)
{
    if(RationalNumber::operator==(rigth))
        return false;
    return true;
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
