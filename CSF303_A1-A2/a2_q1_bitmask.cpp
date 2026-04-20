#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "========================================\n";
    cout << "  Assignment 2 - Q1: Bitmasking\n";
    cout << "========================================\n";
    cout << "Enter N: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int K;
    cout << "Enter K: ";
    cin >> K;

    // Total number of subsets = 2^N
    // Each bit in 'mask' represents whether arr[i] is included (1) or not (0)
    int totalSubsets = 1 << n;   // same as 2^n
    int count = 0;

    cout << "\nSubsets with sum divisible by " << K << ":\n";
    cout << "--------------------------------------------\n";

    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        vector<int> subset;

        // Check each bit position i
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {     // if bit i is set, include arr[i]
                sum += arr[i];
                subset.push_back(arr[i]);
            }
        }

        // Check divisibility
        if (sum % K == 0) {
            count++;
            cout << "  Subset { ";
            if (subset.empty()) cout << "(empty)";
            else for (int x : subset) cout << x << " ";
            cout << "} --> sum = " << sum << "\n";
        }
    }

    cout << "--------------------------------------------\n";
    cout << "Total subsets divisible by " << K << ": " << count << "\n";
    cout << "(Out of " << totalSubsets << " total subsets)\n";

    return 0;
}