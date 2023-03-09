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
int inDegree[1002];
vector<int> arr[1002];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> M;

	int num;
	int tmp;
	rep(i, M)
	{	
		cin >> num;
		cin >> tmp;
		int a;
		rep(j, num - 1)
		{
			cin >> a;
			arr[tmp].push_back(a);
			inDegree[a]++;
			tmp = a;
		}
	}

	vi ans;
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	bool pos = true;
	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
		{
			pos = false;
			break;
		}

		int cur = q.front();
		q.pop();
		ans.push_back(cur);

		for (int j = 0; j < arr[cur].size(); j++)
		{
			int nx = arr[cur][j];
			if (--inDegree[nx] == 0)
				q.push(nx);
		}
	}

	if (pos)
	{
		for (auto i : ans)
			cout << i << "\n";
	}
	else
		cout << 0;


	return 0;
}