#ifndef MYTEMP_H
#define MYTEMP_H
/*
    Following Appendix D
    Description of Generci Fuction Templates
    The Generic Function Templates are implemented below:
*/

// t scalar_difference
// Returns absolute difference between scalar values:
template <typename T>

double scalar_difference(T a, T b)
{

    return abs(a.getScalarValue() - b.getScalarValue());

} // end of double scalar_difference(T a, T b)

// t equals
// Returns true if two values are equal:
template <typename T>

bool equals(T a, T b)
{

    return a == b;

} // end of bool equals(T a, T b)


/*
================================================================================
==                            Addtional Templates                             ==
================================================================================
*/


// t CompareScalar:
// Returns true if the scalar value of a is less than the scalar value of b:
// If ASC is true, the comparison is made in ascending order:
// If ASC is false, the comparison is made in descending order:
template <typename T, bool ASC>

bool CompareScalar(T a, T b)
{

    if (ASC)
    {
        
        return a.getScalarValue() < b.getScalarValue();

    }
    else
    {

        return a.getScalarValue() > b.getScalarValue();

    } // end of if-else statement

} // end of bool CompareScalar(T a, T b)


// t CompareX:
// Returns true if the x value of a is less than the x value of b:
// If ASC is true, the comparison is made in ascending order:
// If ASC is false, the comparison is made in descending order:
template <typename T, bool ASC>

bool CompareX(T a, T b)
{

    if (ASC)
    {

        return a.getX() < b.getX();

    }
    else
    {

        return a.getX() > b.getX();

    } // end of if-else statement

} // end of bool CompareX(T a, T b)


// t CompareY:
// Returns true if the y value of a is less than the y value of b:
// If ASC is true, the comparison is made in ascending order:
// If ASC is false, the comparison is made in descending order:
template <typename T, bool ASC>
bool CompareY(T a, T b)
{

    if (ASC)
    {

        return a.getY() < b.getY();

    }
    else
    {

        return a.getY() > b.getY();

    } // end of if-else statement

}


// t CompareXandY:
// Returns true if the x value of a is less than the x value of b:
// If ASC is true, the comparison is made in ascending order:
// If ASC is false, the comparison is made in descending order:
// If pt is 1, the comparison is made for the first point:
// If pt is 2, the comparison is made for the second point:
template <typename T, bool ASC, int pt>

bool CompareXandY(T a, T b)
{

    int x1, x2, y1, y2;

    if (pt == 1)
    {

        x1 = a.getPt1().getX();
        y1 = a.getPt1().getY();
        x2 = b.getPt1().getX();
        y2 = b.getPt1().getY();

    }
    else
    {

        x1 = a.getPt2().getX();
        y1 = a.getPt2().getY();
        x2 = b.getPt2().getX();
        y2 = b.getPt2().getY();

    } // end of if-else statement
    if (ASC)
    {

        if (x1 == x2)
        {

            return y1 < y2;

        }
        else
        {

            return x1 < x2;

        } // end of inner if-else statement

    }
    else
    {

        if (x1 == x2)
        {

            return y1 > y2;

        }
        else
        {

            return x1 > x2;

        } // end of inner if-else statement

    } // end of if-else statement

} // end of bool CompareXandY(T a, T b)


// t CompareZ:
// Returns true if the z value of a is less than the z value of b:
// If ASC is true, the comparison is made in ascending order:
// If ASC is false, the comparison is made in descending order:
template <typename T, bool ASC>

bool CompareZ(T a, T b)
{

    if (ASC)
    {

        return a.getZ() < b.getZ();

    }
    else
    {

        return a.getZ() > b.getZ();

    } // end of if-else statement

} // end of bool CompareZ(T a, T b)

#endif
