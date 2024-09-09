#include<stdio.h>
#include <stdbool.h>
#include<limits.h>

void display(int n,int pid[],int at[],int bt[],int st[],int et[],int wt[],int tat[]){
    printf("PID   Arrival  Burst  Start    End   waiting  Turn_Around\n");
    for(int i=0;i<n;i++){
        printf("%d\t %d \t%d  \t%d \t%d \t%d \t%d\n",pid[i],at[i],bt[i],st[i],et[i],wt[i],tat[i]);
    }
}

void Swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void answer(int n,int pid[],int at[],int bt[]){
    int st[n];
    int et[n];
    int wt[n];
    int tat[n];

    for(int i=0;i<n;i++){
        st[i] = 0; 
        et[i] = 0;
        wt[i] = 0;
        tat[i] = 0;
    }

    st[0] = at[0];
    et[0] = at[0]+bt[0];

   for(int i=1;i<n;i++){
    if(et[i-1]>=at[i]){
    st[i] = et[i-1];
    et[i] = st[i]+bt[i];
    }else{
    st[i] = at[i];
    et[i] = at[i]+bt[i];
    }
   }

    float avgWt=0,avgTat=0;
    for (int i = 0; i < n; i++) {
        tat[i] = et[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgWt=avgWt+wt[i];
        avgTat=avgTat+tat[i];
    }

    display(n, pid, at, bt, st, et, wt, tat);
    printf("\nAverage WaitingTime -> %.2f",avgWt/n);
    printf("\nAverage TurnAroundTime -> %.2f",avgTat/n);
}

void sort_according_to_at(int n,int pid[],int at[],int bt[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                Swap(&at[j],&at[j+1]);
                Swap(&bt[j],&bt[j+1]);
                Swap(&pid[j],&pid[j+1]);
            }
        }
    }

    answer(n, pid, at, bt);
}

int main(){
int n;
printf("Enter total number of processors: ");
scanf("%d",&n);

int pid[n];
int at[n];
int bt[n];


printf("Enter Processor id , arrival time ,burst time :\n ");
for(int i=0;i<n;i++){
     scanf("%d",&pid[i]);
     scanf("%d",&at[i]);
     scanf("%d",&bt[i]);
}

sort_according_to_at(n, pid, at, bt);

return 0;
}

