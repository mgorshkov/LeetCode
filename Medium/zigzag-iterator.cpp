//540 · Zigzag Iterator
//Algorithms
//Medium
//Accepted Rate
//61%
//
//DescriptionSolutionNotesDiscussLeaderboard
//Description
//Given two 1d vectors, implement an iterator to return their elements alternately.
//
//Example
//Example1
//
//Input: v1 = [1, 2] and v2 = [3, 4, 5, 6]
//Output: [1, 3, 2, 4, 5, 6]
//Explanation:
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
//Example2
//
//Input: v1 = [1, 1, 1, 1] and v2 = [3, 4, 5, 6]
//Output: [1, 3, 1, 4, 1, 5, 1, 6]

class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if (!v1.empty())
            q.push({v1.begin(), v1.end()});
        if (!v2.empty())
            q.push({v2.begin(), v2.end()});
    }

    /*
     * @return: An integer
     */
    int next() {
        auto its = q.front();
        q.pop();
        auto result = *its.first++;
        if (its.first != its.second)
            q.push(its);
        return result;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return !q.empty();
    }

private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
