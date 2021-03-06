% Water Jug Problem [U19CS012] BHAGYA VINOD RANA

% Dead States in the Process [In-case if occurs]

water_jug(X, Y):-X>4, Y<3, write('jug 1 overflow\n').
water_jug(X, Y):-X<4, Y>3, write('jug 2 overflow\n').
water_jug(X, Y):-X>4, Y>3, write('jug 1 and 2 overflow\n').

% Final Goal State to be Achieved

water_jug(X, Y):- X=:=2, Y=:=0, write('\nGoal reached\n').

% Static Path to final state {2,0}

water_jug(X, Y):-

X=:=0, Y=:=0, write('Jug A: 0 & Jug B: 3 (Filled Jug B)\n'), water_jug(0, 3);
X=:=0, Y=:=3, write('Jug A: 3 & Jug B: 0 (Poured Water in Jug A from Jug B)\n'), water_jug(3, 0);
X=:=3, Y=:=0, write('Jug A: 3 & Jug B: 3 (Filled Jug B)\n'), water_jug(3, 3);
X=:=3, Y=:=3, write('Jug A: 4 & Jug B: 2 (Poured Water in Jug A from Jug B)\n'), water_jug(4, 2);
X=:=4, Y=:=2, write('Jug A: 0 & Jug B: 2 (Emptied Jug A)\n'), water_jug(0, 2);
X=:=0, Y=:=2, write('Jug A: 2 & Jug B: 0 (Poured Water in Jug A from Jug B)\n'), water_jug(2, 0);
X=:=4, Y=:=0, write('Jug A: 1 & Jug B: 3 (Poured Water in Jug B from Jug A)\n'), water_jug(1, 3);
X=:=1, Y=:=3, write('Jug A: 1 & Jug B: 0 (Emptied Jug B)\n'), water_jug(1, 0);
X=:=1, Y=:=0, write('Jug A: 0 & Jug B: 1 (Poured Water in Jug B from Jug A)\n'), water_jug(0, 1);
X=:=0, Y=:=1, write('Jug A: 4 & Jug B: 1 (Filled Jug A)\n'), water_jug(4, 1);
X=:=4, Y=:=1, write('Jug A: 2 & Jug B: 3 (Poured Water in Jug B from Jug A)\n'), water_jug(2, 3);
X=:=2, Y=:=3, write('Jug A: 2 & Jug B: 0 (Emptied Jug B)\n'), water_jug(2, 0).

% Other States Transitions.

water_jug(X, Y):-
X=:=2, Y>0, write('Jug A: 2 & Jug B: 0 (Emptied Jug B)\n'), water_jug(2, 0);
X=:=1, Y=:=1, write('Jug A: 2 & Jug B: 0 (Poured Water in Jug A from Jug B)\n'), water_jug(2, 0);
X=:=2, Y>0, write('Jug A: 2 & Jug B: 0 (Emptied Jug B)\n'), water_jug(2, 0);
X>0, Y=:=2, write('Jug A: 0 & Jug B: 2 (Emptied Jug A)\n'), water_jug(0, 2);
X>0, Y=:=3, write('Jug A: 0 & Jug B: 3 (Emptied Jug A)\n'), water_jug(0, 3);
X>0, Y=:=1, write('Jug A: 4 & Jug B: 1 (Filled Jug A)\n'), water_jug(4, 1).

my_main:- write("Enter the initial state (X, Y) \nX: "), read(A), write("\nY "), read(B),
write("\nJug A: "), write(A), write(" & Jug B: "), write(B),
write(" (Initial state)\n"), water_jug(A, B).
