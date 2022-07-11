//642 · Moving Average from Data Stream
//Algorithms
//Easy
//Accepted Rate
//50%
//Description
//Solution
//Notes
//Discuss
//Leaderboard
//Description
//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
//Contact me on wechat to get Amazon、Google requent Interview questions . (wechat id : jiuzhang0607)
//
//
//Example
//Example 1:
//
//MovingAverage m = new MovingAverage(3);
//m.next(1) = 1 // return 1.00000
//m.next(10) = (1 + 10) / 2 // return 5.50000
//m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
//m.next(5) = (10 + 3 + 5) / 3 // return 6.00000

class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) : m_size{size} {
        // do intialization if necessary
    }

    /*
     * @param val: An integer
     * @return:
     */
    double next(int val) {
        if (m_d.size() >= m_size) {
            m_sum -= m_d.front();
            m_d.pop_front();
        }
        m_d.push_back(val);
        m_sum += val;
        return (double)m_sum / m_d.size();
    }
private:
    int m_size;
    long long m_sum{0};
    std::deque<int> m_d;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
