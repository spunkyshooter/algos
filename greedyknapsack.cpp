#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define profit first
#define weight second

typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(ii f , ii s){
    return (1.0*f.profit/f.weight) > (1.0*s.profit/s.weight);
}

void printProfitsAndWeights(const vii &profitAndWeights){
    cout<<"profits and their corresponding weights: ";
    for(ii p : profitAndWeights){
        cout<<p.profit<<' ';
    }
    for(ii p : profitAndWeights){
        cout<<p.weight<<' ';
    }
}

double solveGreedily(vii &profitAndWeights, int noOfObjects,int &weigthOfKnapsack){
    sort(profitAndWeights.begin(), profitAndWeights.end(),cmp); 
        //Now array will be sorted based on profit/weight

        // If you wanna see the array
        // printProfitsAndWeights(profitAndWeights);

    double TotalProfit = 0.0;
    for(int i = 0; i< noOfObjects ; i++){
            if(profitAndWeights[i].weight <= weigthOfKnapsack){
                weigthOfKnapsack -= profitAndWeights[i].weight;
                TotalProfit += profitAndWeights[i].profit;
            }else{
                //Control arrives here when knapsack weight is less.
                // then grab the most fractional part of the object which has greater profit to weight ratio
                weigthOfKnapsack = 0; //hence knapsack will be filled
                TotalProfit += (1.0)*profitAndWeights[i].profit/profitAndWeights[i].weight; //adding the fractional profit
                break; //since knapsack is full. As a theif i should return home first.
            }
        }
        return TotalProfit;
}

int main(){

    int noOfObjects, weigthOfKnapsack;
    cout<<"Enter the #Objects : ";
    cin>>noOfObjects;
    cout<<"Enter the weigthOfKnapsack : ";
    cin>>weigthOfKnapsack;

    // we don't need objects id at all. we can use indexes
    vii profitAndWeights(noOfObjects);
    cout<<"Enter the profits of all the Objects:\n";
    for(int i= 0; i< noOfObjects ; i++){
        cin>>profitAndWeights[i].profit; //profit
    }
    cout<<"Enter the weights of all the Objects:\n";
    for(int i= 0; i< noOfObjects ; i++){
        cin>>profitAndWeights[i].weight; //weights
    }

    double TotalProfit = solveGreedily(profitAndWeights, noOfObjects,weigthOfKnapsack);

    cout<<"Total profit is: "<<TotalProfit<<'\n';
}
