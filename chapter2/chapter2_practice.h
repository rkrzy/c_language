//
// Created by 임준식 on 25. 5. 4.
//

#ifndef C_PRACTICE_CHAPTER2_PRACTICE_H
#define C_PRACTICE_CHAPTER2_PRACTICE_H
#include <stdio.h>
#include <math.h>

void h_to_i(char str[], int length){
    int result = 0;
    int mul = 1;
    for(int i = length - 1; i > 1; i--){
        if('a' <= str[i] && 'f' >= str[i]){
            result += (str[i] - 'a' + 10) * mul;
        }else if('A' <= str[i] && 'F' >= str[i]){
            result += (str[i] - 'A' + 10) * mul;
        }
        else{
            result += (str[i] - '0') * mul;
        }
        mul *= 16;
    }
    printf("%d", result);
}

void str_remove(char * str1, int n){
    while(str1[n] != '\0'){
        str1[n] = str1[n+1];
        n++;
    }
}

void squeeze(char * str1, char * str2){
    for(int i = 0; str2[i] != '\0'; i++){
        for(int j = 0; str1[j] != '\0'; j++){
            if(str2[i] == str1[j]){
                str_remove(str1, j);
                j--;
            }
        }
    }
    printf("%s", str1);
}

unsigned get_bits(unsigned x, int p, int n){
    return (x >>(p+1-n)) & ~ (~0 << n);
}

unsigned set_bits(unsigned x, unsigned y, int p, int n){

    y = y & ~(~0 << n); //가장 우측의 n개의 비트 구하기
    // 1을 왼쪽으로 n만큼 이동하고 -1을 하면 n아래의 비트가 모두 1로 변환된다. 그리고 왼쪽으로 p만큼 이동시킴
    //마지막으로 보수를 취하면 원하는 위치의 값들을 0으로 대체하는게 가능해진다.
    x = x & ~( ((1 << n) - 1) << p );
    x = x | (y << p); //비트를 p만큼 이동시켜서 x의 p번째 비트부터 오른쪽으로 n개까지를 y의 값으로 대체한다.
    return x;
}

unsigned invert(unsigned x, int p, int n){
    unsigned mask = ((1 << n) - 1) << (p + 1 - n);

    return x ^ mask;
}

unsigned rightrot(unsigned x, int n){
    unsigned mask = x & ((1<<n) -1);
    return (x << n) | mask;
}

int bit_count(unsigned x)
{
    x &= (x-1);
   return x;
}

int lower(int x){
    int y;
    y = (x >= 65 && x <= 90) ? x + 32 : x;

    return y;
}
#endif //C_PRACTICE_CHAPTER2_PRACTICE_H
