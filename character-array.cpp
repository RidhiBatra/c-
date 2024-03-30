//check palindrome racecar
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    char arr[n+1];
    cin>> arr;
    bool check = 1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] != arr[n-1-i])
        {
            check=0;
            break;
        }
    }
    if(check == true)
    cout << "word is a palindrome" << endl;
    else{
        cout << " word is not a palindrome" << endl;

    }return 0;
}


//largest word in a sentence
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    int i=0;
    int currlen=0, maxlen = 0;
    int st=0, maxst=0;
    while(1)
    {
        if(arr[i]==' ' || arr[i] == '\0')
        {
            if(currlen > maxlen)
            {
                maxlen = currlen;
            }currlen = 0;

        }else
        currlen++;
        if(arr[i] == '\0')
        break;
        i++;
    }cout<< maxlen <<endl;
    return 0;
}

