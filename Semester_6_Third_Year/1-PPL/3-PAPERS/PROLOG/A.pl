rpg([],[]).
rpg([X|T],[X,X,X|T1]):-rpg(T,T1).