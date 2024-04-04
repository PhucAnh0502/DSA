#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10001
#define MAX_LINE_LENGTH 256

typedef struct
{
    char time[20];
    char type[5];
    char content[MAX_LINE_LENGTH];
} TB;

int TypeValue(const char* logType) {
    if (strcmp(logType, "ERRO") == 0) return 3;
    if (strcmp(logType, "WARN") == 0) return 2;
    if (strcmp(logType, "INFO") == 0) return 1;
    return 0; 
}

int compare(const void *a, const void *b)
{
    TB *A = (TB *)a;
    TB *B = (TB *)b;

    int typecmp = TypeValue(B->type) - TypeValue(A->type);
    if (typecmp != 0)
        return typecmp;

    int timecmp = strcmp(A->time, B->time);
    if (timecmp != 0)
        return timecmp;
    return strcmp(A->content, B->content);
}

int main()
{
    TB input[MAX_LINES];
    int cnt = 0;

    while (fgets(input[cnt].time, 20, stdin) != NULL)
    {
        input[cnt].time[19] = '\0'; 
        scanf("%s", input[cnt].type);
        getchar();
        fgets(input[cnt].content, MAX_LINE_LENGTH, stdin);
        char *newline = strchr(input[cnt].content, '\n');
        if (newline)
            *newline = '\0';
        cnt++;
    }

    qsort(input, cnt, sizeof(TB), compare);

    for (int i = 0; i < cnt; i++)
    {
        printf("%s %s %s\n", input[i].time, input[i].type, input[i].content);
    }
    return 0;
}
