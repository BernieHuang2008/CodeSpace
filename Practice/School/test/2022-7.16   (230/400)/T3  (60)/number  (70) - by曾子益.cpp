#include <bits/stdc++.h>
using namespace std;
int a, c = -1, d = -1;
const int H = 2e5 + 5;
long long b[H];

bool fun_g(int one, int two) {
	if (one > two) {
		return true;
	}
	return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + a + 1, fun_g);
	for (int i = 2; i <= a; i++) {
		if (b[i] != b[1]) {
			c = b[i];
			for (int j = i; j <= a; j++) {
				if (b[j] != b[i]) {
					d = b[j];
					break;
				}
			}
			break;
		}
	}
	for (int i = 1; i < a; i++) {
		for (int j = i + 1; j <= a; j++) {
			int e = b[i] % b[j];
			if (e < c && e > d) {
				d = e;
			}
		}
	}
	cout << d;
	return 0;
}