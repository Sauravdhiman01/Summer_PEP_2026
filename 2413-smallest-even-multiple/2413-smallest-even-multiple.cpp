class Solution {
public:
    int smallestEvenMultiple(int n) 
    {
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            if(ans % 2 == 0)
            {
                return ans;
            }
            return ans * 2;
        }
    return 0;
    }
};