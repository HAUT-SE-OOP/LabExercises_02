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
   RationalNumber::RationalNumber(int Numerator,int Denominator)
   {
       if(Numerator>=0)
            numerator=Numerator;
       else
            numerator=1;
       if(Denominator>0)
            denominator=Denominator;
       else
            denominator=1;
       reduction();
   }

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber &str)
{
    RationalNumber temp;
    if(denominator==str.denominator)
    {
        temp.numerator=numerator+str.numerator;
        temp.denominator=denominator;
        temp.reduction();
        return temp;
    }
    else
    {
        temp.denominator=denominator*str.denominator;
        temp.numerator=numerator*str.denominator+str.numerator*denominator;
        temp.reduction();
        return temp;
    }
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &str)
{
    RationalNumber temp;
    if(denominator==str.denominator)
    {
        temp.numerator=numerator-str.numerator;
        temp.denominator=denominator;
        temp.reduction();
        return temp;
    }
    else
    {
        temp.denominator=denominator*str.denominator;
        temp.numerator=numerator*str.denominator-str.numerator*denominator;
        temp.reduction();
        return temp;
    }
}

// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &str)
{
    RationalNumber temp;
    temp.numerator=numerator*str.numerator;
    temp.denominator=denominator*str.denominator;
    temp.reduction();
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &str)
{
    if(str.numerator!=0)
    {
        RationalNumber temp;
        temp.numerator=numerator*str.denominator;
        temp.denominator=denominator*str.numerator;
        temp.reduction();
        return temp;
    }
    else
        throw out_of_range("Divisor cannot be zero");
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &str)
{
    if(denominator==str.denominator)
    {
        if(numerator>str.numerator)
            return 1;
        else
            return 0;
    }
    else
    {
        if(numerator*str.denominator>str.numerator*denominator)
            return 1;
        else
            return 0;
    }
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber &str)
{
    if(denominator==str.denominator)
    {
        if(numerator<str.numerator)
            return 1;
        else
            return 0;
    }
    else
    {
        if(numerator*str.denominator<str.numerator*denominator)
            return 1;
        else
            return 0;
    }
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber &str)
{
    if(denominator==str.denominator)
    {
        if(numerator>=denominator)
            return 1;
        else
            return 0;
    }
    else
    {
        if(numerator*str.denominator>=str.numerator*denominator)
            return 1;
        else
            return 0;
    }
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &str)
{
    if(denominator==str.denominator)
    {
        if(numerator<=str.numerator)
            return 1;
        else
            return 0;
    }
    else
    {
        if(numerator*str.denominator<=str.numerator*denominator)
            return 1;
        else
            return 0;
    }
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber &str)
{
    if(denominator==str.denominator)
    {
        if(numerator==str.numerator)
            return 1;
        else
            return 0;
    }
    else
    {
        if(numerator*str.denominator==str.numerator*denominator)
            return 1;
        else
            return 0;
    }
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber &str)
{
    if(denominator==str.denominator)
    {
        if(numerator!=str.numerator)
            return 1;
        else
            return 0;
    }
    else
    {
        if(numerator*str.denominator!=str.numerator*denominator)
            return 1;
        else
            return 0;
    }
}
ostream &operator<<(ostream &output,const RationalNumber &a)
{
    if (a.numerator == 0 ) // print fraction as zero
      output <<a.numerator;
   else if ( a.denominator == 1 ) // print fraction as integer
      output << a.numerator;
   else
      output << a.numerator << '/' << a.denominator;

   return output;
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
