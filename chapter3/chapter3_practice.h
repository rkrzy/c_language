//
// Created by 임준식 on 25. 5. 5.
//

#ifndef C_PRACTICE_CHAPTER3_PRACTICE_H
#define C_PRACTICE_CHAPTER3_PRACTICE_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int bin_search(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(x < v[mid]){
            high = mid - 1;
        }
        else if(x > v[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int bin_search_improve(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        if(v[mid] == x){
            return mid;
        }
        else if(x < v[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

void escape(char * s, char * t){
    int i, j;
    for(i = 0; s[i] != '\0'; i++){
        switch (s[i]) {
            case '\n' :
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t' :
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}


int atoi (char s[])
{
    int i, n, sign;

    for(i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(n = 0; isdigit(s[i]); i++){
        n = 10 * n + (s[i] - '0');
    }
    return sign *n;
}

void shell_sort(int v[], int n){
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++){
            for(j = i -gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

void reverse(char s[]){
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void expand(char * s1, char * s2){
    int i;
    int k = 0;
    int c = 0;
    for(i = 0; s1[i] != '\0'; i++){
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' &&
            ((s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >= 'a' && s1[i + 1] <= 'z') ||
             (s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z') ||
             (s1[i - 1] >= '0' && s1[i - 1] <= '9' && s1[i + 1] >= '0' && s1[i + 1] <= '9'))) {

            for (c = s1[i - 1] + 1; c <= s1[i + 1]; c++) {
                s2[k++] = c;
            }
        } else {
            s2[k++] = s1[i];
        }
    }
    s2[k] = '\0';
}

//word의 범위는 2^31 ~ 2^31 -1까지라서 해당 값으로 표현이 안됨.
//매개변수를 long long으로 변경하면 가능해진다.
void itoa(int n, char s[])
{
    int i, sign;

    //음수라면 양수로 변경해준다.
    if((sign = n) < 0){
        n = -n;
    }
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }
    while((n /= 10) > 0);

    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    //숫자를 거꾸로 넣었기 때문에 다시 역으로 변경해준다.
    reverse(s);
}

int itob(int n, char s[], int b){
    int s_len = 0;
    int mul = 1;
    int temp = 0;
    while(s[s_len] != '\0'){
        s_len++;
    }
    s_len--;

    for(int i = s_len; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9'){
            temp = s[i] - '0';
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            temp = s[i] - 'a' + 10;
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            temp = s[i] - 'A' + 10;
        }else{
            continue;
        }

        n += mul * temp;
        mul *= b;
    }
    return n;
}

int trim(char s[]){
    int n;

    for(n = strlen(s) - 1; n >= 0; n--){
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n'){
            break;
        }
    }
    s[n+1] = '\0';
}

void goto_practice(){
    int n = 0;
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 20; j++){
            n += j;
            if(n == 20){
                goto end;
            }
        }
    }
    end :
    printf("%d", n);
}

#endif //C_PRACTICE_CHAPTER3_PRACTICE_H
