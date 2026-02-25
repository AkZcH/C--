class Solution:
    def mySqrt(self, x: int) -> int:
        low = 1
        high = x

        while low <= high:
            M = (low + high) //2
            M_sq = M*M

            if M_sq == x:
                return M
            elif M_sq < x:
                low = M+1
            else:
                high = M-1
                
        return high
            
        
