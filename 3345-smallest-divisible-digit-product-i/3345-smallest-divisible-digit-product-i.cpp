class Solution {
private:
    bool check(int n , int t)
    {
        int product = 1;
        while(n > 0)
        {
            int digit = n % 10;
            if(digit == 0) return 1;
            product *= digit;
            n /= 10;
        }
        return product % t == 0;
    }
public:
    int smallestNumber(int n, int t) 
    {
        while(not check(n , t))
        {
            n++;
            
        }
        return n;
    }
};