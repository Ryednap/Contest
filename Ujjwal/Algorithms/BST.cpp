#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

template<class T, class U> 
struct Node {
	T key;
	U value;
	int h = 1;
	Node * left = nullptr, *right = nullptr;

	Node () {}
	Node (T a, U b) : key(a) , value(b), h(1) {}
	Node (pair<T, U> p) {
		key = p.first;
		value = p.second;
		h = 1;
	}
	pair<T, U> Get_pair() {
		return make_pair(key, value);
	}
};


template<class T, class U> 
struct Map { // AVL implementation use of C++ map
	using Ntu = Node < T, U > ;
	using Ptu = pair < T, U > ;
	Ntu * Root  = nullptr;

	Map() {}
	
	
	void Add (const Ptu & p) {
		Root = Insert (Root, p);
	}
	void Add (Ptu & p) {
		Root = Insert(Root, p);
	}
	void Add (int key, int value) {
		Ptu p = make_pair(key, value);
		Add(p);
	}

	void Remove (const int & key) {
		Root = remove (Root, key);
	}

	int & operator [] (const int key) {
		Ntu * ref = Find(key);
		if(ref == nullptr) {
			Add(make_pair(key, 0));
			ref = Find(key);
			assert(ref != nullptr);
		}
		return ref -> value;
	}
	
	bool Present(const int key) {
		Ntu * ref = Find(key);
		return ref != nullptr;
	}
	
#ifdef LOCAL
	void Inorder(Ntu * root) {
		if(root == nullptr) return;
		Inorder(root -> left);
		debug() << owo(root->Get_pair());
		Inorder(root->right);
	}
#endif
	private :

		Ntu * Right_Rotate (Ntu * node) {
			Ntu * next = node -> left;
			Ntu * next_right = next -> right;

			next-> right = node;
			node -> left = next_right;
			Set_height(node);
			Set_height(next);
			return next;
		}

		Ntu * Left_Rotate (Ntu * node) {
			Ntu * next = node -> right;
			Ntu * next_left = next -> left;
			
			next-> left = node;
			node -> right = next_left;
			Set_height(node);
			Set_height(next);
			return next;
		}

		Ntu * Get_min_Node (Ntu * node) {
			Ntu * a = node;
			while (a -> left != nullptr) {
				a = a -> left;
			}
			return a;
		}

		int H (Ntu * node) {
			if(node == nullptr) return 0;
			else return node -> h;
		}

		void Set_height (Ntu * node) {
			assert (node != nullptr);
			int a = H(node -> left);
			int b = H(node -> right);
			node -> h = max(a, b) + 1;
		}

		int Get_balance (Ntu * node ) {
			if(node == nullptr) return 0;
			else {
				return H(node -> left) - H(node -> right);
			}
		}


		Ntu * Insert (Ntu * root, const Ptu & p) {
			if(root == nullptr) {
				return new Ntu (p);
			} else if(root -> key > p.first) {
				root -> left = Insert(root -> left, p);
			} else if(root -> key < p.first) {
				root -> right = Insert(root -> right, p);
			} else return root; // Same key found

			Set_height(root);
			int d = Get_balance(root); // get the imbalance factor

			if(d > 1) { // left heavy
				int w = root -> left -> key;
				assert(root -> left != nullptr);
				if(p.first > w) {
					root -> left = Left_Rotate (root -> left);
				}
				return Right_Rotate (root);

			} else if(d < -1) { // right heavy
				int w = root -> right -> key;
				assert( root -> right != nullptr);
				if(p.first < w) {
					root -> right = Right_Rotate (root -> right);
				}
				return Left_Rotate (root);
			}

			return root;
		}
		Ntu * remove (Ntu * root, const int & key ) {
			if(root == nullptr) return root;
			
			if(root -> key > key) {
				root -> left = remove(root -> left, key);
			} else if(root -> key < key) {
				root -> right = remove(root -> right, key);
			} else { // target found

				if(root -> left == nullptr || root -> right == nullptr) { // 1 child case
					Ntu * temp = root -> left ? root -> left : root -> right;
					if(temp == nullptr) { // No child case
						temp = root; root = nullptr;
					} else *root = *temp; // copy the information for temp and root
					free(temp);

				} else { // 2 child case
					Ntu * temp = Get_min_Node (root -> right);
					root -> key = temp -> key;
					root -> value = temp -> value;
					root -> right = remove (root -> right, temp -> key); // remove the in-order successor
				}
			}

			if(root == nullptr) return root;
			assert(root != nullptr);
			Set_height(root);
			int d = Get_balance(root);
			int d_l = Get_balance(root -> left);
			int d_r = Get_balance(root -> right);
			//debug() << owo(d) owo(d_l) owo(d_r) owo(root -> Get_pair());
			if(d > 1) {
				if(d_l < 0) { // left will be negative when the right of it will be heavy making the left - right rotation
					root -> left = Left_Rotate(root -> left);
				}
				return Right_Rotate(root);
			} else if(d < -1) {
				if(d_r > 0) { // right will be positive when the left of it will be more haavy.
					root -> right = Right_Rotate(root -> right);
				} 
				return Left_Rotate(root);
			}
			return root;
		}

		Ntu * Find(const int & key) {
			for(Ntu * i = Root; i != nullptr; ) {
				if(i -> key == key) return i;
				else if(i -> key > key) {
					i = i -> left;
				} else {
					i = i -> right;
				}
			}
			return nullptr;
		}

};

#ifdef LOCAL
	template<class T, class U>
	debug & operator << (debug & d, const Map<T, U> & m) {
		m.Inorder(m.Root);
		return d;
	}
#endif

int main() {
	return 0;
}
