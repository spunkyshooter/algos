#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,j,k) for(int i=j ;i<k;i++)
#define per(i,j,k) for(int i = j; i>k;i--)



void merge(int arr[], int p,int q,int r){
    int n1 =q-p + 1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];

    rep(i,0,n1){
        L[i] = arr[p+i];
    }
    rep(i,0,n2){
        R[i] = arr[q+1+i];
    }
    //sentinals: it shoud be large number
    L[n1] = (int)1e9;
    R[n2] = (int)1e9;

    int i = 0,j = 0;
    //loop should from p to r(inclusive)
    rep(k,p,r+1){
        if( L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }

}
void mergesort(int arr[],int l,int u){
    if(l<u){
    int mid  = l+ (u-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,u);
    merge(arr,l,mid,u);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int arr[12] = {10,9,8,7,6,3,12,5,4,3,2,1};
    mergesort(arr,0,12);
    rep(i,0,12){
        cout<<arr[i]<<" ";
    }
    return 0;
}
