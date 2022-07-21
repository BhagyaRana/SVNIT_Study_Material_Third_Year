% Program: family.pl
% U19CS012 [BHAGYA VINOD RANA]

% Knowledge Base
% parent(X,Y) -> X is the Parent of Y

parent(albert, jim).
parent(albert, peter).
parent(jim, brian).
parent(john, darren).
parent(peter, lee).
parent(peter, sandra).
parent(peter, james).
parent(peter, kate).
parent(peter, kyle).
parent(brian, jenny).
parent(irene, jim).
parent(irene, peter).
parent(pat, brian).
parent(pat, darren).
parent(amanda, jenny).

% female(Person)
% Person is female.
female(irene).
female(pat).
female(lee).
female(sandra).
female(jenny).
female(amanda).
female(kate).

% male(Person)

% Person is male.
male(albert).
male(jim).
male(peter).
male(brian).
male(john).
male(darren).
male(james).
male(kyle).

% yearOfBirth(Person, Year).

% Person's Year_of_Birth is Year.
yearOfBirth(irene, 1923).
yearOfBirth(pat, 1954).
yearOfBirth(lee, 1970).
yearOfBirth(sandra, 1973).
yearOfBirth(jenny, 2004).
yearOfBirth(amanda, 1979).
yearOfBirth(albert, 1926).
yearOfBirth(jim, 1949).
yearOfBirth(peter, 1945).
yearOfBirth(brian, 1974).
yearOfBirth(john, 1955).
yearOfBirth(darren, 1976).
yearOfBirth(james, 1969).
yearOfBirth(kate, 1975).
yearOfBirth(kyle, 1976).

%1.  Is Albert a parent of Peter?
% parent(albert, peter).

%2.  Who is the child of Jim?
% parent(jim, Who).

%3.  Who are the parents of Brian?
% parent(Who, brian).

%4.  Is Irene a grandparent of Brian?

% Define the Rule Grandparent
% grandparent(G,C) - G is grandparent of C
grandparent(G,C) :-
    parent(G, F),
    parent(F, C).

% grandparent(irene,brian).

%5.  Find all the grandchildren of Irene

% grandparent(irene, Who).


%6.  Now add the following rule to familytree.pl and re-consult:

older(Person1, Person2) :-
    yearOfBirth(Person1, Year1),
    yearOfBirth(Person2, Year2),
    Year2 > Year1.

%7.  Who is older than Pat?
% older(Who, pat).

%8.  Who is younger than  Darren?
% older(darren, Who).

%9.  List the siblings of Sandra.

% Define the Rule sibling.
% sibling(B,S) - B is the sibling of S
sibling(B,S) :-
    parent(P, B),
    parent(P, S),
    B \= S.

% sibling(sandra, Who).

%10.  Who is the older brother of Sandra?

% Define the Rule olderbrother
olderbrother(X, Y):-
    male(X),
    parent(P, X),
    parent(P, Y),
    X \= Y,
    older(X, Y).

% olderbrother(Who, sandra).

%11.  Find the predecessors of Kyle.

% Define the Rule predecessor
predecessor(X, Y):-
    parent(X, Z),
    predecessor(Z, Y).

predecessor(X, Y):-
    parent(X, Y).

% predecessor(Who, kyle).

%12.  Does Kate have a sister?

% Define the Rule sister
sister(X, Y):-
    female(X),
    parent(P, X),
    parent(P, Y),
    X \= Y.

% sister(Who, kate).

% Does Kate have Sister?
% sister(_, kate).

%13. How many females and males are there in the knowledge base?

person(X):-
    female(X).
person(Y):-
    male(Y).

% aggregate_all(count, person(Who), Total).

% For Individual Male and Female Count
% aggregate_all(count, male(X), Total).
% aggregate_all(count, female(X), Total).
