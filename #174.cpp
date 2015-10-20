/*============================================================
Problem: Dungeon Game
==============================================================
The demons had captured the princess (P) and imprisoned her in 
the bottom-right corner of a dungeon. The dungeon consists of 
M x N rooms laid out in a 2D grid. Our valiant knight (K) was 
initially positioned in the top-left room and must fight his 
way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive 
integer. If at any point his health point drops to 0 or below, 
he dies immediately.

Some of the rooms are guarded by demons, so the knight loses 
health (negative integers) upon entering these rooms; other 
rooms are either empty (0's) or contain magic orbs that increase 
the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight 
decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health 
so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the 
knight must be at least 7 if he follows the optimal path 
RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3		3
-5		-10		1
10		30		-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room 
the knight enters and the bottom-right room where the princess 
is imprisoned.
============================================================*/
class Solution {
private:
    int calcHealth(int val) {
        return val>0 ? val : 1;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m==0) return 1;
        int n = dungeon[0].size();
        
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        
        dp[m-1][n-1] = calcHealth(1-dungeon[m-1][n-1]);
        
        for (int k=m+n-3; k>=0; k--) {
            for (int i=0; i<m; i++) {
                int j = k-i;
                if (j<0 || j>=n) continue;
                if (i+1<m) dp[i][j] = min(dp[i][j], calcHealth(dp[i+1][j]-dungeon[i][j]));
                if (j+1<n) dp[i][j] = min(dp[i][j], calcHealth(dp[i][j+1]-dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};