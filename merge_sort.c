#include <stdio.h>

void printArray(int arr[], int size);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
int getValidInput();

int step_by_step = 0;

int main() {
    int n, choice;
    

    
    printf("Enter the number of elements you want to sort: ");
    n = getValidInput();
    
    if (n <= 0) {
        printf("Error: Number of elements must be positive!\n");
        return 1;
    }
    
    int arr[n];
    
    printf("\nEnter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        arr[i] = getValidInput();
    }
    
    printf("\nOriginal Array:\n");
    printArray(arr, n);
    
    printf("\nDo you want to see step-by-step sorting process? (1 for Yes, 0 for No): ");
    choice = getValidInput();
    if (choice == 1) {
        step_by_step = 1;
    }
    
    printf("\n=== Starting Merge Sort ===\n\n");
    
    mergeSort(arr, 0, n - 1);
    
    printf("=== Sorting Complete! ===\n\n");
    printf("Sorted Array:\n");
    printArray(arr, n);
    
    printf("\nThank you for using Merge Sort Program!\n");
    
    return 0;
}

int getValidInput() {
    int value;
    char ch;
    
    while (1) {
        if (scanf("%d", &value) == 1) {
            while ((ch = getchar()) != '\n' && ch != EOF);
            return value;
        } else {
            printf("Invalid input! Please enter a valid integer: ");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    if (step_by_step) {
        printf("Merging: ");
        printf("[");
        for (i = left; i <= right; i++) {
            printf("%d", arr[i]);
            if (i < right) printf(", ");
        }
        printf("] -> ");
        printf("Left: [");
        for (i = 0; i < n1; i++) {
            printf("%d", L[i]);
            if (i < n1-1) printf(", ");
        }
        printf("], Right: [");
        for (j = 0; j < n2; j++) {
            printf("%d", R[j]);
            if (j < n2-1) printf(", ");
        }
        printf("]\n");
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    if (step_by_step) {
        printf("After merge: ");
        printArray(arr + left, n1 + n2);
        printf("\n");
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        if (step_by_step) {
            printf("Splitting: [");
            for (int i = left; i <= right; i++) {
                printf("%d", arr[i]);
                if (i < right) printf(", ");
            }
            printf("] into left [");
            for (int i = left; i <= mid; i++) {
                printf("%d", arr[i]);
                if (i < mid) printf(", ");
            }
            printf("] and right [");
            for (int i = mid + 1; i <= right; i++) {
                printf("%d", arr[i]);
                if (i < right) printf(", ");
            }
            printf("]\n");
        }
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

