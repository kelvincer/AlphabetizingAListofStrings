/*
8.21 (Alphabetizing a List of Strings) Use the string-comparison functions and the
techniques for sorting arrays to write a program that alphabetizes a list of strings. Use
the names of 10 or 15 towns in your area as data for your program.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *s1, const void *s2)
{
    const char **e1 = (const char **)s1;
    const char **e2 = (const char **)s2;

    return strcmp(*e1, *e2);
}

int pstrcmp(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
    char words[1000];
    size_t num_words = 0;
    char s = ' ';
    char *token;
    char *word_list[1000];

    fgets(words, 1000, stdin);

    /* get the first token */
    token = strtok(words, &s);

    /* walk through other tokens */
    while (token != NULL)
    {
        token[strcspn(token, "\n")] = '\0';
        // printf("%s\n", token);
        word_list[num_words] = token;
        num_words++;
        token = strtok(NULL, &s);
    }

    qsort(word_list, num_words, sizeof(char *), cmp);

    printf("\nResult: ");

    for (size_t i = 0; i < num_words; i++)
    {
        printf("%s ", word_list[i]);
    }

    puts("");
}