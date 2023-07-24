#include<bits/stdc++.h>
using namespace std;


// DISJOINT SET UNION IS BASSICALLY USEFUL WHEN WE HAVE TO FIND THE STRONGLY CONNECTED COMPONENTS
class DisjointSet{ 
    public:
    vector<int>rank,parent,size;
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i =1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUpar(int node){
        if(parent[node]==node){
            return node;
        }

        return  parent[node] = findUpar(parent[node]);
    }


    void unionByRank(int u ,int v){
        int ulp_u =  findUpar(u);
        int ulp_v =  findUpar(v);

        if(ulp_u==ulp_v){
            return;
        }

        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]  = ulp_u;
            rank[ulp_u]++;
        }else{
            parent[ulp_u] =  ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u =  findUpar(u);
        int ulp_v =  findUpar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] =  ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v] =  ulp_u;
            size[ulp_u] += size[ulp_v] ; 
        }
    }
};


int main(){

     DisjointSet ds(6);

    return 0;
}