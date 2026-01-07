#include "Calculate.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

double modulo(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Error: Modulo by zero!\n");
        return 0;
    }
    return (int)a % (int)b;
}

int compare(double a, double b) {
    if (a == b) return 0;
    else if (a < b) return -1;
    else return 1;
}

char *concat(const char *a, const char *b) {
    char *result = malloc(strlen(a) + strlen(b) + 1);
    strcpy(result, a);
    strcat(result, b);
    return result;
}

void reference_op(const char *op) {
    printf("Reference operator '%s' invoked\n", op);
}
