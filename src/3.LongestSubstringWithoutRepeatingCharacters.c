#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int lengthOfLongestSubstring(char * s){
    uint32_t charMap[4] = {0x0, 0x0,0x0, 0x0};
    uint32_t mapshifft = 0, mapidx = 0;
    uint32_t maptmpshifft = 0, maptmpidx = 0;
    int result = 0, current = 0;
    char *pccurrent = s, *pcstart = s, *pctmp = NULL;
    /* if (s == NULL) */
    /* { */
    /*     return -1; */
    /* } */
    /* printf("%d- 0x%x, 0x%x\n", __LINE__, charMap[0], charMap[1]); */

    while(*pccurrent != '\0')
    {
        mapshifft = *pccurrent % 32;
        mapidx = *pccurrent / 32;
        /* printf("%d- %d, %d\n", __LINE__, mapshifft, mapidx); */
        if (charMap[mapidx] & (0x1ull << mapshifft)) // map is 1 in that char
        {
            //update result
            result = (result < current ? current:result);
            charMap[0] = 0;
            charMap[1] = 0;
            charMap[2] = 0;
            charMap[3] = 0;
            
            //remove the duplicated char in the beging & update map
            current = 0;
            pctmp = pccurrent;
            do
            {
                maptmpshifft = *pctmp % 32;
                maptmpidx = *pctmp / 32;
                charMap[maptmpidx] |= (0x1ull << maptmpshifft);
                ++current;
                --pctmp;
            }while(*pctmp != *pccurrent && pctmp >= pcstart);
            pcstart = pctmp + 1;
            /* printf("%d,%d- 0x%x, 0x%x,0x%x, 0x%x\n", __LINE__, current, charMap[0], charMap[1], charMap[2], charMap[3]); */
        }
        else
        {
            charMap[mapidx] |= (0x1ull << mapshifft);
            ++current;
            /* printf("%d,%d- 0x%x, 0x%x,0x%x, 0x%x\n", __LINE__, current, charMap[0], charMap[1], charMap[2], charMap[3]); */
        }

        // update ptr
        pccurrent += 1;
    }
    result = (result < current ? current:result);
    return result;
}

