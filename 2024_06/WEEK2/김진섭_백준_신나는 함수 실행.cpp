#include <iostream>
#include <map>
#include <tuple>
using namespace std;

map<tuple<int, int, int>, int>value;


int recursion(int a, int b, int c) {

	if (value.find({ a,b,c }) != value.end()) return value[{ a, b, c }];

	if (a <= 0 || b <= 0 || c <= 0) return 1;	
	else if (a < b && b < c) return value[{ a, b, c }] = recursion(a, b, c - 1) + recursion(a, b - 1, c - 1) - recursion(a, b - 1, c);
	else return value[{ a, b, c }] = recursion(a - 1, b, c) + recursion(a - 1, b - 1, c) + recursion(a - 1, b, c - 1) - recursion(a - 1, b - 1, c - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a(0), b(0), c(0);	

	for (a = 1; a <= 20; ++a) {		
		for (b = 1; b <= 20; ++b) {
			for (c = 1; c <= 20; ++c) {
				value[{ a, b, c }] = recursion(a, b, c);
			}
		}
	}
	
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0) cout << "1\n";
		else if (a > 20 || b > 20 || c > 20) cout << value[{20, 20, 20}] << '\n';
		else cout << value[{a,b,c }] << '\n';
	}
}