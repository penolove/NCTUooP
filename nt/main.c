#include <stdio.h>
#include "math.h"

int main(void) {
    int num = 0;
    int power = 0; 

    printf("輸入數值："); 
    scanf("%d", &num); 

    printf("輸入平方："); 
    scanf("%d", &power); 

    printf("%d 平方：%d\n", num, myPow2(num));
    printf("%d 的 %d 次方 %d\n", num, power, myPow(num, power));
        
    return 0;
}
