#include <stdio.h>
#include <math.h>

#define N 100

int main(){
// number of repetion  * number_random_number * cordinate
// [
//     [[],[]]
//     [[],[]]
//     []
//     []
//     []

// ]
int generated_random_number[N][N][2];

float point_inside_circle[N][N][2];

int number_of_replication;
// number of repetition
printf("Enter number of replication  :");
scanf("%d",&number_of_replication);

// number of random nuber to generate
int number_of_random_number;
printf("Enter the total random number to generated : ");
scanf("%d",&number_of_random_number);

int i,j,k;

// taking the seed input for each repition
for(i=0;i<number_of_replication;i++){
    
    printf("Repetition %d \n",i+1);
    
    printf("Seed value x0 and x1 : ");
    

    scanf("%d %d",&generated_random_number[i][0][0],&generated_random_number[i][0][1]);
    scanf("%d %d",&generated_random_number[i][1][0],&generated_random_number[i][1][1]);
}

// generating random number for each repetition
for(i=0;i<number_of_replication;i++){

    for(j=2;j<number_of_random_number;j++){
        for(k = 0;k<2; k++){

        generated_random_number[i][j][k] = (generated_random_number[i][j-2][k] + generated_random_number[i][j-1][k]) % 101;
        

        // printf("%d ",generated_random_number[i][j][k]);
        // point_inside_circle[i][j][k] = generated_random_number[i][j][k] / 101.0;
           
     }
    }
}

// // calculating points 
for(i=0;i<number_of_replication;i++){

    for(j=0;j<number_of_random_number;j++){
        for(k = 0;k<2; k++){

        point_inside_circle[i][j][k] = (float)generated_random_number[i][j][k] / 101;
        }
    }
}

// // counting whether the point inside the circle or not
// // couter holds small n value
int couter[N] = {0}; 
float radius;
for(i=0;i<number_of_replication;i++){

    for(j=0;j<number_of_random_number;j++){
       
    //    calucuating the radius of circle
    radius = point_inside_circle[i][j][0]*point_inside_circle[i][j][0] + point_inside_circle[i][j][1]*point_inside_circle[i][j][1];
    
    //  increasing counter for each replication only 
    if(radius<=1){
        // the point is inside the circle
        couter[i] = couter[i] + 1;
    }
    }
  
}


// // calculating the pi value
float error[N];
float pi[N];
float actualPi = 3.1415;
float sum_error =0;
float sum_pi = 0;
printf(" pi acutal \t pi calucated \t error\n");
for(i=0;i<number_of_replication;i++){

   
    
        // calculating value of p[i] and error
        pi[i] = 4.0*couter[i] / number_of_random_number ;
        error[i] = fabs(pi[i]-actualPi) / actualPi;

        printf("%.3f \t %.3f \t %.3f \n",actualPi , pi[i] ,error[i]);
    
        sum_pi += pi[i];
        sum_error += error[i];
}

float calculated_pi = sum_pi / number_of_replication;
float calculated_error = sum_error * 100 / number_of_replication;
printf("Average pi : %.4f \n",calculated_pi);
printf("percentage error : %.4f \n",calculated_error);

return 0;

}