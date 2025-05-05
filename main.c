#include <stdio.h>
#include "chapter1/stringCalculate.h"
#include "chapter2/chapter2_practice.h"
#include "chapter3/chapter3_practice.h"
int main(void) {
    char s1[] = "-a-z";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);
}


