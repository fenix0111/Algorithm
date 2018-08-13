// Leetcode 127. Word Ladder
// https://leetcode.com/problems/word-ladder/description/
// Runtime: 715ms (terrible..)

// 山寨了下宽度优先搜索算法。未优化，故很慢
class Solution {

    // do not write like this in production code
    class Vertex {
        public String name = "";
        public boolean isVisited = false;
        public int minDistance = Integer.MAX_VALUE;
        public ArrayDeque<Vertex> neighbours = new ArrayDeque<>();
    }

    boolean oneDiff(String s, String t) {
        int numDiff = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                numDiff++;
            }
        }

        return numDiff == 1;
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int res = 0;

        boolean hasSame = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (endWord.equals(wordList.get(i))) {
                hasSame = true;
            }
        }

        // if wordList did not contain endWord
        if (!hasSame) {
            return 0;
        }

        // make a graph
        ArrayList<Vertex> G = new ArrayList<>();

        // begin word as first vertex
        Vertex beginV = new Vertex();
        beginV.name = beginWord;
        beginV.isVisited = true;
        beginV.minDistance = 1;

        G.add(beginV);

        for (int i = 0; i < wordList.size(); i++) {
            Vertex v = new Vertex();
            v.isVisited = false;
            v.minDistance = Integer.MAX_VALUE;
            v.name = wordList.get(i);

            G.add(v);
        }

        // make neighbours
        for (int i = 0; i < G.size(); i++) {
            Vertex iv = G.get(i);
            Vertex jv = null;
            for (int j = 0; j < G.size(); j++) {
                if (i != j) {
                    jv = G.get(j);
                    if (oneDiff(iv.name, jv.name)) {
                        iv.neighbours.add(jv);
                    }
                }
            }
        }

        // run BFS to all vertices
        ArrayDeque<Vertex> queue = new ArrayDeque<>();
        queue.addLast(G.get(0));

        // run BFS
        while (!queue.isEmpty()) {
            Vertex v = queue.removeFirst();
            ArrayDeque<Vertex> vNeighbours = v.neighbours;
            for (Vertex vn : vNeighbours) {
                if (!vn.isVisited && (v.minDistance + 1 < vn.minDistance)) {
                    vn.minDistance = v.minDistance + 1;
                    vn.isVisited = true;
                    queue.addLast(vn); // enqueue the neighbor
                }
            }
        }

        // retrieve shortest ladder length
        for (int i = 0; i < G.size(); i++) {
            if (endWord.equals(G.get(i).name)) {
                res = G.get(i).minDistance;
            }
        }
        
        // this means the endWord was not found
        if (res == Integer.MAX_VALUE) {
            res = 0;
        }

        return res;
    }
}
