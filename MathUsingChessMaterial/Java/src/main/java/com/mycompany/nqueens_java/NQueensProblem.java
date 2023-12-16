package com.mycompany.nqueens_java;

/**
 *
 * @author RCL
 */
public class NQueensProblem {
        protected int width = 0;
        protected int height = 0;
        protected boolean[][] grid;

        public NQueensProblem(int n) {
            this.width = n;
            this.height = n;

            this.grid = new boolean[n][];
            for (int i = 0; i < this.grid.length; i++) 
            {
                this.grid[i] = new boolean[n];
            }
        }

        protected boolean isValid(int x, int y) {
            for (int i = 1; i < width; i += 1) {
                if (y - i >= 0 && y - i < height && x - i >= 0 && x - i < width) {
                    if (this.grid[y - i][x - i]) {
                        return false;
                    }
                }
                if (y - i >= 0 && y - i < height && x + i >= 0 && x + i < width) {
                    if (this.grid[y - i][x + i]) {
                        return false;
                    }
                }
                if (y - i >= 0 && y - i < height) {
                    if (this.grid[y - i][x]) {
                        return false;
                    }
                }
            }
            return true;
        }

        protected int solQueens(int y) {
            int sum = 0;
            for (int x = 0; x < width; x += 1) {
                if (y == height - 1) {
                    if (this.isValid(x, y)) {
                        sum += 1;
                    }
                }
                else {
                    if (this.isValid(x, y)) {
                        this.grid[y][x] = true;
                        sum += this.solQueens(y + 1);
                        this.grid[y][x] = false;
                    }
                }
            }
            return sum;
        }

        public int SolveQueens() {
            return this.solQueens(0);
        }
    
}
