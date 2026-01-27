# 3650. Minimum Cost Path with Edge Reversals

## 🔗 LeetCode Link
[Minimum Cost Path with Edge Reversals](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals)

---

## 🧩 Problem Statement

You are given a graph with `n` nodes numbered from `0` to `n - 1` and a list of edges.
Each edge is represented as `[u, v, w]`, meaning:

- Traveling from node `u` to node `v` costs `w`
- Reversing the edge and traveling from `v` to `u` costs `2 * w`

Your task is to find the **minimum cost** to travel from node `0` to node `n - 1`.

If it is not possible to reach the destination, return `-1`.

---

## 🧪 Example

**Input**
n = 3
edges = [[0,1,1],[1,2,2]]


**Output**
3


**Explanation**
- 0 → 1 costs 1  
- 1 → 2 costs 2  
Minimum total cost = 3

---

## 📏 Constraints

- `1 ≤ n ≤ 10^5`
- `0 ≤ edges.length ≤ 2 × 10^5`
- `0 ≤ u, v < n`
- `1 ≤ w ≤ 10^6`

---

## 🏷️ Topics

- Graph
- Shortest Path
- Dijkstra’s Algorithm
- Priority Queue
- Greedy

---

## 🧠 Approach

This is a **shortest path problem** on a graph with **asymmetric edge weights**.
It is efficiently solved using **Dijkstra’s Algorithm**.

### Steps

1. Build an adjacency list:
   - Add edge `u → v` with cost `w`
   - Add reversed edge `v → u` with cost `2w`
2. Use a min-heap (priority queue) storing `(currentCost, node)`
3. Maintain a distance array `dist[]` where `dist[i]` is the minimum cost to reach node `i`
4. Skip stale entries from the priority queue
5. Stop early when node `n - 1` is reached

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O((n + m) log n)`
- **Space Complexity:** `O(n + m)`
