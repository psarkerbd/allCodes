// Verdict:: Accepted   *
// Time:: 0.093         *
//***********************
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
#define sfint(a,b) scanf("%d %d",&a,&b)
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
#define all(x) x.begin(),x.end()
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
template<class T> T gcd(T a, T b ) {return b==0?a:gcd(b,a%b);}
template<class T> T large(T a, T b ) {return a>b?a:b;}
template<class T> T small(T a, T b ) {return a<b?a:b;}

//...................................................................................................................

int prime[mx7],prm[(mx7/2)+1],plen=0;

void seieve(int n)
{
    int i,j,x=(int)sqrt(double(n));

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
            prm[plen++]=i;
        }
    }

    //lp1(i,plen)cp(prm[i]);
}

int main()
{
    seieve(mx7);
    int n;
    while(1==sf("%d",&n) and n)
    {
        int b,i,h=n/2,cnt=0;

        for(i=0;i<plen;i++)
        {
            if(prm[i]<=h)
            {
                b=n-prm[i];

                if(!checkbit(prime[b>>5],b&31))
                {
                    if(b+prm[i]==n)
                    {
                        cnt+=1;
                    }
                }
            }

            else
                break;
        }

        pf("%d\n",cnt);
    }

    return 0;
}
