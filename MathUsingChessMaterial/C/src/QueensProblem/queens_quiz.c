
char is_valid(char **grid, int width, int height, int x, int y)
{
    for(int i=1; i<width; i+=1)
    {
        //if(y+i>=0 && y+i<height && x+i>=0 && x+i<width){
        //    if(*(*(grid+y+i)+x+i))
        //    {
        //        return 0;
        //    }
        //}
        if(y-i>=0 && y-i<height && x-i>=0 && x-i<width){
            if(*(*(grid+y-i)+x-i))
            {
                return 0;
            }
        }
        //if(y+i>=0 && y+i<height && x-i>=0 && x-i<width){
        //    if(*(*(grid+y+i)+x-i))
        //    {
        //        return 0;
        //    }
        //}
        if(y-i>=0 && y-i<height && x+i>=0 && x+i<width){
            if(*(*(grid+y-i)+x+i))
            {
                return 0;
            }
        }
        if(y-i>=0 && y-i<height){
            if(*(*(grid+y-i)+x))
            {
                return 0;
            }
        }
        //if(y+i>=0 && y+i<height){
        //    if(*(*(grid+y+i)+x))
        //    {
        //        return 0;
        //    }
        //}
        //if(x-i>=0 && x-i<width){
        //    if(*(*(grid+y)+x-i))
        //    {
        //        return 0;
        //    }
        //}
        //if(x+i>=0 && x+i<width){
        //    if(*(*(grid+y)+x+i))
        //    {
        //        return 0;
        //    }
        //}
    }
    return 1;
}

int sol_queens(char **grid, int width, int height, int y)
{
    int sum = 0;
    for(int x=0; x<width; x+=1)
    {
        if(y == height - 1)
        {
            sum += (int)is_valid(grid, width, height, x, y);
        }
        else
        {
            if(is_valid(grid, width, height, x, y))
            {
                *(*(grid+y)+x) = 1;
                sum += sol_queens(grid, width, height, y+1);
                *(*(grid+y)+x) = 0;
            }
        }
    }
    return sum;
}

int solve_queens(char **grid, int n)
{
    return sol_queens(grid, n, n, 0);
}