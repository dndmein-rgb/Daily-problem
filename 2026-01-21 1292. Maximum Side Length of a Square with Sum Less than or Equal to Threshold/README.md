# 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Problem Link:** [LeetCode – Maximum Side Length of a Square with Sum ≤ Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

---

## 🧩 Problem Description

You are given a 2D matrix `mat` of size `n x m` and an integer `threshold`.

Your task is to find the **maximum side length** of a **square submatrix** such that the **sum of all its elements is less than or equal to `threshold`**.

A square submatrix must have:
- Equal number of rows and columns
- Be fully contained inside the matrix

Return the **largest possible side length**.

---

## 📥 Examples

### Example 1
Input:
mat = [[1,1,3,2,4,3,2],
[1,1,3,2,4,3,2],
[1,1,3,2,4,3,2]]
threshold = 4

Output:
2


**Explanation:**  
The largest square with sum ≤ 4 is:
1 1
1 1

Sum = 4, side length = 2

---

### Example 2
Input:
mat = [[2,2,2,2],
[2,2,2,2],
[2,2,2,2]]
threshold = 1

Output:
0


**Explanation:**  
Every element is greater than the threshold.  
No valid square exists.

---

### Example 3
Input:
mat = [[1,2,3],
[4,5,6],
[7,8,9]]
threshold = 45

Output:
3


**Explanation:**  
The entire matrix forms a valid square.  
Sum = 45, side length = 3

---

## 🧠 Core Idea

Brute force is a bad joke here.

Checking every possible square takes **O(n³)** time, which collapses under constraints up to **300 × 300**.

So we combine two standard techniques that actually respect reality:

1. **2D Prefix Sum**  
   Enables O(1) submatrix sum queries.

2. **Binary Search on Side Length**  
   Efficiently grows the square size instead of trying everything.

---

## 🧮 Prefix Sum Explanation

Define a prefix sum matrix `pref` where:

pref[i][j] = sum of elements in submatrix (1,1) to (i,j)


To compute the sum of a square with:
- Top-left corner `(i, j)`
- Side length `k`

We use:

sum =
pref[i + k - 1][j + k - 1]

pref[i - 1][j + k - 1]

pref[i + k - 1][j - 1]

pref[i - 1][j - 1]


This gives **constant-time** square sum computation.

---

## 🔍 Binary Search Strategy

For every cell `(i, j)` as a potential top-left corner:

- We binary search the **largest valid square**
- Lower bound = `current_best + 1`
- Upper bound = remaining grid size from `(i, j)`

If a square of size `mid` satisfies the threshold:
- Try larger sizes
Otherwise:
- Shrink the search

This avoids pointless recomputation.

---

## ⏱️ Time & Space Complexity

- Prefix sum construction: **O(n × m)**
- Binary search per cell: **O(log(min(n, m)))**
- Total time: **O(n × m × log(min(n, m)))**
- Space: **O(n × m)**

This comfortably passes all constraints.

---

## 🚨 Common Mistakes to Avoid

- Off-by-one errors in prefix indexing
- Using `mid + 1` instead of `mid` when updating the answer
- Binary searching beyond the remaining grid size
- Forgetting prefix padding (0th row/column)

---

## ✅ Final Takeaway

This problem isn’t about clever tricks.  
It’s about **discipline**:

- Correct prefix sums
- Controlled binary search
- Respecting boundaries

Once those are solid, this becomes a predictable, mechanical solve instead of a guessing game.
