% if(X>Y)
%  if(Y>Z)  
%     Max - X, Min - Z
%  else
%    if X>Z    
%     Max - X, Min - Y
%    else
%     Max - Z, Min - Y
% else
%  if(X>Z)  
%     Max - Y, Min - Z
%  else
%    if Y>Z    
%     Max - Y, Min - X
%    else
%     Max - Z, Min - X

min_max_salary(X,Y,Z,Min,Max):-
    (
        (X>Y) ->  
        (
            (Y>Z) -> 
                (Max=X,Min=Z)
            ;
                (X>Z) -> 
                    (Max=X,Min=Y)
                ;
                    (Max=Z,Min=Y)
        )
        ;
        (
            (X>Z) -> 
                (Max=Y,Min=Z)
            ;
                (Y>Z) -> 
                    (Max=Y,Min=X)
                ;
                    (Max=Z,Min=X)
        )

    ).