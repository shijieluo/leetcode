class Solution {
    /*static bool isPalindrome(string s, int begin, int end){
        while(begin<end){
            if(s[begin++]!=s[end--]) return false;
        }
        return true;
    }*/
public:
    int minCut(string s) {                
        if(s.size()==0) return 0;
        vector<vector<int>> palindrome(s.size()+1,vector<int>(s.size()+1));
        vector<int> dp(s.size(),0);
        for(int i=0;i<s.size();i++){
            int l = i, r = i;
            palindrome[l][r] = 1;
            while(r<s.size()-1 && s[l] == s[r+1]){
                r++;
                palindrome[l][r] = 1;
            }
            while(l>0 && r<s.size()-1 && s[l-1]==s[r+1]){
                l--;
                r++;
                palindrome[l][r] = 1;
            }
        }
        for(int i=0;i<s.size();i++){
            dp[i] = i;
        }
        for(int i=1;i<s.size();i++){
           for(int j=i;j>=0;j--){
               if(palindrome[j][i]){
                   if(j>0) dp[i] = min(dp[i],1+dp[j-1]);
                   if(j==0) dp[i] = 0;
               }
            }           
        }
        return dp[s.size()-1];
    }
};