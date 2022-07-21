% Print(s) Out Element at Position 2,4,6,8,...

% Query : evenpo([a,b,c,d,e,f],R) -> R = [b,d,f]

% evenpo([X],[]).
% evenpo([X,X2],[X2]).
% evenpo([H,H2|T],[H2|R]):-
%     evenpo(T,R).

evenpo(L):-
    evenpos(L,Ans),
    print_list(Ans).

evenpos([X],[]).
evenpos([X,X2],[X2]).
evenpos([H,H2|T],[H2|R]):-
    evenpos(T,R).

print_list([]).
print_list([H|T]):-
    write(H),
    write(" "),
    print_list(T).