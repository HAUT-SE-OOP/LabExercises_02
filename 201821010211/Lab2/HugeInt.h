// Lab 2: Hugeint.h
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public:
   HugeInt( long = 0 ); // conversion/default constructor
   HugeInt( const char *string ); // conversion constructor

   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const;
   HugeInt operator+( const std::string &) const;
   // addition operator;
   // HugeInt + string that represents large integer value
   const HugeInt &operator=( const HugeInt &);
   bool operator==(const HugeInt &)const;
   bool operator!=(const HugeInt &op2)const
   {
       return !(*this==op2);
   }
   bool operator>(const HugeInt &)const;
   bool operator<=(const HugeInt &op2)const
   {
       return !(*this==op2);
   }
    bool operator<(const HugeInt &)const;
   bool operator>=(const HugeInt &op2)const
   {
       return !(*this==op2);
   }
   /* Write prototypes for the six relational and equality operators */

   int getLength() const;
private:
   short integer[ 30 ];
}; // end class HugeInt

#endif
