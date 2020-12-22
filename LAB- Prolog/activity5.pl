parent(jill,bill).
parent(sarah, bill).
parent(sam,jill).
parent(ana,jill).
parent(jan,sarah).
parent(smith,sarah).

grandparent(X,Y) :- parent(X,Z) , parent(Z,Y).
sibling(X,Y) :- parent(X,Z), parent(Y,Z), not(X = Y).
cousin(X,Y) :- grandparent(X,Z) , grandparent(Y,Z), not(X = Y).


