#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
string fractionToDecimal(int n, int d) {
	    // Code here
	    int q=n/d;
	    int r=n%d;
	    string ans;
	    ans=to_string(q);
	    if(r==0)
	        return ans;
	    else{
	       unordered_map<int,int> m;
	       ans+='.';
	       while(r){
	           if(m.find(r)!= m.end()){
	               ans.insert(m[r],"(");
	               ans+=")";
	               return ans;
	           }
	           else{
    	           m[r]=ans.size();
                   r*=10;
    	           q=r/d;
    	           r%=d;
    	           ans+=to_string(q);
	           }
	       }
	    return ans;
	}
}
int main(){
    //here
    int numerator,denominator;
    cin>>numerator>>denominator;
    cout<<"\n"<<fractionToDecimal(numerator,denominator);
    getch();
    return 0;
}