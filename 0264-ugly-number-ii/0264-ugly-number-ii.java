class Solution {
    public int nthUglyNumber(int n) {
        long[] nums = new long[n];
        nums[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int i = 1; i < n; i++) {
            long nextUgly = Math.min(nums[i2] * 2, Math.min(nums[i3] * 3, nums[i5] * 5));
            nums[i] = nextUgly;

            if (nextUgly == nums[i2] * 2) i2++;
            if (nextUgly == nums[i3] * 3) i3++;
            if (nextUgly == nums[i5] * 5) i5++;
        }

        return (int)nums[n - 1];
    }
}