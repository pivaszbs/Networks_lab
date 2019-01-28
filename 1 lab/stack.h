#ifndef STACK_H_
#define STACK_H_
typedef struct node 
{
    int value;
    struct node* next;
} node_t;
typedef struct stack
{
    node_t* top;
    int n;
} my_stack_t;
int peek(my_stack_t* s);  
void push(my_stack_t* s, int data);
void pop(my_stack_t* s);
int empty(my_stack_t* s);
void display(my_stack_t* s);
void create(my_stack_t* s);
void stack_size(my_stack_t* s);
#endif