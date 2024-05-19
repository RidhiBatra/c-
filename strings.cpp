#include <iostream>
#include <string>
 using namespace std;
 int main(){
    string s1 = "fam";
    string s2 = "ily";

    //add
    s1.append(s2);
    cout << s1 << endl;
    //access any alphabet
    cout << s1[1] << endl;
    //clear a string
    s1.clear();
    cout << s1;
    //compare 2 strings
    cout << s2.compare(s1) << endl;
    //check if string is empty
    s1.empty();
    //erase
    s1.erase(3,3);
    //find
    s1.find();
    cout << s1.find() << endl;
    //insert any string
    s1.insert (2, "lol");
    cout << s1 <<endl;
    //length
    s1.size();
    s1.length();
    //substring
    string s = s1.substr(6,4);
    cout << s <<endl;
    //string to integer
    stoi(s1);
    //integer to string
    to_string(s1) + "2";
    //sort
    #include <algorithm>
    sort(s1.begin(), s1.end());



    return 0;
 }