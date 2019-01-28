#include <stdlib.h>
#include <stdio.h>
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

int empty(my_stack_t* stack){
    if (stack!=NULL)
        return stack->n==0;
    else
        return -1;
    
}
int peek(my_stack_t* stack){
    if ((stack!=NULL)&&!empty(stack))
        return stack -> top -> value;
    else
        return -1;
}
void push(my_stack_t* stack, int data){
    if (stack!=NULL)
    {
        node_t* node = malloc(sizeof(node_t));
        stack->n++; 
        if (empty(stack)){
            stack->top = node;
            node->value = data;
        } 
        else
        {
            node->next = stack->top;
            stack->top = node;
            node->value = data;  
        }
    }
}
void pop(my_stack_t* stack){
    if ((stack!=NULL)&&!empty(stack))
    {
        node_t* n = stack->top;
        free(n);
        stack->top=stack->top->next;
        stack->n--;
    }    
}
void display(my_stack_t* stack){
    if ((stack!=NULL)&&!empty(stack))
    {
        int m = stack->n;
        node_t* current = stack->top;
        for (int i = m; i > 0; i--)
        {
            printf("%i ", current->value);
            current=current->next;
        }
        printf("\n");
    }
}
void create(my_stack_t* stack)
{
    if (stack!=NULL)
        stack->n=0;
}
void stack_size(my_stack_t* stack)
{
    if (stack!=NULL)
        printf("%i\n", stack->n);
}