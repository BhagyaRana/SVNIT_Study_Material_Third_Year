% 1. Perform Towers of Hanoi.

% Base Case - Only 1 disk to be moved from A To C
toh(1, A, C, _) :-
    write(' Move Top Disk from '),
    write(A),
    write(' to '),
    write(C),
    nl.

% Recursive toh defination to Move N disks from A to C using B {Helper}
toh(N, A, C, B) :-
    N>1,
    M is N-1,
    % Move N-1 disks from src (A) to intermediate (B)
    toh(M, A, B, C),
    % Move the Nth disk from src (A) to destination (C)
    toh(1, A, C, _),
    % Move the Remaining N-1 disks from intermediate (B) to destination (C)
    toh(M, B, C, A).
