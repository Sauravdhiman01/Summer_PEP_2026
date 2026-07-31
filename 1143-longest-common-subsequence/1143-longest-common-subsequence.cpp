class Solution {
private:
    int getComLCS(int i, int j, vector<vector<int>>&dp, string &text1, string & text2)
    {
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j])
        {
            return dp[i][j] =  (1 + getComLCS(i - 1, j - 1, dp, text1, text2));
        }

        return dp[i][j] = (max(getComLCS(i - 1, j,dp, text1, text2), getComLCS(i, j - 1, dp, text1, text2)));
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size(), m = text2.size();

        vector<vector <int>> dp(n, vector<int>(m , -1));


        return getComLCS(n - 1,m - 1, dp, text1, text2);
    }
};