#include<bits/stdc++.h>
using namespace std;

int* one_merge(const int A[],const int B[],int m,int n){
    int *C = new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<=B[j]){
            C[k]=A[i];
            k++;i++;
        }else{
            C[k]=B[j];
            k++;j++;
        }
    }
    while(i<m){C[k]=A[i];k++;i++;}
    while(j<n){C[k]=B[j];k++;j++;}
    return C;
}

vector<int> two_merge(const int A[],const int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j]){C.push_back(A[i]);i++;}
        else if(A[i]>B[j]){
            C.push_back(B[j]);j++;
        }else{
            C.push_back(A[i]);i++;j++;
        }
    }
    while(i<m){C.push_back(A[i]);i++;}
    while(j<n){C.push_back(B[j]);j++;}
    // Removing the duplicates in C manually 
    // vector<int> D;
    // D.push_back(C[0]);
    // for(auto i=C.begin()+1;i!=C.end();i++){
    //     if(*i != *(i-1)){D.push_back(*i);}
    // }
    // return D; 

    C.erase(unique(C.begin(),C.end()),C.end());
    return C;
}

vector<int> three_merge(const int A[],const int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j]){i++;}
        else if(A[i]>B[j]){j++;}
        else if(A[i]==B[j]){
            C.push_back(A[i]);j++;i++;
        }
    }
    C.erase(unique(C.begin(),C.end()),C.end());
    return C;
}

int main(){

    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }

    int m,n;
    //Receiving the inputs from the input file
    inputFile>>m>>n;
    int *A = new int[m];
    int *B = new int[n];
    for(int i=0;i<m;i++){inputFile>>A[i];}
    for(int i=0;i<n;i++){inputFile>>B[i];}
    inputFile.close();

    clock_t start,end;

    start=clock();

    outputFile<<"Outputs of all the subparts of this question are addressed here itself"<<endl;
    // Generating output of the first part
    int* one_C = one_merge(A,B,m,n);
    outputFile<<"a_ The merge of A and B gives: "<<endl;
    for(int i=0;i<m+n;i++){
        outputFile<<one_C[i]<<" ";
    }
    outputFile<<endl;

    // Generating output of the second part
    vector<int> two_C = two_merge(A,B,m,n);
    outputFile<<"b_The sorted array C for A U B : "<<endl;
    for(const auto &i:two_C){
        outputFile<<i<<" ";
    }
    outputFile<<endl;

    // Generating the output of the third part
    vector<int> three_C = three_merge(A,B,m,n);
    outputFile<<"c_The sorted array C for A intersection B : "<<endl;
    for(const auto &i:three_C){
        outputFile<<i<<" ";
    }
    outputFile<<endl;

    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;

}