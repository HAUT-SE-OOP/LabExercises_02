// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int u,int d)
{
    if(d==0)
        {u=1;
        d=1;}
    numerator=u;
    denominator=d;
    reduction();
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator

RationalNumber RationalNumber::operator+(RationalNumber right)
{
    RationalNumber temp;
    int a,b,c;
    a=numerator;
    b=denominator;
    c=denominator;
    a=a*right.denominator;
    b=b*right.denominator;
    right.numerator=right.numerator*c;
    right.denominator=right.denominator*c;
    temp.numerator=a+right.numerator;
    temp.denominator=b;
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator + */

// overloaded - operator
RationalNumber RationalNumber::operator-(RationalNumber right)
{
    RationalNumber temp;
    int a,b,c;
    a=numerator;
    b=denominator;
    c=denominator;
    a=a*right.denominator;
    b=b*right.denominator;
    right.numerator=right.numerator*c;
    right.denominator=right.denominator*c;
    temp.numerator=a-right.numerator;
    temp.denominator=b;
    if(temp.denominator==0||temp.denominator<0)
        cout<<"出现数学逻辑错误，故程序将其变为0";
    else
        temp.reduction();
    return temp;
}
/* Write definition for overloaded operator - */

// overloaded * operator
RationalNumber RationalNumber::operator*(RationalNumber right)
{
    RationalNumber temp;
    temp.numerator=this->numerator*right.numerator;
    temp.denominator=this->denominator*right.denominator;
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator/(RationalNumber right)
{
    RationalNumber temp;
    temp.numerator=this->numerator*right.denominator;
    temp.denominator=this->denominator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
bool RationalNumber::operator>(RationalNumber right)
{
    RationalNumber temp;
    temp=*this-right;
    if(temp.denominator<0||temp.numerator<0)
        return false;
    return true;

}
/* Write definition for operator > */

// overloaded < operator
bool RationalNumber::operator<(RationalNumber right)
{
    RationalNumber temp;
    temp=*this-right;
    if(temp.denominator<0||temp.numerator<0)
        return true;
    return false;

}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator>=(RationalNumber right)
{
    if(*this<right)
        return false;
    else
        return true;
}
/* Write definition for operator >= */

// overloaded <= operator
bool RationalNumber::operator<=(RationalNumber right)
{
    if(*this>right)
        return false;
    else
        return true;
}
/* Write definition for operator <= */

// overloaded == operator

/* Write definition for operator == */
bool RationalNumber::operator==(RationalNumber right)
{
    if(this->denominator==right.denominator&&this->numerator==right.numerator)
        return true;
    else
        return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(RationalNumber right)
{
    if(*this==right)
        return false;
    else
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
