% Breadth For Search Implementation of the 8 Puzzle Problem

% There are Cases When the Stack Overflows (>1 GB), Due to Space Complexity of UFS O(b^d)

% Main F(x) to Solve the 8 Puzzle Problem
puzzle(State):-
    ucs([State],[State],N),!,
    write("Total Steps: "),
    write(N).

% Check if the Goal is Reached
ucs([State | _],_,0):-goal(State).

ucs([CurState | RemQueue],Visited,N):-
    % Find all the Possible Moves
    findall(X,move(CurState,X,_),AllPossibleState),
    % Avoid Repeated Nodes
    removeDuplicate(AllPossibleState,Visited,PossibleState),
    % Store Frontier of Nodes in FIFO Queue
    append(PossibleState,Visited,NewVisited),
    % Store Remaining in Other Queue
    append(RemQueue,PossibleState,NewRemQueue),
    % Recur for Updated Queue with New Visited Nodes
    ucs(NewRemQueue,NewVisited,N1),
    % Count the Required Number of Steps
    N is N1 + 1.

% F(x) to Remove Duplicates from the List 

% Base Case
removeDuplicate([],_,[]).

% If Member is Not in the List, then Add it to Answer
removeDuplicate([H1|AllRem],Visited,[H1 | T1]):-
    not(memberchk(H1,Visited)),
    removeDuplicate(AllRem,Visited,T1).

% If Member is in the List, then Don't Add it to Answer
removeDuplicate([H1|AllRem],Visited,T1):-
    memberchk(H1,Visited),
    removeDuplicate(AllRem,Visited,T1).

% Goal State to be Acheived
goal( state(1,2,3,4,5,6,7,8,*) ).

% Reference for Below Moves - https://stackoverflow.com/questions/67642302/prolog-for-eight-puzzle

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