#include <bits/stdc++.h>

using namespace std;
int n;
vector<int>A, B, C;
int main()
{
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        if (x < 0)
            A.push_back(x);
        if (x > 0)
            B.push_back(x);
        if (x == 0)
            C.push_back(x);
    }
    if (B.size() == 0){
        cout<<1<<" "<<A[0]<<endl;
        cout<<2<<" "<<A[1]<<" "<<A[2]<<endl;



        cout<<C.size() + A.size() - 3<<" ";
        for (int i = 3; i < A.size();i++) cout<<A[i]<< " ";
        for (int i = 0; i < C.size(); i++) cout<<0<<" ";
    }
    else {
        if (A.size() % 2 == 0){
            cout<<A.size() - 1<<" ";
            for (int i = 1; i < A.size();i++) cout<<A[i]<<" ";
            cout<<endl;
            cout<<B.size()<< " ";
            for (int i = 0; i < B.size();i++) cout<<B[i]<< " ";
            cout<<endl;
            cout<<C.size()+1<<" "<<A[0]<< " ";
            for (int i = 0; i < C.size();i++) cout<<0<<" ";
        }
        else {
            cout<<A.size()<<" ";
            for (int i = 0; i < A.size(); i++) cout<<A[i]<< " ";
            cout<<endl;
            cout<<B.size()<<" ";
            for (int i = 0; i < B.size(); i++) cout<<B[i]<< " ";
            cout<<endl;
            cout<<C.size()<<" ";
            for (int i = 0; i < C.size(); i++) cout<<C[i]<< " ";

        }
    }
    return 0;
}