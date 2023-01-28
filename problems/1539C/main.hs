{-# LANGUAGE ScopedTypeVariables #-}

import qualified Data.ByteString.Char8 as C
import Data.Int (Int)
import Data.List (sort)
import Debug.Trace

readMultipleFromLine :: IO [Int]
readMultipleFromLine = map parse . C.words <$> C.getLine
  where
    parse s = let Just (n, _) = C.readInt s in n

joints :: Int -> [Int] -> [Int]
joints x a = [j - i | (i, j) <- zip a $ tail a, j - i > x]

uniteCount :: Int -> Int -> [Int] -> Int
uniteCount _ _ [] = 0
uniteCount x k a =
  let need = head a `div` x - (if head a `mod` x == 0 then 1 else 0)
   in if need <= k
        then uniteCount x (k - need) $ tail a
        else length a

main = do
  [n, k, x] :: [Int] <- readMultipleFromLine
  a :: [Int] <- readMultipleFromLine
  print $ 1 + uniteCount x k (sort $ joints x $ sort a)