class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n  = cards.size();
        unordered_set<int> st;
        int res = INT_MAX;
        int i = 0;
        for(int j=0;j<n;j++)
        {
            if(st.find(cards[j])!=st.end()){
            while(i<j && st.find(cards[j])!=st.end())
            {
                   res = min(res,j-i+1);
                   st.erase(cards[i]);
                   i++; 
            }
            st.insert(cards[j]);
            }
            else{
            st.insert(cards[j]);
            }

        
        }

        return res==INT_MAX?-1:res;
        
    }
};