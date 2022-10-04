// QUESTION -.Given a string S, Check if characters of the given string can be rearranged to form a palindrome.
// Note: You have to return 1 if it is possible to convert the given string into palindrome else return 0.

// Example 1:

// Input:
// S = "geeksogeeks"
// Output: Yes
// Explanation: The string can be converted
// into a palindrome: geeksoskeeg

// Approach -> Using hash map we will store th frequency of each cherecter and if a charecter repeted more than on time then it will not rearranged palindrome.

// The Time Complexity will be O(S) S= size of String and Space Complexity will be O(Distinct Characters)

int isPossible(string S)
{
    unordered_map<char, int> mp;
    for (auto x : S)
    {
        mp[x]++;
    }

    int count = 0;

    for (auto x : mp)
    {
        if (x.second % 2 != 0)
        {
            count++;
        }
    }
    // if count>1 then return false as 0 otherwise return true as 1
    return count > 1 ? 0 : 1;
}
