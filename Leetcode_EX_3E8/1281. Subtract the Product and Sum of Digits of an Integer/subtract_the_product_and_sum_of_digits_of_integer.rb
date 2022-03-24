# Leetcode 1281. Subtract the Product and Sum of Digits of an Integer
# 

# @param {Integer} n
# @return {Integer}
def subtract_product_and_sum(n)
    sum = 0
    prod = 1
    
    while n > 0
        rem = n % 10
        sum += rem
        prod *= rem
        n /= 10
    end
    
    return prod - sum
end
