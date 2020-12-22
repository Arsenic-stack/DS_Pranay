#include <stdio.h>
#include <stdlib.h>
int binSrch(int arr[], int l, int r, int val)
{
    if (r >= l)
    {
        int mid = l + (r - 1) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[mid] > val)
            return binSrch(arr, l, mid - 1, val);
        return binSrch(arr, mid + 1, r, val);
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int to_search;
    printf("Enter the element to search : ");
    scanf("%d", &to_search);
    int found = binSrch(arr, 0, n, to_search);
    if (found == -1)
        printf("\nDidn't find %d\n", to_search);
    else
        printf("\nFound %d at %d\n", to_search, found);

    return 0;
}
