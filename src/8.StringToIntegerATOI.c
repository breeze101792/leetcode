#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int myAtoi(char * str)
{
    int result = 0;
    uint32_t u32best_idx_start = 0, u32best_idx_end = 0, u32best_len = 0;
    uint32_t u32tmp_idx_start = 0, u32tmp_idx_end = 0, u32tmp_len = 0;
    uint32_t u32current_idx = 0, u32sign = 0, u32posidx = 0, u32isValid = 0, u32isOverflow = 0;
    if (str[0] == '\0')
    {
        return 0;
    }

    // printf("num: %c, %c\n", '0', '9');
    for (u32current_idx = 0; str[u32current_idx] != '\0'; u32current_idx++)
    {
        if (str[u32current_idx] == '-' && (str[u32current_idx + 1] >= '0' && str[u32current_idx + 1] <= '9'))
        {
            break;
        }
        else if (str[u32current_idx] == '+' && (str[u32current_idx + 1] >= '0' && str[u32current_idx + 1] <= '9'))
        {
            break;
        }
        else if (str[u32current_idx] >= '0' && str[u32current_idx] <= '9')
        {
            break;
        }
        else if (str[u32current_idx] == ' ')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    // printf("idx: %u\n", u32current_idx);
    // printf("input: %c\n", str[u32current_idx]);
    // for (u32current_idx = 0; str[u32current_idx] != '\0'; u32current_idx++)
    for (; str[u32current_idx] != '\0'; u32current_idx++)
    {
        // printf("input: %c\n", str[u32current_idx]);
        if (str[u32current_idx] >= '0' && str[u32current_idx] <= '9')
        {
            if (u32tmp_len == 0)
            {
                u32tmp_idx_start = u32current_idx;
                u32tmp_idx_end = 0;
                u32tmp_len = 0;
            }
            u32tmp_len++;
            u32tmp_idx_end = u32current_idx;
            // printf("char %c->len, start, end: %u, %u, %u\n", str[u32current_idx], u32tmp_len, u32tmp_idx_start, u32tmp_idx_end);
        }
        else if (u32tmp_len > 0)
        {

            if (u32tmp_len > u32best_len)
            {
                u32best_len = u32tmp_len;
                u32best_idx_start = u32tmp_idx_start;
                u32best_idx_end = u32tmp_idx_end;
                // printf("[Best]start, end: %u, %u, %u\n", u32best_len, u32best_idx_start, u32best_idx_end);
            }
            u32tmp_len = 0;
        }
        // else if (str[u32current_idx] == '-' || str[u32current_idx] == '+')
        // {
        //     continue;
        // }
        // else if (str[u32current_idx] == ' ')
        // {
        //     continue;
        // }
        // else
        // {
        //     return 0;
        // }
    }
    if (u32tmp_len == 0 && u32best_len == 0)
    {
        return 0;
    }
    else if (u32best_len == 0)
    {
        u32best_len = u32tmp_len;
        u32best_idx_start = u32tmp_idx_start;
        u32best_idx_end = u32tmp_idx_end;
    }
    // printf("[Best]start, end: %u, %u, %u\n", u32best_len, u32best_idx_start, u32best_idx_end);
    for (u32current_idx = u32best_idx_start; u32current_idx <= u32best_idx_end; u32current_idx++)
    {
        // printf("[Rsult]: %c, %u, %u\n", str[u32current_idx], u32current_idx, result);
        if (result == 214748364 && str[u32current_idx] >= '8')
        {
            u32isOverflow = 1;
            break;
        }
        else if (result > 214748364 && u32current_idx <= u32best_idx_end)
        {
            u32isOverflow = 1;
            break;
        }
        // printf("[Rsult]: %c, %u\n", str[u32current_idx], result);
        if (result != 0)
        {
            result = result * 10 + (uint32_t)str[u32current_idx] - (uint32_t)'0';
        }
        else
        {
            result = (uint32_t)str[u32current_idx] - (uint32_t)'0';
            // printf("[Else]: %i, %u, %u\n", result,  (uint32_t)str[u32current_idx], (uint32_t)'0');
        }
    }
    // printf("[Sign]start, end: %u, %u, %u\n", u32best_len, u32best_idx_start, u32best_idx_end);
    if (u32best_idx_start > 0 && str[u32best_idx_start - 1] == '-')
    {
        if (u32isOverflow == 1)
        {
            result = -2147483648;
        }
        else
        {
            result = result * -1;
        }
    }
    else if (u32isOverflow == 1)
    {
        result = 2147483647;
    }

    return result;
}
int main(int argc, char **argv)
{
    // char pctest[] = "Test Pattern is -256, not 2778.";
    // char pctest[] = "42";
    // char pctest[] = "   -42";
    // char pctest[] = "words and 987";
    char pctest[] = "-91283472332";
    // char pctest[] =  "2147483647";
    // char pctest[] = "";
    // char pctest[] = "+";
    // char pctest[] = "+-12";
    // char pctest[] = "2147483800";
    // pctest = malloc(256);
    printf("Ans-> %i\n", myAtoi(pctest));
    return 0;

}
