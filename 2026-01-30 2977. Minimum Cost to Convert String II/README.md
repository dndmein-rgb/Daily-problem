# [2977. Minimum Cost to Convert String II](https://leetcode.com/problems/minimum-cost-to-convert-string-ii)

## 🧠 Problem Statement

You are given two strings `source` and `target` of equal length.

You are also given conversion rules:
- `original[i]` → `changed[i]` with cost `cost[i]`

Each rule converts an entire **substring** (not a single character).
Conversions can be applied multiple times and indirectly.

Return the **minimum total cost** to convert `source` into `target`.
If it is impossible, return `-1`.

---

## ✍️ Input

- `source`: string
- `target`: string
- `original`: array of strings
- `changed`: array of strings
- `cost`: array of integers

## 📤 Output

- Minimum conversion cost, or `-1` if conversion is impossible

---

## 📌 Constraints

- `1 <= source.length <= 10^4`
- `source.length == target.length`
- `1 <= original.length <= 2000`
- Sum of lengths of `original[i]` is bounded
- Strings contain lowercase English letters

---

## 🧪 Example

**Input**
source = "abcd"
target = "bcde"
original = ["a","ab","bc","cd"]
changed = ["b","bc","cd","de"]
cost = [1,2,2,2]


**Output**
4


---

## 🛠️ Approach

### 1️⃣ Graph Construction
- Each unique substring in `original` and `changed` is a node.
- Each conversion rule is a **directed weighted edge**.

### 2️⃣ All-Pairs Shortest Paths
- Run Dijkstra from every node.
- This handles indirect conversions optimally.

### 3️⃣ Dynamic Programming on String
- `dp[i]` = minimum cost to convert `source[i…n-1]`
- Transitions:
  - Do nothing if `source[i] == target[i]`
  - Try all valid substring lengths and add conversion cost

This cleanly separates **conversion cost logic** from **string alignment logic**.

---

## ⏱️ Complexity Analysis

- **Graph phase:**  
  `O(V × E log V)` where `V` is number of unique substrings
- **DP phase:**  
  `O(n × L)` where `L` is number of distinct substring lengths
- **Space Complexity:**  
  `O(V² + n)`

---

## ✅ Key Takeaway

This is not a string problem.  
It’s **shortest paths + DP**, glued together by substrings.

If you tried greedy matching or per-character logic here,
you never understood the problem in the first place.
