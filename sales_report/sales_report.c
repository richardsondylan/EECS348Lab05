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
        int minMonthIndex, maxMonthIndex;

        const char* months[] = {
            "January", "Februrary", "March", "April", "May", "June", "July",
            "August", "September", "October", "November", "December" 
        };

        for(int i = 0; i < size; ++i){
            if(arr[i] < min){
                min = arr[i];
                minMonthIndex = i;
            } else if(arr[i] > max){
                max = arr[i];
                maxMonthIndex = i;
            }
            average += arr[i];
        }
        average /= 12;
        printf("Sales summary report:\n");
        printf("Minimum of sales: %f (%s)\n", min, months[minMonthIndex]);
        printf("Maximum of sales: %f (%s)\n", max, months[maxMonthIndex]);
        printf("Average of sales: %f\n\n", average);
    }
}

void compute_six_month_moving_average(float *arr, int size){


    const char* months[] = {
        "January", "Februrary", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December" 
    };


    if(size != 12){
        printf("Error: Passed array of size not equal to 12. Not full annual report.\n");
    }
    else {
        printf("Six-month moving average report:\n");
        for(int i = 0; i < 7; ++i){
            float average = 0.;
            for(int x = 0; x < 6; ++x){
                average += arr[i + x];
            }
            average /= 6;
            printf("%s-%s %20f\n", months[i], months[i+5], average);
        }
    } 
}



int main(){

    float arr[] = {23458.01,40122,56011.85,37820,37904,60200,72400,56210,67230,68233,80950,95225};
    generate_sales_reports(arr, 12);
    compute_sales_report_stats(arr, 12);
    compute_six_month_moving_average(arr, 12);
    return 0;
}