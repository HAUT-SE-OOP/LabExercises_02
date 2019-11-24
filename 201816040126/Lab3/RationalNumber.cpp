// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n1,int d1) // default constructor
{
    numerator=n1;
    denominator=d1;
    reduction();
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator
RationalNumber RationalNumber::operator+( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator = denominator * right.denominator;//calculate the denominator by +
    temp.numerator = numerator * right.denominator + right.numerator*denominator;//calculate the numerator by +
    temp.reduction();
    return temp;
};
/* Write definition for overloaded operator + */

// overloaded - operator
RationalNumber RationalNumber::operator-( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator = denominator * right.denominator;//calculate the denominator by -
    temp.numerator = numerator * right.denominator - right.numerator*denominator;//calculate the numerator by -
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator - */

// overloaded * operator
RationalNumber RationalNumber::operator*( const RationalNumber &right )
{
    RationalNumber temp;
    temp.denominator = denominator * right.denominator;//calculate the denominator by *
    temp.numerator = numerator * right.numerator;//calculate the numerator by *
    temp.reduction();
    return temp;
}
/* Write definition for overloaded operator * */

// overloaded / operator
RationalNumber RationalNumber::operator/( const RationalNumber &right )
{
    RationalNumber temp;

        temp.denominator = denominator / right.denominator;//calculate the denominator by /
        temp.numerator = numerator / right.numerator;//calculate the numerator by /
        temp.reduction();
        if( denominator == 0)
        {
           cout << " The denominator can't be ";

           return 0;
        }
        if( numerator == 0)
        {
        temp.denominator =0;
        temp.numerator =0;
        temp.reduction();
        }

    return temp;
}
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
bool RationalNumber::operator>(RationalNumber &right)
{
    if(numerator * right.denominator > denominator*right.numerator)// if more
        return true;
    else
        return false;
}
/* Write definition for operator > */

// overloaded < operator
bool RationalNumber::operator<(RationalNumber &right)
{
    if(numerator * right.denominator < denominator*right.numerator)//if less
        return true;
    else
        return false;
}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator>=(RationalNumber &right)
{
    if(numerator*right.denominator < denominator*right.numerator)//if less or same
        return false;
    else
        return true;
}
/* Write definition for operator >= */

// overloaded <= operator
bool RationalNumber::operator<=(RationalNumber &right)
{
    if(numerator*right.denominator > denominator*right.numerator)//if more or same
        return false;
    else
        return true;
}
/* Write definition for operator <= */

// overloaded == operator
bool RationalNumber::operator==(RationalNumber &right)
{
    if(numerator*right.denominator == denominator*right.numerator)//if are same
        return true;
    else
        return false;
}
/* Write definition for operator == */

// overloaded != operator
bool RationalNumber::operator!=(RationalNumber &right)
{
    if(numerator*right.denominator == denominator*right.numerator)//if are not same
        return false;
    else
        return true;
}
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

ostream &operator<<( std::ostream & output, const RationalNumber & number )
{
    if ( number.numerator == 0 ) // print fraction as zero
      output << number.numerator;
   else if ( number.denominator == 1 ) // print fraction as integer
      output << number.numerator;
   else
      output << number.numerator << '/' << number.denominator;

     return output;
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
