# Bifurcated Bicing - Bike Sharing System Simulation

This project implements a complete simulation of a shared bicycle management system (similar to Barcelona's *Bicing*), developed in C++. [cite_start]The core of the system organizes stations geographically using a **Binary Tree** structure, allowing for efficient search algorithms, load restructuring, and occupancy coefficient calculations[cite: 4, 50].

## 🚀 Features

* [cite_start]**Hierarchical Organization:** Stations are structured in a binary tree, representing logical proximity or zones.
* [cite_start]**Fleet Management:** Registration, removal, and status queries for both bicycles and stations[cite: 4, 5].
* [cite_start]**Trip History:** Tracks the history of trips (origin/destination) for every bicycle[cite: 2].
* [cite_start]**Rebalancing Algorithm (`subir_bicis`):** Moves bicycles from leaf stations toward the root to fill central stations, based on load priorities[cite: 3, 6].
* **Smart Assignment (`asignar_estacion`):** Recursively calculates "unoccupancy coefficients" of subtrees to determine the optimal location for introducing new bicycles[cite: 49, 51].

## 🛠️ Build and Run

The project includes a `makefile` to facilitate compilation with the strict flags required.

### Requirements
* G++ Compiler with C++11 support.
* Linux/Unix environment (recommended).

### Compilation Instructions

To generate the `program.exe` executable:
```bash
make
