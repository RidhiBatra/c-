//print numbers till n 
//a.) decreasing      b.) increasing order
#include <iostream>
using namespace std;
void dec(int n){
    if(n==0){
        return ;
    }
    cout<< n << endl;
    dec(n-1);
}
void inc(int n){
    if(n==1){
        cout<<"1"<<endl;
        return ;
    }
    inc(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    dec(n);
    inc(n);
    return 0;
}

//check if an array is sorted or not
#include <iostream>
using namespace std;
bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool restArray = sorted(arr+1, n-1);
    return (arr[0]<arr[1] && restArray);
}
int main(){
    int arr[]={1,2,3,4,5};
    cout<<sorted(arr,5)<<endl;
    return 0;
}


//find the first and last occurance of a number in an array
#include <iostream>
using namespace std;
int firstocc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }return firstocc(arr,n,i+1, key);
}
int lastocc(int arr[],int n, int i,int key){
    int restArray = lastocc(arr,n,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key)
{
    return i;
}return -1;
}
int main(){
    int arr[]={4,2,1,2,5,2,7};
    cout<<firstocc(arr,7,0,2)<<endl;
    cout<<lastocc(arr,7,0,2)<<endl;
    return 0;}

    //reverse a sring using recursion  "binod"
    #include <iostream>
    using namespace std;
    void reverse(string s){
        if(s.length()==0){
            return ;
        }
        string ros = s.substr(1);
        reverse(ros);
        cout<<s[0];
    }
    int main(){
        reverse("binod");
        return 0;
    }



    //replace pi with 3.14 in string
    #include <iostream>
    using namespace std;
    void replacePi(string s){
        if(s.length()==0){
            return;
        }
        if(s[0]=='p' && s[1]=='i'){
            cout<<"3.14";
            replacePi(s.substr(2));
        }
        else{
            cout<<s[0];
            replacePi(s.substr(1));
        }
    }
    int main(){
        replacePi("pippppiiiipi");
        return 0;
    }

//remove all duplicates from the string
#include <iostream>
using namespace std;
string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans = removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return ch+ans;
}
int main(){
    cout<<removeDup("aaaaaaaaabbbeecdddd")<<endl;
    return 0;
}

//move all x to the end of the string
#include <iostream>
using namespace std;
string moveallX(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans= moveallX(s.substr(1));
    if(ch=='X'){
        return ans+ch;
    }return ch+ans;
}
int main(){
    cout<<moveallX("axxbdxcefxhisx")<<endl;
    return 0;
}

//generate all substrings of a string
#include <iostream>
using namespace std;
void subseq(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}
int main(){
    subseq("ABC","");
    cout<<endl;
    return 0;
}


//print all possible words from phone digits
#include <iostream>
using namespace std;
string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqr","stuv","wxyz"};
void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code = keypadArr[ch-'0'];
    string ros = s.substr(1);
    for (int i=0;i<code.length();i++){
        keypad(ros, ans + code[i]);
    }
}
int main(){
    keypad("23","");
    return 0;
}



//print all possible permutations of a string
#include <iostream>
using namespace std;
void permutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0; i<s.length();i++){
        char ch=s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        permutation(ros,ans+ch);
    }
}
int main(){
    permutation("ABC","");
    return 0;
}



//count the number of paths possible from start point to end point in gameboard
#include <iostream>
using namespace std;

int countPath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        countPath(s+i,e);
    }return count;
}
int main(){
    cout<<countPath(0,3)<<endl;
    return 0;
}

//count the number of paths possible in a maze
#include <iostream>
using namespace std;
int countPathMaze(int n, int i, int j){
    if(i==n && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }return countPathMaze(n,i+1,j) + countPathMaze(n,i,j);
}
int main(){
    cout<<countPathMaze(3,0,0)<<endl;
    return 0;
}

//tiling problrm
//given a "2*n" board and tiles of size "2*1" ,count the number of ways to tile the given board using these tiles
#include <iostream>
using namespace std;
int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==1){
        return 1;
    }return tilingWays(n-1) + tilingWays(n-2);
}
int main(){
    cout<<tilingWays(4)<<endl;
    return 0;
}

//freinds pairing problem
//find the number of ways in which n freinds can remain single or can be paired up.
#include <iostream>
using namespace std;
int freindsPairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }return freindsPairing(n-1) + freindsPairing(n-2)*(n-1);
}
int main(){
    cout<<freindsPairing(4)<<endl;
}

//0-1 knapsack problem
//put n items with given weight and value in a knapsack of capacity W to get the maximum total value in the knapsack
#include <iostream>
using namespace std;
int knapsack(int value[], int wt[],int n, int W){
    
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(value,wt, n-1, W);
    }
    return max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsack(value, wt, n-1,W));
}
int main(){
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<knapsack(wt,value,3,W)<<endl;
}


//tower of hanoi
#include <iostream>
using namespace std;
void towerofHanoi(int n, char src, char dest, char helper);{
    if(n==0){
        return 0;
    }
    towerofHanoi(n-1,src,helper,dest);
    cout<<"Move from"<<src<<" to "<<dest<<endl;
    towerofHanoi(n-1,helper,dest,src);
}
int main(){
    towerofHanoi(3,'A','C','B');
    return 0;
}




    



