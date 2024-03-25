#include<bits/stdc++.h>
using namespace std;
string bin(int N){
 string l="";
 while(N)
 {
     l=l+to_string(N%2);
     N/=2;
 }
 string s="";
 for(int i=l.length()-1;i>=0;i--)
 {
     s=s+l[i];
 
 }
 return s;
}
//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string> k;
	for(int i=1;i<=N;i++)
	{
	    string s=(bin(i));
	    k.push_back(s);
	}
	return k;
}
//{ Driver Code Starts.
int main()
{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	return 0;
}
// } Driver Code Ends
