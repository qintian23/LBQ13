#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
ll ex, ey, dis;

ll max_abs(ll x, ll y){
	return max(abs(x), abs(y));
}

int main(int argc, char const *argv[]){
	scanf("%lld%lld", &ex, &ey);
	ll m_abs;
	m_abs = max_abs(ex, ey);
	if (ex >= 0 && ey >= 0){
		if (ex <= ey)
			dis = 4 * m_abs * m_abs - abs(ex - ey);
		else
			dis = 4 * m_abs * m_abs + abs(ex - ey);
	}else if (ex < 0 && ey > 0){
		dis = 4 * m_abs * m_abs - 2 * m_abs + (ex + ey);
	}else if (ex <= 0 && ey <= 0){
		if (ex >= ey)
			dis = 4 * m_abs * m_abs + 2 * m_abs - (ex + ey);
		else
			dis = 4 * m_abs * m_abs - 2 * m_abs + (ex + ey);
	}else if (ex > 0 && ey < 0){
		dis = 4 * m_abs * m_abs + 2 * m_abs - (ex + ey);
	}
	printf("%lld\n", dis);
	return 0;
}