#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> t[3];
	int n;
	cout << "Please enter the number of rings to move: ";
	cin >> n;
	cout << endl;

	int c, d;
	if (n % 2 == 0){
		d = 1;
		c = 2;
	}
	else{
		c = 1;
		d = 2;

	}

	int from = 0, to = c, candidate = 1, move = 0;

	// Initialize the towers
	for (int i = n + 1; i >= 1; --i)
		t[0].push_back(i);
	t[1].push_back(n + 1);
	t[2].push_back(n + 1);

	while (t[1].size() < n + 1) { 
		cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 'A') << " to tower " << char(to + 'A') << "\n";

		
		int x = t[from].back();
			t[to].push_back(x);
		t[from].pop_back();

		
		if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()){
			from = (to + 1) % 3;
		}
		else
			from = (to + 2) % 3;

		
		candidate = t[from].back();

		
		if (t[(from + c) % 3].back() > candidate){
			to = (from + c) % 3;
		}
		else{
			to = (from + d) % 3;
		}
	}

	return 0;
}