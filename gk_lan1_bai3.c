#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(const char *word, const char *hauto) {
    int wordLen = strlen(word);
    int hautoLen = strlen(hauto);
    if (wordLen < hautoLen) {
        return 0;
    }
    int wordIndex = wordLen - 1;
    int hautoIndex = hautoLen - 1;
    while (hautoIndex >= 0) {
        if (word[wordIndex] != hauto[hautoIndex]) {
            return 0;
        }
        wordIndex--;
        hautoIndex--;
    }
    return 1;
}

int scmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char hauto[10];
    char input[1000000];
    scanf("%s", hauto);
    getchar();

    char *words[10001];
    int cnt = 0;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        char *token = strtok(input, " \n");
        while (token != NULL && cnt < 10001) {
            token[strcspn(token, "\n")] = '\0';
        	strcpy(words[cnt], token);
        	cnt++;
        	token = strtok(NULL, " ");
        }
    }

    qsort(words, cnt, sizeof(char *), scmp);

    for (int i = 0; i < cnt; i++) {
        if (check(words[i], hauto)) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
