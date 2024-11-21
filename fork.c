#include<stdio.h>
#include<stdbool.h>
#include<unistd.h>
#include<stdlib.h>



void bubbleSortAscending(int arr[],int n){
  bool swapped;
  for(int i=0;i<n-1;i++){
    swapped = false;
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        swapped = true;
      }
    }
    if(swapped == false) break;
  }
}


void bubbleSortDescending(int arr[],int n){
  bool swapped;
  for(int i=0;i<n-1;i++){
    swapped = false;
    for(int j=0;j<n-i-1;j++){
      if(arr[j]<arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        swapped = true;
      }
    }
    if(swapped == false) break;
  }
}


int main(){
  int p;
  int n;
  printf("Enter size of Array: ");
  scanf("%d",&n);
  
  int arr[n];
  printf("Enter Array elements: ");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  
  printf("Hello My PID %d Parent pid is :%d, \n",getpid(),getppid());
  
  sleep(2);
  
  p = fork();
  
  if(p<0){
    printf("\nError");
    exit(1);
  }else if(p==0){
    bubbleSortAscending(arr, n);
    for(int i=0;i<n;i++){
      printf("i = %d arr[i] = %d pid = %d ppid = %d\n",i,arr[i],getpid(),getppid());
      
    }
    printf("\n");
        printf("Child procees terminates\n");
  }else{
    bubbleSortDescending(arr, n);
    for(int i=0;i<n;i++){
      printf("i = %d arr[i] = %d pid = %d ppid = %d \n",i,arr[i],getpid(),getppid());
      
    }
    printf("\n");
        printf("Parent procees terminates\n");
  }
  
  printf("Hello My PID %d Parent pid is :%d, \n",getpid(),getppid());
  
  return 0;
}
