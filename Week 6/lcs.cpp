#include <bits/stdc++.h>
using namespace std;
 
int longestConsecutive(vector<int> &arr) {
    unordered_set<int> numSet(arr.begin(), arr.end());
    int longest = 0;
    for (int x : numSet) {
        if (numSet.find(x - 1) == numSet.end()) {
            int len = 1;
            while (numSet.find(x + len) != numSet.end()) {
                len++;
            }
            longest = max(longest, len);
        }
    }
    return longest;
}

int main() {
    int n;
    cout << "eenter number of elements: ";
    cin >> n;
 
    vector<int> arr(n);
    cout << "enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    cout << "Longest consecutive sequence length: " << longestConsecutive(arr) << endl;
 
    return 0;
}