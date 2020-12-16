#include <stdio.h>
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
    int arr[] = {5, 6, 7, 24, 35, 45, 75, 76, 356, 456, 3576, 45376};
    int found = binSrch(arr, 0, sizeof(arr) / sizeof(int), 7);
    if (found == -1)
        printf("\nnot found\n");
    else
        printf("\nfound at %d\n", found);

    return 0;
}
