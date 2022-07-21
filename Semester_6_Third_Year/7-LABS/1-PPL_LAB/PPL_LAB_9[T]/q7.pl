% WAP to count the Number of Occurances of a Given Object in a List in Prolog

count([],_,Ans):-Ans is 0.

count([H|T], X, Ans):-
    H =:= X,
    count(T, X, C1),
    Ans is C1 + 1.

count([H|T], X, Ans):-
    H =/= X,
    count(T, X, Ans).