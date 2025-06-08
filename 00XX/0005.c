/** @file   0005.c
 *  @brief  Finds the longest palindromic substring
 *  @author Bart Lunenborg, s3410579
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int front, int back) {
  while (front <= back) {
    if (s[front++] != s[back--]) {
      return 0;
    }
  }
  return 1;
}

char *longestPalindrome(char* s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (isPalindrome(s, j, len - i + j - 1)) {
        char *p = malloc(len - i + 1);
        strncpy(p, s + j, len - i);
        p[len-i] = '\0';
        return p;
      }
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  printf("%s\n", longestPalindrome("babad"));
  return 0;
}
