#include<stdio.h>
#include <stdbool.h>
#include<limits.h>

void display2(int n,int pid[],int at[],int bt[],int priority[],int st[],int et[],int wt[],int tat[]){
    printf("PID Arrival Burst Priority Start End waiting Turn_Around\n");
    for(int i=0;i<n;i++){
        printf("%d\t %d \t%d \t%d \t%d \t%d \t%d \t%d\n",pid[i],at[i],bt[i],priority[i],st[i],et[i],wt[i],tat[i]);
    }
}

void Swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sort_according_to_priority(int n, int pid[], int at[], int bt[], int priority[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - (i - start) - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                Swap(&at[j], &at[j + 1]);
                Swap(&bt[j], &bt[j + 1]);
                Swap(&pid[j], &pid[j + 1]);
                Swap(&priority[j], &priority[j + 1]);
            }
        }
    }
}


void display(int n,int pid[],int at[],int bt[],int priority[]){
    for(int i=0;i<n;i++){
        printf("%d %d %d %d \n",pid[i],at[i],bt[i],priority[i]);
    }
    printf("\n");
}

void answer(int n,int pid[],int at[],int bt[],int priority[]){
    int st[n];
    int et[n];
    int wt[n];
    int tat[n]; 
    for(int i=0;i<n;i++){
        st[i]=0;et[i]=0;wt[i]=0;tat[i]=0;
    }
    st[0] = at[0];
    et[0] = at[0]+bt[0];
 
    for(int i=1;i<n;i++){
        int j = i;
        while(j<n && at[j]<=et[i-1]) j++;
        
        sort_according_to_priority(n,pid,at,bt,priority,i,j);

        if(et[i-1] > at[i]){
            st[i] = et[i-1];
            et[i] = st[i]+bt[i];
        }
        else{
            st[i] = at[i];
            et[i] = at[i]+bt[i];
        }
    }
  
    float avgWt=0,avgTat=0,avgRes=0;
    for(int i=0;i<n;i++) {
   tat[i]=et[i]-at[i];
   wt[i]=tat[i]-bt[i];
}
 for(int i=0;i<n;i++) {
   avgWt=avgWt+wt[i];
   avgTat=avgTat+tat[i];
}
    display2(n, pid, at, bt, priority,st,et,wt,tat);

   printf("\nAverage WaitingTime -> %.2f",avgWt/n);
printf("\nAverage TurnAroundTime -> %.2f",avgTat/n);

    
    
}


void sort_according_to_at(int n,int pid[],int at[],int bt[],int priority[n]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                Swap(&at[j],&at[j+1]);
                Swap(&bt[j],&bt[j+1]);
                Swap(&pid[j],&pid[j+1]);
                Swap(&priority[j],&priority[j+1]);
            }else if(at[j]==at[j+1]){
                if(priority[j]>priority[j+1]){
                Swap(&at[j],&at[j+1]);
                Swap(&bt[j],&bt[j+1]);
                Swap(&pid[j],&pid[j+1]);
                Swap(&priority[j],&priority[j+1]);
                }
            }
        }
    }
    printf("\n After sorting according to Arrival time\n");
     display(n, pid, at, bt, priority);
     answer(n, pid, at, bt, priority);
}

int main(){
int n;
printf("Enter total number of processors: ");
scanf("%d",&n);

int pid[n];
int at[n];
int bt[n];
int priority[n];

printf("Enter Processor id , arrival time ,burst time , priority:\n ");
for(int i=0;i<n;i++){
     scanf("%d",&pid[i]);
     scanf("%d",&at[i]);
     scanf("%d",&bt[i]);
     scanf("%d",&priority[i]);
}

sort_according_to_at(n, pid, at, bt, priority);


return 0;
}

