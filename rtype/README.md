# R-type

DOCUMENTATION : https://lebaku.github.io/#/

## Table of Contents
- [About R-TYPE ?](#about-r-type)
- [ECS](#ECS)
- [Networking](#networking)
- [Installer](#installer)

## About R-Type ?

This game is informally called a Horizontal Shmup (e.g. Shoot’em’up), and while R-Type is not the first one of its category, this one has been a huge success amongst gamers in the 90’s, and had several ports, spin-offs,
and 3D remakes on modern systems.

Other similar and well known games are the Gradius series and Blazing Star on Neo Geo.


## Construction du projet

ECS (…), Networking,


## ECS

The Entity Component System makes it easier to create and compute a game.
Current available components and systems :

* Position (Manage an entity's position)
* Sprite (Allow to draw, set textures)

To use the ECS you first need to declare `Manager` which will handle all entities.
You can then add entities using `manager.AddEntity()` and you attach components to these entities using `entity.addComponent<ComponentYouWantToAdd>()`.

* *To create new components you need the new component to inherit from `Component`.*
* *To create new systems you need the new system to inherit from `System`.*

## Networking

The base of networking is to allow players to play on the same party. We can achieve this with the help of ASIO :
* cross-platform C++ library
* Low-level I/O programing
* Asynchronous model using modern C++

With this methode we can build a server using IPC (Inter Process Communication) with a TCP/IP network.

The goal of our networking is give players the possibility to host their parties and play together.


## Installer

With the help of CMakeLists the project install by itself all the dependencies.

* SFML
* ASIO
* ...
