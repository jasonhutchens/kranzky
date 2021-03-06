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

0. Ensure you have homebrew + the command-line devtools installed
1. "brew bundle"
2. "make"

Design
------

* Game Engine
  + AssetManager
  + InputManeger
  + SceneManager
  + EntityManager
    - List of Systems
    - List of Entities
  + System
    - PhysicsSystem
    - PlayerSystem
    - ...
