/*
 * Author: Suki Sahota
 * Description: Technical Interview Practice
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    // Create an unorder_map named isOdd
    unordered_map<int, bool> isOdd;

    int pairs = 0;

    // Load isOdd with ar vector values
    for (auto it = ar.begin(); it != ar.end(); ++it) {
        auto itr = isOdd.find(*it);
        // Check if this sock is already in isOdd
        if (itr != isOdd.end()) {
            if ((*itr).second) {
                pairs++;
                (*itr).second = false;
            } else {
                (*itr).second = true;
            }
        } else {
            // Insert new sock into isOdd
            isOdd.insert(make_pair(*it, true));
        }
    }

    // Print and return the count of pairs of socks
    cout << pairs << endl;
    return pairs;
}

int main()
{
    return 0;
}
