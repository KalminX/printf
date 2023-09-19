#include <stdio.h>
#include "main.h"


int main() {
    int num1 = 42;
    int num2 = -1234;

    _printf("Number 1: %d\n", num1);
    _printf("Number 2: %d\n", num2);

    _printf("Number 1 (as %i): %i\n", num1, num1);
    _printf("Number 2 (as %i): %i\n", num2, num2);

    return 0;
}
