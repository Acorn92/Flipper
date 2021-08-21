#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void EquivalentKeypresses(char * strArr[], int arrLength) {
  
  // code goes here  
  //разбиваем на две строки
  char *str1;
  char *str2;
  int start = -1;
  int end = -1;
  int i = 0;
  int len1 = strlen(strArr[0]);
  int len2 = strlen(strArr[1]);

      //проверяем на наличие символов -B
    for (int i = 0; i < arrLength; i++)
    {
        int lenStrArr = strlen(strArr[i]);
        char *buf = strstr(strArr[i], "-B"); 
        while(buf != NULL)
       // if (buf != NULL)
        {
            char *buf1;
            //удалим из строк возможные символы -В формируя конечный вид введённой строки    
            int lenBuf = strlen(buf);
            int lenStr = lenStrArr - lenBuf;
            if (lenStr == 0)//tесли символ удаления вначале
            {
                buf1 = (char*)malloc(len2 - 3);//удалим символ удаления
                memcpy(buf1, strArr[i] + 3, len2 - 3);
            }
            else
            {
                //сохраним строку после символа удаления
                char *strnew = (char*)malloc(lenBuf - 2);
                strnew = strncpy(strnew, buf + 2, (lenBuf - 2));

                buf1 = (char*)malloc(len2);    
                memcpy(buf1, strArr[i], len2);
                if (lenStr == 2)
                    buf1[1] = '\0';//если удалили первый элемент, то левая часть строки пустая
                else
                    buf1[lenStr - 3] = '\0';//затираем элемент перед символом удаления
                buf1 = strcat(buf1, strnew);
                //free(*strArr[i]);
            }
            strArr[i]=buf1;
            lenStrArr = strlen(strArr[i]);
            //strArr[i] = strcpy(strArr[i], buf1);
            //free(buf1);
            buf = strstr(strArr[i], "-B");
        }
        printf("%s \n", strArr[i]);
    }


  //str1, str2


  //сравниваем получившиеся строк
  //выводим результат


}

int main(void) { 
   
  // keep this function call here
  char * A[] = {"a,b,c,d", "a,b,c,d,-B,d"};
  char *A1[] = {"c,a,r,d", "c,a,-B,r,d"};
  char *A2[] = {"q,w,e,r,t,y", "-B,-B,q,w,w,-B,e,r,t,y"};
  char *A3[] = {"p,o,i,n,-B,t", "-B,p,o,i,t"};
  char *A4[] = {"u,m,b,r,r,-B,e,l,l,a", "u,m,b,b,-B,r,e,l,l,a"};
  char *A5[] = {"", "-B,-B,-B"};
  char *A6[] = {"a,e,i,o,u", "a,-B,e,i,o,u"};
  char *A7[] = {"s,t,r,e,e,t", "-B,s,s,-B,t,r,e,e,t"};
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  int arrLength1 = sizeof(A1) / sizeof(*A1);
  int arrLength2 = sizeof(A2) / sizeof(*A2);
  int arrLength3 = sizeof(A3) / sizeof(*A3);
  int arrLength4 = sizeof(A4) / sizeof(*A4);
  int arrLength5 = sizeof(A5) / sizeof(*A5);
  int arrLength6 = sizeof(A6) / sizeof(*A6);
  int arrLength7 = sizeof(A7) / sizeof(*A7);
  EquivalentKeypresses(A, arrLength);
  EquivalentKeypresses(A1, arrLength1);
  EquivalentKeypresses(A2, arrLength2);
  EquivalentKeypresses(A3, arrLength3);
  EquivalentKeypresses(A4, arrLength4);
  EquivalentKeypresses(A5, arrLength5);
  EquivalentKeypresses(A6, arrLength6);
  EquivalentKeypresses(A7, arrLength7);
  return 0;
    
}