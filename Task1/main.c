#include <stdio.h>

#include <string.h>


void ComandLine(char * str)
{    
    int i = 0;
    int strLen = strlen(str);

    char *strez;
    //получаем позицию последнего пробела
    //int i = strrchr(str, "=");
    //получаем значения после пробела
   // char *buf[strLen - i];
    //memcpy(buf, str, strlen(buf));

    char *buf = strrchr(str, 61);
    int len1 = strlen(str);
    int len2 = strlen(buf);
    int len3 = len1 - len2;
    char *newstr;
    memcpy(newstr, str, len3);
    // while (str[i] != '\n')
    // {
    //     int posf = 0
    //     if (str[i] == '=')
    //     {
    //         int leftCount = i; // размер слева
            
            

    //         i = posF;
    //         printf("%d\n", leftCount);
    //     }
    //     i++;
    // }
    
    //printf("%\d\w", str);
}

int main(int arg, char** arr) {
    //printf("Hello!\n");
    char str[] = "line=line2";
    ComandLine(str);
    return 0;
}
