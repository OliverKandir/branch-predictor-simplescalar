// gradient_update.c — weight update kernel with adaptive learning rates
#include <stdio.h>
#include <math.h>

#define LAYERS 64
#define DIM 256

int main()
{
    static float W[LAYERS][DIM], grad[LAYERS][DIM], lr[LAYERS];
    for (int i = 0; i < LAYERS; i++)
        for (int j = 0; j < DIM; j++)
        {
            W[i][j] = ((i * 31 + j * 7) % 101 - 50) / 50.0f;
            grad[i][j] = ((i * 19 + j * 11) % 97 - 48) / 60.0f;
        }

    for (int i = 0; i < LAYERS; i++)
    {
        lr[i] = 0.001f + (i % 5) * 0.0001f;
        for (int j = 0; j < DIM; j++)
        {
            float g = grad[i][j];
            if (fabsf(g) > 1.0f)
                lr[i] *= 0.9f;
            else if (fabsf(g) < 0.01f)
                lr[i] *= 1.05f;
            W[i][j] -= lr[i] * g;
            if (((int)(W[i][j] * 1000)) % 13 == 0)
                W[i][j] += 0.0001f;
        }
    }

    printf("W[0][0]=%.6f\n", W[0][0]);
    return 0;
}
