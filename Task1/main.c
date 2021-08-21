#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strnew(char * str, int newsize, char * newchar)
{
    int i = 0;
    char rez[newsize + 1];
    str[i] = '\0';
}

char * writeStr(char * str, char val)
{
    int len = strlen(str);
    int i = len;
    char *new = (char*)malloc(len + 1);
    new[len + 1] = '\0';
    while (i > 0)
    {
        new[i] = str[i - 1];
        i--;
    }
    new[i] = val;
    //free(str);
    return new;
//     str = (char*)malloc(len + 1);
//     *str = *new;
}


void ComandLine(char * str)
{    
    int i = 0;
    int strLen = strlen(str);

    char *strez = "\0";
    
    while (strlen(str) > 0)
    {
        //находим первый с конца =
        char *buf = strrchr(str, 61);
        int right = (strlen(buf) - 1);//получаем длину от равно    
        str[strlen(str) - (right + 1)] = '\0';//укорачиваем строку
        strez = writeStr(strez, (right + '0'));
        strez = writeStr(strez, '=');
        buf = strrchr(str, 32);//находим пробел
        int left;
        if (buf == NULL)//если строка пустая
        {
            left = strlen(str);
            str[0] = '\0';
            strez = writeStr(strez, left + '0');
            break;
        }
        else
        {
            left = strlen(buf);
            str[strlen(str) - left] = '\0';
            strez = writeStr(strez, ((left - 1) + '0'));
            strez = writeStr(strez, ' ');
        }      
    }

    //for (int i = 0; i < strlen(strez); i++)
      printf("%s\n", strez);
   
}

int main(int arg, char** arr) {
    //printf("Hello!\n");
    char str[] = "letters=A B Z T numbers=1 2 26 20 combine=true";
    ComandLine(str);
    return 0;
}