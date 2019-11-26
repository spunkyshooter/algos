
#include<bits/stdc++.h>
using namespace std;

/* M1: Lomuto’s Partition , running one loop over l to r and swapping elements if 
the elements are small to pivot.
This is pleasant to see and easy to remember,
But in worst case in which almost all  elements are less than pivot, hence 
the elements swaps with itself. the swapping in more.
ex: 1 2 3 4 5 6 9 7 10
partition: rearranges the elements pivot element is in its sorted position
All the elements left of pivot will be less than pivot
Similary all the elements right to the pivot will be greater than pivot

*/
int lomutoPartition(vector<int> &A,int l,int r){
  int pivot = A[r]; //last element is pivot
  int i = l-1; //since we increase i when we encounter smaller element

  for(int j = l;j<r;j++){
    if(A[j] <= pivot){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}

//m2: hoare-partition
//When an inversion is found, two values are swapped and process is repeated.
int hoarePartition(vector<int> &A,int l,int r){
    int pivot = A[l];
    int i = l-1;
    int j = r+1;
    while (1){
        do{
            i++;
        }while(A[i] < pivot); //don't use equality sign
        do{
            j--;
        } while (A[j] > pivot); //don't use equality sign
        if(i<j) swap(A[i],A[j]);
        else return j;
    }
}



//M3:Modified original-hoare-partition. Better than original Hoare partion
//When an inversion is found, two values are swapped and process is repeated.
//In this case pivot won't be in any one of the partition.
//so we should call quicksort as we do in case of lomuto partition
//i.e  quickSort(A,l,j-1); 
 //   quickSort(A,j+1,r);
int hoarePartition2(vector<int> &A,int l,int r){
  //if we choose last element as pivot
  //Last swap should be with i and return i
    int pivot = A[r];
    int i = l-1;
    int j = r;
    while (i<j){
        do{
            i++;
        }while(A[i] < pivot); //don't use equality sign
        do{
            j--;
        } while (A[j] > pivot); //don't use equality sign
        if(i<j) swap(A[i],A[j]);
    }
    swap(A[r],A[i]);
    return i;

    //if we choose first element as pivot
  //Last swap should be with j and return j
    // int pivot = A[l];
    // int i = l; //since we do i++ so lth won't be compared.
    // int j = r+1; //since we want jth element to be compared, but we are doing  j-- in do while. so increase j
    // while (i<j){
    //     do{
    //         i++;
    //     }while(A[i] < pivot); //don't use equality sign
    //     do{
    //         j--;
    //     } while (A[j] > pivot); //don't use equality sign
    //     if(i<j) swap(A[i],A[j]);
    // }
    // swap(A[l],A[j]);

    // return j;
}

void quickSort(vector<int> &A,int l,int r){
  
  if(l<r){
    int j = hoarePartition(A,l,r);
    quickSort(A,l,j); //when using hoarePartition:  j, lomutoPartition: j-1 , hoarePartion2: j-1
    quickSort(A,j+1,r);
  }

}


int main(){

  vector<int> A = {5,4};
  quickSort(A,0, (int)A.size()-1); //pass the first and last index (not the size)

  for(int x:A){
      cout<<x<<' ';
  }
  return 0;
}
