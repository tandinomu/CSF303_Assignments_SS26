#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────────
// KMP: Compute LPS (Longest Prefix Suffix) array
//
// LPS[i] = length of the longest proper prefix of pattern[0..i]
//          that is also a suffix of pattern[0..i]
// "Proper" means it cannot be the full string itself.
// ─────────────────────────────────────────────────────────────────────────────
vector<int> computeLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0;  // length of previous longest prefix-suffix
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            // Characters match — extend the prefix-suffix
            lps[i] = ++len;
            i++;
        } else {
            if (len != 0) {
                // Fall back using previously computed LPS value
                // (do NOT increment i here)
                len = lps[len - 1];
            } else {
                // No prefix-suffix possible at this position
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    cout << "==========================================\n";
    cout << "  Assignment 2 - Q5: String Matching\n";
    cout << "==========================================\n\n";

    // ── Part (a): KMP LPS Array ───────────────────────────────────────────
    cout << "--- Part (a): KMP — LPS Array for \"ABABCABAB\" ---\n\n";

    string pattern = "ABABCABAB";
    vector<int> lps = computeLPS(pattern);

    // Print index row
    cout << "  Index  : ";
    for (int i = 0; i < (int)pattern.size(); i++)
        cout << setw(4) << i;
    cout << "\n";

    // Print character row
    cout << "  Char   : ";
    for (char c : pattern)
        cout << setw(4) << c;
    cout << "\n";

    // Print LPS row
    cout << "  LPS    : ";
    for (int x : lps)
        cout << setw(4) << x;
    cout << "\n\n";

    // Step-by-step derivation
    cout << "  Step-by-step derivation:\n";
    cout << "  ┌───────┬──────┬─────────────────────────────────────────────┐\n";
    cout << "  │ Index │ Char │ Reasoning                                   │\n";
    cout << "  ├───────┼──────┼─────────────────────────────────────────────┤\n";
    cout << "  │   0   │  A   │ First char, no proper prefix → LPS[0] = 0  │\n";
    cout << "  │   1   │  B   │ 'B' != 'A', no match         → LPS[1] = 0  │\n";
    cout << "  │   2   │  A   │ 'A' == 'A' (pat[0])          → LPS[2] = 1  │\n";
    cout << "  │   3   │  B   │ 'B' == 'B' (pat[1])          → LPS[3] = 2  │\n";
    cout << "  │   4   │  C   │ 'C' != 'A', fallback len=0   → LPS[4] = 0  │\n";
    cout << "  │   5   │  A   │ 'A' == 'A' (pat[0])          → LPS[5] = 1  │\n";
    cout << "  │   6   │  B   │ 'B' == 'B' (pat[1])          → LPS[6] = 2  │\n";
    cout << "  │   7   │  A   │ 'A' == 'A' (pat[2])          → LPS[7] = 3  │\n";
    cout << "  │   8   │  B   │ 'B' == 'B' (pat[3])          → LPS[8] = 4  │\n";
    cout << "  └───────┴──────┴─────────────────────────────────────────────┘\n\n";

    return 0;
}