%{
 % 
 %  Coded by RCL 
 % 
%}

classdef NQueens % MUST match the name of this file 
    
    properties (Access = private)
        width  % 寬
        height % 高
        grid   % n x n 棋盤
    end

    methods
        
        function instance = setProperties(instance, n)
            instance.width  = n;
            instance.height = n;
            instance.grid = logical(zeros(n));
        end
        
        function valid = isValid(instance, x, y)
            for i = 0 : (instance.width - 1)
                if y - i >= 1 && y - i <= instance.height && x - i >= 1 && x - i <= instance.width
                    if instance.grid(y - i, x - i)
                        valid = false;
                        return;
                    end
                end
                if y - i >= 1 && y - i <= instance.height && x + i >= 1 && x + i <= instance.width
                    if instance.grid(y - i, x + i)
                        valid = false;
                        return;
                    end
                end
                if y - i >= 1 && y - i <= instance.height
                    if instance.grid(y - i, x)
                        valid = false;
                        return;
                    end
                end
            end
            valid = true;
        end
        
        function localSum = solQueens(instance, y)
            localSum = 0;
            for x = 1 : instance.width
                if y == instance.height
                    if isValid(instance, x, y)
                        localSum = localSum + 1;
                    end
                else
                    if isValid(instance, x, y)
                        instance.grid(y, x) = true;
                        localSum = localSum + solQueens(instance, y + 1);
                        instance.grid(y, x) = false;
                    end
                end
            end
        end
        
        function total = SolveQueens(instance)
            tic
            total = solQueens(instance, 1);
            toc
        end
        
    end
    
end