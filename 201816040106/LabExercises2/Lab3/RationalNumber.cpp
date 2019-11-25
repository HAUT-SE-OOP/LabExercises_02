// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream> 
#include<algorithm>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber(int a,int b){
   if(b<=0) denominator=1;
   else denominator=b;
   numerator=a;
   reduction();
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(RationalNumber right)
{
   if(right.denominator==denominator)
      return RationalNumber(right.numerator+numerator,denominator);
   else{
      int lcm=denominator*right.denominator/__gcd(denominator,right.denominator);
      int tempNumerator,tempDenominator=denominator;
      tempNumerator=(numerator*(lcm/denominator)+right.numerator*(lcm/right.denominator));
      tempDenominator *= lcm/denominator;
      return RationalNumber(tempNumerator,tempDenominator);
   }
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(RationalNumber right)
{
   if(right.denominator==denominator) return RationalNumber(numerator-right.numerator,denominator);
   else{
      int lcm=denominator*right.denominator/__gcd(denominator,right.denominator);
      int tempNumerator,tempDenominator=denominator;
      tempNumerator=(numerator*(lcm/denominator)-right.numerator*(lcm/right.denominator));
      tempDenominator *= lcm/denominator;
      return RationalNumber(tempNumerator,tempDenominator);
   }
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(RationalNumber right)
{
   int tempNumerator=numerator,tempDenominator=denominator;
   tempNumerator*=right.numerator,tempDenominator*=right.denominator;
   return RationalNumber(tempNumerator,tempDenominator);
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(RationalNumber right)
{
   int tempNumerator=numerator,tempDenominator=denominator;
   tempNumerator*=right.denominator,tempDenominator*=right.numerator;
   return RationalNumber(tempNumerator,tempDenominator);
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(RationalNumber &right){
   if(right.denominator==denominator){
      return numerator>right.numerator;
   } 
   else{
      int lcm=denominator*right.denominator/__gcd(denominator,right.denominator);
      int tempNumerator1=numerator,tempNumerator2=right.numerator;
      tempNumerator1*=lcm/denominator;
      tempNumerator2*=lcm/right.denominator;
      return tempNumerator1>tempNumerator2;
   }
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(RationalNumber &right){
   return !(*this==right||*this>right);
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(RationalNumber &right){
   return !(*this<right);
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(RationalNumber &right){
   return !(*this>right);
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(RationalNumber &right){
   return (numerator==right.numerator&&denominator==right.denominator);
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(RationalNumber &right){
   return !(*this==right);
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
