#include<bits/stdc++.h>
using namespace std;

struct my
{
    string st;
    int sn;
};

int main()
{
    map<string,bool>mp;
    my ar[100];
    int slen=0;
    string s1,s2;
    vector<string>vs;
    vector<int>vi;

    // input the strings
    for(int i=0;i<2;i++)
    {
        cin >> s1;
        vs.push_back(s1);
        cin >> s2;
        vs.push_back(s2);
    }

//    sort(vs.begin(),vs.end());
//    for(int i=0;i<vs.size();i++) cout << vs[i] << " ";

    // distinct strings
    for(int i=0,j=1;i<vs.size();i++)
    {
        if(!mp[vs[i]])
        {
            //vi.push_back(j);
            ar[slen].st=vs[i]; // insert string into a structure array
            ar[slen++].sn=j; //insert that string's position into a structure array
             j++; // increasing the position.
        }

        mp[vs[i]]=true;
    }

    //for(int i=0;i<slen;i++)cout << ar[i].st << " " << ar[i].sn << " ";

    for(int i=0;i<vs.size();i++)
    {
        for(int j=0;j<slen;j++)
        {
            if(vs[i] == ar[j].st) // matching the strings
            {
                vi.push_back(ar[j].sn); // and insert their position into an integer vector.
            }
        }
    }

    // printing their position
    for(int i=0;i<vi.size();i++) cout << vi[i] << " ";

    return 0;
}
