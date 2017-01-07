/**
 * http://tokyo-ct.net/usr/kosaka/for_students/jissen1/akiyojissen1/kougi17.html
 * の実装。これをひな形にいろんな言語で書いてみる。
 */
#include <string.h>
#define max(a,b) ((a)>(b)?a:b)
typedef unsigned char uchar;

int skip[256];

void bm_init(char pattern[], int patn_len) {
    for (int i=0; i<256; i++) skip[i] = patn_len;
    for (int i=0; i<patn_len-1; i++) skip[pattern[i]] = patn_len - i - 1;
}

int bm_search(char text[], char pattern[]) {
    int i, j;
    int text_len, patn_len;

    text_len = strlen(text);
    patn_len = strlen(pattern);

    i = patn_len - 1;

    while (i < text_len) {
        j = patn_len - 1;
        while (text[i] == pattern[j]) {
            if (j == 0) return i;
            i--; j--;
        }
        i += max(skip[text[j]], patn_len-j);
    }
    return -1;
}
