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
RationalNumber::RationalNumber(int n,int d)
{
    numerator=n;
    if(d>0)
        denominator=d;

    reduction();
}

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(RationalNumber & right )
{
    RationalNumber temp1,temp2;

    temp1.numerator=numerator;
    temp1.denominator=denominator;

    numerator=numerator*right.denominator+right.numerator*denominator;
    denominator=denominator*right.denominator;
    reduction();
    temp2.numerator=numerator;
    temp2.denominator=denominator;


    numerator=temp1.numerator;
    denominator=temp1.denominator;

    return temp2;
}

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(RationalNumber & right )
{
    RationalNumber temp1,temp2;

    temp1.numerator=numerator;
    temp1.denominator=denominator;

    numerator=this->numerator*right.denominator-right.numerator*this->denominator;
    denominator=this->denominator*right.denominator;
    reduction();
    temp2.numerator=numerator;
    temp2.denominator=denominator;


    numerator=temp1.numerator;
    denominator=temp1.denominator;

    return temp2;
}

// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(RationalNumber & right )
{
    RationalNumber temp1,temp2;

    temp1.numerator=numerator;
    temp1.denominator=denominator;

    numerator=this->numerator*right.numerator;
    denominator=this->denominator*right.denominator;
    reduction();
    temp2.numerator=numerator;
    temp2.denominator=denominator;


    numerator=temp1.numerator;
    denominator=temp1.denominator;
    return temp2;
}

// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(RationalNumber & right )
{
    RationalNumber temp1,temp2;

    temp1.numerator=numerator;
    temp1.denominator=denominator;
    if(right.numerator==0)
    {
        throw invalid_argument("The denominator cannot be zero.");
    }
    else
    {
        numerator=numerator*right.denominator;
        denominator=denominator*right.numerator;
        reduction();
        temp2.numerator=numerator;
        temp2.denominator=denominator;


        numerator=temp1.numerator;
        denominator=temp1.denominator;
        return temp2;
    }
}

// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(RationalNumber &right)
{
     if((*this-right).numerator>0)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(RationalNumber &right)
{
    if((*this-right).numerator<0)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(RationalNumber &right)
{
     if((*this-right).numerator>=0)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(RationalNumber &right)
{
     if((*this-right).numerator<=0)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(RationalNumber &right)
{
    if((*this-right).numerator==0)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(RationalNumber &right)
{
     if((*this-right).numerator!=0)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

// function printRational definition
/*void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational*/

ostream &operator<<(ostream &output,const RationalNumber &right)
{
    if ( right.numerator == 0 ) // print fraction as zero
      output << right.numerator;
   else if ( right.denominator == 1 ) // print fraction as integer
      output << right.numerator;
   else
      output << right.numerator << '/' << right.denominator;

      return output;
}

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

/*RationalNumber &RationalNumber::operator>(RationalNumber &right)
{
     if((*this-right).numerator>0)
     {
         return *this;
     }
     else
     {
         return right;
     }
}*/
