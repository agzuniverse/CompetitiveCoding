/*
 * You are given n eggs. There is a building with k floors such that the eggs
 * will break when dropped from all floors above a particular floor, including
 * that floor. It will not break when dropped from floors below this floor. Find
 * the minimum number of drops required to identify this floor in the worst
 * case. This solution runs in O(nk^2) time.
 */

public class EggDrop {
    static int findMinDrops(int n, int k) {
        int minDropsForFloor[][] = new int[n + 1][k + 1]; // Matrix represnting the minimum drops for i eggs and j
                                                          // floors
        for (int i = 1; i <= n; i++) {
            // For 0 floors we need 0 drops and for 1 floor we need 1 drop
            minDropsForFloor[i][0] = 0;
            minDropsForFloor[i][1] = 1;
        }
        for (int j = 1; j <= k; j++) {
            minDropsForFloor[1][j] = j; // we need j drops for j floors with 1 egg
        }

        int res;

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                minDropsForFloor[i][j] = Integer.MAX_VALUE;
                for (int x = 1; x < j; x++) {
                    /*
                     * If the egg breaks, we have i-1 eggs left and x-1 floors to check (the floors
                     * below) If the egg does not break, we have i eggs left and j-x floors to check
                     * (the floors above) We take the max value of min drops for both cases to move
                     * towards the worst case.
                     */

                    res = Integer.max(minDropsForFloor[i - 1][x - 1], minDropsForFloor[i][j - x]) + 1;
                    if (res < minDropsForFloor[i][j])
                        minDropsForFloor[i][j] = res;
                }
            }
        }
        return minDropsForFloor[n][k];
    }

    public static void main(String args[]) {
        System.out.println(Integer.toString(findMinDrops(2, 100))); // Sample input: 2 eggs and 100 floors.
    }
}