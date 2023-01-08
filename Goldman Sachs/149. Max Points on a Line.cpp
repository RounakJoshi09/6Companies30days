class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         int n  = points.size();
         int res = 0 ;
         for(int i=0;i<n;i++)
         {
             unordered_map<double,int> mp;
             int vertical =0 ;
             int horizontal = 0;
             for(int j=0;j<n;j++)
             {
                 if(i!=j)
                 {
                 if(points[i][0] == points[j][0])
                {
                    vertical++;
                }
                else if(points[i][1] == points[j][1])
                {
                    horizontal++;
                }
                else
                {
                 double slope = ((points[j][1]-points[i][1])*1.0)/((points[j][0]-points[i][0])*1.0);
                       mp[slope]++; 
                }    
                
                }
             for(auto x:mp)
             {
                 res = max(res,x.second);

             }
             res = max(res,max(horizontal,vertical));
             }
         }
        return res+1;
    }
};