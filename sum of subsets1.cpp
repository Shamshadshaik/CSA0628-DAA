#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool solution[MAX_SIZE]; 


void printSubset(int arr[], int size) {
    printf("Subset with sum:\n");
    for (int i = 0; i < size; i++) {
        if (solution[i])
            printf("%d ", arr[i]);
    }
    printf("\n");
}
bool subsetSum(int arr[], int n, int sum, int target, int index) {
    if (sum == target) {
        printSubset(arr, index);
        return true;
    }

    if (index == n || sum > target)
        return false;

    
    solution[index] = true;
    if (subsetSum(arr, n, sum + arr[index], target, index + 1))
        return true;

    
    solution[index] = false;
    return subsetSum(arr, n, sum, target, index + 1);
}

int main() {
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the target sum: ");
    scanf("%d", &target);

    if (!subsetSum(arr, n, 0, target, 0))
        printf("No subset with the given sum exists.\n");

    return 0;
}

