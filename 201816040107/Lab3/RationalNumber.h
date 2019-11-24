// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
   RationalNumber( int = 0, int = 1 ); // default constructor
   /* Write prototype for operator + */
   RationalNumber operator+(RationalNumber &);//生命重载'+';
   RationalNumber operator-(RationalNumber &);//声明重载'-';
   RationalNumber operator*(RationalNumber &);//声明重载'*';
   RationalNumber operator/(RationalNumber &);//声明重载'/';
   bool operator>(RationalNumber &);
   bool operator>=(RationalNumber &);
   bool operator<(RationalNumber &);
   bool operator<=(RationalNumber &);
   bool operator==(RationalNumber &);
   bool operator!=(RationalNumber &);
   /* Write prototype for operator - */
   /* Write prototype for operator * */
   /* Write prototype for operator / */

   // relational operators
   /* Write prototype for operator > */
   /* Write prototype for operator < */
   /* Write prototype for operator >= */
   /* Write prototype for operator <= */

   // equality operators
   /* Write prototype for operator == */
   /* Write prototype for operator != */

   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif



