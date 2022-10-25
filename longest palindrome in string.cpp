#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int expandCentre(string S,int i,int j){
        int n=S.length();
        while(i>=0 && j<n && S[i]==S[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalin (string S) {
        int start=0,end=0;
        for(int i=0;i<S.length();i++){
            int l1=expandCentre(S,i,i+1);
            int l2=expandCentre(S,i,i);
            int l=max(l1,l2);
            if(end-start+1<l){
                start=i-(l-1)/2;
                end=i+l/2;
            }
        }
        return S.substr(start,(end-start+1));
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
