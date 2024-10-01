#include <stdio.h>
void sort(int ar[], int n);
int iterative(int ar[], int num, int n);
int recursion(int ar[], int num, int start, int end, int count);

int main()
{
    int n, num, pos;
    int choice;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ar[i]);
    }

    printf("Enter number to be searched: ");
    scanf("%d", &num);

    sort(ar, n);

    printf("After sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");

    printf("Choose search method: 1 for Iterative, 2 for Recursive: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        pos = iterative(ar, num, n);
        break;
    case 2:
        pos = recursion(ar, num, 0, n - 1, 1);
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }
    if (pos == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", pos);
    }

    return 0;
}

void sort(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n -1; j++)
        {
            if (ar[i]> ar[j])
            {
                int temp = ar[j];
                ar[j] = ar[i];
                ar[i] = temp;
            }
        }
    }
}

int iterative(int ar[], int num, int n)
{
    int start = 0, end = n - 1, mid, count = 1;

    while (start <= end)
    {
        count++;
        mid = (start + end) / 2;
        if (num == ar[mid])
        {
            printf("Number of comparisons is %d\n", count);
            return mid;
        }
        else if (num > ar[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int recursion(int ar[], int num, int start, int end, int count)
{
    if (start <= end)
    {
        count++;
        int mid = (start + end) / 2;
        if (num == ar[mid])
        {
            printf("Number of comparisons is %d\n", count);
            return mid;
        }
        else if (num > ar[mid])
        {
            return recursion(ar, num, mid + 1, end, count);
        }
        else
        {
            return recursion(ar, num, start, mid - 1, count);
        }
    }
    return -1;
}