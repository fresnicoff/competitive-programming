# 🏆 Codeforces Solutions

Welcome to my repository of [Codeforces](https://codeforces.com/) solutions! This workspace serves as both a personal archive tracking my competitive programming growth and an educational reference for different algorithmic approaches.


## 📂 Repository Structure

Each problem has its own dedicated directory named after its Contest ID and Problem Code (e.g., `698A-Vacations`).

Inside every problem folder, you will find:
* **Multiple Solution Approaches:** A problem may contain multiple solution files demonstrating different solving strategies (e.g., a brute-force baseline vs. a Top-Down Dynamic Programming approach vs. an optimized Bottom-Up DP).
* **Detailed Explanations & Complexity Analysis:** Solutions contain inline commentary explaining the core intuition, as well as explicit **Time Complexity** $\mathcal{O}(N)$ and **Space Complexity** $\mathcal{O}(N)$ breakdowns.
* **Sample Test Cases:** `input.txt` and `output.txt` files for local testing.

```text
📦 competitive-programming
 ┣ 📂 698A-Vacations
 ┃ ┣ 📜 input.txt
 ┃ ┣ 📜 output.txt
 ┃ ┗ 📜 top-down.cpp
 ┣ 📂 118D-Caesars Legions
 ┃ ┣ 📜 bottom-up.cpp			# Optimized Bottom-Up DP
 ┃ ┣ 📜 input.txt
 ┃ ┣ 📜 output.txt
 ┃ ┗ 📜 top-down.cpp			# Top-Down DP
 ┣ 📂 33B-String Problem
 ┃ ┣ 📜 input.txt
 ┃ ┣ 📜 main.cpp
 ┃ ┗ 📜 output.txt
 ┣ 📜 README.md
 ┗ 📜 LICENSE
```


## 🧠 Core Algorithms & Data Structures

Throughout these solutions, you will find implementations and complexity analyses of:
* **Graph Algorithms:** BFS, DFS, Kruskal, Dijkstra, Bellman-Ford, Floyd-Warshall, Topological Sort.
* **Dynamic Programming:** 1D/2D DP, Top-Down DP, Bottom-Up DP.
* **Searching & Paradigms:** Divide & Conquer, Backtracking, Greedy Algorithms, Binary Search, Two Pointers, Sliding Window.


## 🚀 How to Test & Run

To test any solution using the included sample inputs:

1. **Clone the repository:**
```bash
git clone git@github.com:fresnicoff/competitive-programming.git
```

2. **Navigate to the target problem folder:**
```bash
cd 698A-Vacations
```

3. **Run the solution against the sample input:**
```bash
g++ -O2 top-down.cpp -o solution
./solution < input.txt
```

Compare your terminal output directly against `output.txt` to verify correctness.


---

## 📝 Note on Plagiarism

These solutions are provided solely for educational purposes and personal tracking. If you are actively participating in a live Codeforces contest, please do not copy code from this repository, as doing so violates Codeforces' rules and will result in penalties or account bans.