#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int lb,int ub,int X){
   //base condition
   if(ub < lb || (lb == ub && A[lb] != X)) return -1;
    int mid = lb+(ub -lb)/2;
    if(A[mid] == X) return mid;
    else if(X < A[mid]) return binarySearch(A,lb,mid-1,X);
    else return binarySearch(A,mid+1,ub,X); 
   

}

int binarySearch3(const int A[], int v,int val){
   int u = 0;
   while(u < v){
      int mid = (u+v)/2;
      if(A[mid] == val) return mid;
      else if(A[mid] > val) v = mid -1;
      else u = mid+1;
   }
   return -1;
}
int main(){
   //  freopen("data.in" , "r",stdin);
   //  freopen("data.out","w",stdout);
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++) cin>>A[i];
    sort(A,A+n);
    
    for(int i=0; i<n; i++) cout<<A[i]<<" ";
    cout<<"\n"<<binarySearch(A,0,n-1,4)<<"\n";
   //  cout<<binarySearch2(A,n,4)<<"\n";
    cout<<binarySearch3(A,n-1,4)<<"\n";
    return 0;
}
