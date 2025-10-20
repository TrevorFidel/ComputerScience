
#include <stdio.h>

int main(){
    int first = 0;
    int second = 1;
    int ans = first + second;
    printf("Answer: %d, \n",first,second);
    int sum = first+ second;
    
    for(int first = 0;first < 40;first+1 ){
        
        sum = first + second;
        first = second;
        second = sum;
        printf("Answers: %d \n",sum);
    }
    
    
}

