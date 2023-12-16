"""
 * 
 *  Coded by Rei-Chi Lin 
 * 
"""

function isValid(grid :: Vector{Vector{Bool}}, width :: Int, height :: Int, x :: Int, y :: Int) :: Bool
    for i in 1:width
        if y - i >= 1 && y - i <= height && x - i >= 1 && x - i <= width
            if grid[y - i][x - i]
                return false
            end
        end
        if y - i >= 1 && y - i <= height && x + i >= 1 && x + i <= width
            if grid[y - i][x + i]
                return false
            end
        end
        if y - i >= 1 && y - i <= height
            if grid[y - i][x]
                return false
            end
        end
    end
    return true
end

function solQueens(grid :: Vector{Vector{Bool}}, width :: Int, height :: Int, y :: Int) :: Int
    sum :: Int = 0
    for x in 1:width
        if y == height
            if isValid(grid, width, height, x, y)
                sum += 1
            end
        else
            if isValid(grid, width, height, x, y)
                grid[y][x] = true
                sum += solQueens(grid, width, height, y + 1)
                grid[y][x] = false
            end
        end
    end
    return sum
end

function SolveQueens(n :: Int) :: Int
    width  :: Int = n
    height :: Int = n
    grid   :: Vector{Vector{Bool}} = [[ false for x in 1:n] for y in 1:n]
    return solQueens(grid, width, height, 1)
end

function Run()
    print("N = ")
    input :: String = readline()
    n :: Int = parse(Int, input)
    @timev numOfSolutions :: Int = SolveQueens(n) 
    println("\nWhen N = " * string(n) * ", \nnumber of solutions = " * string(numOfSolutions))
end

Run()
