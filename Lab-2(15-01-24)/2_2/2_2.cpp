#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[],int m,int n){
    for(int i=m;i<n;i++){
        int key = A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main(){

    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }

    // m is the size of the 1st sorted part of the array
    int n,m;
    inputFile>>n>>m;
    // n is the total size of the array

    int *A = new int[n];
    for(int i=0;i<n;i++){inputFile>>A[i];}
    inputFile.close();

    clock_t start,end;
    start=clock();
    insertionSort(A,m,n);
    end=clock();

    outputFile<<"The complete sorted array : "<<endl;
    for(int i=0;i<n;i++){
        outputFile<<A[i]<<" ";
    }
    outputFile<<endl;
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
}