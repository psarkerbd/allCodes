/// Header file begin
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
#include<utility>
#include <queue>
#include <algorithm>
/// End
//..........
/// Macro
#define sf scanf
#define pf printf
#define sfint(a,b) scanf("%d %d",&a,&b)
#define sfl(a,b) scanf("%ld %ld",&a,&b)
#define sfll(a,b) scanf("%lld %lld",&a,&b)
#define sfd(a,b) scanf("%lf %lf",&a,&b)
#define sff(a,b) scanf("%f %f",&a,&b)
#define lp1(i,n) for(i=0;i<n;i++)
#define lp2(i,n) for(i=1;i<=n;i++)
#define mem(c,v) memset(c,v,sizeof(c))
#define cp(a) cout<<" "<<a<<" "<<endl
#define nl puts("")
#define sq(x) ((x)*(x))
#define all(x) x.begin(),x.end()
#define sz size()
#define gc getchar()
#define pb push_back
/// End.........

/// Size
#define mx7 20000100
#define mx6 1500000
#define mx5 100005
#define mx4 1000100
#define inf 9999                                          //infinity value
#define eps 1e-9
#define mx (65540)
#define mod 1000000007
#define pi acos(-1.0)

/// Macros for Graph

#define white 0
#define gray 1
#define black -1
#define nil -2

using namespace std;
//..................................................................................................................
typedef long long LL;
typedef long L;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned int ui;
typedef pair<int, int> pii;

template<class T> T setbit(T n, T pos){n=n|(1<<pos); return n;}
template<class T> T checkbit(T n, T pos){n=n&(1<<pos); return n;}
template<class T> T gcd(T a, T b ) {return b<=0?a:gcd(b,a%b);}
template<class T> T large(T a, T b ) {return a>b?a:b;}
template<class T> T small(T a, T b ) {return a<b?a:b;}

vector< vector <int> > G;

vector<int>par(100); // initialized the 100 elements of par vector

vector<int>color(100); // initialized the 100 elements of color vector

vector<int>level(100);// initialized the 100 elements of level vector

int node,edge;

void BFS(int src, int n)
{
    queue<int>Q;
//    memset(color,white,sizeof(color));
//    memset(level,inf,sizeof(level));
//    memset(par,nil,sizeof(par));
    fill(all(color),white);
    fill(all(level),inf);
    fill(all(par),nil);

    color[src]=gray;
    level[src]=0;
    par[src]=nil;

    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();

        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];

            if(color[v]==white)
            {
                color[v]=gray;
                level[v]=level[u]+1;
                par[v]=u;
                Q.push(v);
            }
        }

        color[u]=black;
        Q.pop();
    }

    for(int i=1;i<=n;i++)
    {
        cout << src << " to " << i << " is " << level[i] << endl;
    }
}

void print_path(int src, int des)
{
    if(des == src)
    {
        cout << src << " ";
    }

    else if(par[des] == nil)
    {
        cout << " No path here..";
    }

    else
    {
        print_path(src,par[des]);
        cout << des << " ";
    }
}

int main()
{
    cout << "Take Node and Edges : ";
    cin >> node >> edge;

    cout << "Take Connected Nodes: \n";

    G.resize(edge);

    for(int i=1;i<=edge;i++)
    {
        int x,y,cost;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    cout << "Graph: \n";

    for(int i=1;i<=node;i++)
    {
        int sze = G[i].size();

        cout << "for node " << i << " : ";

        for(int j=0;j<sze;j++)
        {
            cout << G[i][j] << " ";
        }

        cout << endl;
    }

    int source,destination;

    cout << "Enter Source: ('0' to end): ";
//    cin >> source >> destination;
//
//    BFS(source,node);
//
//    cout << "\nPath :: ";
//
//    print_path(source,destination);
      while(cin >> source and source!=0)
      {
           cout << " Enter Destination Node : ";
           cin >> destination;

           cout << "Distance : \n";
          BFS(source,node);

          cout << "\nPath: ";
          print_path(source,destination);

          cout << "\nEnter Source: ('0' to end): ";
      }

      return 0;
}
