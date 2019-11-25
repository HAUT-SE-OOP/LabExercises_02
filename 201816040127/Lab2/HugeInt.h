#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public:
   HugeInt( long = 0 ); // conversion/default constructor
   HugeInt( const char * ); // conversion constructor

   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const;

   // addition operator;
   HugeInt operator+( const char * ) const;// HugeInt + string that represents large integer value

   HugeInt operator-( const HugeInt & ) const;

   // addition operator; HugeInt - int
   HugeInt operator-( int ) const;

   // addition operator;
   HugeInt operator-( const char * ) const;// HugeInt - string that represents large integer value


   bool operator==( const HugeInt & ) const;//the == relational

   bool operator!=( const HugeInt & ) const;//the != relational

   bool operator>( const HugeInt & ) const;//the > relational

   bool operator<( const HugeInt & ) const;//the < relational

   bool operator>=( const HugeInt & ) const;//the >= relational

   bool operator<=( const HugeInt & ) const;//the <= relational

   int getLength() const;
private:
   short integer[ 30 ];
}; // end class HugeInt

#endif
