    class comprator{
    public:
    bool operator()(vector<int>& v1,vector<int>& v2)
    {
         if(v1[1]==v2[1])
        {
            return (v1[1]-v1[0]+1)>(v2[1]-v2[0]+1);
        }
        return v1[1]>v2[1];
    }

};
class Solution {
public:
    bool isPossible(vector<int>& nums) {

        priority_queue<vector<int>, vector<vector<int>>, comprator> pq;

        int n = nums.size();
        for(int i = 0 ;i <n;i ++)
        {
            if(pq.empty()==true)
            {
                pq.push(vector<int>{nums[i],nums[i]});
            }
            else
            {
                vector<int> sub = pq.top();
                
                if(nums[i]==sub[1]+1)
                {
                    pq.pop();
                    pq.push(vector<int>{sub[0],nums[i]});
                }
                else if(sub[1]<(nums[i]-1))
                {
                    if((sub[1]-sub[0]+1)>=3)
                    {
                        i--;
                        pq.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(nums[i]==sub[1])
                {
                    pq.push(vector<int>{nums[i],nums[i]});
                }
                
            }
        }
        while(pq.empty()==false)
        {
            vector<int> sub= pq.top();
            cout<<sub[0]<<" "<<sub[1]<<endl;
            pq.pop();
            if((sub[1]-sub[0]+1)<3)
            {
                return false;
            }
        }
        return true;

    }
};