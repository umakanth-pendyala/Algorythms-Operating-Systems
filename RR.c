#include <stdio.h>

int bt[10], ct[10], Qunatum, tat[10], wt[10], temp[10];
int processes;

void main () {
    printf ("enter the number of processes :\t");
    scanf ("%d", &processes);

    printf ("enter the time quantum :\t");
    scanf ("%d", &Qunatum);

    for (int i = 0; i < processes; i++) {
        printf ("\n\nprocess details %d:\n", i);
        printf ("enter the burst time of process %d\t:", i);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    int count = 0;
    int i = 0, countTIme = 0;
    while (count != processes) {
        int time = Qunatum;
        while (time > 0 && bt[i] > 0) {
            bt[i] --;
            time --;
            countTIme++;
        }
        if (bt[i] == 0) {
            ct[i] = countTIme;
            tat[i] = ct[i];
            wt[i] = tat[i] - bt[i];
            count ++;
            bt[i] = -1;
        }
        i++;
        if (i == processes) i = 0; 
    }
    printf ("bt\tct\ttat\twt\n");
    for (int i = 0; i < processes; i++) printf ("%d\t%d\t%d\t%d\n",temp[i], ct[i], tat[i], wt[i]);
}