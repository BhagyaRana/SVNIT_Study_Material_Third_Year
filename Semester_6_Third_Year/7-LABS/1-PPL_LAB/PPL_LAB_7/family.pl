/* Facts */

female(mary).
female(sandra).
female(juliet).
female(lisa).

male(peter).
male(paul).
male(dick).
male(bob).
male(harry).
% Added "tom", Husband of Mary
male(tom).

parent(bob, lisa).
parent(bob, paul).
parent(bob, mary).
parent(juliet, lisa).
parent(juliet, paul).
parent(juliet, mary).
parent(peter, harry).
parent(lisa, harry).
parent(mary, dick).
parent(mary, sandra).

husband(bob,juliet).
husband(peter,lisa).
husband(tom,mary).

/* Rules */

% Child
child(X, Y):-
    parent(Y, X).

% Mother
mother(X, Y):-
    female(X),
    parent(X, Y).

% Father
father(X, Y):-
    male(X),
    parent(X, Y).

% Wife
wife(X, Y):-
    husband(Y, X).

% Son
son(X, Y):-
    male(X),
    parent(Y, X).

% Daughter
daughter(X, Y):-
    female(X),
    parent(Y, X).

% Brother
brother(X,Y) :-
    male(X),
    parent(P,X),
    parent(P,Y),
    X \= Y.
print_brothers :- brother(X, Y), format('~a is_brother_of ~a', [X, Y]).

% Sister
sister(X,Y) :-
    female(X),
    parent(P,X),
    parent(P,Y),
    X \= Y.
print_sisters :- sister(X, Y), format('~a is_sister_of ~a', [X, Y]).

% Uncle - X is an uncle of Y if X is the brother of some person, Z, and Z is a parent of Y
uncle(X, Y) :-
    brother(X, Z),
    parent(Z, Y).
print_uncles :- uncle(X, Y), format('~a is_uncle_of ~a', [X, Y]).

% Aunt - X is an aunt of Y if X is the sister of some person, P, and P is a parent of Y
aunt(X, Y) :-
    sister(X, P),
    parent(P, Y).
aunt(X, Y) :-
    parent(P, Y),
    brother(Uncle, P),
    wife(X, Uncle).
print_aunts :- aunt(X, Y), format('~a is_aunt_of ~a', [X, Y]).

% Nephew
nephew(X, Y) :- uncle(Y, X), male(X).
nephew(X, Y) :- aunt(Y, X), male(X).
print_nephews :- nephew(X, Y), format('~a is_nephew_of ~a', [X, Y]).

% Niece
niece(X, Y) :- uncle(Y, X), female(X).
niece(X, Y) :- aunt(Y, X), female(X).
print_nieces :- niece(X, Y), format('~a is_niece_of ~a', [X, Y]).
