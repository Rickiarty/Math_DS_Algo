using NQueens;
using System.Text;

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
StringBuilder sb = new StringBuilder();
sb.Append($"When n = {n}, there are {numOfSol} solution(s) to Queen Problem.\n\n");

DateTime end_time = DateTime.Now; // get current time before finish 

sb.Append($" started at {start_time}\n");
sb.Append($"finished at {end_time}\n");
sb.Append($"    Δt(time delta) = {end_time - start_time}\n\n"); // calculate Δt(time delta) inaccurately 
string resultStr = sb.ToString();
Console.Write(resultStr);
#if RELEASE
File.AppendAllText("results.log", resultStr);
#endif