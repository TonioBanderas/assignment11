#include "base.h"


/*
These are the kinds of partenthesis this program will look for.
    ()
    <>
    []
    {}
*/
typedef struct Stack {
    char parentheses;
    struct Stack* next;
} Stack;

Stack* make_stack(char parentheses) {
    Stack * stack;
    stack = xcalloc(1, sizeof(Stack));
    stack->parentheses = parentheses;
    stack->next = NULL;
    return stack;
}

void push(char parentheses, Stack ** old_stack) {
    Stack *new_stack = make_stack(parentheses);
    new_stack->next = *old_stack;
    *old_stack = new_stack;
}

bool is_stack_empty(Stack* stack) {
    return !stack;
}

char pop(Stack** stack) {
    if(is_stack_empty(*stack)){
        return 0;
    }
    Stack* temp = *stack;
    *stack = (*stack)->next; 
    char popped = temp->parentheses;
    free(temp);
    return popped;
}

void print_my_text(String text) {
    //printf("\n");
    for(int index = 0; text[index] != '\0'; index++) {
        printf("%c", text[index]);
    }
    printf("\n");
}

bool is_opposite(char open, char close) {
    if( (open == '(' && close == ')') ||
        (open == '<' && close == '>') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == '}')) {
        return true;
    }
    return false;

}

bool verify_parentheses(String text) {
    Stack* stack = NULL;
    for(int index = 0; text[index] != '\0'; index++) {
        if( text[index] == '(' ||
            text[index] == '<' ||
            text[index] == '{' ||
            text[index] == '[' ||
            text[index] == ')' ||
            text[index] == '>' ||
            text[index] == '}' ||
            text[index] == ']')
            {   
            push(text[index], stack);
                while(is_opposite(stack->next->parentheses, stack->parentheses)){
                    pop(stack);
                
                    printf("dieses element liegt oben auf: %c\n", stack->parentheses);
                    pop(stack);
                }
            }
        }
    return false;
}

int main(void) {
    //report_memory_leaks(true);
    
    test_equal_i(verify_parentheses(""), true);
    test_equal_i(verify_parentheses("Hello World"), true);
    test_equal_i(verify_parentheses("()"), true);
    test_equal_i(verify_parentheses("<{[()]}>"), true);
    test_equal_i(verify_parentheses("<{[)]}>"), false);
    test_equal_i(verify_parentheses("( Test ) "), true);
    test_equal_i(verify_parentheses("(1+2)*[2+3+(1 + 6/5)]"), true);
    test_equal_i(verify_parentheses("(an unmatched left parenthesis creates an unresolved tension that will stay with you all day"), false);
    test_equal_i(verify_parentheses("< [ > ]"), false);
    test_equal_i(verify_parentheses("<{[()]}"), false);
    test_equal_i(verify_parentheses("(<<({[({<{<({<([[[<[{(<{(<{{<[{<{{{<<{([<<<{{[{<<[[(([{[[[([(({()}))])]]]}]))]]>>}]}}>>>])}>>}}}>}]>}}>)}>)}]>]]])>})>}>})]})>>)"), true);
    
    
    Stack* stack = NULL;
    push('"', &stack);
    push('r', &stack);
   
    char a = pop(&stack);
    //printf("%c", stack->parenthesis);
    char b = pop(&stack);

    printf("%c", b);

    //pop(stack);
    return 0;
}
