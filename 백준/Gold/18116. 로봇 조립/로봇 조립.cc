#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

struct Point {
	ll x, y;

	bool operator < (const Point& a)
	{
		if (y == a.y)
			return x < a.x;
		else
			return y < a.y;
	}
};

ll ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b)
{
	return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}


int manhat(int startX, int startY, int endX, int endY)
{
	return abs(startX - endX) + abs(startY - endY);
}

int N, M;

int par[1000002];
int parts[1000002];
int ans = 0;
int maxi = 0;

int find(int a)
{
	if (a == par[a])
		return a;
	else
		return par[a] = find(par[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;

	if (a > b)
		swap(a, b);
	par[a] = b;
	parts[b] += parts[a];
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= 1000001; i++)
	{
		par[i] = i;
		parts[i] = 1;
	}

	int a, b;
	for (int i = 0; i < N; i++)
	{
		char c;

		cin >> c;

		if (c == 'I')
		{
			cin >> a >> b;
			merge(a, b);
		}
		else if (c == 'Q')
		{
			cin >> a;
			
			cout << parts[find(a)]<<"\n";
		}
	}


	return 0;
}