#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 256

//  LLM Feedforward Layer with Complex Activation
int main()
{
    static double A[N][N], B[N][N], C[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            A[i][j] = sin(i * 0.1 + j * 0.2);
            B[i][j] = cos(i * 0.3 - j * 0.1);
        }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < N; k++)
                sum += A[i][k] * B[k][j];

            // Activation logic (ReLU-like, but branched)
            if (sum > 5)
                C[i][j] = tanh(sum / 5.0);
            else if (sum > 1)
                C[i][j] = log(sum + 1);
            else if (sum > 0)
                C[i][j] = sum * sum;
            else if (sum > -2)
                C[i][j] = -sum / 2;
            else
                C[i][j] = sin(sum);

            // Secondary branch: normalization
            if (((int)(sum * 10)) % 7 == 0)
                C[i][j] += 0.1;
            else if (((int)(sum * 10)) % 11 == 0)
                C[i][j] -= 0.05;
        }
    }
    printf("C[0][0]=%.4f\n", C[0][0]);
}
