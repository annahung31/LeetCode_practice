

class Solution(object):
    '''
    O(n)
    '''
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        f = [0] * (n+1)
        f[0] = 1
        f[1] = 1
        for i in range(2,n+1):

            f[i] = f[i-1] + f[i-2]
        
        return f[n]



class SolutionB(object):
    '''
    record what have been calculated
    '''
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        f = [0] * (n+1)
        f[0] = 1
        f[1] = 1

        return self.numOfSolutions(f, n)

    def numOfSolutions(self, f, n):
        if f[n] > 0:
            return f[n]
        if n <= 1:
            return 1
        f[n] = self.numOfSolutions(f, n-1) + self.numOfSolutions(f, n-2)
        return f[n]
        


class SolutionC(object):
    '''
    O(1)
    觀察 solution 可以發現其實每次都只有訪問前兩個（n-1, n-2)來得到 f(n)，
    因此只需要兩個位置來紀錄就好了
    '''
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        step_two = 1  #兩步之前的解
        step_one = 1  #一步之前的解
        curr =  0     #目前所需的解

        for _ in range(2, n+1):
            curr =  step_one + step_two
            step_two = step_one
            step_one = curr
        
        '''
        觀察 fibonacci sequence:
        5 = 4    +   3  
            one     two

        6 = 5    +   4

        故當進到下一個 loop 時， two 是上一輪的 one，而 one 是上一輪的 curr。
        '''


        return curr

         


sol = SolutionB()

ans = sol.climbStairs(3)
print(ans)