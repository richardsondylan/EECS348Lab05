#include <stdio.h>
#include <stdlib.h>


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

struct month_sale_pair{
    char *month;
    float sales;
} typedef month_sale_pair;


int compare(const void *month_sale_pair1, const void *month_sale_pair2){
    return ((month_sale_pair*)month_sale_pair2)->sales - ((month_sale_pair*)(month_sale_pair1))->sales;
}


void sort_sales_report(float *arr, int size){

    const char* months[] = {
        "January", "Februrary", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December" 
    };

    if(size != 12){
        printf("Error: Passed array of size not equal to 12. Not full annual report.\n");
    }
    else {
        printf("Sales report (highest to lowest)\n");
        printf("%-10s Sales\n", "Month");
        month_sale_pair new_arr[size];
        for(int i = 0; i < size; ++i){
            month_sale_pair pair = {months[i], arr[i]};
            new_arr[i] = pair;
        }
        qsort(new_arr, 12, sizeof(month_sale_pair), compare);
        
        for(int i = 0; i < size; ++i){
            printf("%-10s %f\n", new_arr[i].month, new_arr[i].sales);
        }

        printf("\n");
    }

}

void read_input_file(char *file_name, float *arr, int size){
    FILE *file;
    file = fopen(file_name, "r");
    if(file == NULL){
        printf("Could not open file.\n");
    }
    else {
        fread(arr, sizeof(float), 12, file);
        for(int i = 0; i < size; ++i){
            printf("%f\n", arr[i]);
        }
    }


}



int main(){

    float arr[] = {23458.01,40122,56011.85,37820,37904,60200,72400,56210,67230,68233,80950,95225};
    float arr1[12];
    read_input_file("test.txt", arr1, 12);

    return 0;
}