// Brute-Force -> Traverse Every Element and Find Duplicate of this.
// T.C->O(N^2) and S.C->O(1)

// Optimize Approach->Using Map I will able to Store the Frequency of Every Element
// T.C->O(N) and S.C->O(N)

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;

    for (auto x : mp)
    {
        if (x.second > 1)
        {
            ans.push_back(x.first);
        }
    }
    return ans;
}