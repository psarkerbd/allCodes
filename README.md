//# codeing
//fohinni
.........................................................................................................................

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <sstream>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#define sf scanf
#define pf printf
#define sfint(a) scanf("%d",&a)
#define sfinttwo(a,b) scanf("%d %d",&a,&b)
#define sfl(a,b) scanf("%ld %ld",&a,&b)
#define sfll(a,b) scanf("%lld %lld",&a,&b)
#define sfd(a,b) scanf("%lf %lf",&a,&b)
#define sff(a,b) scanf("%f %f",&a,&b)
#define lp1(i,n) for(i=0;i<n;i++)
#define lp2(i,n) for(i=1;i<=n;i++)
#define LL long long
#define L long
#define mem(c,v) memset(c,v,sizeof(c))
#define ui unsigned int
#define cp(a) cout<<" "<<a<<" "<<endl
#define ull unsigned long long int
#define nl puts("")
#define sq(x) ((x)*(x))
#define mx7 20000100
#define mx6 1500000
#define mx5 100005
#define inf 1<<30                                           //infinity value
#define eps 1e-9
#define mx (65540)
#define mod 1000000007
#define pb push_back
#define pi acos(-1.0)
#define sz size()
#define gc getchar ()


using namespace std;
//..................................................................................................................
template<class T> T setbit(T n, T pos){n=n|(1<<pos); return n;}
template<class T> T checkbit(T n, T pos){n=n&(1<<pos); return n;}

int prime[1],pr[100],plen=0;

void seieve(int n)
{
    int i,j,x=sqrt(n);

    prime[0]=setbit(prime[0],0);
    prime[0]=setbit(prime[0],1);

    for(i=4;i<=n;i+=2)prime[i>>5]=setbit(prime[i>>5],i&31);

    for(i=3;i<=x;i+=2)
    {
        if(!checkbit(prime[i>>5],i&31))
        {
            for(j=i*i;j<=n;j+=i)
            {
                prime[j>>5]=setbit(prime[j>>5],j&31);
            }
        }
    }

    for(i=2;i<=n;i++)
    {
        if(!checkbit(prime[i>>5],i&31))
        {
            pr[plen++]=i;
        }
    }
}

map<int,int>mp;

void divisor(int n)
{
    int i,m=1,tmp,take=n;

    mp.clear();

    for(i=0;i<plen and sq(pr[i])<=n;i++)
    {
        if(!(n%pr[i]))
        {
            while(!(n%pr[i]))
            {
                mp[pr[i]]++;
                n/=pr[i];
                if(n==0 or n==1) break;
            }

            int tmp=powl(pr[i],(mp[pr[i]] + 1)); //cout << "tmp=" << tmp << " ";
            m*=((tmp-1)/(pr[i] - 1)); //cout << "m=" << m << " ";
        }
    }

    if(n>1)
    {
        tmp=powl(n,2);
        m*=((tmp-1) / (n-1));
    }

    pf("Summation of the divisors of %d is %d :)\n",take,m);
    m=1;
}

int main()
{
    int n;
    seieve(100);

    while(sfint(n)==1)
    {
         divisor(n);
    }

    return 0;
}
