import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> heap = new PriorityQueue<Long>();
        Set<Long> set = new HashSet<Long>();
        int[] factors = {2, 3, 5};
        
        heap.add(1L);
        set.add(1L);
        long uglyNum = 0;

        for (int i = 0; i < n; i++) {
            uglyNum = heap.poll();
            for (int fact : factors) {
                long newUgly = uglyNum * fact;
                if (set.contains(newUgly) == false) {
                    set.add(newUgly);
                    heap.add(newUgly);
                }
            }
        }
        return (int) uglyNum;
    }
}