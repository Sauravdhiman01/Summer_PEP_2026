class Solution {
private:
    void reverse(int i, int n, vector<char> &s)
    {
        if(i >= n /2) return;
        swap(s[i], s[n - i - 1]);
        reverse(i + 1, n , s);
    }
public:
    void reverseString(vector<char>& s) 
    {
        int n = s.size();
        reverse(0, n , s);
    }
};