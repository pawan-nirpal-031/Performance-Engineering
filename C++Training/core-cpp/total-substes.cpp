#include <iostream>
#include <vector>
using namespace std;

void setprint(vector<pair<int,int>> &a,vector<pair<int,int>> answer,int curr){
    if(curr==a.size()){
        cout<<"printing set : ";
        for(auto &x : answer) cout<<" {"<<x.first<<" , "<<x.second<<"} ";
        cout<<"\n\n";
        return;
    }
    // x yes -> skip 
    // x no -> ans.add(x,y)
    bool found = 0; 
    for(auto p : answer){
        if(p.first==a[curr].first){
            found = 1;
            break;
        }
    }
    if(found){// skip this 
        setprint(a,answer,curr+1);
    }else{
        answer.push_back({a[curr].first,a[curr].second});
        setprint(a,answer,curr+1);
        answer.pop_back(); 
        setprint(a,answer,curr+1);
    }
}

int main(){
    vector<pair<int,int>> a = {{1,3},{2,4},{2,6},{3,3},{4,4},{4,6}};
    setprint(a,{},0);
}