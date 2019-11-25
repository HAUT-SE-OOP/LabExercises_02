// Lab 2: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

#include "Hugeint.h" // HugeInt class definition

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   for ( int j = 29; value != 0 && j >= 0; j-- )
   {
      integer[ j ] = value % 10;
      value /= 10;
   } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const char *string )
{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = strlen( string );

   for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )

      if ( isdigit( string[ k ] ) )
         integer[ j ] = string[ k ] - '0';

} // end HugeInt conversion constructor

// get function calculates length of integer
int HugeInt::getLength() const
{
   int i;
   for ( i = 0; i <= 29; i++ )
      if ( integer[ i ] != 0 )
         break; // break when first digit is reached

   return 30 - i; // length is from first digit (at i) to end of array
} // end function getLength

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
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
      } // end if
      else // no carry
         carry = 0;
   } // end for

   return temp; // return copy of temporary object
} // end function operator+

HugeInt HugeInt::operator-( const HugeInt &op2 ) const
{
   HugeInt temp; // temporary result
   int carry = 0,flag=0,f=0,i;
   if(getLength()<op2.getLength())
    carry=1;
   else if(getLength()==op2.getLength())
   {
       for(i=30-getLength();i<30;++i)
       {
            if(integer[i]>op2.integer[i])
                flag++;
            else if (integer[i]<op2.integer[i])
            {
                carry=1;break;
            }
       }
      if(flag==0&&carry==1);
      else carry=0;
   }
   else if(getLength()>=op2.getLength())
    carry=0;

   flag=0;
   if(carry==0)
   {
       for ( i = 29; i >= 0; i-- )
   {
      if ( integer[ i ] >= op2.integer[i] )
      {
         flag = 0;
      }
      else
         flag = 1;

         if(flag==0)
         {
              temp.integer[ i ] =
          integer[ i ]-op2.integer[ i ]-f;
         }
         else if(flag==1)
         {
              temp.integer[ i ] =
          integer[ i ]-op2.integer[ i ]-f+10;
         }

          f=flag;
   }
   }
   else
   {
       for ( i = 29; i >= 0; i-- )
   {
      if ( integer[ i ] <= op2.integer[i] )
      {
         flag = 0;
      }
      else
         flag = 1;

         if(flag==0)
         {
              temp.integer[ i ] =
          op2.integer[ i ]-integer[ i ]-f;
         }
         else if(flag==1)
         {
              temp.integer[ i ] =
          op2.integer[ i ]-integer[ i ]-f+10;
         }

          f=flag;
   }
      temp.integer[ 29-temp.getLength() ]=-1;
   }

   return temp; // return copy of temporary object
}

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const char *op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// equality operator; HugeInt == HugeInt
/* Write a definition for the == operator */
bool HugeInt::operator ==( const  HugeInt&op2 ) const
{
    int i;
    //cout<<getLength()<<endl;
    if(getLength()!=op2.getLength())
        return false;

    for(i=30-getLength();i<30;++i)
        {
            if(integer[i]!=op2.integer[i])
                return false;
        }

    return true;
}

// inequality operator; HugeInt != HugeInt
/* Write a definition for the != operator
   by calling the == operator */
bool HugeInt::operator!=( const  HugeInt&op2 ) const
{
    return !(*this==op2);
}

// less than operator; HugeInt < HugeInt
/* Write a definition for the < operator */
bool HugeInt::operator<( const  HugeInt&op2 ) const
{
    int i,f1,f2;
    if(getLength()<op2.getLength())
        return true;
    else if(getLength()==op2.getLength())
    {
        for(i=30-getLength(),f1=0,f2=0;i<30;++i)
        {
            if(integer[i]<op2.integer[i])
            {
                f1++;break;
            }
            else if(integer[i]>op2.integer[i])
                f2++;
        }
        if(f1>0&&f2==0)
            return true;
    }
    return false;
}

// less than or equal operator; HugeInt <= HugeInt
/* Write a definition for the <= operator
   by calling the < and == operators */
bool HugeInt::operator<=( const  HugeInt&op2 ) const
{
    return !(*this>op2);
}

// greater than operator; HugeInt > HugeInt
/* Write a definition for the > operator
   by calling the <= operator */
bool HugeInt::operator>( const  HugeInt&op2 ) const
{
    return op2<*this;
}

// greater than or equal operator; HugeInt >= HugeInt
/* Write a definition for the >= operator
   by calling the > and == operators */
bool HugeInt::operator>=( const  HugeInt&op2 ) const
{
    return !(*this<op2);
}

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i,j=0;

   for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ )
      ; // skip leading zeros

   if ( i == 30 )
      output << 0;
   else
   {
       if(num.integer[30-num.getLength()]==-1)
            {
                output <<'-';j++;
            }
       for (i=30-num.getLength()+j ; i <= 29; i++ )
      {
          output << num.integer[ i ];
      }
   }
   return output;
} // end function operator<<
