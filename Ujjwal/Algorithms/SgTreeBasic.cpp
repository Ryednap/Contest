#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class SegmentTree {
    public :
        SegmentTree (std :: vector<int> & v) {
            const int n = (int)v.size();
            A = v;
            st.assign(4 * n + 1, 0);
            lo.assign(4 * n + 1, 0); 
            hi.assign(4 * n + 1, 0);
            Init(1, 0, n - 1);
       }

       void Update(int pos, int val) {
           Update(1, pos, val);
       }

       int rmq (int l, int r ) {
           return RMQ (1, l, r);
       }

  private :
     std :: vector<int> lo, hi;
     std :: vector<int> st;
     std :: vector<int> A;

    void Set (int i) {
        st[i] = std :: min(st[2 * i], st[2 * i + 1]);
    }
    
     void Init (int i, int l, int r) {
         lo[i] = l;
         hi[i] = r;
         if(l == r) {
             st[i] = A[l];
             return;
         }
         
         int mid = (l + r)/2;
         Init(2 * i , l, mid);
         Init(2 * i + 1, mid + 1, r);
         Set(i);
     }

     void Update(int i, int pos, int value) {
         if (lo[i] > pos || hi[i] < pos) return;
         if (hi[i] == lo[i]) {
			st[i] = value;
             return;
         }
         
         Update(2 * i, pos, value);
         Update(2 * i + 1, pos, value);
         Set(i);
     }

     int RMQ (int i, int l, int r) {
         if(hi[i] < l || lo[i] > r) return INT_MAX;
         else if(hi[i] <= r && lo[i] >= l) {
          	return st[i];   
         }

         int a = RMQ (2 * i, l, r);
         int b = RMQ ( 2 * i + 1, l, r);
         return std :: min(a, b);
    }

};


int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	SegmentTree sg(v);
	cout << sg.rmq(1, 3) << endl;
	sg.Update(1, 1);
	cout << sg.rmq(1, 3) << endl;
    return 0;
}







