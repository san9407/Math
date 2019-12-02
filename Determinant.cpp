//C++로 디터미넌트 구하기
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <regex>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const long long LINF = 1e18 + 1;
typedef long long ll;
typedef pair<int, int> P;

double mat[10][10] =
{
	-21,-29,83,79,31,-12,78,27,-56,-63,
	-24,-77,-65,24,-76,53,66,-22,-70,-69,
	-96,-10,-95,0,-17,20,4,31,-41,13,
	-81,-23,24,-55,-50,28,40,-3,-83,44,
	44,-35,-94,62,-68,49,94,71,17,-90,
	-46,67,89,-71,-91,18,-16,13,37,38,
	-57,-5,-7,-51,60,-42,-15,93,99,-27,
	-30,-70,77,-46,99,-15,77,43,21,-82,
	71,71,34,50,10,4,50,49,19,94,
	38,-8,69,15,60,71,32,8,25,33
};

double determinant(double matrix[10][10], int n)
{
	double det = 0;
	double submatrix[10][10];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}

int main()
{
	printf("%lf\n", determinant(mat, 10));
	return 0;
}
