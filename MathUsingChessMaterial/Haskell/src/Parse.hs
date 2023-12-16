module Parse (parseStringToInt) where

import Data.Char

parseStringToInt :: [Char] -> Int 
parseStringToInt [] = 0 
parseStringToInt (c:cs) = if length cs /= 0 
                        then (
                                if '0' <= c && c <= '9' 
                                then (ord c) - (ord '0') 
                                else error "wrong format"
                             ) * 10 + (parseStringToInt cs) 
                        else 
                            if '0' <= c && c <= '9' 
                            then (ord c) - (ord '0') 
                            else error "wrong format" 
