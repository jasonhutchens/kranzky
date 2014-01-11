Kranzky Engine
==============

A C++ 2D game engine for OSX, Linux and Windows, featuring:

* Component-based Entity System
* 2D Graphics
* Sounds
* Physics
* PS3 / XBOX 360 Controller Support
* Zero-configuration LAN Multiplayer support

Status
------

Very early stages of development under OSX; other platforms not investigated
yet. See the TASKS.todo file for a rough idea of what the plan is. The first
release of the Engine will be a Bomberman clone playable on the LAN with OSX,
Linux and Windows clients all in the same game. Once that's working, we'll
extract a generic engine and break the game out into a seperate project.

Development (OSX)
-----------------

0. Ensure you have the command-line devtools installed
1. Install the GOSU framework
   a) Download latest gosu-mac-0.7.x.tar.gz to http://www.libgosu.org/downloads/
   b) Unzip and copy to /Library/Frameworks
2. Install Box2D
   a) Download Box2D\_v2.1.2.zip from https://code.google.com/p/box2d/downloads/list
   b) Unzip and cd to Box2D\_v2.1.2/Box2D/Build
   c) cmake -DBOX2D\_INSTALL=ON -DBOX2D\_BUILD\_SHARED=ON ..
   d) make ; make install
3. Install ZeroMQ
   a) Download zeromq-3.2.4.tar.gz from http://zeromq.org/intro:get-the-software
   b) Unzip and cd to zeromq-3.2.4
   c) ./configure
   d) make ; make install
4. Good to go; type make
