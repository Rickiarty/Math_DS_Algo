int clear_digit_grid(char **digit_grid, int width, int height)
{
    for(int y=0; y<height; y+=1)
    {
        for(int x=0; x<width; x+=1)
        {
            *(*(digit_grid+y)+x) = 0;
        }
    }
    return 0;
}

int init_grid(char **grid, char **digit_grid, int width, int height)
{
    clear_digit_grid(digit_grid, width, height);
    for(int y=0; y<height; y+=1)
    {
        for(int x=0; x<width; x+=1)
        {
            if(y & 1)
            {
                if(x & 1)
                {
                    *(*(grid+y)+x) = '#';
                }
                else
                {
                    *(*(grid+y)+x) = '_';
                }
            }
            else
            {
                if(x & 1)
                {
                    *(*(grid+y)+x) = '_';
                }
                else
                {
                    *(*(grid+y)+x) = '#';
                }
            }
        }
    }
    return 0;
}