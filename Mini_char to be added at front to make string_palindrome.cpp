// QUESTION->Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
// Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

// Example 1:

// Input:
// S = "abc"
// Output: 2
// Explanation: 
// Add 'b' and 'c' at front of above string to make it
// palindrome : "cbabc"
// Example 2:

// Input:
// S = "aacecaaa"
// Output: 1
// Explanation: Add 'a' at front of above string
// to make it palindrome : "aaacecaaa"


#include<iostream>
using namespace std;

 bool ispalindorm(string s,int end){
        int start=0;
        
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    // T.C-> O(N^2) and S.C->O(N)
    int minChar(string str){
       int end=str.length()-1;
       
       while(end>=0){
           if(ispalindorm(str,end)){
               return str.length()-1-end;
           }
           end--;
       }
       return -1;
    }
    // T.C->O(N) and S.C->O(N)
int MinChar(string str){
      int low=0;
      int high=str.length()-1;
      int ans=0;
      while(low<=high){
          if(str[low]==str[high]){
              low++;
              high--;
          }
          else{
              ans=str.length()-high;
              low=0;
          while(str[low]==str[high]){
             ans--;
             low++;
          }
          high--;
          }
      }
      return ans;
    }
int main()
{
    string s;
    cin>>s;
   cout<<MinChar(s)<<endl;
   return 0;
}