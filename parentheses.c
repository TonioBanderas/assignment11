#include "base.h"
/*
These are the kinds of partenthesis this program will look for.
    ()
    <>
    []
    {}
*/
typedef struct Stack {
    char opening_par;
    char* content;
    struct Stack * next;
} Stack;


void print_my_text(String text) {
    //printf("\n");
    for(int index = 0; text[index] != '\0'; index++) {
        printf("%c", text[index]);
    }
    printf("\n");
}



bool verify_parentheses(String text) {
    for(int index = 0; text[index] != '\0'; index++) {
        
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
