class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int left = 0;
        int right =  0;
        int res = 0;
        while(right<n)
        {
            mp[s[right]]++;
            
            while(mp['a']>0 && mp['b']>0 && mp['c']>0 && left<=right)
            {
                mp[s[left]]--;
                res += (n-right);
                left++;
                
            }
            right++;
        }

        return res;
        
    }
};