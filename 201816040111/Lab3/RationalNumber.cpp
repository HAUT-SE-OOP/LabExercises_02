bool RationalNumber::operator>( RationalNumber &op)
{if ( judgeDenominatorZero( denominator , op.denominator ) == 1 )
    {
        op.denominator = -1;
        return 0;
    }
    else if( denominator == op.denominator)
    {
        if(numerator > op.numerator)
            return true;
        else
            return false;
    }
    else
    {
        if ( numerator * op.denominator > op.numerator * denominator )
            return true;
        else
            return false;
    }
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<( RationalNumber &op )
{if ( judgeDenominatorZero( denominator , op.denominator ) == 1 )
    {
        op.denominator = -1;
        return 0;
    }
   else if( denominator == op.denominator)
    {
        if(numerator > op.numerator)
            return false;
        else
            return true;
    }
    else
    {
        if ( numerator * op.denominator > op.numerator * denominator )
            return false;
        else
            return true;
    }
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=( RationalNumber &op)
{if ( judgeDenominatorZero( denominator , op.denominator ) == 1 )
    {
        op.denominator = -1;
    }
    if ( operator > (op) || operator == (op) )
        return true;
    else
        return false;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=( RationalNumber &op )
{if ( judgeDenominatorZero( denominator , op.denominator ) == 1 )
    {
        op.denominator = -1;
    }
    if ( operator < (op)|| operator == (op) )
        return true;
    else
        return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==( RationalNumber &op )
{if ( judgeDenominatorZero( denominator , op.denominator ) == 1 )
    {
        op.denominator = -1;
    }
    if ( (numerator == op.numerator) && ( denominator == op.denominator) )
        return true;
    else
        return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=( RationalNumber &op )
{if ( judgeDenominatorZero( denominator , op.denominator ) == 1 )
    {
        op.denominator = -1;
    }
    if ( !operator == (op) )
        return true;
    else
        return false;
}
// function printRational definition
bool RationalNumber::judgeDenominatorZero( int x , int y )
{
    if(  x == 0 || y == 0 )
        return true;
    else
        return false;
}

// function reduction definition
void RationalNumber::reduction()
{
    int largest, gcd = 1;  // greatest common divisor;

    largest = ( numerator > denominator ) ? numerator: denominator;

    for ( int loop = 2; loop <= largest; loop++ )
        if ( numerator % loop == 0 && denominator % loop == 0 )
            gcd = loop;

    numerator /= gcd;
    denominator /= gcd;
} // end function reduction

ostream &operator<<( ostream &output , const RationalNumber &a)
{
    if (a.denominator == -1)
        cout << "Denominator is 0, so it can't operator";
     if ( a.numerator == 0 ) // print fraction as zero
        cout << a.numerator ;
    else if ( a.denominator == 1 ) // print fraction as integer
        cout << a.numerator;

    else
        cout << a.numerator << '/' << a.denominator;
        return output;
}
