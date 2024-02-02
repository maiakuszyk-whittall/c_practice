/* Highest Digit Detector
 *
 * Takes a number of arguments on the command line and returns the largest digit
 * if any from each argument.
 *
 * Written by Oliver Dixon
 * Commented by Maia Kuszyk-Whittall
 *
 * Friday, 2nd February 2024 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct digit {
    char value;
    size_t position;
};

static inline bool is_digit ( char c )
{
    // Switch case is used as it optimises the process into a one cycle or
    // sometimes a zero cycle time-frame instead of a perhaps five cycle routine
    switch ( c ) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
    }

    return false;
}

static bool get_digit ( const char * str, struct digit * result )
{
    // ASCII offset is used so that computing can be done and printed using the
    // real world value of the number not the ASCII value
    // Defining the string length so it doesn't have to be repeated for each
    // character in the for loop 
    const char ASCII_OFFSET = '0';
    const size_t len = strlen ( str );

    struct digit digit = { .value = -1 };
    char c;
   
    // Loops for length of string entered into command line 
    for ( size_t i = 0; i < len; i++ ) {
        // value looking at in each loop cycle is stored in c
        c = str [ i ];
       
        // If c is a digit and equal to or bigger than the current stored value
        // it is stored as the new value
        if ( is_digit ( c ) && c >= digit.value ) {
            digit.value = str [ i ];
            digit.position = i;
        }
    }

    // Checks that the string has a value to return if not there is not a value
    // to print
    if ( digit.value > 0 ) {
        result->value = digit.value - ASCII_OFFSET;
        result->position = digit.position;
        return true;
    }

    return false;
}

int main ( int argc, char ** argv )
{
    // Defines struct
    struct digit digit;
   
    // For each argument the function checks if the argument has any digits if
    // not it is ignored
    for ( int i = 1; i < argc; i++ )
        if ( get_digit ( argv [ i ], &digit ) )
            // Prints the highest digit and its position
            printf ( "Digit = %d\tPosition = %ld\n", digit.value,
                digit.position );

    return 0;
}

