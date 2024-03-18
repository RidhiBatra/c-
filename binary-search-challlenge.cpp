//binary search challenge 1
/* problem- given is an array with n elements that represents n positions along a straight line. find K elements such that the minimum distance between
any two elements is the maximum possible*/

/*approach- find all possible subset of size K and compare the minimum distance between all of them
binary search-- 1. sort the array for binary search technique
                2. pick middle element as result and check for its feasibility.
                3. if feasible, search the right half of the array with larger minimum distance.
                4. else, search the left half of the array.*/
                
                bool isFeasible(int mid, int arr[], int n, int k){
                    int pos = arr[0], elements = 1;
                    for(int i=1; i<n; i++){
                        if(arr[i] - pos >= mid){
                            pos = arr[i];
                            elements++;
                            if(elements == k){
                                return true;
                            }
                        }
                    }return false;
                }
                #include<iostream>
                #include<algorithm>
                using namespace std;
                 int largestMinDistance(int arr[], int n, int k){
                    sort(arr, arr+n);

                    int result = -1;
                    int left =1, right = arr[n-1];

                    while(left<right){
                        int mid = (left+right)/2;
                        if(isFeasible(mid, arr, n, k)){
                            result = max(result, mid);
                            left = mid+1;
                        }else{
                            right= mid;
                        }
                    }return result;
                 }
                 int main(){
                    int arr[] = {1,2.8,4,9};
                    int n=5;
                    int k=3;

                    cout<< "largest min distance is: " << largestMinDistance(arr, n, k) <<endl;
                    return 0;
                 }

                 //binary search challenge 2
                 //allocate minimum pages
                 /* n- number of pags in n different books(ascending order)
                    m- number of students
                    all the books have to be divided among m students, consecutively. allocate the pages in such a way
                    that maximum pages allocated to a student is minimum.*/

                    /* strategy- apply binary search for minimum & maximum possible value of 'max' pages.
                    check the feasibility of this chosen value.
                    
                    checking feasibility- assign pages to each student in a sequential manner, while the current number of allocate
                    pages dont exceed the value set by binary search.*/
                    #include<iostream>
                    #include<climits>
                    using namespace std;

                    bool isPossible(int arr[], int n, int m, int min){
                        int studentsRequired = 1, sum =0;
                        for(int i=0; i<n; i++){
                            if(arr[i] > min){
                                return false;
                            }
                            if(sum+arr[i] > min){
                                studentsRequired++;
                                sum = arr[i];
                                if(studentsRequired > m){
                                    return false;
                                }
                            }else{
                                sum+= arr[i];
                            }
                        }return true;
                    }

                    int allocateMinimumPages(int arr[], int n, int m){
                        int sum = 0;
                        if(n<m){
                            return -1;
                        }
                        for(int i=0; i<n; i++){
                            sum = sum + arr[i];
                        }
                        int start = 0, end = sum, ans= INT_MAX;
                        while(start <= end){
                            int mid = (start + end)/2;
                            if(isPossible(arr, n, m, mid)){
                                ans = min(ans, mid);
                                end = mid-1;
                            }else{
                                start = mid+1;
                            }
                        }return ans;
                    }
                    int main(){
                        int arr[] = {12, 34, 67, 90};
                        int n = 4;
                        int m = 2;
                        cout<<"the minimum no. of pages: "<<allocateMinimumPages(arr, n, m)<<endl;
                        return 0;
                    }
//Painter's partition problem
/* n- length of n different boards
m- painters available
A painter paints 1 unit of board in 5 unit of time & each painter will paint consecutive boards.
find the minimum time that will be reqd to paint all the boards*/

/* strategy- apply binary search for minimum & maximum psbl values of 'min' length of board
to be painted. check the feasibilty of this chosen value

checking feasibility- assign board to each painter in a sequential manner, while the current length
of assigned boards dont exceed the value set by binary search.*/
#include<iostream>
int findFeasible(int boards[], int n, int limit){
    int sum = 0, painters = 1;
    for(int i=0; i<n; i++){
        sum += boards[i];
        if(sum>limit){
            sum = boards[i];
            painters++;
        }
    }return painters;
}
using namespace std;
int paintersPartition(int boards[], int n, int m){
    int totalLength = 0, k=0;
    for(int i=0; i<n; i++){
        k= max(k, boards[i]);
        totalLength += boards[i];
    }
    int low = k, high = totalLength;
    while(low <high){
        int mid = (low + high)/2;
        int painters = findFeasible(boards, n, mid);
        if(painters <= m){
            high = mid;
        }else{
            low = mid -1;
        }
    }return low;
}
int main(){
    int arr[] = {10,20,30,40};
    int n =4;
    int m=2;
    cout << " Minimum time to paint boards: "<< paintersPartition(arr, n, m);
    cout<<endl;
    return 0;
}

