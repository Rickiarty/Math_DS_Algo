#include <stdlib.h>
#include <stdio.h>

int next_possible_moves(int **pairs, char **grid, int width, int height, int x, int y)
{
    int num_of_valid_pairs = 0;
    int delta_x[] = {-2, 2, -1, 1, -2,  2, -1,  1};
    int delta_y[] = {-1, 1, -2, 2,  1, -1,  2, -2};
    for(int i = 0; i < 8; i += 1)
    {
        if(x+delta_x[i]>=0 && x+delta_x[i]<width && y+delta_y[i]>=0 && y+delta_y[i]<height)
        {
            if ( !*(*(grid + y + delta_y[i]) + x + delta_x[i]) ) // *(*(grid + y + delta_y[i]) + x + delta_x[i]) == 0 
            {    
                *(*(pairs+num_of_valid_pairs))   = x + delta_x[i];
                *(*(pairs+num_of_valid_pairs)+1) = y + delta_y[i];
                num_of_valid_pairs += 1;
            }
        }
    }
    return num_of_valid_pairs;
}

char check_whether_all_cells_filled(char **grid, int width, int height)
{
    for(int y=0; y<height; y+=1)
    {
        for(int x=0; x<width; x+=1)
        {
            if(!*(*(grid+y)+x)) // *(*(grid+y)+x) == 0 
            {
                return 0;
            }
        }
    }
    return 1;
}

int sol_knight(char **grid, int width, int height, int x, int y, int start_x, int start_y, int *num_of_close_path)
{
    int sum = 0;

    // allocation in memory 
    int **pairs = (int**)malloc(8 * sizeof(int*));
    for(int i=0; i<8; i+=1)
    {
        *(pairs + i) = (int*)malloc(2 * sizeof(int));
    }

    *(*(grid+y)+x) = 1; // grid[y][x] = 1 
    int count_pairs = next_possible_moves(pairs, grid, width, height, x, y);
    if(count_pairs == 0)
    {
        if(check_whether_all_cells_filled(grid, width, height)) // check_whether_all_cells_filled(grid, width, height) != 0 
        {
            sum += 1;
            if(x == start_x && y == start_y)
            {
                *(num_of_close_path) += 1;
            }
        }
    }
    else
    {
        for(int i=0; i<count_pairs; i+=1)
        {
            sum += sol_knight(grid, width, height, *(*(pairs+i)), *(*(pairs+i)+1), start_x, start_y, num_of_close_path);
        }
    }
    *(*(grid+y)+x) = 0; // grid[y][x] = 0 

    // de-allocation in memory 
    for(int i=0; i<8; i+=1)
    {
        free(*(pairs + i));
    }
    free(pairs);

    return sum;
}

int solve_knight(char **grid, int n, int *num_of_close_path, int *num_of_open_path)
{
    int width  = n;
    int height = n;
    int half_n = n / 2;
    int num_of_sol = 0;
    if(n & 1) // odd: n % 2 == 1 
    {
        // start from first one of four quarters of chess board 
        for(int y=0; y<=half_n; y+=1)
        {
            for(int x=0; x<half_n; x+=1)
            {
                num_of_sol = sol_knight(grid, width, height, x, y, x, y, num_of_close_path);
            }
        }
        num_of_sol *= 4;
        *num_of_close_path *= 4;
        // start from central cell of chess board 
        num_of_sol += sol_knight(grid, width, height, half_n, half_n, half_n, half_n, num_of_close_path);
    }
    else // even: n % 2 == 0 
    {
        // start from first one of four quarters of chess board 
        for(int y=0; y<half_n; y+=1)
        {
            for(int x=0; x<half_n; x+=1)
            {
                num_of_sol = sol_knight(grid, width, height, x, y, x, y, num_of_close_path);
            }
        }
        num_of_sol *= 4;
        *num_of_close_path *= 4;
    }
    *num_of_open_path = num_of_sol - *num_of_close_path;
    
    return num_of_sol;
}