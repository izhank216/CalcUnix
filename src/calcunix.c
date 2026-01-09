#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Calculate.h"

int main() {

    printf("Welcome to CalcUnix!\n\n");
    printf(" ____  ____  _     ____ _     _      _ ___  _\n");
    printf("/   _\\/  _ \\/ \\   /   _Y \\ /\\/ \\  /|/ \\\\  \\//\n");
    printf("|  /  | / \\|| |   |  / | | ||| |\\ ||| | \\  / \n");
    printf("|  \\__| |-||| |_ /\\|  \\_| \\_/|| | \\||| | /  \\ \n");
    printf("\\____/\\_/ \\|\\____/\\____|____/\\_/  \\|\\_//__/\\\\\n");
    printf("                                              \n\n");

    double a, b, result;
    char op[2];
    char input1[256], input2[256];

    while (1) {
        printf("Enter calculation (e.g., 5 + 3 or text & text): ");

        if (scanf("%s", input1) != 1) {
            printf("Invalid input.\n");
            continue;
        }

        if (scanf("%1s %s", op, input2) != 2) {
            printf("Invalid input.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/' || op[0] == '%') {
            a = atof(input1);
            b = atof(input2);
            if (op[0] == '+') result = add(a,b);
            else if (op[0] == '-') result = subtract(a,b);
            else if (op[0] == '*') result = multiply(a,b);
            else if (op[0] == '/') result = divide(a,b);
            else if (op[0] == '%') result = modulo(a,b);
            printf("Result: %.2lf\n\n", result);
        }
        else if (op[0] == '=' || op[0] == '<' || op[0] == '>') {
            a = atof(input1);
            b = atof(input2);
            int cmp = compare(a,b);
            if (op[0] == '=') printf("Result: %s\n\n", (cmp==0)?"true":"false");
            else if (op[0] == '<') printf("Result: %s\n\n", (cmp==-1)?"true":"false");
            else if (op[0] == '>') printf("Result: %s\n\n", (cmp==1)?"true":"false");
        }
        else if (op[0] == '&') {
            char *res = concat(input1, input2);
            printf("Result: %s\n\n", res);
            free(res);
        }
        else if (op[0]==':' || op[0]=='!' || op[0]==';') {
            reference_op(op);
        }
        else {
            printf("Unknown operator '%s'\n\n", op);
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}
