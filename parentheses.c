#include "base.h"


/*
These are the kinds of partenthesis this program will look for.
    ()
    <>
    []
    {}
*/
typedef struct Stack {
    char parenthesis;
    struct Stack * next;
} Stack;

Stack* make_stack() {
    Stack * stack;
    stack = xcalloc(1, sizeof(Stack));
    stack->next = NULL;
    return stack;
}

Stack* push(char parenthesis, Stack old_stack) {
    Stack *new_stack = make_stack();
    new_stack->next = &old_stack;
    new_stack->parenthesis = parenthesis;
    return new_stack;
}

bool is_stack_empty(Stack* stack) {
    if(stack->next == NULL && stack->parenthesis == 0) {
        return true;
    }
    return false;
}

void print_fn(Stack* stack) {
    if(stack->next == NULL) {
        return;
    }
    else {
        printf("%c", stack->parenthesis);
        print_fn(stack->next);
    }
}

Stack* pop(Stack* stack) {
    Stack* temp;
    temp = stack;
    stack = stack->next;
    temp->parenthesis = 0;
    free(temp);
}

void print_my_text(String text) {
    //printf("\n");
    for(int index = 0; text[index] != '\0'; index++) {
        printf("%c", text[index]);
    }
    printf("\n");
}

bool is_opposite(char open, char close) {
    if( open == '(' && close == ')' ||
        open == '<' && close == '>' ||
        open == '{' && close == '}' ||
        open == '[' && close == '}') {
        return true;
    }
    return false;

}

Stack* rmv_par(Stack* stack){
    if()
}

bool verify_parentheses(String text) {
    Stack* stack;// = make_stack();
    if(is_opposite('(', ')') {printf("\n\n\nWOW\n\n\n")};
    for(int index = 0; text[index] != '\0'; index++) {
        //stack = push(text[index], *stack);
        //printf("%c", stack->parenthesis);
        //stack = pop(stack);
        if( text[index] == '(' ||
            text[index] == '<' ||
            text[index] == '{' ||
            text[index] == '[' ||
            text[index] == ')' ||
            text[index] == '>' ||
            text[index] == '}' ||
            text[index] == ']')
        {   
            stack = push(text[index], *stack);
            if(stack->next->parenthesis == )
        }
        
        
    
    }   
    
    return false;
}

int main(void) {
    report_memory_leaks(true);
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
    return 0;
}
