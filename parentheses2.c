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

void stack_print(Stack * stack) {
    if (stack->next == NULL) {
      printcln(stack->content);  
    }
    else {
        printcln(stack->content);
        stack_print(stack->next);
    }
}

int stack_length(Stack * stack) {
    if (stack->next == NULL) {
        return 0;
    }
    else {
        return 1 + stack_length(stack->next);
    }
}

void stack_push(Stack * stack, char parentheses) {
    Stack * old_stack = stack_new();
    old_stack->content = stack->content;
    old_stack->next = stack->next;
    stack->content = parentheses;
    stack->next = old_stack;
}

Stack* stack_pop(Stack * stack) {
    Stack * temp = stack_new();

    temp->content = stack->next->content;
    temp->next = stack->next->next;
    return temp;

}


Stack* call_switch(Stack * stack) {
    if (stack->content == ')' && stack->next->content == '(') {    
        printsln("pop '( und )'"); 
        stack = stack_pop(stack);
        stack = stack_pop(stack);
        return stack;
    }
   
    if (stack->content == '}' && stack->next->content == '{') {
        printsln("pop '{ und }'"); 
        stack = stack_pop(stack);
        stack = stack_pop(stack); 
        return stack;
   
    }
    
    if (stack->content == '>' && stack->next->content == '<') {
        printsln("pop '< und >'"); 
        stack = stack_pop(stack);
        stack = stack_pop(stack);
        return stack;

    }
    
    if (stack->content == ']' && stack->next->content == '[') {
        printsln("pop '[ und ]'"); 
        stack = stack_pop(stack);
        stack = stack_pop(stack);
        return stack;
    }
    else {
        return stack;
    }
}

Stack add_to_stack(String text) {
    Stack * stack = stack_new();

    for(int index = 0; text[index] != '\0'; index++) {
        if (text[index] == '(' || text[index] == ')') {
            stack_push(stack, text[index]);
        }        
     
        if (text[index] == '<' || text[index] == '>') {
            stack_push(stack, text[index]);
        }        
   
        if (text[index] == '['|| text[index] == ']') {
            stack_push(stack, text[index]);
        }        
    
        if (text[index] == '{'|| text[index] == '}') {
            stack_push(stack, text[index]);
        }        

        stack = call_switch(stack);
    }
    stack_print(stack);
    printiln(stack_length(stack));
    return *stack;
}




bool verify_parentheses(String text) {
    Stack stack = add_to_stack(text);
    
    if (stack_length(&stack) % 2 == 0) {
        return true;
    }
    else {
        if(stack.next == NULL) { //if stack is empty ?!
            return true;
        }
        else {
            return false;
        }
    }
}

int main(void) {
    //report_memory_leaks(true);

    test_equal_i(verify_parentheses("hello"), true);
    test_equal_i(verify_parentheses("Hello World"), true);
    test_equal_i(verify_parentheses("()"), true);

    test_equal_i(verify_parentheses("<{[()]}>"), true);
    /*
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
