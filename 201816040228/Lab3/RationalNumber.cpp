// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
// Implement the RationalNumber constructor. Validate d first to ensure that
//it is a positive number and set it to 1 if not. Call the reduction utility function at the end
RationalNumber::RationalNumber( int  num, int deno)
{
    numerator=num;
    denominator=deno;
    reduction();
}

// overloaded + operator
// definition for overloaded operator +
RationalNumber RationalNumber::operator+(RationalNumber &m)
{
    if(denominator==0||m.denominator==0||numerator==0||m.numerator==0)
    {
        throw invalid_argument( "分母或者除数不能为0" );
    }
    else if(numerator==0||m.numerator==0)
    {
        cout<<"0/0"<<endl;
    }
    else
    {
        int a,b;
        a=numerator*m.denominator+m.numerator*denominator;
        b=denominator*m.denominator;
        return RationalNumber(a,b);
    }
}
// overloaded - operator
// definition for overloaded operator -
RationalNumber RationalNumber::operator-(RationalNumber &m)
{
    if(denominator==0||m.denominator==0||numerator==0||m.numerator==0)
    {
        throw invalid_argument( "分母或者除数不能为0" );
    }
    else if(numerator==0||m.numerator==0)
    {
        cout<<"0/0"<<endl;
    }
    else
    {
        int a,b;
        a=numerator*m.denominator-m.numerator*denominator;
        b=denominator*m.denominator;
        return RationalNumber(a,b);
    }
}

// overloaded * operator
// definition for overloaded operator
RationalNumber RationalNumber::operator*(RationalNumber &m)
{
    if(denominator==0||m.denominator==0||numerator==0||m.numerator==0)
    {
        throw invalid_argument( "分母或者除数不能为0" );
    }
    else if(numerator==0||m.numerator==0)
    {
        cout<<"0/0"<<endl;
    }
    else
    {
        int a,b;
        a=numerator*m.numerator;
        b=denominator*m.denominator;
        return RationalNumber(a,b);
    }
}

// overloaded / operator
//definition for overloaded operator . Check if the client is
//   attempting to divide by zero and report an error message if so
RationalNumber RationalNumber::operator/(RationalNumber &m)
{
    if(m.denominator==0||m.numerator==0)
    {
        cout<<"分母或者除数不能为0"<<endl;
    }
    else if(m.numerator==0)
    {
        cout<<"0/0"<<endl;
    }
    else
    {
        int a,b;
        a=numerator*m.denominator;
        b=denominator*m.numerator;
        return RationalNumber(a,b);
    }
}

// overloaded > operator
// definition for operator >
bool RationalNumber::operator > ( const RationalNumber &m) const
{
    int a,b;
    a=numerator*m.denominator;
    b=denominator*m.numerator;
    if( a> b)
    {
        return true;
    }
    else
        return false;
   return false;
}
// overloaded < operator
//definition for operator <
bool RationalNumber::operator < ( const RationalNumber &m) const
{
    int a,b;
    a=numerator*m.denominator;
    b=denominator*m.numerator;
    if( a< b)
    {
        return true;
    }
    else
        return false;
   return false;
}
// overloaded >= operator
// definition for operator >=
bool RationalNumber::operator >= ( const RationalNumber &m) const
{
    int a,b;
    a=numerator*m.denominator;
    b=denominator*m.numerator;
    if( a>= b)
    {
        return true;
    }
    else
        return false;
   return false;
}
// overloaded <= operator
// definition for operator <=
bool RationalNumber::operator <= ( const RationalNumber &m) const
{
    int a,b;
    a=numerator*m.denominator;
    b=denominator*m.numerator;
    if( a<= b)
    {
        return true;
    }
    else
        return false;
   return false;
}
// overloaded == operator
// definition for operator ==
bool RationalNumber::operator == ( const RationalNumber &m) const
{
    int a,b;
    a=numerator*m.denominator;
    b=denominator*m.numerator;
    if( a== b)
    {
        return true;
    }
    else
        return false;
   return false;
}
// overloaded != operator
//definition for operator !=
bool RationalNumber::operator != ( const RationalNumber &m) const
{
    int a,b;
    a=numerator*m.denominator;
    b=denominator*m.numerator;
    if( a!= b)
    {
        return true;
    }
    else
        return false;
   return false;
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
/*void printRational(const RationalNumber &m)
{
   if ( m.numerator == 0 ) // print fraction as zero
      cout << m.numerator;
   else if ( m.denominator == 1 ) // print fraction as integer
      cout << m.numerator;
   else
      cout << m.numerator << '/' << m.denominator;
} // end function printRational*/
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
