ReClass
=======

### [Download the Latest Release](https://github.com/CoolOppo/ReClass/releases/latest)

ReClass is a tool for reverse-engineering data structures in memory. It's similar to [Cheat Engine's data/structure dissector](http://i.imgur.com/G9vHIX9.png), but it is much better. ReClass is known best for its code generation feature. The code generator will create a class usable in C and C++, which makes writing code for use in an injected DLL much easier.

Example Usage
-------------

*Note: If you don't know how to find memory addresses using a tool like Cheat Engine, you're in way over your head.*

ReClass is simple, so let me start off by saying it's alright to tinker with it instead of reading this guide. If you're still interested, let's go! You'll start off by opening a process of your choosing in ReClass. For this example, we'll open up CS:GO and add a couple things from `C_BaseEntity`. To attach to CS:GO, click the "Select" button, and then click on `csgo.exe` from the list of available processes. Next, click on the "New" button in order to create a new class in ReClass (not in the game's actual memory):

![](http://i.imgur.com/ZomftN7.png)

Now, change the address of the class to the base address of the actual one by double-clicking on the number at the top left of the class. You can give the class a name of your choosing by double-clicking on the name to the right of the word "Class". After that, we're going to head on over to the "Modify" tab and click on "Add 1024" a bunch of times until the class is around 16 kB (i.e. 16,000 bytes) long:

![](http://i.imgur.com/WkbgOni.png)

I'm finally going to start the actual reverse-engineering part of this example! Using Cheat Engine, I found that the index of the current entity in the crosshair sits in a `DWORD` exactly `0x23D8` bytes away from the base address of `C_BaseEntity`. Let's go ahead and document that in ReClass:

![](http://i.imgur.com/KSLK5SO.jpg)

After you've decided you want to generate code you can actually use, just click the "Generate" button, and there you have it:

![](http://i.imgur.com/6u4Elhc.png)

Authors
-------

ReClass was initially written by [DrUnKeN ChEeTaH](http://www.unknowncheats.me/forum/member17344.html), P47R!CK, and [dogmatt](http://www.unknowncheats.me/forum/member168606.html). Later on, it was ported to Windows 64-bit by [IChooseYou](http://www.unknowncheats.me/forum/member278477.html), and [learn_more](http://www.unknowncheats.me/forum/member124636.html) made a few improvements to that version. Finally, [CoolOppo](https://github.com/CoolOppo) forked and re-scaffolded the repository, and started more development on the project.
