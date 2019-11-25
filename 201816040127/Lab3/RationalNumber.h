#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
   RationalNumber( int = 0, int = 1 ); // default constructor

   RationalNumber operator+( const RationalNumber & ) const;// addition operator; RationalNumber +

   RationalNumber operator-( const RationalNumber & ) const;// addition operator; RationalNumber -

   RationalNumber operator*( const RationalNumber & ) const;// addition operator; RationalNumber *

   RationalNumber operator/( const RationalNumber & ) const;// addition operator; RationalNumber /


   // relational operators
   bool operator>( const RationalNumber & ) const;//the > relational

   bool operator<( const RationalNumber & ) const;//the < relational

   bool operator>=( const RationalNumber & ) const;//the >= relational

   bool operator<=( const RationalNumber & ) const;//the <= relational

   // equality operators
   bool operator==( const RationalNumber & ) const;//the == relational

   bool operator!=( const RationalNumber & ) const;//the != relational


   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber
