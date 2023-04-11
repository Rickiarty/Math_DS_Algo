using NQueens;

Console.Write("n = ");
string? input = Console.ReadLine();

DateTime start_time = DateTime.Now; // get time right after user's input  

int n = 0;
if (int.TryParse(input, out n))
{
    if (n <= 0)
    {
        throw new ArgumentException("Argument error: the 1st argument should be positive.", nameof(args));
    }
}
else
{
    throw new ArgumentException("Argument error: the 1st argument should be an integer.", nameof(args));
}
Console.Write("\n");

NQueensProblem queensProblemObj = new NQueensProblem(n);

Console.Write("computing ...\n\n(Press [Ctrl + C] if you want to stop execution.)\n\n");
int numOfSol = queensProblemObj.SolveQueens();
Console.Write($"When n = {n}, there are {numOfSol} solution(s) to Queen Problem.\n\n");

DateTime end_time = DateTime.Now; // get current time before finish 

Console.WriteLine($" started at {start_time}");
Console.WriteLine($"finished at {end_time}");
Console.WriteLine($"     Δt(time delta) = {end_time - start_time}"); // calculate Δt(time delta) inaccurately 
