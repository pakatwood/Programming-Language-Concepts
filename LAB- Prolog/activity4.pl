mammal(horse).
mammal(X) :- legs(X,4),arms(X,0).
mammal(X) :- legs(X,2),arms(X,2).
legs(X,2) :- mammal(X),arms(X,2).
legs(X,4) :- mammal(X),arms(X,0).
arms(horse,0).
