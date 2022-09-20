
#include "libraries.h"

//bubble_sort

int Sorting(char **lines_buffer, size_t lines_amount, int (*strcmp_type)(char *str1, char *str2))
{
    Assert(lines_buffer != NULL, POINTER_IS_NULL);
    Assert(strcmp_type  != NULL, POINTER_IS_NULL);

    bool sorted = true;

    for (unsigned int indention = 0; indention < lines_amount; indention++)
    {
        for (unsigned int index = 0; index < lines_amount - indention - 1; index++)
        {
            if (strcmp_type(lines_buffer[index], lines_buffer[index + 1]) > 0)
            {
                char* temporary = lines_buffer[index + 1];
                lines_buffer[index + 1] = lines_buffer[index];
                lines_buffer[index] = temporary;

                sorted = false;
            }
        }

        if (sorted)
            break;
    }

    return 0;
}

int Strcmp(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return POINTER_IS_NULL;
    }

    int ch1 = 0;
    int ch2 = 0;

    while (true)
    {
        ch1 = *str1;
        ch2 = *str2;

        if ((ch1 == ch2) && ch1 != '\0' &&  ch2 != '\0')
        {
            str1++;
            str2++;
            continue;
        }

        return (ch1 - ch2);
    }
}

int ReversedStrcmp(char *str1, char *str2)
{
    Assert(str1 != 0, POINTER_IS_NULL);
    Assert(str2 != 0, POINTER_IS_NULL);

    char *pt1 = str1 + strlen(str1) - 1;
    char *pt2 = str2 + strlen(str2) - 1;

    while (true)
    {
        if ((*pt1 == *pt2) && (pt1 - str1) != 0
                           && (pt2 - str2) != 0)
        {
            pt1--;
            pt2--;

            continue;
        }

        return (*pt1 - *pt2);
    }
}
