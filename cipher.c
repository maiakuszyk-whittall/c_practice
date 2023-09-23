#include <stdio.h>
#include <string.h>

static char * cipher ( char * str )
{
    const int alphabet_length = 'Z'-'A' + 1 ;
    const int key = 10;
    const size_t string_length = strlen(str);

    char ch;

    for(size_t i = 0; i< string_length; i++)
    {
        ch = str[i] - 'A';
        if ( ch >= alphabet_length || ch<0 )
            return "ERROR!";

        str[i] = ((ch + key) % alphabet_length) + 'A';
    }
    return str;
}

int main ( int argc, char ** argv )
{
    for ( int i = 1; i < argc; i++ )
		puts ( cipher ( argv [ i ] ) );
	
    return 0;
}

