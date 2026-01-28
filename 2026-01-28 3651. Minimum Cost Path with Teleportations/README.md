# 3651. Minimum Cost Path with Limited Teleports

## 🧠 Problem Statement

You are given an `n x m` grid where each cell contains a non-negative integer cost.

You start at the top-left cell `(0, 0)` and want to reach the bottom-right cell `(n - 1, m - 1)`.

From any cell, you may perform one of the following operations:

1. Move **right** or **down**, paying the cost of the destination cell.
2. Use a **teleport** (at most `k` times total) to jump to **any cell** whose value is **less than or equal to** the current cell value.
   - Teleporting itself costs nothing.

Return the **minimum total cost** to reach `(n - 1, m - 1)`.

---

## ✍️ Input

- `grid`: a 2D integer matrix of size `n x m`
- `k`: maximum number of teleports allowed

## 📤 Output

- An integer representing the minimum cost to reach the destination

---

## 📌 Constraints

- `1 <= n, m <= 100`
- `0 <= grid[i][j] <= 10^5`
- `0 <= k <= 100`

---

## 🧪 Example

**Input**
grid = [[5,3,4],
[6,1,2],
[7,8,0]]
k = 1


**Output**
5


---

## 🛠️ Approaches

### ❌ Approach 1: Recursive DP with Brute Teleports (TLE)

**Idea**
- Use a 3D DP state `dp[i][j][k]`
- From each cell:
  - Move right
  - Move down
  - Try teleporting to every valid cell

**Problem**
- Teleport step loops over the entire grid
- Results in `O(n²m²k)` complexity
- Completely infeasible for constraints

This solution is correct in logic but fails on performance.

---

### ✅ Approach 2: Optimized DP with Value-Based Relaxation (Accepted)

**Key Insight**
- Teleports depend only on **cell values**, not positions
- If cells are processed in increasing order of value, teleport transitions can be optimized

**Steps**
1. Flatten all cells and sort them by grid value
2. Maintain a `cost[i][j]` DP table
3. For each teleport step:
   - Relax costs across cells with smaller or equal values
   - Then propagate costs using bottom-up DP (right and down moves)
4. Repeat for `k` teleport layers

This avoids brute-forcing teleport transitions.

---

## ⏱️ Complexity Analysis

### Recursive DP
- **Time:** Exponential / TLE
- **Space:** `O(n * m * k)`

### Optimized DP
- **Time:** `O(k * n * m)`
- **Space:** `O(n * m)`

---

## ✅ Key Takeaway

The hard part isn’t DP.  
It’s realizing that **teleports are value-based, not position-based**.

Once you stop brute-forcing destinations and start grouping by values,
the problem collapses into something manageable.

Optimization beats clever recursion every single time.
