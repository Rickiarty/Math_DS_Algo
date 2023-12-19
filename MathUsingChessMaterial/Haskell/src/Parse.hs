module Parse (parseStringToInt) where

import Data.Char

parseStringToInt :: [Char] -> Int 
parseStringToInt str = parseStrToInt str (10 ^ ((length str) - 1))

parseStrToInt :: [Char] -> Int -> Int 
parseStrToInt [] _ = 0 -- empty string 
parseStrToInt (c:cs) times = if length cs /= 0 -- not last char in string 
                                then (
                                        if '0' <= c && c <= '9' 
                                        then (ord c) - (ord '0') 
                                        else error "wrong format"
                                      ) * times + (parseStrToInt cs (times `div` 10)) 
                                else -- last char in string 
                                    if '0' <= c && c <= '9' 
                                    then (ord c) - (ord '0') 
                                    else error "wrong format" 
