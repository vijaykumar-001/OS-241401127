#include <stdio.h>

int main()
{
    int n, completed = 0, time = 0;

    printf("Enter number of processes: \n");
    scanf("%d", &n);

    int at[n], bt[n], priority[n], done[n];
    int ct[n], tat[n], wt[n];
    float avgtat = 0, avgwt = 0;

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority for P%d: \n", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        done[i] = 0;
    }

    // Scheduling Logic
    while (completed < n)
    {
        int idx = -1;
        int highPriority = 9999;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && done[i] == 0)
            {
                if (priority[i] < highPriority)
                {
                    highPriority = priority[i];
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            done[idx] = 1;
            completed++;
        }
        else
        {
            time++;   // CPU Idle
        }
    }

    // Separate loop for average calculation
    for (int i = 0; i < n; i++)
    {
        avgtat += tat[i];
        avgwt += wt[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);
    printf("Average Waiting Time: %.2f\n", avgwt / n);

    return 0;
}
