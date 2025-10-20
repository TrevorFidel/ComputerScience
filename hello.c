#include <stdio.h>

int main(){
printf("Hello world! \n");
char charactername []= "John";
int characterage = 35;
printf("%s is %d years old \n", charactername, characterage);
int num1 = 5;
printf("num1 is %d \n", num1);
num1 = 10;
printf("num1 is now %d \n", num1);
// so here the variable is changed but now lets now work on constant variables that cant be changed.
const int num2 = 6;
printf("num2 is %d \n", num2);
//num2 = 10; this will give an error because num2 is a constant variable and cant be changed.

//USER INPUT
// first we need to create a variable to store the input byb the user
int age;
printf("Enter your Age: \n");
scanf("%d",&age);
printf("You are %d years old \n", age);

// Working with decimals
double num3 ;
printf("Enter your gpa: ");
scanf("%lf",&num3);
printf("Your gpa is %f \n",num3);

//characters
char grade;
printf("Enter your grade: ");
scanf(" %c",&grade);
printf("Your grade is %c \n",grade);

//strings
char name[20];// we need to define the size of the string
printf("Enter your name: "); 
// when using this when this the moment you space then scanf will not read te other part of the text.hence fgets comes in
fgets(name, 20, stdin); // this will read the whole line including spaces .. 
printf("Your name is %s \n ",name);
return 0;

}