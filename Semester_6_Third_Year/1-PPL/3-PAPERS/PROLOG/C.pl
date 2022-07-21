rec([],L2,L2).
rec(L1,[],L1):-L1=[_|_].
rec([H1|T1],[H2|T2],[H1|T3]):-rec(T1,[H2|T2],T3).
rec([H1|T1],[H2|T2],[H2|T3]):-rec([H1|T1],T2,T3).
