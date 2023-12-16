module NQueen (solveNQueen) where

import Prelude
import Data.Bool

solveNQueen :: Int -> Int
solveNQueen n = solveNQ (n-1) (n-1) n (initGrid n)

initGrid :: Int -> [[Bool]]
initGrid n = take n (repeat (take n (repeat False)))

setElemIn1D :: Int -> Bool -> [Bool] -> [Bool] 
setElemIn1D x value list = bef ++ value : aft 
                            where (bef,_:aft) = splitAt x list 

setElemIn2D :: Int -> Int -> Bool -> [[Bool]] -> [[Bool]] 
setElemIn2D x y value grid = bef ++ (setElemIn1D x value (grid !! y)) : aft 
                            where (bef,_:aft) = splitAt y grid 

solveNQ :: Int -> Int -> Int -> [[Bool]] -> Int 
solveNQ 0 y n grid = if doesCollide 0 y n grid 
                    then 0 
                    else -- does not collide at (x,y) 
                        if y > 0 
                        then solveNQ (n-1) (y-1) n (setElemIn2D 0 y True grid) 
                        else 1 
solveNQ x y n grid = (solveNQ (x-1) y n grid) + if doesCollide x y n grid 
                                                then 0 
                                                else -- does not collide at (x,y) 
                                                    if y > 0 
                                                    then solveNQ (n-1) (y-1) n (setElemIn2D x y True grid) 
                                                    else 1 

doesCollide :: Int -> Int -> Int -> [[Bool]] -> Bool 
doesCollide x y n grid = (doesCollide1 x y n grid) || (doesCollide2 x y n grid) || (doesCollide3 x y n grid) 

doesCollide1 :: Int -> Int -> Int -> [[Bool]] -> Bool 
doesCollide1 x y n grid = if y >= n || x < 0 
                            then False 
                            else 
                                if (grid !! y) !! x 
                                then True 
                                else doesCollide1 (x-1) (y+1) n grid 

doesCollide2 :: Int -> Int -> Int -> [[Bool]] -> Bool 
doesCollide2 x y n grid = if y >= n 
                            then False 
                            else 
                                if (grid !! y) !! x 
                                then True 
                                else doesCollide2 x (y+1) n grid 

doesCollide3 :: Int -> Int -> Int -> [[Bool]] -> Bool 
doesCollide3 x y n grid = if y >= n || x >= n 
                            then False 
                            else 
                                if (grid !! y) !! x 
                                then True 
                                else doesCollide3 (x+1) (y+1) n grid 
