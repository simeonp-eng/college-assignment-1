 #include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printf("After partitioning with pivot %d: ", pivot);
    printArray(arr, n);

    return i + 1;
}

void quicksort(int arr[], int low, int high, int n) {
    if(low < high) {
        int pi = partition(arr, low, high, n);

        quicksort(arr, low, pi - 1, n);
        quicksort(arr, pi + 1, high, n);
    }
}

int main() {
    int n;

    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1, n);

    return 0;
}

