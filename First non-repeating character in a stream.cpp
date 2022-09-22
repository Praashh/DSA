// QUESTION-> Given an input stream of A of n characters consisting only of lower case alphabets. 
//The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer

// Example 1:

// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'

//  Time Complexity: O(26 * n)
//  Space Complexity: O(26)

	string FirstNonRepeating(string A){
		unordered_map<char,int>mp;
		queue<int>q;
		string ans="";
		for(int i=0;i<A.length();i++){
		       mp[A[i]]++;
               q.push(A[i]);
		    
		    while(!q.empty()){
		         if(mp[q.front()]>1){
		            q.pop();
		         }
		         else{
		            ans+=q.front();
		            break;
		         }
		    }
		    if(q.empty()){
		        ans+='#';
		    }
		}
		return ans;
	}