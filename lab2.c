#include <stdio.h>
#include <math.h>
int main(){

    int x0,x1,m = 10000;
    int  xi,xi_1,xi_2;
    int i;
    
    int random_number[10000];
    // printf("Enter x0 x1:");
    // scanf("%d %d",&x0,&x1);

    int total_random_number = 1000;
    int x;
    // loop of x is to find the total random number must be supplied to support independence
    for(x =1;x<total_random_number;x++){
    
    x0 = 1254;
    x1 = 9735;
    xi_1 = x1;
    xi_2 = x0;
    random_number[0] = x0;
    random_number[1] = x1;
    xi_2 = x0;
    xi_1 = x1;
    random_number[0] = x0;
    random_number[1] = x1;
    for(i=2; i<=x; i++){
        xi_2 = random_number[i-2];
        xi_1 = random_number[i-1];
        do{
        xi = (xi_1 + xi_2) % m;
        xi_1 = xi_2;
        xi_2 = xi;
        }while(0);
        random_number[i] = xi;
    }
// printf("\n --------------random number generarted ----------------\n");
    for(i = 0;i<x;i++){

        // printf("%d  \t",random_number[i]);
    }

// printf("\n----------------------random number generated ------------------\n");

// extracting digit and checking all and counting as well
int num;
int digits[5] = {0};
int observed[10] = {0,0,0,0,0,0,0};
/*
0 -> all same
1 -> all different
2 -> three of kind
3 -> two pair
4 -> one pair
*/
int j,k;
int temp;
for(i = 0;i<x;i++){
    // extracting digit
    num = random_number[i];

    for(j=0;j<4;j++){
        digits[j] = 0;
    }
    j = 0;
    while(num){
        digits[j] = num % 10;
        j++;
        num  = num / 10;
    }

    for(j=0;j<3;j++){
        for(k=j+1;k<3;k++){
            if(digits[j]<digits[k]){

            temp = digits[j];
            digits[j] = digits[k];
            digits[k] = temp;
            }
        }
    }
    // observed[0] for same digit
    if((digits[0] == digits[1]) && (digits[1] == digits[2]) && (digits[2] == digits[3]) && (digits[3] == digits[1])){

        observed[0]++;
    }
    // for all different
    else if((digits[0] != digits[1]) && (digits[0] != digits[2]) && (digits[0] != digits[3])&&(digits[1] != digits[2]) && (digits[1] != digits[3])&& (digits[2] != digits[3])){
        observed[1]++;
    }
    // for three of kind
    else if(((digits[0] == digits[1])&& (digits[1] == digits[2]) && (digits[2] != digits[3]) ) || (  (digits[0] != digits[1]) && digits[1] == digits[2] && digits[2] == digits[3])){
        observed[2]++;
    }
    // for two pair
    else if((digits[0] == digits[1]) && (digits[2] == digits[3])){
        observed[3]++;
    }
    // for one pair
    else{
        observed[4]++;
    }


   










}
float test_statistics;
float sum = 0;
float expected[5] = {0.001,0.504,0.036,0.027,0.432};
    // printf("\n s.n observed\t expected \t test statistics");
    for(i=0;i<5;i++){
        expected[i] = expected[i] * x;
        test_statistics = observed[i] - expected[i];
        test_statistics = test_statistics*test_statistics / expected[i];
        sum = sum + test_statistics;



        // printf("\n %d \t %d \t %.2f \t %.2f",i+1,observed[i],expected[i],test_statistics);
    }

// printf("\n");
float xai = 9.49;

// printf("sum = %f",sum);
if(sum <= xai){
    printf("\ntotal random_number: %d\n",x);
    // printf("\nindependence\n");
    // break;
}
else{
    // printf("\n dependent \n");
    // printf("\n");
    // printf("%d \t",x);
}

    }
}
