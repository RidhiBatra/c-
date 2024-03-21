//write a program to check if a given number is power of 2
#include <iostream>
using namespace std;
bool ispowerof2(int n){
    return (n && !(n & n-1));     //(n-1 & n) has same bits as n except the rightmost set bit
}                                // n has only one set bit,and n-1 will have all set bits after that position

int main(){
    cout<< ispowerof2(14) << endl;
    return 0;
}


//write a program to count the number of ones in binary representation of a number
#include <iostream>
using namespace std;
int numberofones(int n){
    int count=0;
    while(n){
        n=n & (n-1);
        count++;
    }return count;
}
int main(){
    cout<<numberofones(19)<<endl;
    return 0;
}


//write a program to generate all possible subsets of a set
#include <iostream>
using namespace std;
void subsets(int arr[], int n){
    for(int i=0; (i<<n);i++){
        for(int j=0;j<n;j++){
        if(i & (1<<j)){
            cout<<arr[j]<<" ";
        }
    }cout<<endl;
}}
int main(){
    int arr[4] = {1,2,3,4};
    subsets(arr,4);
    return 0;
}

//write a program to find a unique number in an array where all numbers except one, are present twice {2,4,6,3,4,6,2}
#include <iostream>
using namespace std;
int unique(int arr[], int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}
int main(){
    int arr[]= {1,2,3,4,1,2,3};
    cout<<unique(arr,7)<<endl;
    return 0;
}

//write a program to find 2 unique numbers in an array where    all numbers except two, are present twice
#include <iostream>
using namespace std;
int setBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}
void unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }
    int tempxor=xorsum;
    int setBit=0;
    int pos=0;
    while(setBit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i], pos-1)){
            newxor=newxor^arr[i];
        }
        
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
    return 0;
}