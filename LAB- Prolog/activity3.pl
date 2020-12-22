:- dynamic precipitation/0, raining/0, snowing/0, freezing/0.
precipitation :- snowing.
precipitation :- raining.
snowing.
snowing :- freezing, precipitation.
raining :- \+ freezing, precipitation.
freezing :- snowing.
