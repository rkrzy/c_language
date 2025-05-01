#include <stdio.h>

void changeCelToFah(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("화씨 -> 섭씨 변환기\n");
    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
void changeFahToCel(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("섭씨 -> 화씨 변환기\n");
    celsius = lower;
    while(celsius <= upper){
        fahr = (celsius+32.0) * (9.0/5.0);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
void changeCelToFahV2(){
    float fahr, celsius;

    for(int i = 300; i >= 0; i = i - 20){
        fahr = i;
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
    }
}

