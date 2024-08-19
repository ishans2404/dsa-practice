class Answer{
    public int[] dp = new int[1001];
    Answer() {
        for(int i = 0; i <= 1000; i++) dp[i] = 1000;
        dp[1] = 0;

        for(int i = 2; i <= 1000; i++) {
            for(int j = 1; j <= (i / 2); j++) {
                if(i % j == 0) {
                    dp[i] = Math.min(dp[i], dp[j] + (i / j));
                }
            }
        }
    }
}

class Solution {
    public static Answer ans = new Answer();
    public int minSteps(int n) {
        return ans.dp[n];
    }
}