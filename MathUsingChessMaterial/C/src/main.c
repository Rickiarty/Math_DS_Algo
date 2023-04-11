#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "init.h"
#include "show.h"
#include "QueensProblem/queens_quiz.h"
#include "KnightTour/knight_quiz.h"

int main(int argc, char** argv) 
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("\n");
    
    // get current time right after user's input 
    time_t t1     = time(NULL);
    struct tm tm1 = *localtime(&t1);

    int width  = n;
    int height = n;

    // allocate space for data in memory 
    char **grid = (char**)malloc(height * sizeof(char*));
    char **digit_grid = (char**)malloc(height * sizeof(char*));
    for(int y=0; y<height; y+=1)
    {
        *(grid + y) = (char*)malloc(width * sizeof(char));
        *(digit_grid + y) = (char*)malloc(width * sizeof(char));
    }

    // initialization 
    init_grid(grid, digit_grid, width, height);

    //show_grid(grid, width, height);
    printf("\n");
    //show_digit_grid(digit_grid, width, height);
    printf("\n");

    printf("computing ...\n\n(Press [Ctrl + C] if you want to stop execution.\n WARNING: it's possible to lead to memory leak.)\n\n");

    // N queens 
    int num_of_sol_Q = solve_queens(digit_grid, n);
    printf("When n = %d, there are %d solution(s) to Queen Problem.\n\n", n, num_of_sol_Q);

    //clear_digit_grid(digit_grid, width, height);
    // knight's tour 
    //int num_of_K_close_path = 0;
    //int num_of_K_open_path  = 0;
    //int num_of_sol_K = solve_knight(digit_grid, n, &num_of_K_close_path, &num_of_K_open_path);
    //printf("When n = %d, there are %d solution(s) to Knight's Tour Problem \n\twhere number of close path = %d and number of open path = %d .\n\n", n, num_of_sol_K, num_of_K_close_path, num_of_K_open_path);
    
    // We MUST de-allocate space for data in memory, if you allocate it by your C code. 
    for(int y=0; y<height; y+=1)
    {
        free(*(grid + y));
        free(*(digit_grid + y));
    }
    free(grid);
    free(digit_grid);

    // get current time before finish 
    time_t t2     = time(NULL);
    struct tm tm2 = *localtime(&t2);

    // compute Δt / time delta of precision in second as type of long integer in C (inaccurately) 
    long time_delta    = (long)difftime(t2, t1); // Δt is difference subtracting t1 from t2. 
    struct tm tm_delta = long_to_time_delta(time_delta);
    
    printf(" started at: %d-%02d-%02d %02d:%02d:%02d\n", tm1.tm_year + 1900, tm1.tm_mon + 1, tm1.tm_mday, tm1.tm_hour, tm1.tm_min, tm1.tm_sec);
    printf("finished at: %d-%02d-%02d %02d:%02d:%02d\n", tm2.tm_year + 1900, tm2.tm_mon + 1, tm2.tm_mday, tm2.tm_hour, tm2.tm_min, tm2.tm_sec);
    printf("time delta (delta t) = %d year(s) %d day(s) %02d:%02d:%02d\n", tm_delta.tm_year, tm_delta.tm_yday, tm_delta.tm_hour, tm_delta.tm_min, tm_delta.tm_sec);
    
    return 0;
}