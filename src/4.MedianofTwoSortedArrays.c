#include <stdlib.h>
#include <stdio.h>
//10|--------|->-------|20
//15|-------<-|--------|25
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    unsigned int idx1 = 0, idx2 = 0;
    unsigned char isOdd = ((nums1Size + nums2Size) % 2 == 1 ? 1:0);
    if (nums2Size > nums1Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    else if (nums2Size == 1 && nums1Size == 1)
    {
        return (nums1[0] + nums2[0])/2.0;
    }

    while(1)
    {

        // Ending condiction
        if (isOdd = 1)
        {

        }
        else
        {

        }

    }
}
