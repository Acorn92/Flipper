#include <stdio.h> 
#include <string.h>

void RectangleArea(char * strArr[], int arrLength) 
{
  
    //найти ширину
    int width = 0;
    int height = 0;
    int arrX[2] = {0, 0};
    int arrY[2] = {0, 0};
    int xmin, xmax, ymin, ymax;
    for (int i = 0; i < arrLength; i++)
    {
        char *numb = (strchr(strArr[i], ' ') + 1);
        int lenY = strlen(numb);
        char *y = (char*)malloc(lenY - 1);
        y = strncpy(y, numb, (lenY - 1));
        char *x = (char*)malloc(strlen(strArr[i]) - (lenY + 1));
        x = strncpy(x, strArr[i] + 1, (strlen(strArr[i]) - (lenY + 2)));
        if (i == 0)
        {
            xmax = (int)(*x - '0');
            xmin = xmax;
            ymax = (int)(*y - '0');
            ymin = ymax;
        }

        if (((int)(*x - '0') > xmin) && ((int)(*x - '0') < xmax))
        //if ((int)(*x - '0') < xmin)
            xmin = (int)(*x - '0');
            //xmax = (int)(*x - '0');

        if ((int)(*x - '0') > xmax)
            xmax = (int)(*x - '0');
                    
        if (((int)(*y - '0') > ymin) && ((int)(*y - '0') < ymax))
            ymin = (int)(*y - '0');

        if ((int)(*y - '0') >= ymax) 
            ymax = (int)(*y - '0');
        



    }
    width = xmax - xmin;
    height = ymax - ymin;
    int S = height * width;
    //strArr[i]
  //найти высоту
    printf("%d\n", S);

}

int main(void) { 
   
  // keep this function call here
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  char * A[] = {"(1 1)","(1 3)","(3 1)","(3 3)"};
  char * A1[] = {"(0 0)","(1 0)","(1 1)","(0 1)"};
  char * A2[] = {"(0 0)","(0 0)","(0 0)","(0 0)"};
  int arrLength = sizeof(A) / sizeof(*A);
  int arrLength1 = sizeof(A1) / sizeof(*A1);
  int arrLength2 = sizeof(A2) / sizeof(*A2);
  RectangleArea(A, arrLength);
  RectangleArea(A1, arrLength1);
  RectangleArea(A2, arrLength2);
  return 0;
    
}