/* Stack class. Inherentry thread-safe on account of being an actor */

#define _STACK_T
#include <stdlib.h>

#include "stack.h"


struct _stack_t
{
    size_t len;
    void **data;
};


stack_t stack_new( void )
{
    stack_t stack = calloc( 1, sizeof(*stack) );

    return stack;
}

void stack_delete( stack_t stack )
{
    free( stack );
}

void stack_push( stack_t stack, void *datum )
{
    stack->len++;
    stack->data = realloc( stack->data, stack->len * sizeof(void*) );

    stack->data[ stack->len - 1 ] = datum;
}

void *stack_pop( stack_t stack )
{
    void *datum = NULL;

    if( stack->len > 0 )
    {
        datum = stack->data[ stack->len - 1 ];
        stack->len--;
        stack->data = realloc( stack->data, stack->len * sizeof(void*) );
    }

    return datum;
}
