#include<bits/stdc++.h>
using namespace std;
void sub(string s){
    int n=4;

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<s[k];
            }
            cout<<endl;
        }
    }
}
 int main(){
    string s="abcd";
    sub(s);
    return 0;
 }