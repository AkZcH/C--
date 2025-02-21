int min(int x, int y){
    if(x<=y){
        return x;
    }
    else{
        return y;
    }
}

int maxArea(int* height, int heightSize) {
    int max_vol=0;
    int vol;
    int h=heightSize;

    int left=0;
    int right=h-1;

    while(left<right){
        vol = min(height[left], height[right]) * (right-left);
        if(max_vol<vol){
        max_vol=vol;
        }
        
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }


    }

return max_vol;
}
