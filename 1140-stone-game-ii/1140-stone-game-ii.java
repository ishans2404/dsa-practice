import java.util.*;

class Solution {
    static class DpKey {
        private final boolean var1;
        private final int var2;
        private final int var3;

        public DpKey(boolean var1, int var2, int var3) {
            this.var1 = var1;
            this.var2 = var2;
            this.var3 = var3;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            DpKey dpKey = (DpKey) o;
            return var1 == dpKey.var1 && var2 == dpKey.var2 && var3 == dpKey.var3;
        }

        @Override
        public int hashCode() {
            return Objects.hash(var1, var2, var3);
        }
    }

    public int stoneGameII(int[] piles) {
        Map<DpKey, Integer> dp = new HashMap<>();
        boolean alice = true;
        int idx = 0;
        int M = 1;
        return helper(alice, idx, M, piles, dp);
    }

    public int helper(boolean alice, int idx, int M, int[] piles, Map<DpKey, Integer> dp) {
        if (idx == piles.length) return 0;

        DpKey key = new DpKey(alice, idx, M);
        if (dp.containsKey(key)) return dp.get(key);

        int res = alice ? 0 : Integer.MAX_VALUE;
        int total = 0;
        for (int X = 1; X <= 2 * M; X++) {
            if (idx + X > piles.length) break;
            total += piles[idx + X - 1];

            if (alice) {
                res = Math.max(res, total + helper(!alice, idx + X, Math.max(M, X), piles, dp));
            } else {
                res = Math.min(res, helper(!alice, idx + X, Math.max(M, X), piles, dp));
            }
        }
        dp.put(key, res);
        return res;
    }
}
