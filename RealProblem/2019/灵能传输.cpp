#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>s(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s[i + 1] = s[i] + x;
        }

        ll s0 = s[0], sn = s[n];
        if (s0 > sn) swap(s0, sn);
        sort(s.begin(), s.end());
        for (int i = 0; i <= n; i++) if (s[i] == s0) {
            s0 = i;
            break;
        }
        for (int i = n; i >= 0; i--) if (s[i] == sn) {
            sn = i;
            break;
        }

        vector<ll>a(n + 1);
        vector<bool>v(n + 1);
        int l = 0, r = n;
        for (int i = s0; i >= 0; i -= 2)
            a[l++] = s[i], v[i] = true;
        for (int i = sn; i <= n; i += 2)
            a[r--] = s[i], v[i] = true;
        for (int i = 0; i <= n; i++)
            if (!v[i]) a[l++] = s[i];

        ll ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, abs(a[i] - a[i - 1]));
        cout << ans << '\n';
    }
    return 0;
}