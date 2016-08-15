// LIS -- O(N log K)

#include<bits/stdc++.h>
using namespace std;

const int inf=9999;

int seq[100], I[100] , ilen=0 , n , L[100] , lisseq[100];

int search_binary(int lo, int hi, int itm)
{
    int mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(I[mid] < itm)
        {
            lo = mid + 1;
        }

        else
        {
            hi = mid - 1;
        }

//        if(I[mid] == itm)
//        {
//            return mid;
//        }
//
//        else if(I[mid] > itm)
//        {
//            hi = mid-1;
//        }
//
//        else if(I[mid] < itm)
//        {
//            lo = mid+1;
//        }
    }

    return lo;
}

int LIS()
{
    int i , r , lislength=0 , pre=0, now=0;

    for(i=0;i<n;i++)
    {
        r = search_binary(0, lislength, seq[i]);

        I[r] = seq[i];
        L[i] = r;

        if(lislength < r)
        {
            lislength = r;
        }
    }

    //cout << "LIS length = " << lislength << "\n";

    return lislength;
}

void find_sequence(int mxlen)
{
    int i=0 , j ;
    //for(i=0;i<n;i++)cout << L[i] << " ";

    for(j=1; j<n; j++)
    {
        if(L[j] > L[i])
        {
            i = j;
        }
    }

    //cout << "i = " << i;

    int top = L[i] - 1;

    lisseq[top] = seq[i];

    top--;

    for(j=i-1; j>=0; j--)
    {
        if(seq[j] < seq[i] and L[j] == L[i] - 1)
        {
            i = j;

            lisseq[top] = seq[i];
            top--;
        }
    }

    cout << "LIS Sequence: ";

    for(i=0;i<mxlen;i++)
    {
        cout << lisseq[i] << " ";
    }
}

int main()
{
    int i;

    //lislength=0;

    //memset(I, inf, sizeof(I));
    memset(L, 1, sizeof(L));


    I[ilen++] = -inf;

    //freopen("input.txt" , "r" , stdin);

    //for(i=0;i<11;i++) cout << I[i] << " ";

    while(cin >> n)
    {
        for(i=0;i<n;i++)
        {
            cin >> seq[i];
            I[ilen++] = seq[i];
        }

        //for(i=0;i<11;i++) cout << I[i] << " ";

        int len = LIS();

        cout << "LIS length = " << len << "\n";

        find_sequence(len);

        cout << "\n";
    }

    return 0;
}

