# Leetcode 1175. Prime Arrangements
# https://leetcode.com/problems/prime-arrangements/

# @param {Integer} n
# @return {Integer}

MOD = 1000000007

def get_prime_num(n)
    sieve = Array.new(n + 1, true)
    (2..n).each { |i|
        j = i * 2
        while j <= n
            sieve[j] = false
            j += i
        end
    }
    
    counts = 0
    i = 2
    while i < sieve.size
        if sieve[i]
            counts += 1
        end
        
        i += 1
    end
    
    return counts
end

def fact(n)
    if n == 1 || n == 0
        return 1
    end
    
    return (fact(n - 1) % MOD * n) % MOD
end
def num_prime_arrangements(n)
    # prime number ! * non prime number !
    prime_nums = get_prime_num(n)
    non_prime_nums = n - prime_nums
    
    return (fact(prime_nums) * fact(non_prime_nums)) % MOD
end
