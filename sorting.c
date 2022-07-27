#include<stdio.h>
// Function to print an array
void DisplayArray(int array[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
//function to swap
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
//insertion sort
void insertionSort(int array[], int length) {
  for (int step = 1; step < length; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
//selection sort
void selectionSort(int array[], int length) {
  for (int step = 0; step < length - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < length; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

int main() {
  
  int n;
  printf("choose length of array:\n");
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++){
    printf("enter the %dth element of arr:\n", i);
    scanf("%d", &arr[i]);
  }
  
  int length = sizeof(arr) / sizeof(arr[0]);
  
  int choice;
  printf("Sorting Menu:\n");
  printf("1. insertion sort\n");
  printf("2. Selection sort\n");
  printf("3. Bubble sort\n");
  printf("4. Merge sort\n");
  printf("5. Quick sort\n");
  printf("Choose the type of sort\n");
  scanf("%d", &choice);
  printf("Unsorted Array\n");
  DisplayArray(arr, length);
  //calling insertion sort function
  if(choice==1){
    insertionSort(arr, length);
    printf("Sorted array in ascending order:\n");
    DisplayArray(arr, length);
  }
  //calling selection sort function
  else if (choice==2)
  {
    selectionSort(arr, length);
    printf("Sorted array in Acsending Order:\n");
    DisplayArray(arr, length);
  }
  //calling Bubble sort function
  else if (choice==3)
  {
    bubbleSort(arr, length);
    printf("Sorted Array in Ascending Order:\n");
    DisplayArray(arr, length);
  }
  //calling Merge sort function
  else if (choice==4)
  {
    mergeSort(arr, 0, length - 1);
    printf("Sorted arrayin Ascending order: \n");
    DisplayArray(arr, length);
  }
  //calling quick sort function
  else if(choice==5){
    quickSort(arr, 0, length - 1);
    printf("Sorted array in ascending order: \n");
    DisplayArray(arr, length);
  }
  else{
    printf("Invalid input, try again.\n");
  }
  return 0;
  
  

}
