// Lab 1: String.cpp
// Member-function definitions for String.cpp
#include <iostream>
using namespace std;

#include <cstring> // strcpy and strcat prototypes
#include "String.h" // String class definition

// conversion constructor: convert a char * to String
String::String( const char * const zPtr )
{
   length = strlen( zPtr ); // compute length
   sPtr = new char[ length + 1 ]; // allocate storage
   assert( sPtr != 0 ); // terminate if memory not allocated
   strcpy( sPtr, zPtr ); // copy literal to object
} // end String conversion constructor

// copy constructor
String::String( const String &copy )
{
   length = copy.length; // copy length
   sPtr = new char[ length + 1 ]; // allocate storage
   assert( sPtr != 0 ); // ensure memory allocated
   strcpy( sPtr, copy.sPtr ); // copy string
} // end String copy constructor

// destructor
String::~String()
{
   delete [] sPtr; // reclaim string
} // end destructor

// overloaded = operator; avoids self assignment
const String &String::operator=( const String &right )
{
   if ( &right != this ) // avoid self assignment
   {
      delete [] sPtr; // prevents memory leak
      length = right.length; // new String length
      sPtr = new char[ length + 1 ]; // allocate memory
      assert( sPtr != 0 ); // ensure memory allocated
      strcpy( sPtr, right.sPtr ); // copy string
   }
   else
      cout << "Attempted assignment of a String to itself\n";

   return *this; // enables concatenated assignments
} // end function operator=

// concatenate right operand and this object and store in temp object
const String &String::operator+( const String &right )/* Write the header for the operator+ member function */
{
   String temp;//Declare a temporary String variable named temp
   temp.length = length + right.length; // new length
   char *tempPtr = new char[ temp.length + 1 ]; // create memory

   strcpy( tempPtr, sPtr ); // copy sPtr
   strcpy( tempPtr + length, right.sPtr ); // copy right.sPtr
   assert( sPtr != 0 );// ensure memory allocated
   delete [] sPtr; // prevents memory leak
   sPtr = tempPtr; // assign new array to sPtr
   length = temp.length; // assign new length to length
   return *this;
   /* Return the temporary String */
} // end function operator+

// overloaded output operator
ostream & operator<<( ostream &output, const String &s )
{
   output << s.sPtr;
   return output; // enables concatenation
} // end function operator<<
