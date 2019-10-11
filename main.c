#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Qsort(int** arr, int a_begin, int a_end);

int main()
{
    int arr_size = 0;
    scanf("%d", &arr_size);

    int* arr = (int*) calloc (arr_size, sizeof(int));
    assert(arr != NULL);

    for(int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);

    //printf("before qsort\n");
    Qsort(&arr, 0, arr_size - 1);
    //printf("after qsort\n");

    for(int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}

void Qsort(int** arr, int a_begin, int a_end){
    int arr_size = a_end - a_begin + 1;
    //printf("I came to qsort arr[arr_size - 1] = %d\t leftboarder = %d\n", (*arr)[arr_size - 1], a_begin);

    int left = a_begin;
    int right = a_end;

    //printf("arr[left] = %d\t arr[right] = %d\n", (*arr)[left], (*arr)[right]);

    if(arr_size == 1) return;

    if (arr_size == 2){
        if ((*arr)[left] > (*arr)[right]){
            int t = (*arr)[right];
            (*arr)[right] = (*arr)[left];
            (*arr)[left] = t;
        }

        return;
    }

    if (arr_size == 3){

        if ((*arr)[left] > (*arr)[left + 1]){
            int t = (*arr)[left + 1];
            (*arr)[left + 1] = (*arr)[left];
            (*arr)[left] = t;
        }

        if ((*arr)[left + 1] > (*arr)[left + 2]){
            int t = (*arr)[left + 2];
            (*arr)[left + 2] = (*arr)[left + 1];
            (*arr)[left + 1] = t;
        }

        if ((*arr)[left] > (*arr)[left + 1]){
            int t = (*arr)[left + 1];
            (*arr)[left + 1] = (*arr)[left];
            (*arr)[left] = t;
        }

        return;
    }

    int middle = (*arr)[a_begin + arr_size / 2];
    //printf("middle = %d\n", middle);

    while (right > left) {
        //printf("In high while\n");

        if ((*arr)[left] < middle){
            while ((*arr)[left] < middle){
                //printf("In low while for left\t arr[left] = %d\n", (*arr)[left]);
                left++;
            }
        }

        if ((*arr)[right] > middle){
            while ((*arr)[right] > middle){
                //printf("In low while for right\t arr[right] = %d\n", (*arr)[right]);
                right--;
            }
        }

        int t = (*arr)[right];
        (*arr)[right] = (*arr)[left];
        (*arr)[left] = t;
        //printf("after swap: arr[%d] = %d arr[%d] = %d\n", left, (*arr)[left], right, (*arr)[right]);
        left++;
        right--;
    }

    //printf("before the recursion\n");
    Qsort (arr, a_begin, right);
    Qsort (arr, left, a_end);

    return;
}
















