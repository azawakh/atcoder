#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define lrep(i, n) for (ll i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(a, b) { int temp = a; a = b; b = temp; }
#define lswap(a, b) { ll temp = a; a = b; b = temp; }

typedef struct {
  ll prime_number;
  int exponent;
} Factor;

typedef struct {
  Factor list[10010];
  int count;
} Factors;

void increment_exponent(int i,Factors*factors){
  factors->list[i].exponent+=1;
}

void add_factor(ll x,Factors*factors){
  factors->list[factors->count].prime_number=x;
  increment_exponent(factors->count,factors);
  factors->count+=1;
}

void add_or_increment(ll x,Factors*factors){
  rep(i,factors->count){
    if(factors->list[i].prime_number==x){
      return increment_exponent(i,factors);
    }
  }
  add_factor(x,factors);
}

void find_smallest_prime_factor(ll x,Factors*factors){
  if(x<=1)return;
  for(ll i=2;i*i<=x;i+=1){
    if(x%i==0){
      add_or_increment(i,factors);
      return find_smallest_prime_factor(x/i,factors);
    }
  }
  add_or_increment(x,factors);
}

Factors*find_prime_factors(ll x){
  Factors*factors=malloc(sizeof(Factors));
  factors->count=0;
  find_smallest_prime_factor(x,factors);
  return factors;
}

void debug(Factors*factors){
  rep(i,factors->count){
    printf("%lld to the power %d\n",factors->list[i].prime_number,factors->list[i].exponent);
  }
}

ll mypow(ll base, int exponent){
  ll r=1;
  if(exponent==0)return r;
  rep(i,exponent){
    r*=base;
  }
  return r;
}

int main() {
  ll n,p;
  scanf("%lld%lld",&n,&p);
  Factors*factors=find_prime_factors(p);
  // debug(factors);

  ll ans=1;
  rep(i,factors->count){
    ll quotient=factors->list[i].exponent/n;
    ans *= quotient<1 ? 1 : mypow(factors->list[i].prime_number,quotient);
  }
  printf("%lld\n",ans);

  free(factors);
  return 0;
}
