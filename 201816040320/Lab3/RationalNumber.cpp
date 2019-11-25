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
    if(b>0)
    {
        numerator=a;
        denominator=b;
    }
    reduction();
}

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+( const RationalNumber &right)
{
    RationalNumber temp;
    temp.denominator=denominator*right.denominator;
    temp.numerator=numerator*right.denominator+denominator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-( const RationalNumber &right)
{
    RationalNumber temp;
    temp.denominator=denominator*right.denominator;
    temp.numerator=numerator*right.denominator-denominator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*( const RationalNumber &right)
{
    RationalNumber temp;
    temp.denominator=denominator*right.denominator;
    temp.numerator=numerator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/( const RationalNumber &right)
{
    if(right.numerator==0)
        cout <<"³ýÊýÎªÁã£¬ÔËËãÊ§°Ü£¡£¡"<<endl;
    else
    {
        RationalNumber temp;
        temp.denominator=denominator*right.numerator;
        temp.numerator=numerator*right.denominator;
        temp.reduction();
        return temp;
    }

}
// overloaded > operator
/* Write definition for operator > */
int RationalNumber::operator>(const RationalNumber &right)
{
    if(((double)numerator/(double)denominator)>((double)right.numerator/(double)right.denominator))
        return 1;
    else
        return 0;
}
// overloaded < operator
/* Write definition for operator < */
int RationalNumber::operator<(const RationalNumber &right)
{
    if((*this)>right||(*this)==right)
        return 0;
    else
        return 1;
}
// overloaded >= operator
/* Write definition for operator >= */
int RationalNumber::operator>=(const RationalNumber &right)
{
    if((*this)>right||(*this)==right)
        return 1;
    else
        return 0;
}
// overloaded <= operator
/* Write definition for operator <= */
int RationalNumber::operator<=(const RationalNumber &right)
{
    if((*this)<right||(*this)==right)
        return 1;
    else
        return 0;
}
// overloaded == operator
/* Write definition for operator == */
int RationalNumber::operator==(const RationalNumber &right)
{
    reduction();
    int a=right.numerator;
    int b=right.denominator;
    if(numerator==a&&denominator==b)
        return 1;
    else
        return 0;
}
// overloaded != operator
/* Write definition for operator != */
int RationalNumber::operator!=(const RationalNumber &right)
{
    if((*this)==right)
        return 0;
    else
        return 1;
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
