% path('X','Y') -> There is Path from Point 'X' to Point 'Y'
path('A','B').

path('B','C').
path('B','F').

path('C','D').
path('C','E').

path('F','G').
path('F','J').

path('G','H').

path('H','I').
path('H','J').

path('J','K').

path('K','L').
path('K','N').

path('L','M').
path('M','Z').

path('P','Q').

path('Q','R').
path('Q','S').

% Prolog F(x) to Append 2 List's
appnd([],X,X).
appnd([H|T],N,[H|T1]):-
    appnd(T,N,T1).

% F(x) to extract all the Un-Visited Nodes in Graph
extend([Node|Path],NewPaths):-
    bagof([NewNode,Node|Path],
          ( (path(Node,NewNode);path(NewNode,Node)),
            not(member(NewNode,[Node|Path]))),
            NewPaths 
         ),!.
    extend(_, []).

% BASE CASE: If the HEAD of the FIRST PATH (in Paths list) is a GOAL then this path is a Solution of the problem
bfs([[Node|Path]|_],[Node|Path],Goal):-
    Node=Goal.

% B.F.S. Recursion
% GENERAL CASE: Otherwise (if the head of the first path is not a goal node) remove the first path from the
% candidates set and generate the set of all possible one-step extensions of this paths, add this set of
% extension at the end of the candidate set, and execute breath-first search on this updated set
bfs([Path|Paths], Sol, Goal):-
    extend(Path, NewPaths),
    appnd(Paths, NewPaths, Paths1),
    bfs(Paths1, Sol, Goal).

% Reference - https://stackoverflow.com/questions/16526720/bfs-visit-in-prolog-why-this-program-dont-work
% Reference - https://www.inf.ed.ac.uk/teaching/courses/lp/2015/slides/prog7.pdf

% F(x) to Print the Entire Path from Source to Destination
displaypath([]):-
    write("END"),nl.

displaypath([H|T]):-
    write(H),
    write(" -> "),
    displaypath(T).

% Main F(x) to Intiate the Search
findpath(Start,Goal):-
    bfs([[Start]], Sol, Goal),
    reverse(Sol, Path),
    displaypath(Path).

% Query

% Does there a Path Exist from Point 'A' to Point 'Z'?
% findpath('A', 'Z').

% Does there a Path Exist from Point 'E' to Point 'M'?
% findpath('E', 'M').

% Does there a Path Exist from Point 'F' to Point 'I'?
% findpath('F', 'I').

% False Cases

% Does there a Path Exist from Point 'A' to Point 'P'?
% findpath('A', 'P').

% Does there a Path Exist from Point 'A' to Point 'P'?
% findpath('R', 'N').