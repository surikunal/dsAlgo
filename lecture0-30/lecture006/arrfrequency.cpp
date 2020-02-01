#include<iostream>
#include<vector>
using namespace std;

bool isReallyCandidate(vector<int> &arr , int data){
    int count=0;
    for(int i : arr){
        if(i==data){
            count++;
        }
    }
    if(count>arr.size()/2){
        return true;
    }
    return false;
}
int potentialCandidate(vector<int> &arr){
    int freq=1;
    int suspect=arr[0];

    for(int i=1 ; i<arr.size() ; i++){      /* here the loop is started from 1 because the
                                            zeroth position is already been included*/
        if(suspect==arr[i]){
            freq++;
        }
        else{
            freq--;
        }
        if(freq==0){
            freq=1;
            suspect=arr[i];
        }
    }
    return suspect;
}
void votingAlgo(){
    vector<int> arr={2,3,4,3,2,2,2,2,3,2,2,2};
    int potential=potentialCandidate(arr);
    bool ans=isReallyCandidate(arr , potential);

    if(ans){
        cout<<"potential : "<<potential;
    }
    else{
        cout<<"potential : "<< -1 <<endl;
    }
}

int main(){
    votingAlgo();
    return 0;
}
        