class Answer{
    public int[] dp = new int[1001];
    int helper(int n) {
        if(n == 1) return 0;

        int steps = 0, fact = 2;
        while(n > 1) {
            while(n % fact == 0) {
                steps += fact;
                n /= fact;
            }
            fact++;
        }
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