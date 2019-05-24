#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;

class SegTree {
	private: int n;
		vector <ll> st;

		int meio(int e, int d) {
			return (e+d)/2;
		}

		ll build(int p, int e, int d) {
			if(e==d) {
				st[p]=v[e];
				return 0;
			} else {
				int m=meio(e, d);
				int res = build(p+p, e, m);
				res = build(p+p+1, m+1, d);
				if(res==0) {
					st[p] = (st[p+p]|st[p+p+1]);
					return 1;
				} else {
					st[p] = (st[p+p]^st[p+p+1]);
					return 0;
				}
			}
		}

		ll update(int p, int e, int d, int pos, int val) {
			if(e>pos or d<pos)	return -1;

			if(e==pos and d==pos) {
				st[p]=val;
				return 0;
			}
			else {
				int m=meio(e, d);
				ll res = -1;
				res = max(res,update(p+p, e, m, pos, val));
				res = max(res,update(p+p+1, m+1, d, pos, val));
				if(res==0) {
					st[p]=(st[p+p]|st[p+p+1]);
					return 1;
				} else {
					st[p]=(st[p+p]^st[p+p+1]);
					return 0;
				}
			}
		}

		pair<ll,ll> query(int p, int e, int d, int i, int j) {
			if(e>j or d<i)	return make_pair(0,-1);
			if(e>=i and d<=j)	return make_pair(st[p],0);
			int m=meio(e, d);
			pair<ll,ll> q1=query(p+p, e, m, i, j);
			pair<ll,ll> q2=query(p+p+1, m+1, d, i, j);
			ll res = max(q1.second,q2.second);
			if(res==0) return make_pair(q1.first|q2.first,1);
			else return make_pair(q1.first^q2.first,0);
			//return (q1^q2);
		}

	public:		
		SegTree(int N) {
			n=N;
			st.assign(4*n, 0);
			build(1, 0, n-1);
		}

		ll update(int pos, int val) {
			return update(1, 0, n-1, pos, val);
		}

		pair<ll,ll> query(int i, int j) {
			return query(1, 0, n-1, i, j);
		}
};

int main() {
	ll n, m, i, size, pos, value;
	scanf("%lld%lld",&n,&m);
	size = (1<<n);
	v.resize(size);
	for(i=0; i<size; i++) {
		scanf("%lld",&v[i]);
	}
	SegTree mySeg(size);
	for(i=0; i<m; i++) {
		scanf("%lld%lld",&pos,&value);
		mySeg.update(pos-1,value);
		printf("%lld\n",mySeg.query(0,size-1).first);
	}
	return 0;
}