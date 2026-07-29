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


## 🧠 Core Algorithms

Throughout these solutions, you will find implementations and complexity analyses of:
* **Graph Algorithms:** BFS, DFS, Dijkstra, Floyd-Warshall, Kruskal, Disjoint Set Union (DSU).
* **Dynamic Programming:** 1D/2D/3D DP, Top-Down Memoization, Bottom-Up Tabulation, Interval DP, and state-compression DP.
* **Searching & Paradigms:** Divide & Conquer, Backtracking, Greedy Algorithms, Recursion, Binary Search.

### Algorithms by solution file
* **101223C-Manic Moving/main.cpp** — Floyd-Warshall + DP over delivery families.
* **102646C-Song Optimization/main.cpp** — Floyd-Warshall + DP over song transitions.
* **106054L-Lakes/bottom-up.cpp** — DP with prefix cost arrays and a 2-row memo table.
* **118D-Caesars Legions/top-down.cpp** and **bottom-up.cpp** — DP over troop counts and the last troop type; uses 3D/4D memo tables.
* **1286A-Garland/bottom-up.cpp** — DP over parity constraints and remaining bulbs; uses 3D memoization.
* **33B-String Problem/main.cpp** — Floyd-Warshall on an alphabet graph to compute minimum edit costs.
* **41D-Pawn/top-down.cpp** — Top-Down DP with state compression and path reconstruction; uses 3D memo tables.
* **698A-Vacations/top-down.cpp** — Recursive DP over days and previous activity; uses a 2D memo table.
* **864E-Fire/top-down.cpp** — DFS over items and remaining time.
* **866D-Buy Low Sell High/bottom-up.cpp** — DP over inventory states and stock transactions.
* **Taller 1-Backtracking y DyC/Ale y los 1s/main.cpp** — Divide & Conquer + recursion on a recursively defined string pattern.
* **Taller 1-Backtracking y DyC/Convertibilidad/main.cpp** — Backtracking with a linked list of decisions to reconstruct a sequence.
* **Taller 1-Backtracking y DyC/l-lindo/main.cpp** — Divide & Conquer over substrings with recursive splitting.
* **Taller 2-Programación Dinámica/Alfabéticamente/top-down.cpp** and **bottom-up.cpp** — DP over word order and inversion states; uses 2D memo tables.
* **Taller 2-Programación Dinámica/Borrar/top-down.cpp** — Interval DP over strings with memoization.
* **Taller 2-Programación Dinámica/Cartas/top-down.cpp** — DP with maps and memorization over card frequencies and people.
* **Taller 3-Grafos/Árbol Único/main.cpp** — Kruskal + Disjoint Set Union (DSU) over a graph.
* **Taller 3-Grafos/Máquina Misteriosa/main.cpp** — BFS over states using a queue.
* **Taller 3-Grafos/Viaje Intergaláctico/main.cpp** — Dijkstra’s algorithm with priority queue.


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