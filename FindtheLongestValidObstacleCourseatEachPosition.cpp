class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        vector<int> ans;
        for(int x : obstacles)
        {
            if(lis.empty() || lis.back() <= x)
            {
                lis.push_back(x);
                ans.push_back(lis.size());
            }
            else
            {
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
                lis[idx] = x;
                ans.push_back(idx+1);
            }
        }
        return ans;
    }
};