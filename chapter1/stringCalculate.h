#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_LINE  1000

void calculateCharV1(){
    long nc;

    nc = 0;
    while(getchar() != 'p')
        nc++;
    printf("%ld\n", nc);
}
void calculateCharV2(){
    double nc;
    for(nc = 0; getchar() != 'p'; ++nc);
    printf("%.0f\n", nc);
}
void calculateLineV1(){
    int c, nl;

    nl = 0;
    while((c = getchar()) != 'p')
        if(c == '\n')
            ++nl;
    printf("%d", nl);
}
void calculateTabLineEmpty(){
    int numTab = 0;
    int numLine = 0;
    int numEmpty = 0;

    int c;
    while((c = getchar()) != 'p'){
        if(c == '\n'){
            numLine++;
        }
        else if(c == ' '){
            numEmpty++;
        }
        else if(c == '\t'){
            numTab++;
        }
    }
    printf("Tab수 : %d, Line수 : %d, Empty수 : %d", numTab, numLine, numEmpty);

}
void calculateWord(){
    int c;
    int numLine = 0;
    int numWord = 0;
    int numChar = 0;
    int state = 0;

    state = OUT;

    while((c = getchar()) != 'p') {
        numChar++;
        if(c == '\n'){
            numLine++;
        }
        if(c == ' '|| c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT) {
            state = IN;
            numWord++;
        }
    }
    printf("%d %d %d \n", numLine, numWord, numChar);
}
void file_word_print(){
    FILE * fp = fopen("sample.txt", "r");
    if(fp == NULL){
        perror("파일 생성 실패");
        return;
    }
    int c;

    while((c= fgetc(fp)) != EOF){

        if(c == '\n' || c == '\t' || c == ' '){
            printf("\n");
        }else{
            putchar(c);
        }
    }
    fclose(fp);
}
void calculate_number() {
    int c, i, num_white, num_other;

    int num_digit[10];

    num_white = num_other = 0;
    for (i = 0; i < 10; i++) {
        num_digit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++num_digit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++num_white;
        else
            ++num_other;
    }

    printf("digits = ");
    for (i = 0; i < 10; i++) {
        printf(" %d", num_digit[i]);
    }
    printf(", white space = %d, other = %d\n", num_white, num_other);

}

int get_line(char line[], int max_line){
    int c, i;
    for(i = 0; i < max_line && (c=getchar()) != 'p' && c != '\n'; i++){
        line[i] = c;
    }
    if(c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
void copy(char to[],const char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0'){
        i++;
    }
}


void a_tab(){
    FILE * fp = fopen("sample.txt", "r");

    if(fp == NULL){
        perror("파일 생성 실패");
        return;
    }
    int c;
    while((c = fgetc(fp)) != EOF){
        if(c == '\t'){
            printf("    ");
        }else{
            putchar(c);
        }
    }
}

void en_tab(){
    FILE * fp = fopen("sample.txt", "r");

    if(fp == NULL){
        perror("파일 열기 실패");
        return;
    }
    int c;
    int count = 0;
    while((c = fgetc(fp)) != EOF){
        if(c == ' '){
            count++;
        }
        else{
            if(count >= 4){
                putchar('\t');
                for(int i = 0; i < count % 4; i++){
                    putchar(' ');
                }
            }
            else{
                for(int i = 0; i < count; i++){
                    putchar(' ');
                }
            }
        }
        count = 0;
        putchar(c);
    }
    if(count > 0){
        for(int i = 0; i <count; i++){
            putchar(' ');
        }
    }
}

void next_line(){
    FILE * fp = fopen("sample.txt", "r");

    if(fp == NULL){
        perror("파일 열기 실패");
        return;
    }
    int c = 0;
    int max_count = 10;
    int count = 0;
    while((c = fgetc(fp)) != EOF){
        if(count >= max_count){
            if(c == ' '){
                printf("\n");
                count = 0;
            }
            else{
                putchar(c);
                count++;
            }
        }else{
            putchar(c);
            count++;
        }

    }
}