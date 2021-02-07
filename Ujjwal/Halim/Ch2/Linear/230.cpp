#include <bits/stdc++.h>

// A very implementation heavy problemn

// A miss in the statement caused a long time : They should have mention that the libaray is also sorted , but instead they told that the book 
// returned are inserted in sorted order. That made me to code assuming that the returned book will occupy the first empty slot in the selve.

// O(n^2) complexity where n = total number of books.

/**
 * Note :- Take care of spaces after the input in case of dealing problems on string
 * Also use a proper form to compare the input for sorting like convert all of them to the lowercase and remove space
 * Always use assert to check for find function like scheme for string.
 *
 */


// Level : 4

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

static inline void ltrim(std :: string & s) {
	s.erase(s.begin(), std :: find_if(s.begin(), s.end(), [] (unsigned char ch)  {
		return !std :: isspace(ch);
	}));
}

static inline void rtrim(std :: string & s) {
	s.erase(std :: find_if(s.rbegin(), s.rend(), [] (unsigned char ch ) {
		return !std :: isspace(ch);
	}).base(), s.end());
}

static inline void trim(std :: string & s) {
	ltrim(s);
	rtrim(s);
}

static inline std :: string toString (char sc [] , int n ) {
	std :: string s = "";
	for(int i = 0; i < n; ++i) {
		s += sc[i];
	}
	return s;
}

static inline std :: string F (string s) {
	string res = "", tok;
	stringstream ss(s);
	while( ss >> tok ) {
		transform(tok.begin(), tok.end(), tok.begin() , ::tolower);
		res += tok;
	} 
	return res;
}

struct Book {
	string title, author;
	Book() {}
	Book(string a, string b) : title(a), author(b) {}
	bool operator < (const Book & b) const {
		if(F(author) == F(b.author)) {
			return F(title) < F(b.title);
		} else return F(author) < F(b.author);
	}
	bool operator == (Book & b)  {
		return F(author) == F(b.author) && F(title) == F(b.title);
	}
};	

//debug & operator << (debug & d, Book & b )  {
	//d << b.title << ' ' << b.author ;
	//return d;
//}

int main() {
	string str;
	vector<Book> lib;
	map<string, Book> mapper;
	while(getline(cin, str) && str != "END") {
		trim(str);
		string a = "", b = "", inp;
		stringstream ss(str);
		bool split = false;
		while( ss >> inp ) {
			trim(inp);
			if(inp == "by") split = true;
			else if(split) b += inp + " ";
			else a += inp + " ";
		}
		trim(a) ; trim(b);
		Book bb = Book(a, b);
		mapper[a] = bb;
		lib.push_back(bb);
	}
	

	sort(lib.begin(), lib.end());
	vector <Book> ret;
	while(cin >> str && str != "END") {
		trim(str);
		if(str == "BORROW") {
			getline(cin, str);
			trim(str);
			
			auto itr = lib.begin();
			for(; itr != lib.end(); ++itr) {
				if(itr->title == str) break;
			}
			assert(itr != lib.end());
			lib.erase(itr);
			
		} else if(str == "RETURN") {
			getline(cin, str);
			trim(str);
			ret.push_back(mapper[str]);
			
		} else {
			for(auto b : ret) {
				lib.push_back(b);
			}
			sort(lib.begin(), lib.end());
			sort(ret.begin(), ret.end());
			//debug() << owo(ret);
			for(auto b : ret) {
				Book prev ("", "");
				for (auto a : lib) {
					if(a == b) break;
					else prev = a;
				}
				if(prev.title == "") {
					printf("Put %s first\n",b.title.c_str());
				} else {
					printf("Put %s after %s\n",b.title.c_str(), prev.title.c_str());
				}
			}
			ret.clear();
			puts("END");
		}
	}
	return 0;
}
