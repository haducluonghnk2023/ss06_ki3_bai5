#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;
void initializeStack(Stack *stack) {
    stack->top = -1;
}
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(Stack *stack, char value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("ngan xep da day.\n");
    }
}
char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("ngan xep rong.\n");
        return '\0';
    }
}

int main(){
	char input[MAX_SIZE];
    Stack stack;
    initializeStack(&stack);

    printf("nhap 1 chuoi: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; 

    for (int i = 0; input[i] != '\0'; i++) {
        push(&stack, input[i]);
    }

    printf("chuoi dao nguoc: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}
