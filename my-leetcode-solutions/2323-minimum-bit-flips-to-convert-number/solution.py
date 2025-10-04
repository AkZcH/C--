class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # Step 1: Perform XOR to find differing bits
        xor_result = start ^ goal

        # Step 2: Count the number of set bits (1s) in xor_result
        flips = 0
        while xor_result > 0:
            # Check if the least significant bit is 1
            if xor_result & 1:
                flips += 1
            # Right shift to check the next bit
            xor_result >>= 1
        
        return flips
