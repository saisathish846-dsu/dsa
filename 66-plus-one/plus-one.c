#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Walk from the least significant digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    // All digits were 9, so the result is 1 followed by n zeros
    int* result = (int*)calloc(digitsSize + 1, sizeof(int));
    result[0] = 1;
    *returnSize = digitsSize + 1;
    return result;
}