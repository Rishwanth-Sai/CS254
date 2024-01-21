#include<bits/stdc++.h>
using namespace std;
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

    int l=A[0];
    for(int i=0;i<n;i++){
        if(A[i]<l){l=A[i];}
    }

    int l_two=A[0];
    for(int i=n;i<n;i++){
        if(A[i]<l_two && A[i]>l){l_two=A[i];}
    }

    end=clock();

    outputFile<<"The least element of the given unsorted array is: "<<l<<endl;
    outputFile<<"While the second least element is: "<<l_two<<endl;

    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
    outputFile<<"Note: The program contains two seperate for loops that run from 0 to n. Hence the Time Complexity is O(n).";
    
}