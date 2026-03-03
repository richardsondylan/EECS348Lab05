#include <stdio.h>



void generate_sales_reports(float *arr, int size){

    const char* months[] = {
        "January", "Februrary", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December" 
    };

    if(size != 12){
        printf("Error: Passed array of size not equal to 12. Not full annual report.\n");
    }
    else {
        printf("Monthly Sales Report for 2024\n\n");
        printf("%-10s Sales\n", "Month");
        for(int i = 0; i < size; ++i){
            printf("%-10s %f\n", months[i], arr[i]);
        }
        printf("\n");
    }
}

void compute_sales_report_stats(float *arr, int size){

    if(size != 12){
        printf("Error: Passed array of size not equal to 12. Not full annual report.\n");
    } 
    else {
        float min, max, average;
        min = max = arr[0];
        for(int i = 0; i < size; ++i){
            if(arr[i] < min){
                min = arr[i];
            } else if(arr[i] > max){
                max = arr[i];
            }
            average += arr[i];
        }
        average /= 12;

        printf("Sales summary report:\n");
        printf("Minimum of sales: %f\n", min);
        printf("Maximum of sales: %f\n", max);
        printf("Average of sales: %f\n", average);
    }
}



int main(){

    float arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    generate_sales_reports(arr, 12);
    compute_sales_report_stats(arr, 12);

    return 0;
}