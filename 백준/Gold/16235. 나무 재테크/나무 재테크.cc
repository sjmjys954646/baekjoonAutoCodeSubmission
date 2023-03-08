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



struct namu {
	int age;
	int curY;
	int curX;
};

struct compare
{
	bool operator()(namu& a, namu& b)
	{
		return a.age > b.age;
	}
};

bool cmp(namu& a, namu& b)
{
	return a.age < b.age;
};

int N, M, K;
int energy[12][12];
int winterAddEnergy[12][12];
int a, b, c;
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
vector<namu> deadNamu;
vector<namu> finNamu;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	deque<namu> nm;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			energy[i][j] = 5;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> winterAddEnergy[i][j];
	}
	
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		nm.push_back({ c,a-1,b-1 });
	}

	sort(nm.begin(), nm.end(), cmp);

	for (int year = 0; year < K; year++)
	{
		//Spring
		for(int i = 0;i < nm.size();i++)
		{
			namu it = nm[i];
			int curAge = it.age;
			int curY = it.curY;
			int curX = it.curX;
			namu agedIt = { curAge + 1,curY,curX };

			if (energy[curY][curX] >= curAge)
			{
				finNamu.push_back(agedIt);
				energy[curY][curX] -= curAge;
			}
			else
			{
				deadNamu.push_back(it);
			}
		}
		nm.clear();

		//Summer
		for (int i = 0; i < deadNamu.size(); i++)
		{
			int curAge = deadNamu[i].age;
			int curY = deadNamu[i].curY;
			int curX = deadNamu[i].curX;
			curAge = curAge / 2;
			energy[curY][curX] += curAge;
		}
		deadNamu.clear();

		//Autumn
		for (int i = 0; i < finNamu.size(); i++)
		{
			namu it = finNamu[i];
			nm.push_back(it);

			if (it.age % 5 != 0)
				continue;

			for (int j = 0; j < 8; j++)
			{
				int ny = it.curY + dy[j];
				int nx = it.curX + dx[j];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N)
					continue;

				nm.push_front({ 1,ny,nx });
			}
		}
		finNamu.clear();
		
		//Winter
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				energy[i][j] += winterAddEnergy[i][j];
		}

		if (nm.size() == 0)
			break;
		
	}

	cout << nm.size();

	return 0;
}