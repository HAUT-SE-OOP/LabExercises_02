// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
   RationalNumber( int = 0, int = 1 ); // default constructor
   RationalNumber operator+(  const RationalNumber & );// addition operator; RationalNumber + HugeInt
   /* Write prototype for operator + */
   RationalNumber operator-(  const RationalNumber & );// subtract operator; RationalNumber - HugeInt
   /* Write prototype for operator - */
   RationalNumber operator*(  const RationalNumber & );// multiply operator; RationalNumber * HugeInt
   /* Write prototype for operator * */
   RationalNumber operator/(  const RationalNumber & );// except operator; RationalNumber / HugeInt
   /* Write prototype for operator / */

   bool operator>(RationalNumber &);//more than
   /* Write prototype for operator > */
   bool operator<(RationalNumber &);//less than
   /* Write prototype for operator < */
   bool operator>=(RationalNumber &);//more than or equal
   /* Write prototype for operator >= */
   bool operator<=(RationalNumber &);//less than or equal
   /* Write prototype for operator <= */

   // equality operators
   bool operator==(RationalNumber &);//Judge whether two numbers are equal
   /* Write prototype for operator == */
   bool operator!=(RationalNumber &);//J bool operatoudge whether two numbers are not equal
   /* Write prototype for operator != */

   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif
