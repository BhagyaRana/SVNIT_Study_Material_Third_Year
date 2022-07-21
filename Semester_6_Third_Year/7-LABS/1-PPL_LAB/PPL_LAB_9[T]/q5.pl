% WAP to Insert Elements in the List Only When the Element is Not in the List

insert(L, X, Ans):-
    contains(L, X, To_Appnd),
    append(L, To_Appnd, Ans).

contains([], X, To_Appnd) :- To_Appnd = [X].

contains([H|T], X, To_Appnd):-
    ( H =:= X, To_Appnd=[], !)
    ;
    (
        contains(T,X,To_Appnd)
    ).
