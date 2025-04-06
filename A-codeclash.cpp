
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000000LL
#define exp -1
#define vll vector<ll>
#define vi vector<ll>
#define vc vector<char>
#define vvll vector<vector<ll>>
#define vvc vector<vector<char>>
vll isPrime(exp+1,1);

ll maxiDays = 3000000;
vll daysMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

void createSieve(){
   isPrime[0]=0 , isPrime[1] = 0 ;
   for(ll i = 2 ; i*i <= exp ; i++){
       if(isPrime[i])
       {
          for(ll j = i*i ; j<=exp ; j+=i)
            isPrime[j] = 0 ;
       }
   }
}

vector<ll> zFunction(string &str) {
    ll n = str.length();
    vector<ll> z(n, 0);

    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (str[z[i]] == str[z[i] + i]) {
            z[i]++;
        }

        if (z[i] + i - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

void separator(const string& s, ll &y, ll &m, ll &d) {
    d = stoi(s.substr(8, 2));
    m = stoi(s.substr(5, 2));
    y = stoi(s.substr(0, 4));
}


ll dateToIndex(ll y, ll m, ll d) {
    ll days = y * 365 + d - 1;
    for (ll i = 0; i < m - 1; ++i)
        days += daysMonth[i];
    return days;
}

void indexToDate(ll index, ll &y, ll &m, ll &d) {
    y = index / 365;
    index %= 365;
    m = 0;
    while (m < 12 && index >= daysMonth[m]) {
        index -= daysMonth[m];
        m++;
    }
    d = index + 1;
    m = m + 1;
}


void solve() {
    ll n, y, d;
    cin >> n >> y >> d;

    vector<pair<ll, ll>> absences;
    ll lastDateIndex = 0;

    for (ll i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        ll y1, m1, d1, y2, m2, d2;
        separator(s1, y1, m1, d1);
        separator(s2, y2, m2, d2);
        ll start = dateToIndex(y1, m1, d1);
        ll end = dateToIndex(y2, m2, d2);
        absences.push_back({start , end});
        lastDateIndex = max(lastDateIndex, end);
    }

    vector<ll> present(maxiDays
    , 1);

    for (auto &i : absences) {
        for (ll j = i.first; j <= i.second; ++j)
            present[j] = 0;
    }

    vector<ll> prefix(maxiDays
     + 1, 0);
    for (ll i = 1; i < maxiDays
    ; ++i)
        prefix[i] = prefix[i - 1] + present[i - 1];

    for (ll today = lastDateIndex + 1;; ++today) {
        bool ok = true;
        for (ll i = 0; i < y; ++i) {
            ll from = today - 365 * (i + 1);
            ll to = today - 365 * i - 1;
            if (from < 0) {
                ok = false;
                break;
            }
            ll daysPresent = prefix[to + 1] - prefix[from];
            if (daysPresent < d) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ll yy, mm, dd;
            indexToDate(today, yy, mm, dd);
            printf("%04lld-%02lld-%02lld\n", yy, mm, dd);
            break;
        }
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1 ;
    while( t-- ) {
        solve() ;
    }
    return 0 ;
}



