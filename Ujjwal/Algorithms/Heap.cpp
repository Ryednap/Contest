#include <bits/stdc++.h>

using namespace std;

class Heap {
    
    vector<int> v;
    int Size = 0;

    Heap () {}
    Heap (int n, int arr [] ) {
        v.resize(n + 1);
        Size = n;
        for (int i = 1; i <= n; ++i) {
           v[i] = arr[i - 1];
        }
        size = n;
        Build_Heap();
    }
    Heap (int n, vector<int> arr) {
        v.resize(nax);
        for(int i = 1; i <= n; ++i) {
            v[i] = arr[i - 1];
        }
        size = n;
        Build_Heap();
    }

    void insert (int x) {
        ++size;
        if(size >= nax << 1 - 1) v.resize(nax + nax);
        v[size] = x;
        Max_Heapify(size);
    }

    int front() {
        return v[1];
    }

    bool Empty() {
        return size != 0;
    }

    int pop () {
        int ret = front();
    }

    private :
        void Max_Heapify (int i) {
            int l = i >> 1;
            int r = i >> 1 + 1;
            
        }

        void Build_Heap () {
          for(int i = n / 2; i >= 1; --i) {
              Max_Heapify(i);
          }
}

int main() {
    return 0;
}