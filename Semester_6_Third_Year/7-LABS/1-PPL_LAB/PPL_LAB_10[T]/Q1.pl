% male(person) - person is male
male(james1).  
male(charles1).
male(charles2).
male(james2).
male(george1).
male(paul).
male(sam).

% female(person) - person is female
female(catherine).
female(elizabeth).
female(sophia).
female(claudia).
female(fay).

% parent(P,C) - P is parent of Child C [Edited]
parent(james1, charles1).
parent(james1,elizabeth).

parent(charles1,charles2).
parent(charles1,catherine).
parent(charles1,james2).

parent(elizabeth,sophia).
parent(sophia,george1).
parent(sam,george1).
parent(fay,catherine).
parent(fay,charles2).
parent(fay,james2).
parent(paul,sophia).
parent(claudia,elizabeth).
parent(claudia,charles1).

% married(X,Y) - X is Married to Y
married(james1, claudia).
married(claudia, james1).
married(charles1, fay).
married(fay, charles1).
married(elizabeth, paul).
married(paul, elizabeth).
married(sophia, sam).
married(sam, sophia).

% Mother
mother(X,Y):-
    female(X),
    parent(X,Y).

% Father
father(X,Y):-
    male(X),
    parent(X,Y).

% sister
sister(X,Y):-
    female(X),
    parent(P,X),
    parent(P,Y),
    X \= Y.

% brother
brother(X,Y):-
    male(X),
    parent(P,X),
    parent(P,Y),
    X \= Y.

% [+] - Extra
sibling(X, Y):- parent(Z, X), parent(Z, Y), X \= Y.
dist_sibling(X, Y) :- distinct(sibling(X, Y)).

% uncle 
uncle(X, Y):- dist_sibling(X, Z), parent(Z, Y), male(X).

% aunt
aunt(X, Y):- dist_sibling(X, Z), parent(Z, Y), female(X).

% grandmother
grandmother(G,C) :-
    female(G),
    parent(G, F),
    parent(F, C).

% grandfather
grandfather(G,C) :-
    male(G),
    parent(G, F),
    parent(F, C).

% brother in law - the brother of one's wife or husband.
brother_in_law(X, Z):- married(Y, Z), sibling(X, Y), male(X).

% sister in law - the sister of one's wife or husband.
sister_in_law(X, Z):- married(Y, Z), dist_sibling(X, Y), female(X).

% mother in law
mother_in_law(X, Y):- married(Y, Z), parent(X, Z), \+ parent(X, Y), female(X).

% father in law
father_in_law(X, Y):- married(Y, Z), parent(X, Z), \+ parent(X, Y), male(X).

% ancestor - recursion based
ancestor(X,Y):-
    parent(X,Y).
ancestor(X,Y):-
    parent(X,C),
    ancestor(C,Y).

% descendant
descendent(X,Y):-
    parent(Y,X).
descendent(X,Y):-
    parent(P,X),
    descendent(P,Y).