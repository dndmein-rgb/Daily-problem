# [1200. Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)

## 🧠 Problem Statement

Given an integer array `arr` of distinct numbers, find all pairs of elements with the **minimum absolute difference** of any two elements.

Return a list of pairs in **ascending order**, where each pair `[a, b]` satisfies:

- `a < b`
- `b - a` is the minimum absolute difference of any two elements in `arr`

---

## ✍️ Input

- An integer array `arr` of distinct integers

## 📤 Output

- A vector of integer pairs `[a, b]` with the minimum absolute difference, sorted in ascending order

---

## 📌 Constraints

- `2 <= arr.length <= 10^5`
- `-10^6 <= arr[i] <= 10^6`
- All elements in `arr` are distinct

---

## 🧪 Examples

### Example 1

**Input**
arr = [4,2,1,3]


**Output**
[[1,2],[2,3],[3,4]]


**Explanation**

Pairs with minimum absolute difference `1` are `[1,2], [2,3], [3,4]`.

---

### Example 2

**Input**
arr = [1,3,6,10,15]


**Output**
[[1,3]]


**Explanation**

Minimum absolute difference is `2` between `[1,3]`.  

---

## 🛠️ Approach

1. Sort the array in ascending order.
2. Find the **minimum difference** between consecutive elements.
3. Collect all consecutive pairs whose difference equals the minimum.
4. Return the pairs in ascending order.

Sorting ensures pairs are automatically in the correct order.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)` for sorting
- **Space Complexity:** `O(1)` extra (excluding output)

---

## ✅ Key Takeaway

Sorting the array transforms a potentially `O(n^2)` problem into `O(n log n)`.  
Always consider how ordering can simplify "difference" problems.
