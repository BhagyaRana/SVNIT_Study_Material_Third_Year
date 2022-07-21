prg([],[]).
prg([X],[X]).
prg([F,_|T],[F|T1]):-prg(T,T1).