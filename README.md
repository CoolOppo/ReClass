ReClass
=======

**This is a guide on using ReClass that will temporarily serve as the README. [Download the latest release here!](https://github.com/CoolOppo/ReClass/releases/latest/)**

[*Source*](http://www.unknowncheats.me/forum/general-programming-and-reversing/120805-reclass-usuage-reclass-and-its-content.html)

What Is ReClass?
----------------

**First of all, what is ReClass? Many would ask this therefore I'll explain it:**

ReClass is a memory structure analysis tool which automatically applies offsets to a given address, it is a better version of the Cheat Engine’s Dissect Data/Structures function, and makes it easier to find different data that is needed.

It is not only “better” than Dissect Data/Structures function in Cheat Engine but kind of more “evoloved”. ReClass includes many functions that Cheat Engine does not have, which makes it a better and a more useful tool when looking for different data that you need in different situations.

What Is ReClass Used For?
-------------------------

ReClass is used for Reversing/Analysis, as said above it is a better version of Cheat Engine’s Dissect Data/Structures. For Example, if you find CPlayer in a game (Like AssaultCube) you can put it into ReClass and reverse the CPlayer further to find different data for your hack, or whatever else you are doing. With ReClass you can set pointers change the datatypes of the addresses and find out if it is what you are looking for. ReClass simply makes it a lot easier for you to reverse different things that you find while reversing a game.

The Basic Usuage Of ReClass
---------------------------

1. Start up ReClass and select a process with the select button as shown below:

![](http://I.imgur.com/Jt7FX1u.png)

After selecting a process you can start the reversing process which is the most interesting part of the whole “Hack Making” process.

1. When you have found an address that is for example the CPlayer Class, in whichever game, like in AssaultCube, then you can use ReClass to Dissect the address and look for offsets that may be useful in further reversing. To make the work easier for you, ReClass includes a “Modify” tab where you can change the offsets of an address into different datatypes after what you think the offset leads to. If you think that the offset leads to an coordinate then you would change the datatype of the offset to VEC 3 which is an 3D Vector (x,y,z), or you could change it to something else. If you have enough experience in using other tools, then using ReClass won’t be so hard. And finding all the data you need will not be so hard either.

2.1. To Reverse with ReClass you will have to select a process first as said above and then you will have to click the “New” button, which will create a new class:

![](http://I.imgur.com/Jt7FX1u.png)

After that you will have to go under to the “Modify” tab and get your job done ![](http://www.unknowncheats.me/forum/images/smilies/tongue.gif) The Modify tab includes different datatype selections and other things that will help you in reversing, which I’ll explain a bit later.

1. ReClass also has an “Settings” tab where you can edit ReClass and make it look how you want it to look like. You can change the colors of your addresses, VTables and do many other different things, even change your reclass background. You can also do different things with it at the home tab, like adding notes, debugging and lots of other stuff.

![](http://I.imgur.com/dsgotB0.png)

![](http://I.imgur.com/Jt7FX1u.png)

That would be it for the “Basic” usuage of ReClass, I'll move on the next step.

ReClass - The Modify Tab, And It’s Content
------------------------------------------

![](http://I.imgur.com/rD78VJQ.png)

This is The Modify Tab, which will be mostly used by you, as it is there where all the reversing is going on. After you have selected a process you can start adding new classes and put in your addresses which you would like to dissect:

![](http://I.imgur.com/nwzUxB4.jpg)

Later on when you have put your address in you can start looking for data, and to do so you would need to understand what some different things are:

![](http://I.imgur.com/xRcCQO3.jpg)

As shown there are offsets which go under the address you are reversing, in AssaultCube’s CPlayer under different of them you can find different things that are needed to create a hack. ReClass also shows the current address you dissect with the offset applied and show’s its value at the end (if any)

On the top you have your datatypes, if you click an address they will light up and you will be able to choose what datatype you want to set the address to. I’ll Explain all the datatypes soon in the tutorial.

The Datatypes
-------------

![](http://I.imgur.com/5EC9zg7.png)

This is the tab with all the datatypes in ReClass, and they are used for different things, I’ll now explain what each one is.

The Hex Datatype
----------------

- `Hex 32` - A 32-bit Hexadecimal Value
- `Hex 16` - A 16-bit Hexadecimal Value
- `Hex 8` - A 8-bit Hexadecimal Value

The Int Datatype
----------------

- `Int 64` - A 64-bit Signed Integer
- `Int 32` - A 32-bit Signed Integer
- `Int 16` - A 16-bit Signed Integer
- `Int 8` - A 8-bit Signed Integer

Other Datatypes
---------------

- `DWORD` - A 32-bit Unsigned Integer
- `WORD` - A 16-bit Unsigned Integer
- `BYTE` - 8-bit Unsigned Value
- `DOUBLE` - 64-bit Decimal Value (What I mean by that is that it can hold values like 6,57)
- `FLOAT` - 32-bit Decimal Value
- `CUSTOM` - As the name says, you customize it
- `MATRIX` - Stores some Data/Numbers in a grid
- `ARRAY` - Type of a list holding data
- `CLASS` - A Class that can hold different objects/data
- `VTable` - A Table of Different Functions that hold data
- `Function` - Something that performs a specific task
- `Pointer` - A variable whose value is the address of another variable - aka something that points to another address
- `ASCII` - is a code for representing English characters as numbers
- `UNICODE` - A Standard For Representing Characters as Integers
- `PCHAR` - is a Pointer to Char (Normally Text/Pointer to ASCII Text)

Vectors
-------

- `VEC2` - a 2D Vector (x,y)
- `VEC3` - a 3D Vector (x,y,z)
- `VEC4` - a 4D Vector (x,y,z,w)

Other Buttons
-------------

- `Delete` - Deletes the datatype you set for an address/offset
- `Show` - Makes the address/offset you hide visible again
- `Hide` - Hides the address/offset from the list
- `Insert` (4,8,64,1024) - Adds addresses/offsets to the list (bit different than “ADD”)
- `Add` (8,64,1024) - Adds Addresses/Offsets to the list
