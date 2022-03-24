# Leetcode 881. Boats to Save People
# https://leetcode.com/problems/boats-to-save-people/

# @param {Integer[]} people
# @param {Integer} limit
# @return {Integer}
def num_rescue_boats(people, limit)
    i = 0
    j = people.length - 1
    boats = 0
    people = people.sort
    while i <= j
        if people[j] + people[i] <= limit
            j -= 1
            i += 1
        else
            j -= 1
        end
        boats += 1
    end
    
    return boats
end
