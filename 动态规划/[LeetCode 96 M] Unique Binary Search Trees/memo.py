class Solution:
    def numTrees(self, n: int) -> int:
        d=[-1 for i in range(n+1)]
        return self.f(n,d)
        
        
        
    def f(self,n,d):
        if d[n] != -1 :
            return d[n]
        if n <= 1 :
            return 1 
        s=0
        for i in range(1,n+1):
            s=s+ self.f(i-1,d)*self.f(n-i,d)
        d[n] =s 
        return s 