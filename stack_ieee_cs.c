#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int min[MAX_SIZE];
    int max[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
    if (s->top == 0) {
        s->min[s->top] = x;
        s->max[s->top] = x;
    } else {
        s->min[s->top] = (x < s->min[s->top - 1]) ? x : s->min[s->top - 1];
        s->max[s->top] = (x > s->max[s->top - 1]) ? x : s->max[s->top - 1];
    }
}

void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return;
    }
    s->top--;
}

int top(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return s->data[s->top];
}

int getMin(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return s->min[s->top];
}

int getMax(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return s->max[s->top];
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 5);
    push(&s, 1);
    push(&s, 10);
    push(&s, 0);
    push(&s, 7);
    
    printf("Top element: %d         O(1)\n", top(&s));
    printf("Minimum element: %d     O(1)\n", getMin(&s));
    printf("Maximum element: %d     O(1)\n", getMax(&s));
    
    pop(&s);
    printf("After popping, Top: %d, Min: %d, Max: %d\n", top(&s), getMin(&s), getMax(&s));
    
    return 0;
}
