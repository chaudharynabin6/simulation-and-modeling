#include <stdio.h>
#include <math.h>
int main(){

    int x0,x1,m = 10000;
    int  xi,xi_1,xi_2;
    int i;
    
    int random_number[1000];
    printf("Enter x0 x1:");
    scanf("%d %d",&x0,&x1);
    xi_2 = x0;
    xi_1 = x1;
    random_number[0] = x0;
    random_number[1] = x1;
    int total_random_number = 1000;
    for(i=2;i<=total_random_number;i++){
        random_number[i] = (random_number[i-2] + random_number[i-1]) % m;

        x1 = random_number[i];
        x0 = random_number[i-1];
       while(random_number[i] <= 999){
           random_number[i] = (x0 + x1) % m;
           x1 = random_number[i];
           x0 = x1;
       }

        
        
    }
printf("\n --------------random number generarted ----------------\n");
    for(i = 0;i<total_random_number;i++){

        printf("%d  \t",random_number[i]);
    }

printf("\n----------------------random number generated ------------------\n");

// extracting digit and checking all and counting as well
int num;
int digits[5];
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
for(i = 0;i<total_random_number;i++){
    // extracting digit
    num = random_number[i];

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
    if((digits[0] == digits[1]) && (digits[1] == digits[2]) && (digits[2] == digits[3])){

        observed[0]++;
    }
    // for all different
    else if((digits[0] != digits[1]) && (digits[1] != digits[2]) && (digits[2] != digits[3])){
        observed[1]++;
    }
    // for three of kind
    else if(((digits[0] == digits[1])&& (digits[1] == digits[2])) || (digits[1] == digits[2] && digits[2] == digits[3])){
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
    printf("\n s.n observed\t expected \t test statistics");
    for(i=0;i<5;i++){
        expected[i] = expected[i] * 1000;
        test_statistics = observed[i] - expected[i];
        test_statistics = test_statistics*test_statistics / expected[i];
        sum = sum + test_statistics;



        printf("\n %d \t %d \t %.0f \t %.0f",i+1,observed[i],expected[i],test_statistics);
    }

printf("\n");
float xai = 9.49;

printf("sum = %f",sum);
if(sum <= xai){
    printf("\nindependence\n");
}
else{
    printf("\n dependent \n");
}
}
