// Lab 2: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

#include "Hugeint.h" // HugeInt class definition

HugeInt::HugeInt( long value )  // a long integer into a HugeInt object
{
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   for ( int j = 29; value != 0 && j >= 0; j-- )
   {
      integer[ j ] = value % 10;
      value /= 10;
   }
}

HugeInt::HugeInt( const char *string )  // representing a large integer into a HugeInt object

{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = strlen( string );

   for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )

      if ( isdigit( string[ k ] ) )
         integer[ j ] = string[ k ] - '0';

}

int HugeInt::getLength() const  // get function calculates length of integer

{
    int i;
   for ( int i = 0; i <= 29; i++ )
      if ( integer[ i ] != 0 )
         break; // break when first digit is reached

   return 30 - i; // length is from first digit (at i) to end of array
}

HugeInt HugeInt::operator+( const HugeInt &op2 ) const  // addition operator; HugeInt + HugeInt
{
   HugeInt temp; // temporary result
   int carry = 0;

   for ( int i = 29; i >= 0; i-- )
   {
      temp.integer[ i ] =
         integer[ i ] + op2.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
      {
         temp.integer[ i ] %= 10;  // reduce to 0-9
         carry = 1;
      }
      else
         carry = 0;
   }

   return temp; // return copy of temporary object
}

HugeInt HugeInt::operator+( int op2 ) const // addition operator; HugeInt + int
{
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
}

HugeInt HugeInt::operator+( const char *op2 ) const  // HugeInt + string that represents large integer value
{
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// equality operator; HugeInt == HugeInt

bool HugeInt::operator==(HugeInt &op2)
{
  if(*this != op2)
    return false;
   return true;
}

// inequality operator; HugeInt != HugeInt

bool HugeInt::operator!=(HugeInt &op2)
{
   if(*this == op2)
    return false;
   return true;
}
// less than operator; HugeInt < HugeInt
bool HugeInt::operator<(HugeInt &op2)
{
   if(*this < op2)
        return true;
    else
        return false;

}
// less than or equal operator; HugeInt <= HugeInt

bool HugeInt::operator<=(HugeInt &op2)
{
    if(*this < op2 || *this == op2)
        return true;
    else
        return false;

}
// greater than operator; HugeInt > HugeInt
bool HugeInt::operator>(HugeInt &op2)
{
   if(*this > op2)
    return true;
   else
    return false;
}
// greater than or equal operator; HugeInt >= HugeInt

bool HugeInt::operator>=(HugeInt &op2)
{
    if(*this > op2 || *this == op2)
        return true;
    else
        return false;
}
// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ )
      ; // skip leading zeros

   if ( i == 30 )
      output << 0;
   else

      for ( ; i <= 29; i++ )
         output << num.integer[ i ];

   return output;
} // end function operator<<


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
