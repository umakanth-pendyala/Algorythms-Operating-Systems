#include <stdio.h>

int alloc[20][20], maxNeed[20][20], avail[20];
int recources, processes;
int executionOrder[20], executionDone[20], index;



int doExecution() {
    int tempValue = 0, count = 0;
    int flag = 1;
    for (int i = 0; i < processes*processes; i++) {
        for (int t = 0; t < processes; t++) {
            tempValue = 0;
            for (int j = 0; j < recources; j++) {
                if (alloc[t][j] + avail[j] >= maxNeed[t][j] && executionDone[t] != 1) {
                    tempValue ++;
                    //printf ("recources: %d", tempValue);
                }
            }
            if (tempValue == recources) {
                //printf ("hi");
                for (int i = 0; i < recources; i++) avail[i] += alloc[t][i]; 
                executionDone[t] = 1;
                executionOrder[index] = t;
                index ++;
                count ++;
            }
        }
        if (count == processes) break;
    }
    if (count == processes) {
        printf ("execution order \n");
        for (int i = 0; i < index; i++) printf ("%d\t", executionOrder[i]);
        return 1;
    }
    else return 0;
}



void main () {
    printf ("enter the number of processes :\t");
    scanf ("%d", &processes);

    printf ("enter number of recources :\t");
    scanf ("%d", &recources);

    printf ("allocation entry\n");
    for (int i = 0; i < processes; i++) {
        printf("\n");
        for (int j = 0; j < recources; j++) {
            printf ("enter the allocation for process : %d : recource : %d :\t", i,j);
            scanf ("%d", &alloc[i][j]);
        }
    }
    
    printf ("max need entry \n");
    for (int i = 0; i < processes; i++) {
        printf("\n");
        for (int j = 0; j < recources; j++) {
            printf ("enter the max need for process : %d : recource : %d :\t", i,j);
            scanf ("%d", &maxNeed[i][j]);
        }
    }

    printf ("availible entry\n");
    for (int i = 0; i < recources; i++) {
        printf ("enter the instance for the recource :%d:\t", i);
        scanf("%d", &avail[i]);
    }

    if (doExecution()) printf ("\nexecution done\n");
    else printf ("\nnot done\n");

}