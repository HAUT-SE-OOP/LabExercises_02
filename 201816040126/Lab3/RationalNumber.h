// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
    friend std::ostream &operator<<( std::ostream &, const RationalNumber & );
public:
   RationalNumber( int = 0, int = 1 ); // default constructor
   RationalNumber operator+(  const RationalNumber & );//  function to addition operator;
   /* Write prototype for operator + */
   RationalNumber operator-(  const RationalNumber & );// function to subtract operator;
   /* Write prototype for operator - */
   RationalNumber operator*(  const RationalNumber & );// function to multiply operator;
   /* Write prototype for operator * */
   RationalNumber operator/(  const RationalNumber & );//function to  except operator;
   /* Write prototype for operator / */

   bool operator>(RationalNumber &);//function about more
   /* Write prototype for operator > */
   bool operator<(RationalNumber &);//function about less
   /* Write prototype for operator < */
   bool operator>=(RationalNumber &);//function about more or equal
   /* Write prototype for operator >= */
   bool operator<=(RationalNumber &);//function about less or equal
   /* Write prototype for operator <= */

   // equality operators
   bool operator==(RationalNumber &);//Judge whether two numbers are the same
   /* Write prototype for operator == */
   bool operator!=(RationalNumber &);//Judge whether two numbers are the different
   /* Write prototype for operator != */

   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif


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
