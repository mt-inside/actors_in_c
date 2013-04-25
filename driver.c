#define _STACK_T
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int main( int argc, char **argv )
{
    stack_t stack = stack_new( );
    char *str;


    stack_push( stack, "!" );
    stack_push( stack, ", world" );
    stack_push( stack, "Hello" );

    while( (str = stack_pop( stack )) )
    {
        printf( "%s", str );
    }
    printf( "\n" );


    return EXIT_SUCCESS;
}
