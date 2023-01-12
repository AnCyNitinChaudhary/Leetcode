//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(struct Item a, struct Item b)//comparator type must be static bool - need to remember
    {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //I am going to use an multimap to store ratio,i as it will be sorted on the bases of keys and here according to the bases of ratios.
        // multimap<double,int> mp;
        // for(int i=0;i<n;i++){
        //   double ratio=(double)arr[i].value/arr[i].weight;
        //   mp.insert(make_pair(ratio,i));
        // }
        // int ans=0;
        // for(auto it=mp.end();it!=mp.begin();it--){
        //     if(W==0)break;
        //     double weight=arr[it->second].weight;
        //     double value=arr[it->second].value;
        //     if(W>=weight){
        //         ans+=weight;
        //         W-=weight;
        //     }
        //     else{
        //         ans+=W;
        //         W=0;
        //         break;
        //     }
        //     cout<<ans<<endl;
        // }
        // return ans;
        // Above use of map is giving error , try to improve this.
        //below approach is based on the gfg article in which they use user defined compare function to implement the sort.
        sort(arr,arr + n, cmp);
        double ans= 0.0;
        for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            ans += arr[i].value;
        }
        else {
            ans+= arr[i].value* ((double)W / (double)arr[i].weight);//must understand this line.
            break;
        }
    }
    return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends