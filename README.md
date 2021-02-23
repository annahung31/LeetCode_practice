# LeetCode_practice
My personal notes for LeetCode practice.


## Problem Index

### Linked list
* [206. Reverse Linked List](206_Reverse_Linked_List.ipynb), [LeetCode](https://leetcode.com/problems/reverse-linked-list/)
    - Reference: https://www.geeksforgeeks.org/reverse-a-linked-list/ 


### DP
* [53.Maximum Subarray](53_Maximum_Subarray.py) 
    - Reference: https://www.youtube.com/watch?v=7J5rs56JBs8 

* [70. Climbing Stairs](70_Climbing_Stairs.py) 
    - Reference: https://www.youtube.com/watch?v=LpsDWvkd-4Q

* [139. Work Break](139_word_break.cpp)
    - Reference: [Solution from paul7](https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization)

### Recurrence

* [215. Kth Largest Element in an Array](215_Kth_Largest_Element_in_an_Array.py) 
    - Reference: 
        - [K’th Smallest/Largest Element in Unsorted Array | Set 3 (Worst Case Linear Time)](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/?ref=rp)
    
    - Important NOTE!: 其中的 Partition 是很常見的operation，標準做法是以 Lomuto scheme 實作 partition,[這個網頁](https://rust-algo.club/sorting/quicksort/)的圖說很易懂。 Worst case: O(n^2)。

    ```
    [ values <= pivot | values > pivot | not checked yet | pivot ]
      low           i   i+1        j-1   j        high-1   high
    arr[low...i] 包含所有小於等於 pivot 的元素。
    arr[i+1...j-1] 包含所有大於 pivot 的元素。
    arr[j...high-1] 包含所有尚未迭代的元素。
    arr[high] pivot 本身。
    ```

## Reference

### Thinking
* [Difference between Divide-and-Conquer and DP](https://sls.weco.net/blog/ie945232/27-may-2007/6442)  
    - DC: Top-down
    - DP: Bottom-up 

### Divide-and-Conquer
* [Merge Sort](https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html)


* [判斷是否為質數](https://coherence0815.wordpress.com/2015/05/15/if-a-number-is-prime-in-c/)
