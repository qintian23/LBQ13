#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return string字符串
     */
    string NS_String(string s, int k) {
        // write code here
        while(k--){
            char c='z';
            for(int i=0; i<s.length(); i++)
            {
                if(c>s[i]) c=s[i];
            }
            while (s.find(c) != -1) 
                s.erase(s.find(c), 1);
            cout<< c <<endl;
        }

        return s;
    }
    
     /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param m long长整型 
     * @return long长整型vector
     */
    vector<long> FarmerNN(int n, long long m) {
        // write code here
        if(m<=n){
        	vector<long> mdata(n);
        	for(int j=0; j<m; j++){
        		++mdata[j];
			}
			return mdata;
		} 
        long c=m/(2*n-2);
        int s=(m%(2*n-2))/n;
        vector<long> data(n,2*c+s);
        data[0]=c+s;
        data[n-1]=c+s;
        int s1=(m%(2*n-2))%n;
        int i=0;
        if(s==0){
        	while(s1--){
        		++data[i++];
			}
		}else{
			while(s1--){
        		++data[n-2-i];
        		i++;
			}
		}
       
		return data;
//        int i=0;
//        int step=1;
//        while(m--){
//        	++data[i];
////        	cout<< i <<endl;
//        	i=i+step;
//			if(i==0 || i==n-1) step=-1*step;
//		}
//		return data;
    }
    
    long long section(vector<int>& a, int t) {
        // write code here
 		unordered_map<int,int> mp;
        long long res=0;
        int l=0,r=0;
        while(r<a.size()){
            mp[a[r]]++;
            while(mp.count(a[r]^t) && mp[a[r]^t]>0){
                mp[a[l]]--;
                l++;
            }
            res+=(r-l);
            r++;
        }
        return res;
        
        
        
//        long long sum=0;
//        for(int i=0; i<a.size()-1; i++){
//        	for(int j=i+1; j<a.size(); j++){
//				
//        		if(int(a[i]^a[j]) == t){
//        			break;
//				}
//				++sum;
//			}
//		}
//		return sum;
    }
    
	int maxSubTree(TreeNode* root) {
        // write code here
        map<pair<string,int>, int> mp;
        int res = 0;
        dfs(root, mp);
        for (const auto&[pa, cnt]: mp)
            if (cnt > 1)
            res = max(res, pa.second);
        return res;
    }
     
    pair<string,int> dfs(TreeNode* root, map<pair<string,int>, int> &mp)
    {
        if (!root) return make_pair(string(""), 0);
        string ans = "1";
        int cnt = 1;
        pair<string, int> left = dfs(root->left, mp);
        pair<string, int> right = dfs(root->right, mp);
        ans += "|" + left.first + "|";
        ans += right.first;
        cnt += left.second + right.second;
        pair<string, int> pa = make_pair(ans, cnt);
        mp[pa]++;
        return pa;
    }
};

int main()
{
//    string s="caabeefa";
//    string s1="cbcb";
//    int k=2;
//    int k1=1;
//    Solution test;
//    cout<< test.NS_String(s1,k1) <<endl;
//	Solution test;
//	vector<long> data;
//	data=test.FarmerNN(2,7);
//	for(int i=0; i<data.size(); i++)
//		cout<<data[i]<<", " ;
	
	Solution test;
	vector<int> a={2,4,6,7,8,9,4};
	cout<< test.section(a,6) <<endl;
	
    return 0;
}
