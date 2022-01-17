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
    struct Stack *next;
} Stack;

Stack* first = NULL;

void free_stack(Stack* stack) {
    if (stack->next == NULL) {
        first = NULL;
        free(stack);
    }
    else {
        free_stack(stack->next);
        free(stack);
        first = NULL;
    }
    
}

void push(char parentheses) {
    Stack* temp = xcalloc(1, sizeof(Stack));
    temp->parentheses = parentheses;
    temp->next = first;
    first = temp;
}

bool stack_empty() {
    if(first == NULL) {
        return true;
    }
    return false;
}

char pop() {
    if(stack_empty()) {
        return 0;
    }
    Stack* temp;
    temp = first;
    char popped = temp->parentheses;
    first = temp->next;
    free(temp);
    return popped;
}

bool does_it_match() {
    
    if((first->parentheses == ')' &&
        first->next->parentheses == '(') ||
       (first->parentheses == '>' &&
        first->next->parentheses == '<') ||
       (first->parentheses == '}' &&
        first->next->parentheses == '{') ||
       (first->parentheses == ']' &&
        first->next->parentheses == '[')) {
        return true;
    }
    return false;
}

bool verify_parentheses(String text) {
    for(int i = 0; i < s_length(text); i++) {
        if(text[i] == '(' ||
            text[i] == '<' ||
            text[i] == '[' ||
            text[i] == '{' ||
            text[i] == ')' ||
            text[i] == '>' ||
            text[i] == ']' ||
            text[i] == '}') {
                push(text[i]);
                if(first->next != NULL) {
                    if(does_it_match()) { 
                        pop();
                        pop();
                    }
                }
            }
    }
    if(first == NULL) {
        return true;
    }
    free_stack(first);
    return false;
    printf("\n");
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


