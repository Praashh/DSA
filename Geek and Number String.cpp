//   QUESTION -> Geek has a string Sof size Nconsisting of characters from '0'to '9'. He wants to minimise the length of the string. In each minimising operation, geek can remove any two consecutive characters
//   if they are of the form {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}.
//  Find the minimum possible length of the string after applying minimising operations. 
 

//  Example :

//  Input: 
//  N = 5 
//  S = "12213"
//  Output: 1

//  Explanation: Geek can get the string of 
//  length 1 in two minimising operation,
//  In 1st operation Geek will remove "12" 
//  from "12213" then Geek left with "213"
//  In 2nd operation Geek will remove "21" 
//  from "213" then Geek left with "3"

// T.C-> O(N) and S.C-> O(N)

// Approach we can use stack in this problem firstly  put element into stack and if there are pair of the current
// in stack that pop and the size of stack is maximum length of string  

class Solution{
public:
    bool IsPair(char a, char b){
        if((a=='1' && b=='2') || (a=='2' && b=='1')){
            return true;
        }
       else if((a=='3' && b=='4') || (a=='4' && b=='3')){
            return true;
        }
       else if((a=='5' && b=='6') || (a=='6' && b=='5')){
            return true;
        }
       else if((a=='7' && b=='8') || (a=='8' && b=='7')){
            return true;
        }
        else if((a=='9' && b=='0') || (a=='0' && b=='9')){
            return true;
        }
        else{
            return false;
        }
        
    }
    int minLength(string s, int n) {
       stack<char>st;
       for(int i=0;i<n;i++){
           if(st.size()==0){
           st.push(s[i]);
           }
            else{
                if(IsPair(st.top(),s[i])){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
       }
       return st.size();
    } 
};
