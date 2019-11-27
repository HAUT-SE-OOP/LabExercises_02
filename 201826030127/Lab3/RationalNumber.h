#ifndef RATIONAL_NUMBERS_H_INCLUDED
#define RATIONAL_NUMBERS_H_INCLUDED

// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
   RationalNumber( int = 0, int = 1 ); // default constructor
   RationalNumber operator+(const RationalNumber &);
   RationalNumber  operator - (const RationalNumber &);
   RationalNumber  operator * (const RationalNumber &);
   RationalNumber  operator / (const RationalNumber &);

   // relational operators

   bool  operator > (const RationalNumber &);
   bool  operator < (const RationalNumber &);
   bool  operator >= (const RationalNumber &);
   bool  operator <= (const RationalNumber &);

   // equality operators
   bool  operator == (const RationalNumber &);
   bool  operator != (const RationalNumber &);

   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif
#endif // RATIONAL_NUMBERS_H_INCLUDED
