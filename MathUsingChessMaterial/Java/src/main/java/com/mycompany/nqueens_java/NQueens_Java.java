package com.mycompany.nqueens_java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author RCL
 */
public class NQueens_Java {

    public static void main(String[] args) {
        int n = 0;
        long start = 0;
        try {
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));
            System.out.print("n = ");
            String input = reader.readLine();
            
            start = System.currentTimeMillis(); // get time right after user's input 
            
            n = Integer.parseInt(input);
            if (n <= 0) {
                System.out.println("Argument error: the 1st argument should be positive.");
            }
        }
        catch (IOException | NumberFormatException ex) {
            System.out.println("Argument error: the 1st argument should be an integer.\n" + ex.toString());
        }
        System.out.print("\n");
                
        NQueensProblem queensProblemObj = new NQueensProblem(n);

        System.out.print("computing ...\n\n(Press [Ctrl + C] if you want to stop execution.)\n\n");
        int numOfSol = queensProblemObj.SolveQueens();
        System.out.print("When n = " + n + ", there are " + numOfSol + " solution(s) to Queen Problem.\n\n");

        long finish = System.currentTimeMillis(); // get current time before finish 
        long timeElapsed = finish - start;
        double timeInSec = timeElapsed / 1000.0;
        
        System.out.println(" started at " + start);
        System.out.println("finished at " + finish);
        System.out.print("    Δt(time delta) = " + timeInSec + " second(s) = ");
        System.out.println(timeElapsed + " milli-second(s)"); // calculate Δt(time delta) inaccurately 
    }
}
