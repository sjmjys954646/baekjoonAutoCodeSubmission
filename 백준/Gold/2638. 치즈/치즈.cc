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

int arr[102][102];
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[102][102];
int newarr[102][102];

void dfs(int startY, int startX)
{

	visited[startY][startX] = 1;
	arr[startY][startX] = -1;

	for (int i = 0; i < 4; i++)
	{
		int nY = startY + dy[i];
		int nX = startX + dx[i];
		if (nX < 0 || nY < 0 || nX > M  + 1|| nY > N + 1)
			continue;
		if (visited[nY][nX])
			continue;
		if (arr[nY][nX] == 1)
			continue;

		dfs(nY, nX);
	}
}

bool check()
{
	int cur = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 1)
				cur++;
		}
	}

	return cur == 0;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0,0);

	int day = 0;
	while (true)
	{
		if (check())
			break;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				newarr[i][j] = arr[i][j];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (newarr[i][j] == 1)
				{
					int cal = 0;
					for (int k = 0; k < 4; k++)
					{
						int nY = i + dy[k];
						int nX = j + dx[k];
						if (nX < 0 || nY < 0 || nX > M + 1 || nY > N + 1)
							continue;

						if (arr[nY][nX] == -1)
							cal++;

					}

					if (cal >= 2)
						newarr[i][j] = -1;
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				arr[i][j] = newarr[i][j];
			}
		}


		memset(visited, 0, sizeof(visited));
		dfs(0, 0);

	/*	for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		day++;
	}

	cout << day;

	return 0;
}