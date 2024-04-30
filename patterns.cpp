//rectangle pattern
#include <iostream>

using namespace std;

int main()
{
    int row,col;
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cout<<"*";
        }cout<<endl;
    }

    return 0;
}


//hollow rectangle pattern
#include<iostream>
using namespace std;
int main(){
    int row,col;
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1||i==row||j==1||j==col){
                cout<<"*";}
                else{cout<<" "}
            }cout<<endl;
        }return 0;
    }


    //inverted half pyramid
    #include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }cout<<endl;
    }
    
    
    return 0;
    }


//half pyramid after 180degree rotation
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i) {
                cout<<" ";
            }else{cout<<"*";
        }}cout<<endl;
    }
    
    
    return 0;
    }


//pyramid using numbers
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }cout<<endl;
    }
    
    
    return 0;
    }


//floyd's triangle
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";count++;
        }cout<<endl;
    }
    
    
    return 0;
    }


    //butterfly pattern
    #include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }int space=2*n-2*i;
        for(int j=1;j<=space;j++){
            cout<<" ";
        }for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }int space=2*n-2*i;
        for(int j=1;j<=space;j++){
            cout<<" ";
        }for(int j=1; j<=i; j++){
            cout<<"*";}
        cout<<endl;
    }
    
    
    return 0;
    }


    //zigzag pattern
    #include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(((i+j)%4==0) || (i==2 && j%4==0)){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}



//star pattern
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
           cout<<" ";}
           for(int j=1;j<=2*i-1;j++){
               cout<<"*";
           }
        cout<<endl;
    }
    for (int i=1;i>=n;i--){
        for(int j=1;j<=n-i;j++){
           cout<<" ";}
           for(int j=1;j<=2*i-1;j++){
               cout<<"*";
           }
        cout<<endl;
    }


    return 0;
}
//palindrome number
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int j;
        for(j=1;j<=n-i;j++){
            cout<<" ";
        }
        int k=i;
        for(;j<=n;j++){
        cout<<k--<<" ";
    }
    k=2;
    for(;j<=n+i-1;j++){
        cout<<k++<<" ";}
        cout<<endl;
    }
    return 0;
}



//number pattern
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
       cout<<endl;
    }
    return 0;
}


//Rhombus pattern
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
       cout<<endl;
    }
    return 0;
}


//0-1 pattern
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=i;j++){
           if((i+j)%2==0){
               cout<<" 1";
           }
           else{
               cout<<" 0";
           }}
       cout<<endl;
    }
    return 0;
}


//Pascal Triangle
#include <iostream>
using namespace std;
int fact(int n){int factorial=1;
for(int i=2;i<=n;i++){
    factorial*=i;
} return factorial;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }cout<<endl;
    }return 0;
}
