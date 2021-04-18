#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
    int sistrSize = strlen(S);
    int *pians = NULL;
    uint32_t u32idxStart = 0, u32idxEnd = 0, u32idx = 0;

    *returnSize = sistrSize + 1;
    pians = malloc(*returnSize*sizeof(int));

    u32idxEnd = sistrSize;

    // printf("%s, %i\n", S, *returnSize);
    // printf("idx -> %i, %i, %i\n", u32idx, u32idxStart, u32idxEnd);

    // if (S[u32idx] == 'D')
    // {
    //     pians[0] = u32idxEnd--;
    // }
    // else
    // {
    //     pians[0] = u32idxStart++;
    // }
    // printf("idx -> %i, %i, %i\n", u32idx, u32idxStart, u32idxEnd);

    for (u32idx = 0; u32idx < sistrSize; u32idx++)
    {
        // printf("%c, idx -> %i, %i, %i\n", S[u32idx], u32idx, u32idxStart, u32idxEnd);
        if (S[u32idx] == 'D')
        {
            pians[u32idx] = u32idxEnd--;
        }
        else
        {
            pians[u32idx] = u32idxStart++;
        }
        // for (int i = 0; i < *returnSize; i++)
        // {
        //     printf("%i, ", pians[i]);
        // }
        // printf("\n");
    }
    pians[u32idx] = u32idxStart++;
    // for (int i = 0; i < *returnSize; i++)
    // {
    //     printf("%i, ", pians[i]);
    // }
    // printf("\n");
    // printf("End:idx -> %i, %i, %i\n", u32idx, u32idxStart, u32idxEnd);
    return pians;
}

int main(int argc, char **argv)
{
    // char pctest[] = "IDID";
    // char pctest[] = "III";
    char pctest[] = "IIDD";
    int rsize=0, *ret = NULL;
    ret = diStringMatch(pctest, &rsize);
    for (int i = 0; i < rsize; i++)
    {
        printf("%i, ", ret[i]);
    }
    printf("\n");
    if (ret != NULL)
    {
        free(ret);
    }
    return 0;

}
