#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <numeric>    // for std::accumulate
#include <algorithm>  // for std::reverse (optional demonstration)
using namespace std;

// ─────────────────────────────────────────────────────────────────────────────
// PART A: vector - store N integers, print in reverse using reverse iterator
// ─────────────────────────────────────────────────────────────────────────────
void partA() {
    cout << "--- Part A: vector (reverse output) ---\n";

    int n;
    cout << "Enter N (1 to 100000): ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter " << n << " integers (space-separated): ";
    for (int i = 0; i < n; i++) cin >> v[i];

    // Using STL reverse iterator — does NOT modify the original vector
    cout << "Reversed output: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";
    cout << "\n\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// PART B: deque - push_front, push_back, pop_front then display
// ─────────────────────────────────────────────────────────────────────────────
void partB() {
    cout << "--- Part B: deque (push/pop operations) ---\n";

    deque<int> dq;

    // Sequence of operations (hardcoded to demonstrate the concept clearly)
    cout << "Performing: push_back(10), push_back(20), push_front(5),\n";
    cout << "            push_back(30), push_front(1), pop_front()\n\n";

    dq.push_back(10);   // deque: [10]
    dq.push_back(20);   // deque: [10, 20]
    dq.push_front(5);   // deque: [5, 10, 20]
    dq.push_back(30);   // deque: [5, 10, 20, 30]
    dq.push_front(1);   // deque: [1, 5, 10, 20, 30]

    cout << "After all push operations: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    dq.pop_front();     // removes 1 → deque: [5, 10, 20, 30]
    cout << "After pop_front()        : ";
    for (int x : dq) cout << x << " ";
    cout << "\n\n";
}

// ─────────────────────────────────────────────────────────────────────────────
// PART C: std::array - fixed size, compute sum with std::accumulate
// ─────────────────────────────────────────────────────────────────────────────
void partC() {
    cout << "--- Part C: std::array (fixed-size, sum via accumulate) ---\n";

    // std::array size must be a compile-time constant
    constexpr int SIZE = 8;
    array<int, SIZE> arr = {4, 7, 2, 9, 1, 5, 8, 3};

    cout << "Fixed array contents: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    // std::accumulate from <numeric> — STL utility for summing
    int total = accumulate(arr.begin(), arr.end(), 0);
    cout << "Sum (via std::accumulate): " << total << "\n\n";
}

int main() {
    cout << "========================================\n";
    cout << "  Assignment 1 - Q1: STL Containers\n";
    cout << "========================================\n\n";

    partA();
    partB();
    partC();

    return 0;
}