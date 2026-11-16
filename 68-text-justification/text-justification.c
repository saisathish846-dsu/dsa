#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int count = 0;
    int i = 0;

    while (i < wordsSize) {
        // Greedily find how many words fit on this line
        int j = i;
        int lettersLen = 0;
        while (j < wordsSize &&
               lettersLen + (int)strlen(words[j]) + (j - i) <= maxWidth) {
            lettersLen += strlen(words[j]);
            j++;
        }

        int numWords = j - i;
        int gaps = numWords - 1;

        char* line = (char*)malloc(maxWidth + 1);
        int pos = 0;

        if (j == wordsSize || gaps == 0) {
            // Last line or single word: left-justify
            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;
                if (k < j - 1) line[pos++] = ' ';
            }
            while (pos < maxWidth) line[pos++] = ' ';
        } else {
            // Fully justify
            int totalSpaces = maxWidth - lettersLen;
            int base = totalSpaces / gaps;
            int extra = totalSpaces % gaps;

            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;
                if (k < j - 1) {
                    int spaces = base + ((k - i) < extra ? 1 : 0);
                    for (int s = 0; s < spaces; s++) line[pos++] = ' ';
                }
            }
        }

        line[maxWidth] = '\0';
        result[count++] = line;
        i = j;
    }

    *returnSize = count;
    return result;
}