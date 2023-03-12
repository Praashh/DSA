#include<iostream>
#include<vector>
using namespace std;

// Recursive Solution T.C-> 2^n*m S.C->O(length of path)

// int MinimumPathSum(vector<vector<int>>&mat, int i, int j){
//     if(i == 0 && j == 0){
//         return mat[i][j];
//     }
//     if(i < 0 || j < 0){
//         return 1e9;
//     }
//     int up = mat[i][j] + MinimumPathSum(mat, i-1, j);
//     int left = mat[i][j] + MinimumPathSum(mat, i, j-1);
//     return min(up, left);
// }

// Recursion + memoization , T.C->O(N*M) and S.C->O(n*M) + O(length of path)

int MinimumPathSum(vector<vector<int>>&mat, int i, int j, vector<vector<int>>&dp){
    if(i == 0 && j == 0){
        return mat[i][j];
    }
    if(i < 0 || j < 0){
        return 1e9;
    }
    if(dp[i][j] != 1e9){
        return dp[i][j];
    }
    int up = mat[i][j] + MinimumPathSum(mat, i-1, j, dp);
    int left = mat[i][j] + MinimumPathSum(mat, i, j-1, dp);
    return dp[i][j] = min(up, left);
}

// Tabular Solution T.C->O(N*M) S.C->O(N*M)
int MinimumPathSum(Vector<vector<int>>&mat){

}

int main()
{
    int n, m;
    cout << "Enter Row and Column Size of Matrix:" << endl;
    cin >> n >> m;
    vector<vector<int>>mat(m, vector<int>(n));
    vector<vector<int>>dp(m, vector<int>(n,1e9));

    cout << "Enter Matrix :" << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    cout << "Matrix is:" << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int ans = MinimumPathSum(mat, m-1, n-1, dp);
    cout << "Minimum Path Sum is:" << ans << endl;
    return 0;
}