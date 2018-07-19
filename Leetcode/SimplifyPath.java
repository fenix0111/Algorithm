// Leetcode 71. Simplify Path
// https://leetcode.com/problems/simplify-path/description/
// Runtime: 11ms

class Solution {
        class Node {
        HashSet<Node> childList = new HashSet<>();
        Node parent = null;
        String val = "";

        public Node(String name) { val = name; }

        public Node getParent() {
            return parent;
        }

        public void setParent(Node p) {
            this.parent = p;
        }

        public void addChild(Node newChild) {
            childList.add(newChild);
        }

        public String getDir() {
            return this.val;
        }
    }

    public String simplifyPath(String path) {
        String UP = "..";
        String CUR = ".";
        String res = "";

        String[] stringList = path.split("/");
        Node root = new Node("/");
        root.setParent(root);

        Node currentNode = root;

        for (int i = 0; i < stringList.length; i++) {
            if (UP.equals(stringList[i])) {
                currentNode = currentNode.getParent();
            } else if (!CUR.equals(stringList[i])) {
                if (!"".equals(stringList[i])) {
                    Node newNode = new Node(currentNode.getDir() + stringList[i] + "/");
                    currentNode.childList.add(newNode);
                    newNode.parent = currentNode;
                    currentNode = newNode;
                }
            }
        }

        if (currentNode.parent == currentNode) {
            res = "/";
        } else {
            res = currentNode.getDir().substring(0, currentNode.getDir().length() - 1);
        }

        return res;
    }
}
