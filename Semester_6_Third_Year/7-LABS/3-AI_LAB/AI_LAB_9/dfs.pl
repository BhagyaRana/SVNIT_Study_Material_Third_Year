% Depth For Search Implementation of the 8 Puzzle Problem

% Main F(x) to Solve the 8 Puzzle Problem
puzzle(State):-
    length(Moves, N),
    dfs([State], Moves, Path), !,
    show([start|Moves], Path),
    format('~nmoves = ~w~n', [N]).

dfs([State|States], [], Path) :-
    % If the Goal State is Reached
    goal(State), !,
    %  Otherwise Backtrack using Stack
    reverse([State|States], Path).
 
dfs([State|States], [Move|Moves], Path) :-
    % Move to Deepest State Possible
    move(State, Next, Move),
    % If the 'Next' is Not a Member of States
    not(memberchk(Next, [State|States])),
    % Recur for Next State
    dfs([Next,State|States], Moves, Path).

% F(x) to Display the 8 Puzzle Board
show([], _).
show([Move|Moves], [State|States]) :-
    State = state(A,B,C,D,E,F,G,H,I),
    format('~n~w~n~n', [Move]),
    format('~w ~w ~w~n',[A,B,C]),
    format('~w ~w ~w~n',[D,E,F]),
    format('~w ~w ~w~n',[G,H,I]),
    show(Moves, States).

% Goal State to be Acheived
goal( state(1,2,3,4,5,6,7,8,*) ).
 
% Empty position is marked with '*'
move( state(*,B,C,D,E,F,G,H,J), state(B,*,C,D,E,F,G,H,J), right).
move( state(*,B,C,D,E,F,G,H,J), state(D,B,C,*,E,F,G,H,J), down ).
move( state(A,*,C,D,E,F,G,H,J), state(*,A,C,D,E,F,G,H,J), left ).
move( state(A,*,C,D,E,F,G,H,J), state(A,C,*,D,E,F,G,H,J), right).
move( state(A,*,C,D,E,F,G,H,J), state(A,E,C,D,*,F,G,H,J), down ).
move( state(A,B,*,D,E,F,G,H,J), state(A,*,B,D,E,F,G,H,J), left ).
move( state(A,B,*,D,E,F,G,H,J), state(A,B,F,D,E,*,G,H,J), down ).
move( state(A,B,C,*,E,F,G,H,J), state(*,B,C,A,E,F,G,H,J), up   ).
move( state(A,B,C,*,E,F,G,H,J), state(A,B,C,E,*,F,G,H,J), right).
move( state(A,B,C,*,E,F,G,H,J), state(A,B,C,G,E,F,*,H,J), down ).
move( state(A,B,C,D,*,F,G,H,J), state(A,*,C,D,B,F,G,H,J), up   ).
move( state(A,B,C,D,*,F,G,H,J), state(A,B,C,D,F,*,G,H,J), right).
move( state(A,B,C,D,*,F,G,H,J), state(A,B,C,D,H,F,G,*,J), down ).
move( state(A,B,C,D,*,F,G,H,J), state(A,B,C,*,D,F,G,H,J), left ).
move( state(A,B,C,D,E,*,G,H,J), state(A,B,*,D,E,C,G,H,J), up   ).
move( state(A,B,C,D,E,*,G,H,J), state(A,B,C,D,*,E,G,H,J), left ).
move( state(A,B,C,D,E,*,G,H,J), state(A,B,C,D,E,J,G,H,*), down ).
move( state(A,B,C,D,E,F,*,H,J), state(A,B,C,D,E,F,H,*,J), left ).
move( state(A,B,C,D,E,F,*,H,J), state(A,B,C,*,E,F,D,H,J), up   ).
move( state(A,B,C,D,E,F,G,*,J), state(A,B,C,D,E,F,*,G,J), left ).
move( state(A,B,C,D,E,F,G,*,J), state(A,B,C,D,*,F,G,E,J), up   ).
move( state(A,B,C,D,E,F,G,*,J), state(A,B,C,D,E,F,G,J,*), right).
move( state(A,B,C,D,E,F,G,H,*), state(A,B,C,D,E,*,G,H,F), up   ).
move( state(A,B,C,D,E,F,G,H,*), state(A,B,C,D,E,F,G,*,H), left ).

% Reference for Code - https://stackoverflow.com/questions/67642302/prolog-for-eight-puzzle