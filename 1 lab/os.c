#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#define MAX 1024
#include "stack.h"
#include <sys/wait.h>
char* msg; 
my_stack_t* stack;
int p[2];
int status;
void sig_handler_server(int signo)
{
    char inbuf[MAX], first_word[MAX], second_word[MAX];
    int nbytes, i, j, x;
    nbytes = read(p[0], inbuf, MAX);
    i=0,j=0;
    while(inbuf[i]>='a'&&inbuf[i]<='z'||inbuf[i]=='_')
    { 
        first_word[i]=inbuf[i];
        i++;
    }   
    first_word[i]='\0';
    while(!(inbuf[i]>='0'&&inbuf[i]<='9'))
    {
        i++;
    }
    while(inbuf[i]>='0'&&inbuf[i]<='9')
    {
        second_word[j++]=inbuf[i++];
    }
    second_word[j]='\0';
    x = atoi(second_word);
    if (strcmp(first_word,"create")==0){
        create(stack);
    }
    else if (strcmp(first_word,"peek")==0)
        printf("%i\n", peek(stack));
    else if (strcmp(first_word,"pop")==0)
        pop(stack);
    else if (strcmp(first_word,"empty")==0)
        printf("%i\n", empty(stack));
    else if (strcmp(first_word,"display")==0)
        display(stack);
    else if (strcmp(first_word,"stack_size")==0)
        stack_size(stack);
    else if (strcmp(first_word,"push")==0)
        push(stack,x);
}
void sig_handler_client(int signo)
{
    scanf("%s",msg);
    write(p[1], msg, MAX); 
    kill(getpid(), SIGUSR2);
}
int main() 
{ 
    signal(SIGUSR1, sig_handler_client);
    signal(SIGUSR2, sig_handler_server);
    stack = malloc(sizeof(my_stack_t));
	msg = malloc(sizeof(char)*MAX);
    pipe(p);
    int pid = fork();
    while(1)
    {
        if (pid == 0) {
            kill(getppid(),SIGUSR1);
            sleep(1);
        } 
        else {
            wait(&status);
            sleep(1);
        } 
    }
    return 0;
}