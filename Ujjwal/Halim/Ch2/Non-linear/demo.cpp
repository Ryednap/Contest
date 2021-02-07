#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> s;
	s.insert(22);
	auto itr = s.begin();
	cout << *itr << endl;
	s.insert(1);
	cout << *itr << endl;
	++itr;
	cout << *itr << endl;
	return 0;
}
