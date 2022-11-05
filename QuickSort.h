//
// Created by Usuario on 02/11/2022.
//

#ifndef PARCIAL2_SIMESVARTANIAN_QUICKSORT_H
#define PARCIAL2_SIMESVARTANIAN_QUICKSORT_H
#include <iostream>
void swap(int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
void swap2(std::string arr[] , int pos1, int pos2){
    std::string temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], std::string arrc[],  int low, int high, int pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(arr[i] > pivot){
            i++;
        }
        else{
            swap(arr,i,j);
            swap2(arrc, i, j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort(int arr[], std::string arrc[],  int low, int high){
    if(low < high){
        int pivot = arr[high];
        int pos = partition(arr, arrc,  low, high, pivot);

        quickSort(arr, arrc, low, pos-1);
        quickSort(arr,arrc,  pos+1, high);
    }
}
void shellsort(int arrn[], std::string arrc[], int cantp)
{
    int i = 0, j = 0, k = 0, mid = 0;
    std::string midn;
    for (k = cantp / 2;k > 0;k /= 2)
    {
        for (j = k;j < cantp;j++)
        {
            for (i = j - k;i >= 0;i -= k)
            {
                if (arrn[i + k] >= arrn[i])
                {
                    break;
                }
                else
                {
                    mid = arrn[i];
                    midn=arrc[i];
                    arrn[i] = arrn[i + k];
                    arrc[i]=arrc[i+k];
                    arrn[i + k] = mid;
                    arrc[i+k]=midn;

                }
            }
        }
    }
    return;
}

#endif //PARCIAL2_SIMESVARTANIAN_QUICKSORT_H
