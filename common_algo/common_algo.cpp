class Solution {
public:
    vector<int> spf;
    vector<int> ds; //disjoint set data structure
    bool gcdSort(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        ds.resize(max_num+1, -1);
        sieve(max_num+1);
        vector<int> sortedArr(nums);
        sort(sortedArr.begin(), sortedArr.end());
        for(int x : nums)
        {
            for(int p : get_primes(x))
            {
                int u = find(ds, x);
                int v = find(ds, p);
                if(u != v)ds[u] = v;
            }
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(find(ds, nums[i]) != find(ds, sortedArr[i]))
            {
                return false;
            }
        }
        return true;
    }
    void sieve(int n)
    {
        spf.resize(n);
        iota(spf.begin(), spf.end(), 0);
        for(int i = 2; i < n; i++)
        {
            if(spf[i] != i)continue;
            for(long long j = 1ll*i*i; j < n; j += i)
            {
                if(spf[j] > i)spf[j] = i;
            }
        }
    }
    vector<int> get_primes(int x)
    {
        vector<int> primes;
        while(x > 1)
        {
            primes.push_back(spf[x]);
            x /= spf[x];
        }
        return primes;
    }
    int find(vector<int> &ds, int i) 
    {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
};