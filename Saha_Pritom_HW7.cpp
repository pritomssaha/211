#include <iostream>
#include <cmath>
#include<cstdlib>
using namespace std;

bool ok(int q[], int col) {
	int mp[3][3] = { { 0, 2, 1 }, { 0, 2, 1 }, { 1, 2, 0 } };
	int wp[3][3] = { { 2, 1, 0 }, { 0, 1, 2 }, { 2, 0, 1 } };
	int i;

	for (i = 0; i<col; i++){
		if (q[col] == q[i])
			return false;
	}
	for (i = 0; i<col; i++){
		if ((mp[col][q[i]]<mp[col][q[col]]) && (wp[q[i]][col]<wp[q[i]][i])){
			return false;
		}
		if ((wp[q[col]][i]<wp[q[col]][col]) && (mp[i][q[col]]<mp[i][q[i]])){
			return false;
		}
	}
	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i = 0; i < 3; ++i)
		cout << i << "\t" << q[i] << "\n";
	cout << "\n";
}

void backtrack(int &c){
	c--;// Go back to the previous column
	if (c<0){
		exit(0);
	}
}
int main() {
	int q[3] = {};
	q[0] = { 0 };
	int c = 0;
	while (c >= 0) {
		c++;  // Move to the next column
		if (c>2)	{// If you have passed the last column,
			print(q);
			backtrack(c);
		}// Call the print function and backtrack
		while (c >= 0) {
			q[c]++;// Move to the next row
			if (q[c]>2){
				q[c] = -1;
				backtrack(c);
			}// If you have passed the end of the column, backtrack

			else{
				if (ok(q, c)){
					break;
				}
			}
		}
		if (c == -1){
			break;
		}
	}
	return 0;
}