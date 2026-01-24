# 🧮 Minimum Pair Removal to Sort Array II

- **Problem:** [LeetCode 3510 – Minimum Pair Removal to Sort Array II](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/)

---

## 🧠 Problem Summary

You are given an array `nums`.

In one operation:
- Choose two **adjacent elements**
- Replace them with their **sum**
- Remove the second element

Repeat until the array becomes **non-decreasing**.

Return the **minimum number of operations**.

This is **Part II**, meaning:
- Larger constraints
- Brute force is dead on arrival
- Greedy + data structures is mandatory

---

## 🚀 Strategy (Why This Works)

Key idea:
> Always merge the **adjacent pair with the smallest sum**.

Why?
- It minimizes disruption
- Removes inversions efficiently
- Prevents large values from poisoning neighbors early

To do this efficiently:
- Track adjacent sums in a **multiset**
- Simulate the array as a **doubly linked list**
- Maintain a counter of **bad (descending) pairs**

Stop when `bad == 0`.

---

## 🛠️ Techniques Used

- Greedy selection via `multiset`
- Linked-list simulation using index arrays
- Precise inversion (bad pair) bookkeeping
- No array rebuilds, no re-sorting, no nonsense

---

## ⏱️ Complexity

- **Time:** `O(n log n)`
- **Space:** `O(n)`

This survives the Part II constraints. Anything simpler does not.

---

## ⚠️ Common Pitfalls

- Re-scanning the array after every merge (TLE)
- Forgetting to update neighbors after merging
- Mishandling inversion count updates
- Assuming Part II is just Part I with bigger input

It isn’t.

---

## 🎯 Takeaway

This problem tests whether you can:
- Control mutations precisely
- Maintain ordering invariants
- Use greedy correctly instead of hoping

If Part I teaches the idea,  
Part II checks if you actually understood it.
