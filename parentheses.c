#include "base.h"
/*
These are the kinds of partenthesis this program will look for.
    ()
    <>
    []
    {}
*/

bool verify_parentheses(String text) {
    int index = 0;

    printf("\n");
    for(index; text[index]!= '\n'; index++) {
        printf("%c", text[index]);
    }
    printf("\n");
    
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

    return 0;
}
