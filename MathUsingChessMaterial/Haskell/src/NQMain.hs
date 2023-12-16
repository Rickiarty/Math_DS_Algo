import NQueen
import Parse

nqmain = do 
    putStr "N = " 
    inputStr <- getLine 
    putStr "\nYour input = \"" 
    putStrLn (inputStr ++ "\"\n")
    putStr "When N = "
    putStr inputStr
    putStr ", \nnum. of solutions = "
    putStrLn (show ( solveNQueen (parseStringToInt inputStr) )) 
