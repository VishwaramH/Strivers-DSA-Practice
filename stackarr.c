// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void printStack(int *stack, int top) {
    for(int i=0;i<top;i++) {
        printf("%d\n",stack[i]);
    }
}

int push(int *stack, int top) {
    if(top >= MAX) {
        printf("Stack is full! Please pop an element from the stack|\n");
        return top;
    } else {
        int elem;
        printf("Enter the element to be pushhed\n");
        scanf("%d",&elem);
        stack[top] = elem;
        top++;
        printf("Element %d got inserted\n",elem);
        return top;
    }
}

int pop(int *stack, int top) {
    if(top <= 0) {
        printf("Stack is empty! Pop operation cannot be performed!\n");
        return top;
    } else {
        top--;
        printf("Element got popped\n");
        return top;
    }
}

int main() {
    int *stack, top;
    char op;
    stack = malloc(MAX*sizeof(int));
    printf("Please enter the values of the stack\n");
    for(int i=0;i<MAX;i++) {
        scanf("%d",&stack[i]);
    }
    top = MAX;
    printf("Please enter the operation to perform\n");
    scanf(" %c",&op);
    while(op!='!') {
        switch(op) {
            case 'a':
                top = push(stack,top);
                break;
            case 'b':
                top = pop(stack,top);
                break;
            case 'c':
                printStack(stack, top);
        }
        printf("Please enter the operation to perform\n");
        scanf(" %c",&op);
    }
    return 0;
}