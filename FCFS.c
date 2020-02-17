#include <stdio.h>

int at[10], bt[10], ct[10], tat[10], wt[10], id[10];
int processes;

void sort () {
    for (int i = 0; i < processes - 1; i++) {
        for (int j = 0; j < processes- (i+1); j++) {
            if (at[j] > at[j+1]) {
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }
}

void main() {
    printf ("enter number of processes :\t");
    scanf ("%d",&processes);

    for (int i = 0; i < processes; i++) {
        printf ("\n\nprocess details :%d\n", i);
        printf ("enter the arrival time of process :%d\t", i);
        scanf ("%d", &at[i]);
        printf ("enter the bust time of process :%d\t", i);
        scanf ("%d", &bt[i]);
    }

    sort();

    for (int i = 0; i < processes; i++) {
        if (i == 0) {
            ct[i] = bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }
        else  {
            ct[i] = ct[i-1] + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }
    }

    printf ("at\tbt\tct\ttat\twt\n");
    for (int i = 0; i < processes; i++) printf ("%d\t%d\t%d\t%d\t%d\n", at[i], bt[i], ct[i], tat[i], wt[i]);

}   