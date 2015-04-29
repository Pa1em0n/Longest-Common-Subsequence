#include <stdlib.h>
#include <stdio.h>

int max(int x, int y){
  return(x > y)? x : y;
}

int LCS(char *A, int m, char *B, int n){
  
  if((m ==0) || (n == 0)){
    return 0;
  }
 
  int matriz[n+1][m+1];
  int i, j;
  for( i = 0; i< n+1; i++){
    matriz[i][0] = 0;
  }
  for(j = 0; j< m+1; j++){
    matriz[0][j] = 0;
  }
  
  for(i = 1; i<n+1; i++){
    for(j = 1; j<m+1; j++){
      if(A[i-1] == B[j-1]){
	matriz[i][j] = matriz[i-1][j-1] + 1;
      }else{
	matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1]);
      }
    }
}

  return matriz[m][n];
}

int main(){
  
  char A[]={"A scrambled version 13, 3, 2, 21, 1, 1, 8, 5 (OEIS A117540) of the first eight Fibonacci numbers appear as one of the clues left by murdered "};

  char B[]={"museum curator Jacque Sauniere in D. Brown's novel The Da Vinci Code (Brown 2003, pp. 43, 60-61, and 189-192). In the Season 1 episode "};
 
  int n = strlen(A);
  int m = strlen(B);
  printf("Longest common substring: %d\n",LCS(A,m,B,n));
  return 0;
}
