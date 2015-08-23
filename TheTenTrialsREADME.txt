The Ten Trials is a text adventure written in C++ (by Alexander Stopar). Choose your fate and select from a variety of options that affect your route and your alignment.

The game (and code) is split into different functions in multiple cpp files. The game starts with a title segment and initializes player statistics such as gender and starting alignment before moving into a prologue and ten trial segments. The text is hardcoded into the game.

Some of the controls vary based on situation (text input, selecting numerical choices, etc.) but Enter is how to scroll and select choices.
In the main action menu:

l - look at environment
s - speak
i - display inventory
a - display alignment
u - use
h - display help
t - touch
e - show health

Watch your actions- you may die at any time in the trials and there are at least 7 possible endings based on which alignment (Good, Evil, Apathy) is highest.

Programming utilized text input functions from <iostream> and <conio.h> while using vectors for groups of objects.
