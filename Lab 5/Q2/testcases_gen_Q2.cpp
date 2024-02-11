#include <bits/stdc++.h>

using namespace std;

void selectAndDeleteRandomNumbers(vector<int> &vec) {
    int index1 = rand() % vec.size();
    int index2;
    do {
        index2 = rand() % vec.size();
    } while (index1 == index2);
    cout << vec[index1] << " " << vec[index2] << " "; 
    if (index1 < index2) {
        vec.erase(vec.begin() + index2);
        vec.erase(vec.begin() + index1);
    } else {
        vec.erase(vec.begin() + index1);
        vec.erase(vec.begin() + index2);
    }
}

int main() {
    freopen("test_cases_Q2.txt", "w", stdout); 
    int t = 10; cout << t << endl;
    while(t--){
        int n = rand() % 9 + 1; cout << n << endl;
        vector<int> numbers(28);
        iota(numbers.begin(), numbers.end(), 2);
        for(int i=0; i<n; i++)
            selectAndDeleteRandomNumbers(numbers);
        cout << endl;
    }
    return 0;
}
