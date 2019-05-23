# Introduction

*Automata*, *Cellular automata*. What are they? And what do they do? Through the body of this introduction, you will learn the fundamentals of CA and automatan based programming. We will go over the principles of automata, the classical representations of them, and what those might look like implemented in actual code. We will also explore automata and their abstractions from a mathematical and theoretical perspective.

## Automata

Before we can understand the idea of a *cellular* automata, we need to understand what automatan, also called machines, really are. An automata *is* neither an object nor a function. Automata have similarities to objects found in object-oriented programming, and functions found in functional programming. Yet, they are not purely one or the other. Automata can hold data, such as values, fields, even data structures. However, automata have no concept of acting as parameters to functions or bodies of code. Nor can they be constructed or destructed, as objects can be.

### Scopes

One of the most stark differences between automata and classical programming paradigms is the concept of *scope*. In typical programming paradigms, you have values or objects whose lifetime, the relative period of time they have accessible data in the program, is determined by the start and end of a scope. The start and end is always explicit, based of the entering and exiting of a block of code. An example of this is a `do while` loop:

```c
do
{
	int x = 3;
	x += 1;
} while(0);
``` 

In the above while loop, the integer `x` is created inside the scope of the loop. The value of `x` is incremented by 1, before the loop terminating, and the scope hence closing.

