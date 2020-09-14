Practices from [ADA2018](https://www.csie.ntu.edu.tw/~yvchen/f107-ada/)

### Basic
* [hw1: #1](./hw1-1)    (Related problem: [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39039/Sharing-my-simple-and-clear-C%2B%2B-solution))

* [hw2: #3-1](./hw2-3_1)  (Related problem: [62. Unique Paths](https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP))
* [hw3: #1](./hw3-1)    (Reference: [Dijkstra by priority queue](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/))


### Advanced
* [hw1 #2](./hw1-2)
    * [Advanced solution](./hw1-2/advancedSolution.cpp):  
        每一個長方形的面積= |x - xi| * |y - yi|。  
        若已知 x > xi, y > yi，則所有長方形的面積總和可簡化為  
        ![equation](https://bit.ly/3isYtzB)  
        再把各項整理後，變成：  
        ![equation](https://bit.ly/2GXLOH4)  
        令[![equation](https://bit.ly/3mnloyO) ，[![equation](https://bit.ly/3mm2WWY) ，[![equation](https://bit.ly/2GYAVVr)  
        於是可以想像成，針對某一點(x,y)去計算其他點的 X, Y , XY。  
        思路：  
        1. Sort by x coord.
        2. 切半分成兩群  
        3. 左右各自往下做，做完回傳到上一層  
        4. 處理跨左右兩邊的情形：左邊挑 y 最小的點，劃一水平線為基準，用小於此基準線的點更新 Sigma(x), sigma(y), sigma(xy).

* [hw2 #1](./hw2-1)  
    * (Reference: [To get sum of Geometric series in O(1)](https://www.geeksforgeeks.org/sum-of-the-series-20-21-22-2n/)) (沒有用到)
    * [用位元運算實現2^N](http://ccy.dd.ncu.edu.tw/~chen/course/Cpp/ch2/8.htm)

* [hw2 #2](./hw2-2)  