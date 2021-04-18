/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <string.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    unsigned char carrier = 0, tmpval = 0;
    struct ListNode *pstresult = NULL, *pstcurrentPtr = NULL, *psttmp = NULL, *pstcurrentl1 = NULL, *pstcurrentl2 = NULL;
    if (l1 == NULL || l2 == NULL)
    {
        return NULL;
    }
    pstcurrentl1 = l1;
    pstcurrentl2 = l2;
    while(!(pstcurrentl1 == NULL && pstcurrentl2 == NULL && carrier == 0))
    {
        // calc value & carrier
        if (pstcurrentl1 != NULL && pstcurrentl2 != NULL)
        {
            tmpval = pstcurrentl1->val + pstcurrentl2->val + carrier;
            pstcurrentl1 = pstcurrentl1->next;
            pstcurrentl2 = pstcurrentl2->next;
        }
        else if (pstcurrentl1 != NULL && pstcurrentl2 == NULL)
        {
            tmpval = pstcurrentl1->val + carrier;
            pstcurrentl1 = pstcurrentl1->next;
        }
        else if (pstcurrentl1 == NULL && pstcurrentl2 != NULL)
        {
            tmpval = pstcurrentl2->val + carrier;
            pstcurrentl2 = pstcurrentl2->next;
        }
        else if (carrier != 0)
        {
            tmpval = carrier;
        }
        carrier = tmpval / 10;
        tmpval %= 10;
        //create result elements
        psttmp = malloc(sizeof(struct ListNode));
        if (psttmp == NULL)
        {
            return pstresult;
        }
        else
        {
            memset(psttmp, 0, sizeof(struct ListNode));
        }
        // update result elements
        if ( pstresult == NULL )
        {
            pstresult = psttmp;
            pstcurrentPtr = pstresult;
        }
        else
        {
            pstcurrentPtr->next = psttmp;
            pstcurrentPtr = pstcurrentPtr->next;
        }
        pstcurrentPtr->next = NULL;
        pstcurrentPtr->val = tmpval;

    }
    return pstresult;
}


