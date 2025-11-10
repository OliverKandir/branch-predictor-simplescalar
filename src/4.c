// layer_norm.c — LLM Layer Normalization with conditional clipping
#include <stdio.h>
#include <math.h>

#define BATCH 256
#define DIM 256
#define EPS 1e-5f

int main()
{
    static float X[BATCH][DIM], Y[BATCH][DIM];
    static float gamma[DIM], beta[DIM];

    for (int i = 0; i < DIM; i++)
    {
        gamma[i] = 1.0f + sinf(i * 0.1f);
        beta[i] = cosf(i * 0.05f);
    }

    for (int i = 0; i < BATCH; i++)
        for (int j = 0; j < DIM; j++)
            X[i][j] = ((i * 7 + j * 13) % 97 - 48) / 12.0f;

    for (int i = 0; i < BATCH; i++)
    {
        float mean = 0.0f, var = 0.0f;
        for (int j = 0; j < DIM; j++)
            mean += X[i][j];
        mean /= DIM;

        for (int j = 0; j < DIM; j++)
        {
            float diff = X[i][j] - mean;
            var += diff * diff;
        }
        var = sqrtf(var / DIM + EPS);

        for (int j = 0; j < DIM; j++)
        {
            float norm = (X[i][j] - mean) / var;
            if (norm > 3.0f)
                norm = 3.0f;
            else if (norm < -3.0f)
                norm = -3.0f;
            else if (fabsf(norm) < 0.01f)
                norm *= 1.5f;
            Y[i][j] = gamma[j] * norm + beta[j];
            if (((int)(Y[i][j] * 100)) % 11 == 0)
                Y[i][j] += 0.01f;
        }
    }

    printf("Y[0][0]=%.6f\n", Y[0][0]);
    return 0;
}
