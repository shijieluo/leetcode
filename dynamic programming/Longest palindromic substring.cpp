class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0;
        if(s == "") return "";
        int b,t;
        for(int i=0;i<s.size();){
            int start=i,end=i;
            int sum = 1, temp = 1;                        
            while(i>0 && s[start-1] == s[i]){
                start--;
                sum++;                                    
            }
            while(i < s.size()-1 && s[end+1] == s[i]){
                end++;
                sum++;                    
            }            
            if(sum - temp){
                i += sum - temp + 1;
            }else{
                i++;
            }
            while(start>0 && end<s.size()-1){                
                if(s[start-1] == s[end+1]){
                    --start;
                    ++end;
                    sum+=2;                    
                }else{
                    break;
                }                
            }            
            if(sum > mx){
                mx = sum;               
                b = start;
                t = end;
            }
        }
        cout<< mx;
        return s.assign(s.begin()+b,s.begin()+t+1);
    }
};