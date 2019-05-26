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

In the above while loop, the integer `x` is created inside the scope of the loop. The value of `x` is incremented by 1, before the loop terminating, and the scope hence closing. We can say the *lifetime* of *x* starts at ends within theose curly braces `{` and `}`. Nearly all programming languages use clearly defined lifetimes, such the one shown. Automata lifetimes are not always defined from the start. The lifetime of an automata can also be modified during the course of a simulation or a program.

### Definition

An automata in it's most fundamental representation can be defined as:

> Let `Q` be a set of states { s_0, s_1, ... s_n }, where `s_0` is the initial state.
> There is a function `T`, where for all states in Q, `T(s) in Q` is true.

Basic automata can be constructed from a set of discrete states with change via a transition function. For now, let's look at an implementation of a fundamental automata.

## One Dimensional

A *one dimensional* automata is a machine which contains a single, finite row of cells. Each cell functions as an independent machine, locked in an order with neighboring machines that is constant throughout runtime. The cells transition through a concept of *generations*. One or more rules are applied to the cell's neighborhoods, for every cell in the automata. Changes to any cell are written to a new row of cells, that represent the incoming, next generation.

```c
static int CELLS[24] = { 1 };
```
