class Solution {
private:
    long long dist(vector<int>& point1 ,vector<int>& point2)
    {
        return 1LL*(point2[0]-point1[0])*(point2[0]-point1[0]) + 1LL*(point2[1]-point1[1])*(point2[1]-point1[1]);  
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int res= 0 ;
        int n =  points.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long distance = dist(points[i],points[j]);
                    mp[i].push_back(distance);
                }
            }
        }
        for(auto x:mp)
        {
            unordered_map<int,int> tmpMp;
            for(auto y:x.second)
            {
                tmpMp[y]++;
            }
            for(auto z:tmpMp)
            {
                res += (z.second)*(z.second-1);
            }
        }
        return res;
        
    }
};