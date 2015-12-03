#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int N;
int pre[100000 + 5], in[100000 + 5], post[100000 + 5];

int getInMid(int s, int t, int x) {
	if (s > t)	return -1;
	int mid = (s + t) / 2;
	for (int i = 0; mid + i <= t || mid - i > s; ++i) {
		if (mid + i <= t && in[mid + i] == x) return mid + i;
		if (mid - i >= s && in[mid - i] == x) return mid - i;
	}
	return -1;
}

void getPost(int sPre, int tPre, int sIn, int tIn, int sPost, int tPost) {
	if (sPre > tPre) return;
	if (sPre == tPre) { post[tPost] = pre[sPre]; return; }
	int midpos = getInMid(sIn, tIn, pre[sPre]);
	post[tPost] = pre[sPre];
	getPost(sPre + 1, sPre + midpos - sIn, sIn, midpos - 1, sPost, sPost + midpos - 1 - sIn);
	getPost(sPre + midpos - sIn + 1, tPre, midpos + 1, tIn, sPost + midpos - sIn, tPost - 1);
}

int main() 
{
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> pre[i];
	for (int i = 0; i < N; ++i) cin >> in[i];
	getPost(0, N - 1, 0, N - 1, 0, N - 1);
	for (int i = 0; i < N - 1; ++i) cout << post[i] << ' ';
	cout << post[N - 1] << endl;
	return 0;
}