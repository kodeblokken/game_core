# Shifting Allies
### The game

A simple (*online*) 2D game where you are a geometric shape with a color(?).
You can shoot liquid using your own body mass, consuming health/size
 in an attempt to damage an enemy. You cannot hurt 
objects of the same type (same shape and color) - doing
so will heal/enlarge the target. If you shoot an enemy target
you will enlargen proportional to the damage done 
(enemy target will weaken).

![*Shifting Allies*](/images/game.jpg)

Objects change type randomly withing a range of time.
Smaller objects move faster than the bigger ones.
Items spawn throughout the map which can affect
objects differently. Items can be picked up as
items on the ground or a 'roll-of-the-dice'
chest which can contain items than can power 
you or cripple you.  

##### Example items
* Elk Blood
	* Gives the object a speed increase for 1 second. :droplet:
* Seed
	* Changes the object's type. :chestnut:

# Guidelines
The code will be organized in states, which means
that the code that we merge needs to work before
merging. This makes it easier to go back and forth
between the different states and track down bugs.

To contribute to the project, create your own branch
of the main project, possibly with the name of
the feature or class you will be working on, 
make commits as you go with your own workflow
(creating a sensible history of your code) until
you have a working copy of whatever you are 
working on. Then you initiate a pull request to open
your code up for review. It will either be merged
or you will receive comments on what is lacking,
etc.

The programming language the code will be written in
is C++ with the primary framework being **SDL.** Code 
should also be documented properly so that others
may get a clear indication of what your code is doing
without needing to study every implementation of every
function. All code and comments must be written in English.

People use different IDEs and operating systems which can generate files local to these systems. If you want git to handle these files for you, just put them or their file extensions into the .gitignore file and git will ignore them. 

```
/** 
 *  Returns the sum of x and y.
 */
int Foo::add(int x, int y){
	return x + y;
}
```


# Stages
*a non-permanent overview of the different stages* 

###  Stage 1
Get a working prototype up and running. Basic
controls in a primitive environment. The essentials 
of a physics engine. Tests using temporary
sprites. 

### Stage 2
Start working on the collision system and the 
shooting mechanism. A bunch of testing.

### Stage 3
Implement the different object types and the
damage/health system. 

### Stage 4 
Create permament sprites for the object types and
tiles for a simple map background. Start the work
on the item system.

### Stage 5 
Start the work on the network side of things.

### Stage 6
Implement a menu. Finalize with a bunch of testing.






