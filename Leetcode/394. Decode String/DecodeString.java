// Leetcode 394. Decode String
// https://leetcode.com/problems/decode-string/description/
// Runtime: 10ms (a bit slow..)

// 使用queue一直转。因为带判断是否包含字符串所以慢了些
public String decodeString(String s) {
        LinkedList<Character> queue = new LinkedList<>();
        for (int j = 0; j < s.length(); j++) {
            queue.addLast(s.charAt(j));
        }

        queue.addLast('-'); // mark as end of queue

        StringBuilder sb = new StringBuilder();

        int depth = 0;
        int times = 0;

        while (queue.contains('[')) {
            if (Character.isDigit(queue.peekFirst())) {
                StringBuilder num = new StringBuilder();
                while (Character.isDigit(queue.peekFirst())) {
                    num.append(queue.removeFirst());
                }
                times = Integer.parseInt(num.toString());
            } else if ('[' == queue.peekFirst()) {
                depth++;
                queue.removeFirst();
                while (depth > 0) {
                    if (']' == queue.peekFirst()) {
                        depth--;
                        if (depth > 0) {
                            sb.append(queue.removeFirst());
                        } else {
                            for (int j = 0; j < times; j++) {
                                for (int k = 0; k < sb.toString().length(); k++) {
                                    queue.addLast(sb.toString().charAt(k));
                                }
                            }

                            // reset all
                            sb.setLength(0);
                            depth = 0;
                            queue.removeFirst();
                        }
                    } else if ('[' == queue.peekFirst()) {
                        depth++;
                        sb.append(queue.removeFirst());
                    } else {
                        sb.append(queue.removeFirst());
                    }
                }
            } else {
                queue.addLast(queue.removeFirst());
            }
        }

        while (queue.peekLast() != '-') {
            queue.addLast(queue.removeFirst());
        }

        sb.setLength(0);

        for (int i = 0; i < queue.size() - 1; i++) {
            // skip the last end marking
            sb.append(queue.get(i));
        }

        return sb.toString();
    }