//search element in sorted & rotated array
/* we are given an ascending sorted array that has been rotated from a pivot point(unknown to us) and
an element X. search for X in the array with complexity less than that of linear search*/

/* find the pivot point
apply binary search in left half
apply binary search in right half

finding pivot- only element that will be greater than its next element i.e. 
arr[i] > arr[i+1], i<=n-1  */
#include<iostream>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right){
    if(left>right){
        return -1;
    }
    int mid = (left+right)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left] <= arr[mid]){
        if(key >= arr[left] && key <= arr[mid]){
            return searchInRotatedArray(arr, key, left, mid-1);
        }
        return searchInRotatedArray(arr, key, mid+1, right);
    }
    if(key >= arr[mid] && key <= arr[right]) {
        return searchInRotatedArray(arr, key, mid+1, right);
    }
    return searchInRotatedArray(arr, key, left, mid-1)
}
int main(){
    int arr[] = {6,7,8,9,10,1,2,5};
    int n= 8;
    int key = 8;
    int idx = searchInRotatedArray(arr,key , 0, n-1);
    if(idx == -1){
        cout << "key doesmt exist" << endl;
    }else{
        cout << "key is present at idx: " << idx << endl;

    }return 0;
}

//find the peak element
/* for a given array, find the peak element in the array. Peak element is one which is 
greater then both, left and right neighbours of itself. 

ascending array: last element is peak
descending array: last element is peak 
for all same element: each element is peak 

strategy 
use binary search, analyze indices from 0 to n-1
compute mid & for each mid check if arr[mid] is a peak element

else if arr[mid-1] > arr[mid], check left for peak
else if arr[mid] < arr[mid+1], check right for peak*/
#include<iostream>
using namespace std;

int findpeakElement(int arr[], int low, int high, int n){
    int mid = low+(high-low)/2;

    if ((mid==0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])){
        return mid;
    }
    else if(mid >0 && arr[mid-1] > arr[mid]){
        return findPeakElement(arr, low, mid-1, n);
    }
    else{
        return findPeakElement(arr, mid+1, high, n);
    }
}
int main(){
    int arr[] = {0,6,8,5,7,9};
    int n=6;
    cout<<" peak element index : "<< findPeakElement(arr,0,n-1, n)<<endl;
    return 0;
}

//max sub array of size = k & sum < x
/* for a given array and integers K & x, find the maximum sum subarray of size K and having
sum less than X. 

approaches:
1. compute sum of all possible subarray of size K(time complexity = 0(n*K))
2. a. Calculate sum of first K elements 
    b. Initialize ans with this sum
    c. Iterate over the rest of the arr keep adding one element in sum & removing one from start
        compare new sum with ans in each iteration */
