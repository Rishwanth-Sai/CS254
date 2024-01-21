#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[],int n){
    for(int i=1;i<n;i++){
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

    // n is the total size of the array
    int n;
    inputFile>>n;
    
    int *A = new int[n];
    for(int i=0;i<n;i++){inputFile>>A[i];}
    inputFile.close();

    clock_t start,end;
    start=clock();
    insertionSort(A,n);
    end=clock();

    outputFile<<"The sorted array(using insertion sort algo.) : "<<endl;
    for(int i=0;i<n;i++){
        outputFile<<A[i]<<" ";
    }
    outputFile<<endl;
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
}