// Leetcode 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/description/
// Runtime: 29ms

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

// 此题不假设Interval对象们按start升序排序, 所以先做了排序
public class Solution {
    final Comparator comp = new Comparator<Interval>() {
        @Override
        public int compare(Interval in1, Interval in2) {
            return in1.start - in2.start;
        }
    };

    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new LinkedList<>();
        if (intervals.size() == 0) {
            return res;
        }

        if (intervals.size() == 1) {
            res.add(intervals.get(0));
            return res;
        }

        Collections.sort(intervals, comp);

        // s和e为目前合并的start和end
        int s = 0;
        int e = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int begin = intervals.get(i).start;
            int end = intervals.get(i).end;
            if (i == 0) {
                s = begin;
                e = end;
                res.add(new Interval(s, e));
            } else {
                if (e >= begin) {
                    // 有可能出现[1-6],[2-4]这种情况, 需要判断
                    if (end > e) {
                        res.get(res.size() - 1).end = end;
                        e = end;
                    }
                } else {
                    s = begin;
                    e = end;
                    res.add(new Interval(s, e));
                }
            }
        }
        return res;
    }
}
