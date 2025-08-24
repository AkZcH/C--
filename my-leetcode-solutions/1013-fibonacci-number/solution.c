

int fib(int n){
    int first = 0;
    int second = 1;

    if(n==0){
        return first;
    }

    else if(n==1){
        return second;
    }

    else{
        return fib(n-1) + fib(n-2);
    }
}
