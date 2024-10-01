    #include <stdio.h>

    //bubble sort code
    void bubble_sort(int arr[], int n) {
      int i, j;
      for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
          }
        }
      }
    }

    int main() {
      //for accepting array elements
        int k;
      printf("enter the limit of array");
      scanf("%d",&k);
        int arr[k];
        printf("enter the elements");
        for (int i=0;i<k; i++) {
            scanf("%d",&arr[i]);
       }


      int n = sizeof(arr) / sizeof(arr[0]);
      printf("Sorted array: ");
      bubble_sort(arr, n);
      for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
      }
      return 0;
    }
    