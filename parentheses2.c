#include "base.h"

typedef struct Stack {
    char content;
    struct Stack * next;
} Stack;

Stack * stack_new() {
    Stack * s = xcalloc(1, sizeof(Stack));
    s->next = NULL;
    return (s);
}

void stack_push(Stack * stack, char parentheses) {
    Stack * old_stack = stack_new();
    old_stack->content = stack->content;
    old_stack->next = stack->next;
    stack->content = parentheses;
    stack->next = old_stack;
}

void stack_print(Stack * stack) {
    if (stack->next == NULL) {
      printcln(stack->content);  
    }
    else {
        printcln(stack->content);
        stack_print(stack->next);
    }
}

void add_to_stack(String text) {
    Stack * stack = stack_new();

    for(int index = 0; text[index] != '\0'; index++) {
        if (text[index] == '(') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == ')') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == '<') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == '>') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == '[') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == ']') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == '{') {
            stack_push(stack, text[index]);
        }        
        if (text[index] == '}') {
            stack_push(stack, text[index]);
        }

    }
    stack_print(stack);
}


bool verify_parentheses(String text) {
    add_to_stack(text);
    //stack bearbeiten 
    return true;
}

int main(void) {
    //report_memory_leaks(true);

    test_equal_i(verify_parentheses("hello"), true);
    test_equal_i(verify_parentheses("Hello World"), true);
    test_equal_i(verify_parentheses("()"), true);
    /*
    test_equal_i(verify_parentheses("<{[()]}>"), true);
    test_equal_i(verify_parentheses("<{[)]}>"), false);
    test_equal_i(verify_parentheses("( Test ) "), true);
    test_equal_i(verify_parentheses("(1+2)*[2+3+(1 + 6/5)]"), true);
    test_equal_i(verify_parentheses("(an unmatched left parenthesis creates an unresolved tension that will stay with you all day"), false);
    test_equal_i(verify_parentheses("< [ > ]"), false);
    test_equal_i(verify_parentheses("<{[()]}"), false);
    test_equal_i(verify_parentheses("(<<({[({<{<({<([[[<[{(<{(<{{<[{<{{{<<{([<<<{{[{<<[[(([{[[[([(({()}))])]]]}]))]]>>}]}}>>>])}>>}}}>}]>}}>)}>)}]>]]])>})>}>})]})>>)"), true);
    */
    return 0;
}
