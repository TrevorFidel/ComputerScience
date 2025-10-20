#include <stdio.h>
#include <stdlib.h>

int main (){
    int num1;
    int num2;

    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);

    int sum = num1 + num2;
    printf("Sum: %d \n",sum);
    int diff = num1 - num2;
    printf("Difference: %d \n",diff);
    int prod = num1 * num2;
    printf("Product: %d \n",prod);
    float quot = (float)num1 / (float)num2;
    printf("Quotient: %f \n",quot);
    int mod = num1 % num2;
    printf("Remainder: %d \n",mod);

    return 0;
}