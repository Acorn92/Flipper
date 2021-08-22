#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cstdlib>
using namespace std;


void countHoles(string strArr[], int arrSize, int i, int j, int count)
{
  strArr[i][j] = static_cast<char>(count);//
  //проверка влево
  if ((strArr[i][j-1] == '0') && (j != 0))
  {
    //  strArr[i][j-1] = static_cast<char>(count);
    strArr[i][j-1] = (char)(count + '0');
    countHoles(strArr, arrSize, i, (j-1), count);
  }
  //проверка вправо
  if ((strArr[i][j+1] == '0') && (j < (strArr[i].size() - 1)))
  {
    // strArr[i][j+1] = static_cast<char>(count);
    strArr[i][j+1] = (char)(count + '0');
    countHoles(strArr, arrSize, i, (j+1), count);
  }
  //проверка вверх
  if ((strArr[i+1][j] == '0') && (i < (arrSize - 1)))
  {
    // strArr[i+1][j] = static_cast<char>(count);
    strArr[i+1][j] = (char)(count + '0');
    countHoles(strArr, arrSize, (i+1), j, count);
  }
  //проверка вниз
  if ((strArr[i-1][j] == '0') && (i != 0))
  {
    // strArr[i-1][j] = static_cast<char>(count);
    strArr[i-1][j] = (char)(count + '0');
    countHoles(strArr, arrSize, (i-1), j, count);
  } 
}
int BitmapHoles(string strArr[], int arrLength) {
  
 // unordered_map<int, pair<int, int>>mp;
  int countH = 2;//т.к. 0 и 1 значения внутри матрицы
  for (int i = 0; i < arrLength; i++)        
      for (int j = 0; j < strArr[i].size(); j++)
      {
        if (strArr[i][j] == '0')
          countHoles(strArr, arrLength, i, j, countH++);
      }
  for (int i = 0; i < arrLength; i++)
      cout << strArr[i] << endl;  

  // code goes here  
  return countH;

}

int main(void) { 
   
  // keep this function call here
  //string A[] = coderbyteInternalStdinFunction(stdin);
  string A[] = {"10111", "10101", "11101", "11111"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << BitmapHoles(A, arrLength) << endl;
  return 0;
    
}