#include <stdio.h>

int n,pos,temp,total=0;
int BT[20], WT[20], TAT[20], P[20];
float avg_TAT = 0.0, avg_WT = 0.0;

void SJF(){
    for(i=0;i<n;i++){
            pos=i;

    for(j=i+1;j<n;j++){
            if(Burst_time[j]<Burst_time[pos])
            pos=j;
    }
    temp=Burst_time[i];
    Burst_time[i]=Burst_time[pos];
    Burst_time[pos]=temp;

    temp=process[i];
    process[i]=process[pos];
    process[pos]=temp;

    }
    Waiting_time[0]=0;

    for(i=1;i<n;i++){
        Waiting_time[i]=0;
        for(j=0;j<i;j++)
            Waiting_time[i]+=Burst_time[j];
        total+=Waiting_time[i];
    }
    avg_Waiting_time=(float)total/n;
    total=0;

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");

    for(i=0;i<n;i++){
        Turn_around_time[i]=Burst_time[i]+Waiting_time[i];
        total+=Turn_around_time[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",process[i],Burst_time[i],Waiting_time[i],Turn_around_time[i]);
    }

    avg_Turn_around_time=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_Waiting_time);
    printf("\nAverage Turnaround Time=%f\n",avg_Turn_around_time);
}

void main() {
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &BT[i]);
        P[i] = i + 1;
    }

    SJF(); 
}

//OUTPUT
Enter the total number of processes: 3
Enter Burst Time:
P[1]: 6
P[2]: 8
P[3]: 7

Process    Burst Time    Waiting Time    Turnaround Time
P[1]        6            0              6
P[3]        7            6              13
P[2]        8            13             21

Average Waiting Time = 6.333333
Average Turnaround Time = 13.333333

