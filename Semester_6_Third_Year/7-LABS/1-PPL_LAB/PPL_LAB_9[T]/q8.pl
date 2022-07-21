% WAP to determine whether an Argument List is Sorted or Not.

is_sorted([]).

is_sorted([_]).

is_sorted([T1,T2|T3]) :- 
    T1 =< T2,
    is_sorted([T2|T3]).