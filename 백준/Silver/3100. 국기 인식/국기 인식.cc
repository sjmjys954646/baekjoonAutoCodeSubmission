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

char arr[10][10];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	rep(i, 6)
	{
		string tmp;
		cin >> tmp;
		rep(j, 9)
		{
			arr[i][j] = tmp[j];
		}
	}

	int ans = INF;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (i == j || j == k)
					continue;

				char board[10][10];
				for (int ii = 0; ii < 2; ii++)
				{
					for (int jj = 0; jj < 9; jj++)
					{
						board[ii][jj] = i + 'A';
					}
				}

				for (int ii = 2; ii < 4; ii++)
				{
					for (int jj = 0; jj < 9; jj++)
					{
						board[ii][jj] = j + 'A';
					}
				}

				for (int ii = 4; ii < 6; ii++)
				{
					for (int jj = 0; jj < 9; jj++)
					{
						board[ii][jj] = k + 'A';
					}
				}

				int sum = 0;
				for (int ii = 0; ii < 6; ii++)
				{
					for (int jj = 0; jj < 9; jj++)
					{
						if (board[ii][jj] != arr[ii][jj])
							sum++;
					}
				}
				ans = min(ans, sum);
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (i == j || j == k)
					continue;

				char board[10][10];
				for (int ii = 0; ii < 6; ii++)
				{
					for (int jj = 0; jj < 3; jj++)
					{
						board[ii][jj] = i + 'A';
					}
				}

				for (int ii = 0; ii < 6; ii++)
				{
					for (int jj = 3; jj < 6; jj++)
					{
						board[ii][jj] = j + 'A';
					}
				}

				for (int ii = 0; ii < 6; ii++)
				{
					for (int jj = 6; jj < 9; jj++)
					{
						board[ii][jj] = k + 'A';
					}
				}

				int sum = 0;
				for (int ii = 0; ii < 6; ii++)
				{
					for (int jj = 0; jj < 9; jj++)
					{
						if (board[ii][jj] != arr[ii][jj])
							sum++;
					}
				}
				ans = min(ans, sum);
			}
		}
	}
	
	cout << ans;

	return 0;
}