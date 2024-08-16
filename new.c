#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Comparison function
int compare(const void *arg1, const void *arg2)
{
    return strcasecmp(*(const char **)arg1, *(const char **)arg2);
}

int main2(void)
{
    char *colors[] = {"Vivek", "Aman", "Shriansh", "Tapas"};
    int i;
    // Size of the array
    int size = sizeof(colors) / sizeof(char *);

    printf("Original array elements:\n");
    for (i = 0; i < size; i++)
    {
        printf("%s ", colors[i]);
    }

    printf("\n");

    // Use qsort to sort
    qsort(colors, size, sizeof(char *), compare);
    printf("Following is the sorted array: ");

    for (i = 0; i < size; ++i)
    {
        printf("%s ", colors[i]);
    }

    puts("");

    return 0;
}