 #include <stdio.h>

int main()
{
    int n, i, x;

    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    int low = 0, high = n - 1, mid;
    int found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == x)
        {
            printf("The target value %d is present at index %d", x, mid);
            found = 1;
            break;
        }
        else if(arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found == 0)
    {
        printf("The target value %d is not present in the array", x);
    }

    return 0;
}