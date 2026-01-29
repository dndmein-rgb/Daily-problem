# [2976. Minimum Cost to Convert String I](https://leetcode.com/problems/minimum-cost-to-convert-string-i)

## 🧠 Problem Statement

You are given two strings `source` and `target` of equal length.

You are also given:
- `original[i]` → `changed[i]` with conversion cost `cost[i]`

Each conversion allows you to change one character into another at the given cost.
Conversions can be applied **multiple times** and **indirectly**.

Return the **minimum total cost** to convert `source` into `target`.
If it is impossible, return `-1`.

---

## ✍️ Input

- `source`: string
- `target`: string
- `original`: vector of characters
- `changed`: vector of characters
- `cost`: vector of integers

## 📤 Output

- Minimum conversion cost, or `-1` if conversion is impossible

---

## 📌 Constraints

- `1 <= source.length <= 10^5`
- `source.length == target.length`
- `1 <= original.length <= 2000`
- Characters are lowercase English letters

---

## 🧪 Example

**Input**
source = "abcd"
target = "bcde"
original = ['a','b','c','d']
changed = ['b','c','d','e']
cost = [1,1,1,1]


**Output**
4


**Explanation**

Each character can be converted directly with cost `1`.

---

## 🛠️ Approach

### Graph Modeling

- Each character (`a` to `z`) is a node.
- Each conversion rule is a **directed weighted edge**.
- We need the shortest path between every pair of characters.

### Algorithm

1. Build a graph of 26 nodes.
2. Run **Dijkstra from each character** (26 times).
3. Store all-pairs shortest paths in `dist[26][26]`.
4. For each position `i`:
   - Add cost to convert `source[i] → target[i]`
   - If no path exists, return `-1`.

---

## ⏱️ Complexity Analysis

- **Time Complexity**
  - `26 × Dijkstra` → `O(26 × E log V)`
  - Effectively constant, since `V = 26`
- **Space Complexity**
  - `O(26 × 26)`

---

## ✅ Key Takeaway

This is not a string problem.  
It’s a **shortest-path problem disguised as one**.

Once you treat characters as graph nodes, the solution becomes mechanical.
If you tried greedy per character without preprocessing, you missed the point.
