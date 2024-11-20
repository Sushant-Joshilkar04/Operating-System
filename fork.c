#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<stdlib.h>

void display(int arr[],int n){
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSortAscending(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void bubbleSortDescending(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        
        if (swapped == false)
            break;
    }
}

int main()
{
    int p,i=0;
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
     scanf("%d",&arr[i]);
    
    printf("Hello My PID %d Parent pid is :%d, \n",getpid(),getppid());
    sleep(2);
    p=fork(); 
    if(p<0){
      printf("\n Error ");
      exit(1);
    }else if(p==0){
        bubbleSortDescending(arr,n);
        for(int i=0;i<n;i++){
            printf("i= %d  arr[i]= %d p = %d ppid = %d \n",i,arr[i],getpid(),getppid());
            sleep(1); // Zombie
            // sleep(10);  // orphan
        }
        printf("\n");
        printf("Child procees terminates\n");
    }else{
        bubbleSortAscending(arr, n);
        for(int i=0;i<n;i++){
            printf("i= %d  arr[i]= %d p = %d ppid = %d \n",i,arr[i],getpid(),getppid());
            sleep(10); // Zombie
          // sleep(1); // orphan
        }
       // wait();
        printf("\n");
        printf("Parent procees terminates\n");

    }
  printf("PID %d Parent pid is :%d, \n",getpid(),getppid());
return 0;    
}
