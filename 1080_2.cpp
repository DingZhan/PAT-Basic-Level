#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct StudentAdv
{
	std::string name;
	short p;
	short m;
	short n;
	short ave;
	char type; //0 p, 1 m, 2 n
};
bool CompareName(const StudentAdv& a, const StudentAdv& b)
{
	if (a.name<b.name)
		return true;
	else if (a.name>b.name)
		return false;
	if (a.type<b.type)
		return true;
	else
		return false;
}
bool CompareAdv(const StudentAdv& a, const StudentAdv& b)
{
	if (a.ave>b.ave)
	{
		return true;
	}
	else if (a.ave<b.ave)
	{
		return false;
	}
	else if (a.name<b.name)
		return true;
	else
		return false;
}
#define MAX_N 10001
#define MAX_3N 30009
StudentAdv Ps[MAX_3N];
int main()
{
	int P, M, N, i, t, ave;
	StudentAdv results[MAX_N];
	cin >> P >> M >> N;
	for (i = 0; i<P; ++i)
	{
		cin >> Ps[i].name >> Ps[i].ave;
		Ps[i].type = 0;
	}
	for (i = 0; i<M; ++i)
	{
		cin >> Ps[i + P].name >> Ps[i + P].ave;
		Ps[i + P].type = 1;
	}
	for (i = 0; i<N; ++i)
	{
		cin >> Ps[i + P + M].name >> Ps[i + P + M].ave;
		Ps[i + P + M].type = 2;
	}
	std::sort(Ps, Ps + P + M + N, CompareName);

	t = 0;
	for (i = 0; i<P + M + N; )
	{
		if (Ps[i].type != 0)
		{
			++i;
			continue;
		}
		if (Ps[i].ave<200)
		{
			++i;
			continue;
		}
		else
		{
			if (Ps[i + 1].name == Ps[i].name && Ps[i + 2].name == Ps[i].name)
			{
				if (Ps[i + 1].ave<Ps[i + 2].ave)
					ave = Ps[i + 2].ave;
				else
					ave = int(Ps[i + 1].ave*0.4 + Ps[i + 2].ave*0.6 + 0.5);
				if (ave<60)
				{
					i += 3;
					continue;
				}
				results[t].ave = ave;
				results[t].name = Ps[i].name;
				results[t].p = Ps[i].ave;
				results[t].m = Ps[i + 1].ave;
				results[t].n = Ps[i + 2].ave;
				++t;
				i += 3;
				continue;
			}
			else if (Ps[i + 1].name == Ps[i].name)
			{
				if (Ps[i + 1].type == 1)
				{
					i += 2;
					continue;
				}
				else
				{
					ave = Ps[i + 1].ave;
					if (ave<60)
					{
						i += 2;
						continue;
					}
					results[t].ave = ave;
					results[t].name = Ps[i].name;
					results[t].p = Ps[i].ave;
					results[t].m = -1;
					results[t].n = Ps[i + 1].ave;
					++t;
					i += 2;
					continue;
				}
			}
			else
			{
				++i;
				continue;
			}
		}
	}

	std::sort(results, results + t, CompareAdv);
	for (i = 0; i<t; ++i)
	{
		cout << results[i].name << " " << results[i].p << " " << results[i].m << " " << results[i].n << " " << results[i].ave << endl;
	}
	return 0;
}