#include <iostream>
using namespace std;
void maxSubarraySum(int arr[], int n, int k, int x){
int sum = 0, ans = 0;
for(int i=0; i<k; i++){
    sum += arr[i];
}
if(sum < x){
    ans = sum;
}
for(int i=k; i<n; i++){
    sum = sum - arr[i-k];
    sum = sum + arr[i];
    if(sum < x){
        ans = max(ans, sum);
    }
}
cout << ans << "is the max subaray sum (<x)" <<endl;        
}
int main(){
    int arr[] = {7,5,4,6,8,9};
    int k =3;
    int x=20;
    int n=6;

    maxSubarraySum(arr, n, k, x);
    return 0;
}
//smallest subarray with sum > x
/* for a given array and an integer X, find the minimum subarray size for which sum>X

approach:
1.compute sum of all subarrays & check the condition    (time complexity= 0(n^2))
2. a. use variables ans,sum & start
   b. Iterate over array & start adding elements to sum
   c.if sum>X, remove elements form the start*/
   #include<iostream>
   using namespace std;

   int smallestSubarrayWithSum(int arr[], int n, int x){
    int sum = 0, minLength = n+1, start = 0, end =0;
    while(end < n){
        while(sum <=x && end<n){
            sum += arr[end++];
        }
        while(sum > x && start < n){
            if(end - start < minLength){
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
   }
   int main(){
    int arr[] = {1, 4, 45, 6, 10, 18};
    int x = 51;
    int n = 6;
    int minLength = smallestSubarrayWithSum(arr, n, x){
            if(minLength == n+1){
        cout << " no such subarray exists" << endl;
    }else{ cout << "smallest length subarray is: " <<minLength << end l;}
   }return 0;}

   //Number formed from subarray of size K, divisble by 3
   /* For a given array and an integer K, check if any subarray of size K exists in the array such that
   elements in the subarray form a number divisble by 3.
   
   approach:
   1. sum of initial K elements from the array
   2. use sliding window technique and one by one, start subtracting
   elemnts from the end & adding from the end
   3. at each step, check if sum divisible by 3 or not. if it is print the elements */
   #include<iostream>
   #include<vector>
   using namespace std;
   void computeNumberFromSubarray(vector<int> arr, int k){
    pair<int, int>ans;
    int sum = 0;

    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    bool found = false;
    if(sum%3 == 0){
        ans = make_pair(0, k-1);
        found = true;
    }
    for(int j=k; j<arr.size(); j++){
        if(found){
            break;
        }
        sum = sum + arr[j] - arr[j-k];
        if(sum%3 == 0){
            ans = make_pair(j-k+1, j);
            found = true;
        }
    }
    if(!found){
        ans = make_pair(-1, 0);
    }
    if(ans.first == -1){
        cout << "no such subarray exists" << end l;
    }
    else{
        for(int i=ans.first; i<=ans.second; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
   }
   int main(){
    vector<int> arr= {84,23,45,12,56,82};
    int k=3;
    computeNumberFromSubarray(arr, k);
    return 0;}

    //Subarray of size K with palindromic concatenation
    /* for a given array and an integer K, check if any subarray of size K exist in the array such that
    concatenation of elements form a palindrome*/
     
    /*approaches
    generate all subarrays of size K (time comlexity 0(n^2)) check if their concatenation forms a palindrome
    2. a. store concatentaion of initial K lements
       b. Iterate over the array & start deleting elemets form the start and adding elements form the end
       c. at each step, check if concatenation is a palindrome */
       #include <iostream>
       #include<vector>
       #include<math>
       using namespace std;
       bool isPalindrome(int n){
        int temp = n, number = 0;
        while(temp>0){
            number = number*10 + temp%10;
            remp = temp/10;
        }
        if(number==n){
            return true;
        }return false;
       }

       int findPalindromeSubarray(vector<int> arr, int k){
        int num = 0;
        for(int i=0; i<k; i++){
            num = num*10 + arr[i];
        }
        if(isPalindrome(num)){
            return 0;
        }
        for(int j=k; j<arr.size(); j++){
            num = (num % (int)pow(10, k-1))*10 + arr[j];
            if(isPalindrome(num)){
                return j-k+1;
            }
        }return -1;
       } 
       int main(){
        vector<int> arr={2,3,5,1,1,5};
        int k = 4;
        int ans = findPalindromicSubarray(arr, k);if(ans== -1){
            cout<< " palindromic subarray doesn't exist" << end l;
        }
        else{
            for(int i=ans; i<ans+k; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }return 0;
       }

       //maximum perfect number in length K

       /* Approach 1
       Generate all the subarrays of size K &count number of perfect numbers(time complexity- 0(n*K))
       trick- Convert the given array into a binary array with values 0 & 1 only. 
       approach 2
       Transverse the array & if the number at index i is a perfect number then replace 
       value at ith index with '1' else with a '0'. */
       #include<iostream>
       #include<math>
       using namespace std;
       bool isNumberPerfect(int n){
        int sum = 1;
        for(int i=2; i<sqrt(n); i++){
            if(n%i == 0){
                if(i == n/i){
                    sum += i;
                }else{
                    sum += i + n/i;
                }
            }
        }
        if(sum == n && n!=1){
            return true;
        }return false;
       }
       int maxSum(int arr[], int n, int k){
        if(n<k){
            cout<< "invalid values"<<endl;
            return -1;
        }
        int res =0;
        for(int i=0; i<k; i++){
            res += arr[i];
        }
        int sum = res;
        for(int i=k; i<n; i++){
            sum += arr[i] - arr[i-k];
            res = max(res, sum);
        }return res;
       }
       int maxNumberOfPerfects(int arr[], int n, int k){
        for(int i=0; i<n; i++){
            if(isNumberPerfect(arr[i])){
                arr[i] = 1;
                if(isNumberPerfect(ar[i])){
                    arr[i] = 1;
                }else{
                    arr[i] = 0;
                }
            }
        }return maxSum(arr, n,k);
       }
       int main(){
        int arr[] = {29,2,3,6,496,99,8128,24};
        int k=4;
        int n= 8;
        cout << maxNumberOfPerfects(arr, n, k)<<endl;
        return 0;
       }