shift(L1, N, L2) :-
    N < 0, !,             % this is the case for negative N
    length(L1, Len),
    N1 is Len + N,
    shift(L1, N1, L2).  

shift(L1, N, L2) :- 
    append(Lx, Ly, L1), % L1 is Lx || Ly
    append(Ly, Lx, L2), % L2 is Ly || Lx
    length(Lx, N).      % The length of Lx is N