% length of list

findlength([],0).
findlength([_|T], N) :-
    findlength(T,X),
    N is X+1.

% find first and last element

firstlast([],[],[]).
firstlast([H],H,H).
firstlast([H|T],H,L) :- firstlast(T,_,L).

% nth element

findnth([H|_],H,1).
findnth([_|T],X,N) :-
    N1 is N-1,
    N1 > 0,
    findnth(T,X,N1).

% increment each element
% X is input Y is output

incrementeach([],[]).
incrementeach([X|Xs],[Y|Ys]) :-
    (number(X) -> Y is X+1),
    incrementeach(Xs,Ys).

% reverse the list

reverseList(Inputlist,Outputlist) :- reverse(Inputlist,[],Outputlist).
reverse([],Outputlist,Outputlist).
reverse([Head|Tail],List1,List2) :- reverse(Tail,[Head|List1],List2).

% list has even number of elements

evenlength([H|T]) :- findlength([H|T],X), 0 is mod(X,2).

% find number of vowels

vowel(a).
vowel(e).
vowel(i).
vowel(o).
vowel(u).
countvowels([],0).
% Exclamation point ! denotes Cut in Prolog
% a special goal that always succeeds, and blocks backtracking for all branches above it that may have alternatives.
countvowels([H|T],X) :- (countvowels(T,Y),vowel(H),X is Y+1,!);(countvowels(T,X)).

% remove duplicates

chk(X,[H|T]) :- ((X=H,!);chk(X,T)).
removeDupli([],[]).
removeDupli([H|T],X) :-
    ((removeDupli(T,Y),not(chk(H,T)),append([H],Y,X),!);
    (removeDupli(T,X))).
