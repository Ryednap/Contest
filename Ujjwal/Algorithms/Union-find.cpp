#include <bits/stdc++.h>

class UnionFind {
    public :
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n);
            total = n;
            for(int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        int Get (int a) {
            if(a == parent[a]) return a;
            else return parent[a] = Get(parent[a]);
        }

        bool Unite (int a, int b) {
            a = Get(a);
            b = Get(b);
            if(a != b) {
                if(rank[a] > rank[b]) std :: swap(a, b);
                rank[b] += rank[a];
                parent[a] = b;
                --total; // total number of sets decreases.
                return true;

            } else return false;
        }

        int sizeOfSet (int a) {
            a = Get(a);
            return rank[a];
        }

        int numDisjointSets() {
            return total;
        }

    private :
        std :: vector<int> parent;
        std :: vector<int> rank;
        int total = 0;
};

int main() {
    return 0;
}