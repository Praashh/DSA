//                        *** GOOGLE INTERVIEW QUESTION*****
// QUESTION-> Given a string S that consists of only alphanumeric characters and dashes. The string is separated into N + 1 groups by N dashes. Also given an integer K. 

//We want to reformat the string S, such that each group contains exactly K characters, except for the first group, which could be shorter than K but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

//Return the reformatted string 

// Example  
// Input: 
// S = "5F3Z-2e-9-w", K = 4
// Output: "5F3Z-2E9W"
// Explanation: The string S has been split into two
// parts, each part has 4 characters. Note that two
// extra dashes are not needed and can be removed

// Approach -> if I add charecters from n-1 index of string with k pairs then i will able to solve the question
// step 1 -> itreate a loop from n-1 index to 0 index
// step 2 -> Ignore all the '-' charecters 
// step 3  -> if there are lower charecter then convert them into upper chaecters
// step 4 -> if count==k then apend a '-' charecter into answer string and initialize count=0;
// step 5 -> reverse the string
// step 6 (most important step)-> if there are '-' charecter at starting index of string then remove it make sure it will do 
// after reversing 

// T.C-> O(N) and S.C-> O(1)
 
 string ReFormatString(string S, int K){
    	int count=0;
    	string ans="";
    	int n=S.length();
    	for(int i=n-1;i>=0;i--){
    	     if(S[i]=='-'){
    	        continue;
    	    }
    	   if(S[i]>='a'&& S[i]<='z'){
    	       S[i]-=32;
    	       ans+=S[i];
    	   }
    	    else{
    	        ans+=S[i];
    	    }
    	       count++;
    	    if(count==K ){
    	        if(i!=0){
    	        ans+='-';
    	        }
    	      // ans+='-';
    	        count=0;
    	    }
    	
    	}
    	
    	reverse(ans.begin(),ans.end());
    	if(ans[0]=='-'){
    	    ans.erase(ans.begin()+0);
    	}
    	return ans;
    }