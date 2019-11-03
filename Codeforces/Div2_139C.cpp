#include <bits/stdc++.h>

using namespace std;

#define MAX numeric_limits<int>::max()

int main() {
	char trash;
	int n, m, x, y, i, j, cont, ans, costOn, costOff;
	
	scanf("%d%d%d%d", &n, &m, &x, &y);
	vector<vector<char>> matrix(n,vector<char>(m));

	for (i=0; i<n; i++) {
		scanf("%c",&trash);
		for (j=0; j<m; j++) {
			scanf("%c",&matrix[i][j]);
		}
	}

	vector<int> arr(m);
	for (j=0; j<m; j++) {
		cont = 0;
		for (i=0; i<n; i++) {
			if (matrix[i][j]=='.') {
				cont++;
			}
		}
		arr[j] = cont;
	}

	/* States:
				index
				color
				#Columns */
	vector<vector<vector<int>>> dp(m+2,vector<vector<int>>(2,vector<int>(y+2,MAX)));
	
	dp[0][0][1] = n - arr[0];
	dp[0][1][1] = arr[0];

	for (i=1; i<m; i++) {
		costOn  = arr[i];
		costOff = n - arr[i];

		/* Changing color */
		for (j=x; j<=y; j++) {
			if (dp[i-1][1][j] != MAX) {
				dp[i][0][1] = min(dp[i][0][1], dp[i-1][1][j] + costOff);
			}
			if (dp[i-1][0][j] != MAX) {
				dp[i][1][1] = min(dp[i][1][1], dp[i-1][0][j] + costOn);
			}
		} 

		for (j=2; j<=y; j++) {
			if (dp[i-1][0][j-1] != MAX) {
				dp[i][0][j] = min(dp[i][0][j], dp[i-1][0][j-1] + costOff);
			}
			if (dp[i-1][1][j-1] != MAX) {
				dp[i][1][j] = min(dp[i][1][j], dp[i-1][1][j-1] + costOn);
			}
		}
	}
	ans = MAX;

	for (i=x; i<=y; i++) {
		ans = min(ans, min(dp[m-1][0][i], dp[m-1][1][i]));
	}

	printf("%d\n",ans);

	return 0;
}
