#include<iostream>
#include<vector>
using namespace std;

int reduce(int n){
    if(n<0) return -1;
    else if(n<10) return n;

    else{
        return reduce(n/10) + n%10;
    }
}

int main(){
    cout<<reduce(99);
    return 0;
}