

int fib(int n){
    // int first = 0;
    // int second = 1;

    // if(n==0){
    //     return first;
    // }

    // else if(n==1){
    //     return second;
    // }

    // else{
    //     return fib(n-1) + fib(n-2);
    // }

        if(n==0 || n==1) return n;


    int prev1= 1;
    int prev2 = 0;
    int current;


    for(int i=2; i<=n; i++){
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}
