//recursive
class Solution {
    public int fib(int n) {
        if(n<=1)
            return n;
        return fib(n-1)+fib(n-2);
    }
}

//dp
class Solution {
	public int fib(int n) {
		if(n<=1)
            return n;
		return memo(n);
	}
	private int memo(int n) {
		int[] dp=new int[n+1];
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<=n;++i)
			dp[i]=dp[i-1]+dp[i-2];
		return dp[n];
	}
}