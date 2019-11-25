// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
   RationalNumber( int = 0, int = 1 ); // default constructor
   /* Write prototype for operator + */
   RationalNumber operator +(RationalNumber &object2);
    /* Write prototype for operator - */
    RationalNumber operator -(RationalNumber &object2);
   /* Write prototype for operator * */
   RationalNumber operator *(RationalNumber &object2);
   /* Write prototype for operator / */
   RationalNumber operator /(RationalNumber &object2);

   // relational operators
   /* Write prototype for operator > */
   bool operator >(RationalNumber &object2);
   /* Write prototype for operator < */
   bool operator <(RationalNumber &object2);
   /* Write prototype for operator >= */
   bool operator >=(RationalNumber &object2);
   /* Write prototype for operator <= */
   bool operator <=(RationalNumber &object2);

   // equality operators
   /* Write prototype for operator == */
   bool operator ==(RationalNumber &object2);
   /* Write prototype for operator != */
   bool operator !=(RationalNumber &object2);

   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif
