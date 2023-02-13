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

int n, s;
vi v;
bool visited[100002];

void bfs()
{
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		vi p;

		p.push_back(cur - v[cur]);
		p.push_back(cur + v[cur]);

		for (int i = 0; i < 2; i++)
		{
			int nX = p[i];

			if (nX < 1 || nX > n)
				continue;
			if (visited[nX] == true)
				continue;

			q.push(nX);
			visited[nX] = true;
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> n;

	v.push_back(0);

	rep(i, n)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	cin >> s;

	bfs();

	int ans = 0;
	rep1(i, n)
		if (visited[i])
			ans++;

	cout << ans;

	return 0;
}