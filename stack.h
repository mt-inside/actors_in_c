
typedef struct _stack_t *stack_t;


extern stack_t stack_new( void );
extern void stack_delete( stack_t stack );

extern void stack_push( stack_t stack, void *datum );
extern void *stack_pop( stack_t stack );
