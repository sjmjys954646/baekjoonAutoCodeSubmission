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

vector<int> v;
int N, M;
int tmp;
vector<int> selected;
map<vi, int> m;
int visited[10];

void dfs(int idx)
{
	if (idx == M)
	{
		if (m.count(selected))
			return;
		else
			m[selected] = 1;

		for (auto i : selected)
			cout << i << " ";
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;

		selected.push_back(v[i]);
		visited[i] = 1;
		dfs(idx + 1);
		selected.pop_back();
		visited[i] = 0;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	dfs(0);

	return 0;
}