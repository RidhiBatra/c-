//lowercase to uppercase or viceversa
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str = "gddgfbdseraethbsresf";
    //convert into uppercase
    for(int i =0; i<str.size(); i++)
    {
        if(str[i] >= 'a' && str[i]<= 'z')
        str[i] -= 32;
    }
    cout<<str <<endl;
    //convert to lowercase
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'A' && str[i] <='Z')
        str[i] += 32;
    }cout << str <<endl;
    return 0;

}

//form the biggest number from the numeric string
int main(){
    string s = "1683298326585";
    sort(s.begin(), s.end(), greater<int>());
    cout<<s<<endl;
    return 0;
}

// input maximum occur alphabet
int main(){
    string s= " hhfdgkjhfjhbkjnlhiut";
    int freq[26];
    for(int i=0; i<26; i++)
    freq[i] = 0;
    for(int i=0; i<s.size(); i++)
    freq[s[i] - 'a']++;
    char ans = 'a';
    int maxF = 0;
    for(int i=0; i<26; i++){
        if(freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i+'a';
        }
    }
    cout << maxF << " " << ans <<endl;
    return 0;
}