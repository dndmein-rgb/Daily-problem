/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
🗓️ Daily Challenge: 1390. Four Divisors
📅 Date: January 4, 2026
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🎯 Problem: 1390. Four Divisors
📌 Link: https://leetcode.com/problems/four-divisors/
🏷️ Difficulty: Medium
🏆 Topics: Array, Math

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📖 Problem Summary
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Given:
- An integer array `nums`.

Goal:
- Find the sum of divisors of integers in the array that have exactly four divisors.
- If an integer has more or less than four divisors, it contributes 0 to the final sum.

Key Insight:
- To find all divisors efficiently, we only need to iterate up to $\sqrt{x}$.
- Divisors come in pairs: if $i$ is a divisor, then $x/i$ is also a divisor.
- A number has exactly four divisors if it is either:
    1. A product of two distinct prime numbers ($p \times q$).
    2. A cube of a prime number ($p^3$).

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💡 Approach (Square Root Factorization)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1. **Helper Function (`fourDiv`)**:
   - Iterate from $i = 1$ to $\sqrt{x}$.
   - If $x \% i == 0$:
     - Increment count by 2 (for $i$ and $x/i$).
     - Add both to a running total.
     - **Edge Case**: If $i == x/i$ (perfect square), the number has an odd count of divisors. Return 0 immediately.
   - After the loop, if the count is exactly 4, return the `total`.

2. **Main Function**:
   - Iterate through the input array and accumulate the results from `fourDiv`.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/



class Solution {
public:
    // Helper function to find sum of divisors if count is exactly 4
    int fourDiv(int x) {
        int count = 0, total = 0;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (i * i == x) {
                    // Perfect square: only adds 1 divisor, so it can't have exactly 4
                    return 0; 
                }
                count += 2;
                total += i;
                total += (x / i);
                
                // Early exit: if count exceeds 4, we don't care about this number
                if (count > 4) return 0;
            }
        }
        return (count == 4) ? total : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += fourDiv(num);
        }
        return sum;
    }
};

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
⚡ Complexity Analysis
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

⏰ Time Complexity: O(N * sqrt(M))
   └─ N is the number of elements in the array, M is the maximum value in nums.
   
💾 Space Complexity: O(1)
   └─ Constant space used for counting and summation.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
🔍 Example Walkthrough (num = 21)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. i = 1: 21%1 == 0. Count = 2, Total = 1 + 21 = 22.
2. i = 2: 21%2 != 0.
3. i = 3: 21%3 == 0. Count = 4, Total = 22 + 3 + 7 = 32.
4. i = 4: 4*4 > 21. Loop ends.
5. Count is 4, return 32.
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/
