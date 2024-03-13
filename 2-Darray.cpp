//spiral order matrix traversal
#include <iostream>
using namespace std;
signed main()
{
    int n,m;
    cin >> n >> m;

    int a[n][m];

    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        cin>> a[i][j];
    } 
    //spiral order print
     int row_start = 0, row_end = n-1, column_start = 0, column_end = m-1;
     while( row_start <= row_end && column_start <= column_end){

     
      //for row_start
     for(int col= column_start; col<= column_end; col++)
        {cout<< a[row_start][col]<< " ";
     }
     row_start++;

     //for column_end
     for(int row= row_start;  row <= row_end; row++)
     cout << a[row][column_end] << " ";
     column_end--;

     //for row_end
     for(int col = column_end; col>= column-start; col--)
     cout << a[row_end][col] << " ";
     row_end--;

     //for column_start
     for(int row = row_end; row>= row_start; row--)
     {
        cout << a[row][column_start] << " ";
     }
     column_start++;
}return 0;
}


//matrix transpose
#include <iostream>
using namespace std;
int main(){
   int A[3][3] ={{3,3,3},{4,5,6},{7,8,9}};
   for(int i=0;i<3;i++){
      for (int j=i;j<3;j++){
         //swap
         int temp = A[i][j];
         A[i][j] = A[i][j];
         A[i][j] = temp;
      }
   } 

   //print
   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
         cout << A[i][j] << " "; }
   cout << "\n";}
   return 0;
}



//matrix multiplication
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main(){
   int n1,n2,n3;
   cin >> n1 >> n2 >> n3;
   int m1[n1][n2];
   int m2[n2][n3];

   for(int i=0; i<n1; i++)
   {
      for(int j=0; j<n2; j++)
      cin>> m1[i][j];
   }
    for(int i=0; i<n2; i++)
   {
      for(int j=0; j<n3; j++)
      cin>> m2[i][j];
   }
   int ans[n1][n3];
   for(int i=0; i<n1; i++)
   { for(int j=0; j<n3; j++)
    ans [i][j]=0;
   }
   for (int i=0; i<n1; i++){
      for(int j=0; j<n3; j++){
         for(int k=0; k<n2; k++){
            ans[i][j] += m1[i][k]*m2[k][j];
         }
      }
   }
   for(int i=0; i<n1; i++){
      for(int j=0; j<n3; j++)
      cout<< ans[i][j]<< " ";
      cout << endl;
   }return 0;
}

//matrix search
#include <iostream>
#include "bits/stdc++.h"
using namespace std; 
int32_t main(){
   int n,m;
   cin>> n>> m;
   int target;
   cin >> target;
   int mat[n][m];
   for (int i=0; i<n; i++){
      for(int j=0; j<m;j++){
         cin>> mat[i][j];
      }
   }
   int r=0, c=m-1;
   bool found = false;
   while( r<n and c>=0){
      if(mat[r][c]==target){
         founf=true;
      }
      if (mat[r][c] > target){
         c--;
      }else{
         r++;
      }
   }
   if(found)
   cout<< " Element found";
   else{
      cout<< "Element does not exist";
   }
}
