#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100000
#define EXPERTS 8

// Mixture-of-Experts with Probabilistic Routing

int main()
{
    int route[N];
    double weights[EXPERTS];
    for (int i = 0; i < EXPERTS; i++)
        weights[i] = (i + 1) * 0.1;

    for (int i = 0; i < N; i++)
        route[i] = rand() % 1000;

    int counters[EXPERTS] = {0};
    for (int i = 0; i < N; i++)
    {
        double val = route[i] / 1000.0;
        int expert;

        // Complex routing logic (branch-heavy)
        if (val < 0.1)
            expert = 0;
        else if (val < 0.2)
            expert = 1;
        else if (val < 0.3)
            expert = 2;
        else if (val < 0.5)
            expert = 3;
        else if (val < 0.7)
            expert = 4;
        else if (val < 0.9)
            expert = 5;
        else
            expert = 6 + (val > 0.95 ? 1 : 0);

        // Sub-branches for load balancing
        if (expert % 2 == 0 && route[i] % 3 == 0)
            counters[expert]++;
        else if (expert % 3 == 0)
            counters[expert] += 2;
        else if (expert % 5 == 0)
            counters[expert] += 3;
        else
            counters[expert] += (route[i] % 7);

        if (val > 0.8 && counters[expert] % 11 == 0)
            counters[expert] -= 1;
    }

    for (int i = 0; i < EXPERTS; i++)
        printf("Expert %d processed %d tokens\n", i, counters[i]);
}
