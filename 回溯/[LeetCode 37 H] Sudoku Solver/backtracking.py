class Solution:
    def get_pos_nums(self, board, position, rows, cols, sub_boxes):
        nums = []
        row, col = position
        box_id = (row//3)*3 + col//3
        
        for s in map(str, range(1, 10)):
            if (not s in rows[row]) and \
                (not s in cols[col]) and \
                (not s in sub_boxes[box_id]):
                nums.append(s)
        return nums
    
    def init(self, board, rows, cols, sub_boxes, empty_pos):
        for i in range(9):
            for j in range(9):
                tmp = board[i][j]
                if tmp != '.':
                    rows[i].add(tmp)
                    cols[j].add(tmp)
                    box_id = (i//3)*3 + (j//3)
                    sub_boxes[box_id].add(tmp)
                else:
                    empty_pos.append((i,j))
        return
        
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [set() for i in range(9)]
        cols = [set() for i in range(9)]
        sub_boxes = [set() for i in range(9)]
        empty_pos = [] # record empty position(row, col)
        
        self.init(board, rows, cols, sub_boxes, empty_pos)
        
        def solve(board, positions):
            if not positions:
                return True
            
            # find all possible numbers on this position
            pos_nums = self.get_pos_nums(board
                                         , positions[0]
                                         , rows
                                         , cols
                                         , sub_boxes)
            if not pos_nums:
                return False
            
            row, col = positions[0]
            box_id = (row//3)*3 + (col//3)
            for s in pos_nums:
                board[row][col] = s
                rows[row].add(s)
                cols[col].add(s)
                sub_boxes[box_id].add(s)
                
                if solve(board, positions[1:]):
                    return True
                
                rows[row].remove(s)
                cols[col].remove(s)
                sub_boxes[box_id].remove(s)
                
            # all possible numbers is invalid, return False
            board[row][col] = '.'
            return False
        
        solve(board, empty_pos)
        return