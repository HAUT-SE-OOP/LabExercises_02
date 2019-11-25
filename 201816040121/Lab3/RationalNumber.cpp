// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream> 
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int a, int b)
{
	if (b != 0)
	{
		numerator = a;
		denominator = b;
	}
	else
		cout << "The denominator is out of range!";
	reduction();
}

// overloaded + operator
RationalNumber RationalNumber::operator+(const RationalNumber& n)
{
	RationalNumber temp;
	temp.numerator = (this->numerator * n.denominator + this->denominator * n.numerator);
	temp.denominator = this->denominator * n.denominator;
	temp.reduction();
	return temp;
}

// overloaded - operator
RationalNumber RationalNumber::operator-(const RationalNumber& n)
{
	RationalNumber temp;
	temp.numerator = (this->numerator * n.denominator - this->denominator * n.numerator);
	temp.denominator = this->denominator * n.denominator;
	temp.reduction();
	return temp;
}

// overloaded * operator
RationalNumber RationalNumber::operator*(const RationalNumber& n)
{
	RationalNumber temp;
	temp.numerator = this->numerator * n.numerator;
	temp.denominator = this->denominator * n.denominator;
	temp.reduction();
	return temp;
}

// overloaded / operator
RationalNumber RationalNumber::operator/(const RationalNumber& n)
{
	RationalNumber temp;
	if (n.numerator != 0)
	{
		temp.numerator = this->numerator * n.denominator;
		temp.denominator = this->denominator * n.numerator;
		temp.reduction();
		return temp;
	}
	else
		cout << "Divisor should be bigger than zero.";
}

// overloaded > operator
bool RationalNumber::operator>(const RationalNumber& n) const
{
	int a, b, t;
	t = this->denominator * n.denominator;
	a = this->numerator * (t / this->denominator);
	b = n.numerator * (t / n.denominator);
	if (a > b)
		return true;
	else
		return false;

}

// overloaded < operator
bool RationalNumber::operator<(const RationalNumber& n) const
{
	int a, b, t;
	t = this->denominator * n.denominator;
	a = this->numerator * (t / this->denominator);
	b = n.numerator * (t / n.denominator);
	if (a < b)
		return true;
	else
		return false;
}

// overloaded >= operator
bool RationalNumber::operator>=(const RationalNumber& n) const
{
	int a, b, t;
	t = this->denominator * n.denominator;
	a = this->numerator * (t / this->denominator);
	b = n.numerator * (t / n.denominator);
	if (a >= b)
		return true;
	else
		return false;
}

// overloaded <= operator
bool RationalNumber::operator<=(const RationalNumber& n) const
{
	int a, b, t;
	t = this->denominator * n.denominator;
	a = this->numerator * (t / this->denominator);
	b = n.numerator * (t / n.denominator);
	if (a <= b)
		return true;
	else
		return false;
}

// overloaded == operator
bool RationalNumber::operator==(const RationalNumber& n) const
{
	int a, b, t;
	t = this->denominator * n.denominator;
	a = this->numerator * (t / this->denominator);
	b = n.numerator * (t / n.denominator);
	if (a == b)
		return true;
	else
		return false;
}

// overloaded != operator
bool RationalNumber::operator!=(const RationalNumber& n) const
{
	int a, b, t;
	t = this->denominator * n.denominator;
	a = this->numerator * (t / this->denominator);
	b = n.numerator * (t / n.denominator);
	if (a != b)
		return true;
	else
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
