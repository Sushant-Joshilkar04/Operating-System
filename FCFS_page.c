
#include <stdio.h>

void display(int size,int frame[]){
    for(int i=0;i<size;i++)
       printf("%d ",frame[i]); 
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter pages: ");
    for(int i=0;i<n;i++) 
    scanf("%d",&arr[i]);
    int size = 0;
    printf("Enter page frame size: ");
    scanf("%d",&size);
    int frame[size] ;
     for(int i=0;i<size ;i++) 
        frame[i] = -1;
     display(size,frame);
     int j=0;
     for(int i=0;i< n;i++) {
        frame[j] = arr[i];
        j++;
        j %= size;
        display(size,frame);
    }

    return 0;
}
