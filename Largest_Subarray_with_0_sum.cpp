// QUESTION->Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.

// Brute Force Approach-> Generate All the subarray and calculate the sumof every subarray 
// if sum==0 then calculate the maximum length of subarray that is calculating by this (j-i+1) and after every traversal return max length

// T.C->O(N^2) and S.C->O(1)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxi=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=A[j];
                if(sum==0){
                    maxi=max(maxi,j-i+1);
                }
                
            }
        }
        return maxi;
    }
};


// Optimize Approach Using unordered_map
// T.C->O(N*log(N)) and S.C->O(N)


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    maxi=max(maxi,i-mp[sum]);
                }
                else{
                    mp[sum]=i;
                }
            }
        }
        return maxi;
    }
};