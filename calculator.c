#include <stdio.h>

int main()
{
    double num1, num2, result;
    char op;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Perform calculation based on the operator
    switch (op)
    {
    case '+':
        result = num1 + num2;
        printf("Result: %lf\n", result);
        break;
    case '-':
        result = num1 - num2;
        printf("Result: %lf\n", result);
        break;
    case '*':
        result = num1 * num2;
        printf("Result: %lf\n", result);
        break;
    case '/':
        if (num2 != 0)
            printf("Result: %lf\n", num1 / num2);
        else
            printf("Error! Division by zero is not allowed.\n");
        break;
    default:
        printf("Invalid operator!\n");
    }

    return 0;
}
