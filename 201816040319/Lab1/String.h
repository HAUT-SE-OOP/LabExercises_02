#include <cstring>
#include <iostream>
#include <cassert>
using namespace std;
class String{
 friend ostream &operator<<(ostream &output,const String &s);
 public:
     String (const char *const = "");
     String (const String &);
     ~String ();
     const String &operator=(const String &);
     const String operator+(const String &);
 private:
    char*sPtr;
    int length;


};
