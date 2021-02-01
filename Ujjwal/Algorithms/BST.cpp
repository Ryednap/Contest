#include <bits/stdc++.h>

using namespace std;

template<typename T, typename U> 
struct BST {
    vector<U> v;
    BST () { }
    BST (int n, T arr) {
        v.resize(n);
        fill(v.begin(), v.end(), -1); // change this is -1 is one of the input
        for(auto x : arr) {
            Add(x, 0);
        }
    }

    static void Add(const & U value, int node) {)
        if(v[node] == -1) {
            v[node] = value;
           
        } else if(value >= v[node]) {
            Add(value, 2 * node + 1);
        } else {
            Add(value, 2 * node);
        }
    }

    static void Delete(const & U value) {
            
    }


};

int main() {
    return 0;
}