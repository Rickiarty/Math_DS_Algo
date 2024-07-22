/*
 * 
 *  This Rust source code was translated from the equivalent Python3 source code by Co-pilot, made by Microsoft. 
 * 
 */

 use std::io::{self, Write};
 use std::time::Instant;
 
 struct NQueensProblem {
     width: usize,
     height: usize,
     grid: Vec<Vec<bool>>,
 }
 
 impl NQueensProblem {
     fn new(n: usize) -> Self {
         let grid = vec![vec![false; n]; n];
         Self {
             width: n,
             height: n,
             grid,
         }
     }
 
     fn is_valid(&self, x: usize, y: usize) -> bool {
         for i in 0..self.width {
             if y >= i && x >= i && self.grid[y - i][x - i] {
                 return false;
             }
             if y >= i && x + i < self.width && self.grid[y - i][x + i] {
                 return false;
             }
             if y >= i && self.grid[y - i][x] {
                 return false;
             }
         }
         true
     }
 
     fn sol_queens(&mut self, y: usize) -> i32 {
         let mut sum = 0;
         for x in 0..self.width {
             if y == self.height - 1 {
                 if self.is_valid(x, y) {
                     sum += 1;
                 }
             } else {
                 if self.is_valid(x, y) {
                     self.grid[y][x] = true;
                     sum += self.sol_queens(y + 1);
                     self.grid[y][x] = false;
                 }
             }
         }
         sum
     }
 
     fn solve_queens(&mut self) -> i32 {
         self.sol_queens(0)
     }
 }
 
 fn main() {
     print!("N = ");
     io::stdout().flush().unwrap();
     let mut input = String::new();
     io::stdin().read_line(&mut input).unwrap();
     let n: usize = input.trim().parse().unwrap();
     let start = Instant::now();
     let mut problem = NQueensProblem::new(n);
     let num_of_solutions = problem.solve_queens();
     let duration = start.elapsed();
     println!("\nWhen N = {}, \nnumber of solutions = {}", n, num_of_solutions);
     println!("Time elapsed is: {:?}", duration);
 }
 