#include<bits/stdc++.h>
// sor a vector using recursion.
using namespace std;
void insertAtCorrect(vector<int> &vec, int &tem){
    auto x = vec.begin(); int N = vec.size();
    for (int i = 0; i <  N; ++i , ++x){
        if (vec[i] > tem){
            vec.insert(x, tem);
            return;
        }
    }
    vec.push_back(tem);
    return;
}
void sort(vector<int> &v){
    if (v.size() == 1){return;}
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v);
    // insert the temp in correct position.
    insertAtCorrect(v, temp);
}
int main(){
    vector<int> B = {8, 4 ,9, 2, 3,  5765, 1};
    sort(B);
    for (auto &x : B){
        cout << x << " ";
    }

}
