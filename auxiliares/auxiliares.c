#include <stdio.h>
#include <string.h>

void minuscula(char* str){
    for(int j = 0; j < strlen(str); j++){
        int valueInASCII = (int)str[j];
        
        if(valueInASCII >= 65 && valueInASCII <= 90){
            str[j] += 32;
        }
    }
}