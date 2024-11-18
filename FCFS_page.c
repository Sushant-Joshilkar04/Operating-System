#include<stdio.h>
#include<stdbool.h>

void display(int frame[],int size){
    for(int i=0;i<size;i++)
     printf(" %d ",frame[i]);
     printf("\n");
}

bool contains(int frame[],int size,int ele){
    for (int i = 0; i < size; i++)
       if(frame[i]==ele)
         return true;
    
    return false;
}

int main(){
    int n;
    printf("Enter number of pages:");
    scanf("%d",&n);
    int pages[n];
    printf("Enter pages: ");
    for(int i=0;i<n;i++)
      scanf("%d",&pages[i]);

    int size;
    printf("Enter pages frame size: ");
    scanf("%d",&size);
    int frame[size];

    for(int i=0;i<size;i++) frame[i] = -1;

    int j=0,hit=0,fault=0; 
    for(int i=0;i<n;i++){
        if(contains(frame,size,pages[i])){
           hit++;
           display(frame,size);
        }else{
            frame[j%size] = pages[i];
            fault++;j++;
            display(frame,size);
        }
    }

    printf("Hit: %d Fault: %d Pages: %d",hit,fault,n);
    return 0;
}
