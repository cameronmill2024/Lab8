#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int extraMemoryAllocated;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// implements heap sort
// extraMemoryAllocated counts bytes of memory allocated
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    extraMemoryAllocated = 0;

   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        
        swap(&arr[0], &arr[i]);
 
       
        heapify(arr, i, 0);
    }
}


void merge(int pData[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    
    int L[n1], R[n2];
 
  
    for (i = 0; i < n1; i++)
        L[i] = pData[l + i];
    for (j = 0; j < n2; j++)
        R[j] = pData[m + 1 + j];
 
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            pData[k] = L[i];
            i++;
        }
        else {
            pData[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1) {
        pData[k] = L[i];
        i++;
        k++;
    }
 
    
    while (j < n2) {
        pData[k] = R[j];
        j++;
        k++;
    }
}
