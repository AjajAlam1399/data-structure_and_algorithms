# 1. Floyd Warshall Algorithm is used to find multi source minimum distance and it is also used to check for negative edge cycle

# 2. Valid for directed graph

# 3. for undirected graph we need to put weight in the initial matrix like :
 # u-->v (wt)
 # u<--v (wt)

# time complexity : O(n^3)
# space complexity : O(n*n) initial matirx;

step 1 : - create a 2-d matrix and assign every element as 1e9
step 2 : - place mati[i][i]=0 because their will be no self edges
step 3 : - if their is edge between u->v then put mati[u][v]=wt;

step 4 :- then apply the remaining algo 

# way to detect cycle 
for(int i=0;i<n;i++){
    if (mati[i][i]<0){
        return "negative edge cycle";
    }
}