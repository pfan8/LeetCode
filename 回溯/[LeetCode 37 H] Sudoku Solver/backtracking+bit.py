class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row={i:0 for i in range(9)}
        col={i:0 for i in range(9)}
        grid={i:0 for i in range(9)}
        dots=[]
        total=0
        for i in range(9):
            total+=1<<i
            for j in range(9):
                if board[i][j]==".": 
                    dots.append((i, j))
                else:
                    val=1<<(ord(board[i][j])-ord("1"))
                    row[i]+=val
                    col[j]+=val
                    grid[(i//3)*3+(j//3)]+=val
        
        def backtrack(dots=dots):
            if not dots: return True 
            x, y=dots[0]
            appeared=row[x] | col[y] | grid[(x//3)*3+(y//3)]
            if appeared==total:
                return False
            for val in range(1, 10):
                tempval=1<<(val-1)
                if (tempval& appeared)==0 : 
                    row[x]+=tempval
                    col[y]+=tempval
                    grid[(x//3)*3+(y//3)]+=tempval
                    board[x][y]=str(val)
                    if backtrack(dots[1:]):
                        return True
                    else: 
                        row[x]-=tempval
                        col[y]-=tempval
                        grid[(x//3)*3+(y//3)]-=tempval
            return False
                                
        backtrack()