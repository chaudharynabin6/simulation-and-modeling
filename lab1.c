#include <stdio.h>
#include <math.h>
int main(){
    int x0,x1,m;
    int  xi,xi_1,xi_2;
    int i;
    
    float random_number[1000];
    printf("Enter x0 x1 and m:");
    scanf("%d %d %d",&x0,&x1,&m);
    xi_2 = x0;
    xi_1 = x1;
    random_number[0] = (float)x0/100;
    random_number[1] = (float)x1/100;
    for(i=2;i<=99;i++){
        xi = (xi_1 + xi_2) % m;
        random_number[i] = xi;
        xi_1 = xi_2;
        xi_2 = xi;
        random_number[i] = random_number[i]/m;
    }

    // for(i=0;i<=99;i++){
    //     // random_number[i] = random_number[i]/m;
    //     // printf("%.2f ",random_number[i]);
    // }
// ----------------------------------------------------------------
    printf("\n \n Testing random numbers generated in step 1\n \n");

    // int v =9;
    // float a = 0.05;
    // float x2_05_9 = 16.9;
    // int class_count[100]; 
    // float num;
    // for(i = 0;i<10;i++){
    //     class_count[i] = 0;
    // }
    
    // for(i = 0; i<100;i++){
    //     num = random_number[i];
    //     if(num<0.1){
    //         class_count[0]++;
    //     }
    //     else if (num<0.2)
    //     {
    //         class_count[1]++;
    //     }
    //     else if (num<0.3)
    //     {
    //         class_count[2]++;
    //     }
    //     else if (num < 0.4)
    //     {
    //         class_count[3]++;
    //     }
    //     else if (num < 0.5)
    //     {
    //         class_count[4]++;
    //     }
    //     else if (num < 0.6)
    //     {
    //         class_count[5]++;
    //     }
    //     else if (num < 0.7)
    //     {
    //         class_count[6]++;
    //     }
    //     else if (num < 0.8)
    //     {
    //         class_count[7]++;
    //     }
    //     else if (num < 0.9)
    //     {
    //         class_count[8]++;
    //     }
    //     else if (num < 1)
    //     {
    //         class_count[9]++;
    //     }
    // }
    //     float sum_chai = 0;
    //     float  oi_ei;
    //     float sum,a1=0,b=0.1;
    //     printf("SN\tclass \t \toi \t oi-ei \t sq(oi - ei)/ei");
    //     for(i = 0; i<10; i++){
            
    //         oi_ei =(float) (class_count[i] - 100/10);
    //         sum = oi_ei*oi_ei/(100/10);
    //         sum_chai = sum_chai + oi_ei*oi_ei/(100/10);
    //         printf("\n%d \t%.1f-%.1f \t %d \t %.0f \t %.2f ",i+1,a1,b,class_count[i],oi_ei,sum);
    //         a1=a1+0.1;b=b+0.1;
    //     }
       
    //     if(sum_chai <= x2_05_9){
    //         printf("\n The random number is distributed uniformly\n");
    //     }
    //     else{
    //         printf("\n The random number generated is not distributed uniformly\n");
    //     }

        int j;
        float temp;
        for(i=0;i<100;i++){
            for(j=i+1;j<100;j++){
               if( random_number[j] <= random_number[i] ){
                   temp = random_number[i];
                   random_number[i] = random_number[j];
                   random_number[j] = temp;
               }
            }
        }
    for (int i = 0; i < 100; i++)
    {
        printf("%.2f\t",random_number[i]);
    }
    
    float d_plus[100];
    float d_minus[100];
    float N = 100;
    for(i = 0; i<100;i++){
        d_plus[i] = i/N - random_number[i];
        d_minus[i] = random_number[i] - (i-1)/N;
    }

    float d_plus_max = d_plus[0];
    float d_minus_max = d_minus[0];
    printf("\n------------d+----------------\n");
    for(i=0;i<100;i++){
         printf("\t %f",d_plus[i]);
        if(d_plus_max<d_plus[i]){
            d_plus_max = d_plus[i];
           
        }

    }
    printf("\n------------ d- -----------------\n");

    for(i=0;i<100;i++){
         printf("\t %f",d_minus[i]);
        if(d_minus_max<d_minus[i]){
            d_minus_max = d_minus[i];

        }
        
    }
    float max;
    if(d_minus_max<d_plus_max){
        max = d_plus_max;
    }
    else{
        max = d_minus_max;
    }

    float d_table = 1.36/pow(N,(1/2));

if(max <= d_table){
    printf("\nUniform\n");
}
else{
    printf("\n Not Uniform \n");
}
    return 0;

}