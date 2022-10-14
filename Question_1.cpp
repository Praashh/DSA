// Reverse an Array

// Approach First Using Stack
// T.C->O(n) and S.C->O(n)

vector<int> Reverse(int arr[],int n){
    stack<int>s;
    vector<int>v;
    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        /* code */
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

// Approach Second Using Two Pointer
// T.C->O(n) and S.C->O(1)
void Reverse(int arr[],int n){
    int start=0;
    int end=n-1;

    while(start<=end){
        swap(arr[start],arr[end]);
    }
}