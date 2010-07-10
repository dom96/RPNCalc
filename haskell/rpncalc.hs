import Data.IORef
import Data.Char

type Stack = [Int]

push :: Int -> Stack -> Stack
push x xs = x:xs

pop :: Stack -> (Int, Stack)
pop [] = error "Stack is empty"
pop (x:xs) = (x, xs)

pop2 :: Stack -> (Int, Int, Stack)
pop2 [] = error "Need at least 2 elements"
pop2 (x:[]) = error "Need at least 2 elements"
pop2 (x:y:xs) = (x, y, xs)

empty :: Stack -> Bool
empty = null

-- Evaluates a string which is either a operator or number(+, 96).
-- Pushes the result to the stack and returns the stack.
eval :: String -> Stack -> Stack
eval "" s = s
eval c s
    | c == "+" =
        let (val2, val, xs) = pop2 $ s
        in push (val + val2) xs
    | c == "-" =
        let (val2, val, xs) = pop2 $ s
        in push (val - val2) xs
    | c == "*" =
        let (val2, val, xs) = pop2 $ s
        in push (val * val2) xs
    | c == "/" =
        let (val2, val, xs) = pop2 $ s
        in push (val `div` val2) xs
    | all isDigit c =
        let xs = push (read c :: Int) s
        in xs
    | otherwise =
        s
        
evalLoop :: [String] -> Stack -> Stack
evalLoop [] s = s
evalLoop (x:xs) s = evalLoop xs (eval x s)

mainLoop ref = do
    code <- getLine
    if null code
        then do
              tmp <- readIORef ref

              putStrLn $ "Stack → " ++ (show tmp)
        else do
              tmp <- readIORef ref
          
              let ret = evalLoop (words code) (tmp)
              writeIORef ref ret
              
              putStrLn $ "Stack → " ++ (show ret)
              mainLoop ref

main = do 
    ref <- newIORef []
    mainLoop ref
