// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
    void setValues(int ,int );
    void setNumerator(int );
    void setDenominator(int );
    int getDenominatorr()const;
    int  getNumerator()const;
   RationalNumber( int = 0, int = 1 ); // default constructor
   /* Write prototype for operator + */
  RationalNumber operator+( const RationalNumber & ) const;
   /* Write prototype for operator - */
   RationalNumber operator-( const RationalNumber & ) const;
   /* Write prototype for operator * */
   RationalNumber operator*( const RationalNumber & ) const;
   /* Write prototype for operator / */
   RationalNumber operator/( const RationalNumber & ) const;

   // relational operators
   /* Write prototype for operator > */
    bool operator > ( const RationalNumber & ) const;
   /* Write prototype for operator < */
    bool operator<( const RationalNumber & ) const;
   /* Write prototype for operator >= */
    bool operator>=( const RationalNumber & ) const;
   /* Write prototype for operator <= */
   bool operator<=( const RationalNumber & ) const;

   // equality operators
   /* Write prototype for operator == */
   bool operator==( const RationalNumber & ) const;
   /* Write prototype for operator != */
   bool operator!=( const RationalNumber & ) const;
   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif

