# Leetcode 1129. Shortest Path with Alternating Colors
# https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

# @param {Integer} n
# @param {Integer[][]} red_edges
# @param {Integer[][]} blue_edges
# @return {Integer[]}
def shortest_alternating_paths(n, red_edges, blue_edges)
    red_g = Hash.new{ |hash, key| hash[key] = [] }
    blue_g = Hash.new{ |hash, key| hash[key] = [] }

    red_edges.each do |e|
        red_g[e[0]] << e[1]
    end

    blue_edges.each do |e|
        blue_g[e[0]] << e[1]
    end

    result = Array.new(n, 100000000)
    result[0] = 0
    (1..(n - 1)).each do |destination|
        # from red_edges first
        calculate(result, false, red_g, blue_g, n, destination)
        calculate(result, true, red_g, blue_g, n, destination)
        result[destination] = -1 if result[destination] == 100000000
    end

    result
end

def calculate(result, is_next_blue_p, red_g, blue_g, n, destination)
    dist = 1
    q = Queue.new
    q.push(0)
    is_end = false
    red_visited = Array.new(n, false)
    blue_visited = Array.new(n, false)

    is_next_blue = is_next_blue_p
    if is_next_blue
        blue_visited[0] = true
    else
        red_visited[0] = true
    end

    while !q.empty?
        sz = q.size
        while sz > 0 
            cur = q.pop
            if is_next_blue
                next_nodes = blue_g[cur]
                next_nodes.each do |node|
                    if node == destination
                        is_end = true
                        break
                    end

                    if !blue_visited[node]
                        q.push(node)
                        blue_visited[node] = true
                    end
                    
                end

                break if is_end
            else
                next_nodes = red_g[cur]
                next_nodes.each do |node|
                    if node == destination
                        is_end = true
                        break
                    end
                    if !red_visited[node]
                        q.push(node)
                        red_visited[node] = true
                    end
                end
                break if is_end
            end

            break if is_end
            sz -= 1
        end

        if is_end
            result[destination] = dist if dist < result[destination]
            return
        end
        is_next_blue = !is_next_blue
        dist += 1
    end
end
