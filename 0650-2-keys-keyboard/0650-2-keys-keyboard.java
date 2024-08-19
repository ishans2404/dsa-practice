class Answer{
    public int[] dp = new int[1001];
    int helper(int n) {
        if(n == 1) return 0;

        int steps = 0;
        for(int i = 2; i * i <= n; i++) {
            while(n % i == 0) {
                steps += i;
                n /= i;
            }
        }
        if(n > 1) steps += n;
        return steps;
    }
    Answer() {
        for(int i = 0; i <= 1000; i++) {
            dp[i] = helper(i);
        }
    }
}

class Solution {
    public static Answer ans = new Answer();
    public int minSteps(int n) {
        return ans.dp[n];
    }
}