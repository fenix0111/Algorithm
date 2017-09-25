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

        int s = 0;
        int e = 0;
        int head = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int begin = intervals.get(i).start;
            int end = intervals.get(i).end;
            if (i == 0) {
                s = begin;
                e = end;
                res.add(new Interval(s, e));
            } else {
                if (e >= begin) {
                    if (end > e) {
                        res.get(res.size() - 1).end = end;
                        e = end;
                    }
                } else {
                    s = begin;
                    e = end;
                    res.add(new Interval(s, e));
                    head = i;
                }
            }
        }

        return res;
    }
}
