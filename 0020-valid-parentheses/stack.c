#include <stdbool.h>

typedef struct Stack
{
    int top;
    char arr[10000];
} Stack;

bool isEmpty(Stack* stack)
{
    return (stack->top == -1);
}

bool isFull(Stack* stack)
{
    return (stack->top == (10000 - 1));
}

void push(Stack* stack, char c)
{
    if (!isFull(stack))
    {
        stack->arr[++(stack->top)] = c;
    }
}

void pop(Stack* stack)
{
    char ret = stack->arr[stack->top];
    stack->top--;
}

char peek(Stack* stack)
{
    return stack->arr[stack->top];
}

bool isValid(char* s)
{
    // Initialize stack
    Stack st;
    st.top = -1;

    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            push(&st, s[i]);
        }
        else
        {
            if (isEmpty(&st)) // Error case: Got a closing bracket when stack is empty
            {
                return false;
            }
            else if ((s[i] == ')') && (peek(&st) == '('))
            {
                pop(&st);
            }
            else if ((s[i] == '}') && (peek(&st) == '{'))
            {
                pop(&st);
            }
            else if ((s[i] == ']') && (peek(&st) == '['))
            {
                pop(&st);
            }
            else // Other invalid case
            {
                return false;
            }
        }
    }

    // Valid stack is empty
    return isEmpty(&st);
}