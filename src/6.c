// token_sampler.c — simulates LLM token sampling with top-k filtering
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VOCAB 500
#define BATCH 64
#define K 20

int main()
{
    static float logits[BATCH][VOCAB];
    int sampled[BATCH];

    for (int i = 0; i < BATCH; i++)
        for (int j = 0; j < VOCAB; j++)
            logits[i][j] = ((i * 19 + j * 37) % 101 - 50) / 10.0f;

    for (int i = 0; i < BATCH; i++)
    {
        float topk[K];
        int topk_idx[K];
        for (int t = 0; t < K; t++)
            topk[t] = -1e9;

        for (int j = 0; j < VOCAB; j++)
        {
            float v = logits[i][j];
            for (int t = 0; t < K; t++)
            {
                if (v > topk[t])
                {
                    for (int s = K - 1; s > t; s--)
                    {
                        topk[s] = topk[s - 1];
                        topk_idx[s] = topk_idx[s - 1];
                    }
                    topk[t] = v;
                    topk_idx[t] = j;
                    break;
                }
            }
        }

        float randf = (float)(rand() % 10000) / 10000.0f;
        int pick = (int)(randf * K);
        if (pick >= K)
            pick = K - 1;
        else if (pick < 0)
            pick = 0;

        if (topk[pick] < -5.0f)
            sampled[i] = -1;
        else if (topk[pick] > 5.0f)
            sampled[i] = topk_idx[pick] / 2;
        else
            sampled[i] = topk_idx[pick];
    }

    printf("sampled[0]=%d\n", sampled[0]);
    return 0;
}
