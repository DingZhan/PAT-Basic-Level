#include <iostream>
#include <cstdlib>

using namespace std;

/*
输入样例1：
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#
输出样例1：
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
输入样例2：
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
输出样例2：
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
*/
const int MAX_N = 11;
int main() {
	std::string A[MAX_N], pass, str;
	int i, N, n;
	cin >> pass >> N;
	cin.ignore();
	n = 0;
	while (true)
	{
		std::getline(cin, str);
		if (str == "#")
			break;
		if (n >= N)
		{
			++n;
			continue;
		}
		A[n] = str;
		++n;
	}
	for (i = 0; i<n; ++i)
	{
		if (i<N && pass == A[i])
		{
			cout << "Welcome in" << endl;
			break;
		}
		else if (i<N)
		{
			cout << "Wrong password: " << A[i] << endl;
			if (i == N - 1)
			{
				cout << "Account locked" << endl;
				break;
			}
		}
	}
	//    system("pause");
	return 0;
}
