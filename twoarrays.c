#include <stdio.h>

 
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

  
    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];


    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
 
    for(int i = 0; i < n / 2; i++) {
        int temp = b[i];
        b[i] = b[n - i - 1];
        b[n - i - 1] = temp;
    }
 
    int merged[2 * n];
    for(int i = 0; i < n; i++) {
        merged[i] = a[i];
        merged[i + n] = b[i];
    }
 
    mergeSort(merged, 0, 2 * n - 1);

     
    for(int i = 0; i < 2 * n; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}