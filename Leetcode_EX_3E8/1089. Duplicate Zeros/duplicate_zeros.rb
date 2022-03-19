# Leetcode 1089. Duplicate Zeros
# https://leetcode.com/problems/duplicate-zeros/

# @param {Integer[]} arr
# @return {Void} Do not return anything, modify arr in-place instead.
def duplicate_zeros(arr)
    q = Queue.new
    
    i = 0
    while i < arr.length
        if arr[i] == 0
            q << 0
        end
        
        if !q.empty?
            q << arr[i]
            arr[i] = q.pop
        end
        
        i += 1
    end
end
