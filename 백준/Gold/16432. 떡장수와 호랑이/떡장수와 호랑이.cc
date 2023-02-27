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

int arr[1002][11];
int cache[1002][11];
int N;
int tmp, ttmp;
bool pos = false;
vi v;
vi ans;

void dfs(int index, int bef)
{
	if (index == N)
	{
		ans = v;

		pos = true;
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (arr[index][i] != 1)
			continue;

		if (cache[index + 1][i] != 0)
			continue;

		if (i == bef)
			continue;

		cache[index + 1][i] = bef;
		v.push_back(i);
		dfs(index + 1, i);
		v.pop_back();
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	rep(i, N)
	{
		cin >> tmp;
		rep(j, tmp)
		{
			cin >> ttmp;
			arr[i][ttmp] = 1;
		}
	}

	dfs(0, 0);

	if (pos)
	{
		for (auto i : ans)
			cout << i << "\n";
	}
	else
		cout << -1;

	

	return 0;
}