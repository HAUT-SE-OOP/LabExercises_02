// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

RationalNumber::RationalNumber( int nume, int deno )
{
    if ( deno <= 0 )
    {
        deno = 1;
    }
    else
    {
        numerator = nume;
        denominator = deno;
    }
    reduction();
}

// overloaded + operator
RationalNumber RationalNumber::operator+( const RationalNumber & r ) const
{
    return RationalNumber( this->numerator*r.denominator + this->denominator*r.numerator, this->denominator*r.denominator );
}

// definition for overloaded operator -
RationalNumber RationalNumber::operator-( const RationalNumber & r ) const
{
    return RationalNumber( this->numerator*r.denominator - this->denominator*r.numerator, this->denominator*r.denominator );
}

// definition for overloaded operator *
RationalNumber RationalNumber::operator*( const RationalNumber & r ) const
{
    return RationalNumber( this->numerator*r.numerator, this->denominator*r.denominator );
}

// definition for overloaded operator /.
RationalNumber RationalNumber::operator/( const RationalNumber & r ) const
{
    if ( r.numerator == 0 )
    {
        throw invalid_argument("Errr: divisor can't be zero\n");
    }
    else
    {
        return RationalNumber( this->numerator*r.denominator, this->denominator*r.numerator );
    }
}

// definition for operator >
bool RationalNumber::operator>( const RationalNumber & r ) const
{
    return ( ( double ) ( this->numerator ) / this->denominator ) > ( ( double ) ( r.numerator ) / r.denominator ) ? true : false;
}


// definition for operator <
bool RationalNumber::operator<( const RationalNumber & r ) const
{
    return ( ( double ) ( this->numerator ) / this->denominator ) < ( ( double ) ( r.numerator ) / r.denominator ) ? true : false;

}

// definition for operator >=
bool RationalNumber::operator>=( const RationalNumber & r ) const
{
    return !( *this < r );
}

// definition for operator <=
bool RationalNumber::operator<=( const RationalNumber & r ) const
{
    return !( *this > r );
}

// definition for operator ==
bool RationalNumber::operator==( const RationalNumber & r ) const
{
    return ( !( *this < r ) ) && ( !( *this > r ) );
}

// definition for operator !=
bool RationalNumber::operator!=( const RationalNumber & r ) const
{
    return !( *this == r );
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
