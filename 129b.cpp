//joyneel
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

set<int> g[105];
int d[105];

int main(){
	int n,m,a,b;
	si(n);si(m);
	for(int i=0;i<m;i++){
		si(a);si(b);
		g[a].insert(b);
		g[b].insert(a);
		d[a]++;
		d[b]++;
	}
	int ans=0,cnt;
	VI v;
	while(1){
		cnt=0;
		v.clear();	
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				cnt++;
				v.PB(i);
				d[i]=0;
			}
		}
		for(int k=0;k<SZ(v);k++){
				int i = v[k];
				for(auto j=g[i].begin();j!=g[i].end();j++){
					int w = *j;
					g[w].erase(i);
					d[w]--;
				}
		}
//		trace(cnt);
		if(!cnt)
			break;
		else
			ans++;
	}
	dout(ans);
	return 0;
}
