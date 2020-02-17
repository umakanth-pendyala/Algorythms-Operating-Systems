#include <stdio.h>

int at[10], bt[10], ct[10], tat[10], wt[10], temp[10];
int processes;


void main () {
    printf ("enter the number  of processes :\t");
    scanf ("%d", &processes);

    for (int i = 0; i < processes; i++) {
        printf ("\n\nprocesss details \t:%d\n", i);
        printf ("enter the arrival time of process %d\t:", i);
        scanf ("%d", &at[i]);
        printf("enter the bust time of process %d\t:", i);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    int count = 0;
    int smallest = 9;
    bt[smallest] = 9999; 
    for (int time = 0; count != processes; time++) {
        smallest = 9;
        for (int i = 0; i < processes; i++) {
            if (at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0) smallest = i;
        }
        bt[smallest] --;
        if (bt[smallest] == 0) {
            ct[smallest] = time + 1;
            tat[smallest] = ct[smallest] - temp[smallest];
            wt[smallest] = tat[smallest] - at[smallest];
            count ++;
        }
    }

    printf ("at\tbt\tct\ttat\twt\n");
    for (int i = 0; i < processes; i++) printf ("%d\t%d\t%d\t%d\t%d\n", at[i], temp[i], ct[i], tat[i], bt[i]);


}