// QUESTION-> You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

// Example 1:

// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are
// [0], [0], [0], [0], [0,0], and [0,0].

// Brute Force Appproach -> We will Itrate loop for every subarray and count the Subarray with Zero Sum
// T.C->O(N^2) and S.C->O(1)

class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {

        ll count = 0;
        for (int i = 0; i < n; i++)
        {
            ll sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += arr[j];

                if (sum == 0)
                    count++;
            }
        }
        return count;
    }
};

// Optimize Approach -> Using  HashMap We will able to Solve this Problem

// T.C->O(N) and S.C->O(N)

class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        unordered_map<ll, int> mp;
        ll count = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == 0)
            {
                count++;
            }
            if (mp.find(sum) != mp.end())
            {
                count += mp[sum];
            }

            mp[sum]++;
        }

        return count;
    }
};