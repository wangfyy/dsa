The World's Richest (25)

Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. 
Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. 
That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains 2 positive integers: N (<=105) - the total number of people, 
and K (<=103) - the number of queries. 
	queries  查询；问题；怀疑；问号  query的复数形式
Then N lines follow, 
each contains the name (string of no more than 8 characters without space), 
age (integer in (0, 200]), and the net worth (integer in [-106, 106]) of a person. 
Finally there are K lines of queries, 
each contains three positive integers: M (<= 100) - the maximum number of outputs, 
and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:
For each query, first print in a line "Case #X:" where X is the query number starting from 1. 
Then output the M richest people with their ages in the range [Amin, Amax]. 
Each person's information occupies a line, in the format    '
Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. 
	In case there are equal worths, it must be in non-decreasing order of the ages. 
	If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. 
		即： 财富-年龄-姓名
It is guaranteed that there is no two persons share all the same of the three pieces of information. 
	In case no one is found, output "None".


Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50

Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None

Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None



#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100010;

int N, K;
int M, Amin, Amax;
int flag;

struct node{
	char name[30];
	int years;
	int money;
}Node[MAXN];

void solve() {
	int i = 0, num = 0;
	for(int j=0; j<N; j++) {
		if(Node[i].years >= Amin && Node[i].years <= Amax) {
			printf("%s %d %d\n",Node[i].name,Node[i].years,Node[i].money);
			num++;			
		}
		i++;
		if(num == M) break;
	}
	if(num == 0) flag = 1;
}

bool cmp(node a, node b) {
	if(a.money != b.money) return a.money > b.money;
	else if(a.years != b.years) return a.years < b.years;
	else return strcmp(a.name, b.name) < 0;  //////按名字典序从小到大
}
int main() {
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++) {
		scanf("%s %d%d",&Node[i].name,&Node[i].years,&Node[i].money);  ////
	}
	sort(Node,Node+N,cmp);
	// for(int i=0; i<N; i++) {
	// 	printf("%s %d %d\n",Node[i].name,Node[i].years,Node[i].money);
	// }
	for(int i=0; i<K; i++) {
		scanf("%d%d%d",&M,&Amin,&Amax);
		printf("Case #%d:\n",i+1);
		solve();
		if(flag == 1) printf("None\n");
	}

	return 0;
}