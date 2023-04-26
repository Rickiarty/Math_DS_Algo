from py3lib.NQProb import NQueensProblem
from datetime import datetime

"""
 * 
 *  Coded by Rei-Chi Lin 
 * 
"""

def main():
    print("n = ", end='')
    instr = input()

    start_time = datetime.now() # get time right after user's input 

    n: int = 0
    n = int(instr)
    if n > 0:
        queensProblemObj: NQueensProblem = NQueensProblem(n=n)

        print("\ncomputing ...\n\n(Press [Ctrl + C] if you want to stop execution.)\n\n")
        numOfSol: int = queensProblemObj.SolveQueens()
        print(f"When n = {n}, there are {numOfSol} solution(s) to Queen Problem.\n\n")

        end_time = datetime.now() # get current time before finish 

        print(f" started at {start_time}")
        print(f"finished at {end_time}")
        print(f"       Δt(time delta) = {end_time - start_time}") # calculate Δt(time delta) inaccurately 
    else:
        print("The number 'n' must greater than 0.")

if __name__ == "__main__":
    main()
