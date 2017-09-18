#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Words {
public:
	Words() {}

	int fullCountUnder = 0;
	bool isFullWord = false;
	map<char, Words*> m;

	void insert(string text) {
		Words* word = this;
		word->fullCountUnder++;

		for (char &c : text) {
			Words* prev = word;
			word = word->has(c);

			if (word == NULL) {
				Words * newWord = new Words();
				prev->m.insert(pair<char, Words*>(c, newWord));
				word = newWord;
			}

			word->fullCountUnder++;
		}

		if (word != this) {
			word->isFullWord = true;
		}
	}

	Words* has(char c) {
		map<char, Words*>::iterator it = this->m.find(c);

		if (it != this->m.end()) {
			return it->second;
		}

		return NULL;
	}

	int matchCount(string partial) {
		Words* word = this;

		for (char& c : partial) {
			word = word->has(c);

			if (word == NULL) {
				return 0;
			}
		}

		return word->fullCountUnder;
	}
};

int main(){
    int n;
    cin >> n;
    
    const string find = "find";
    Words* words = new Words();
    
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        
        if(find.compare(op) == 0) {
            cout << words->matchCount(contact) << endl;
        } else {
            words->insert(contact);
        }
    }
    return 0;
}
