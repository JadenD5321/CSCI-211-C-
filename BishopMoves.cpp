

#include <iostream>
#include <cmath>
using namespace std;

bool okay(int q[], int c, int n) {
    for (int i = 0; i < c; i++)
        if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))// if col difference == row difference, bishop c and i are diagonal to each other
            return false;
    return true;
}

int kBishops(int n, int k) {
    int solutions = 0; // add a counter

    // dynamic allocate an array in heap base on k (num of bishops)
    int* q = new int[k];

    // place first bishop (c=0) at first (top-left) box (q[c]=0)
    int c = 0;
    q[c] = 0;

    // Represenatation of Backtracking Algorithim
    while (c >= 0) {
        c++;
        if (c == k) {
            solutions++;
            c--;
        }
        else
            q[c] = q[c - 1];

        // Position-loop (q[c]-loop)
        while (c >= 0) {
            q[c]++;
            if (q[c] == n*n)
                c--;
            else if (okay(q, c, n)) break;
        }
    }
    delete [] q;
    
    return solutions;
}

// find the possible moves in each direction for the bishop respectively.

int main() {
    int n, k;
    cout << "Enter value of n: ";
    cin >> n;

    if (n == -1)
        return 0;

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Number of solutions: " << kBishops(n, k) << "\n";

    return 0;
}