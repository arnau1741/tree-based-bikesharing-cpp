# Bifurcated Bicing - Bike Sharing System Simulation

This project implements a complete simulation of a shared bicycle management system (similar to Barcelona's *Bicing*), developed in C++. The core of the system organizes stations geographically using a **Binary Tree** structure, allowing for efficient search algorithms, load restructuring, and occupancy coefficient calculations.

## 🚀 Features

* **Hierarchical Organization:** Stations are structured in a binary tree, representing logical proximity or zones.
* **Fleet Management:** Registration, removal, and status queries for both bicycles and stations.
* **Trip History:** Tracks the history of trips (origin/destination) for every bicycle.
* **Rebalancing Algorithm (`subir_bicis`):** Moves bicycles from leaf stations toward the root to fill central stations, based on load priorities.
* **Smart Assignment (`asignar_estacion`):** Recursively calculates "unoccupancy coefficients" of subtrees to determine the optimal location for introducing new bicycles.

## 🛠️ Build and Run

The project includes a `makefile` to facilitate compilation with the strict flags required.

### Requirements
* G++ Compiler with C++11 support.
* Linux/Unix environment (recommended).

### Compilation Instructions

To generate the `program.exe` executable:
```bash
make
