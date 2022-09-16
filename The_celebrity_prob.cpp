// Approach 1:-
// T.C-> O(n*n)
// S.C-> o(1)
int celebrity(vector<vector<int>> &M, int n)
{
    int ans;
    int count = 0;
    bool flage = true;

    for (int i = 0; i < n; i++)
    {
        flage = true;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                flage = false;
                break;
            }
        }
        if (flage == true)
        {
            count++;
            ans = i;
        }
    }
    if (count == 0 || count > 1)
    {
        return -1;
    }
    return ans;
}

// Approach 2 Using Stack
// T.C-> O(N)
// S.C-> O(N)

class Solution
{
public:
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // step -> 1 push all element in stack
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        //step-> 2 Ca
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        // single element in stack is potential celebrity
        // verifiy it 
        int candidate = s.top();
        // count zero's
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] == 0)
            {
                zero++;
            }
        }
        if (zero != n)
        {
            return -1;
        }
        // count one's
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][candidate] == 1)
            {
                one++;
            }
        }
        if (one != n - 1)
        {
            return -1;
        }
       return candidate;
    }
};