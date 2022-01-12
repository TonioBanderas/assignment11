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
/*
void print_my_text(String text) {
    printf("'");
    for(int index = 0; text[index] != '\0'; index++) {
        printf("%c", text[index]);
    }
    printf("'");
    printf("\n");
}
*/

void add_to_stack(String text) {
    //nur Klammern in den Stack laden, den Rest "wegfallen" lassen.
    Stack * stack = stack_new;
    
    for(int index = 0; text[index] != '\0'; index++) {

        if (text[index] == '(' || text[index] == ')') {
        stack->content = text[index];
        stack->next->content = x;
        }

    }
}


bool verify_parentheses(String text) {
    add_to_stack(text);
    //stack bearbeiten 
    return true;
}

int main(void) {
    //report_memory_leaks(true);

    test_equal_i(verify_parentheses(""), true);
    //test_equal_i(verify_parentheses("Hello World"), true);
    //test_equal_i(verify_parentheses("()"), true);
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
