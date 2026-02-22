# ft_shmup

A terminal-based shoot 'em up game built with **C++** and **ncurses**, developed as a Rush project at 42.

## Overview

ft_shmup is a vertical scrolling shooter that runs entirely in the terminal. Navigate your spaceship, dodge enemy fire, destroy waves of enemies, and face off against a boss — all rendered in ASCII art using the ncurses library.

## Features

- **Player-controlled spaceship** with 4-directional movement and shooting
- **Multiple enemy types** with distinct sprites and behaviors
- **Boss battles** with dual cannons and movement patterns
- **Dynamic difficulty** — enemy spawn rate increases with your score
- **Level progression** based on score milestones
- **Scrolling terrain** background for visual depth
- **HUD** displaying lives, score, level, and elapsed time
- **Collision detection** between all entities (player, enemies, bullets)

## Controls

| Key | Action |
|-----|--------|
| `↑` `↓` `←` `→` | Move spaceship |
| `Space` | Shoot |
| `q` | Quit |

## Requirements

- A C++ compiler with C++11 support
- `ncurses` library
- A terminal with at least 40x40 characters

## Build & Run

```bash
# Build
make

# Build and run
make run

# Clean object files
make clean

# Full clean (objects + binary)
make fclean

# Rebuild from scratch
make re

# Run with Valgrind
make valgrind
```

## Project Structure

```
ft_shmup/
├── include/
│   ├── Board.hpp        # Game board / window management
│   ├── Boss.hpp         # Boss enemy class
│   ├── Bullet.hpp       # Player and enemy bullet classes
│   ├── Enemy.hpp        # Enemy class
│   ├── Entity.hpp       # Base entity class with position & collision
│   ├── GameState.hpp    # Game state struct (score, lives, entities...)
│   ├── Player.hpp       # Player class
│   ├── settings.hpp     # Game constants and sprite definitions
│   ├── Terrain.hpp      # Scrolling background
│   └── Updatable.hpp    # Abstract updatable interface
├── src/
│   ├── Board.cpp
│   ├── Boss.cpp
│   ├── Bullet.cpp
│   ├── Enemy.cpp
│   ├── Entity.cpp
│   ├── main.cpp
│   ├── Player.cpp
│   ├── Terrain.cpp
│   └── Updatable.cpp
├── Makefile
└── README.md
```

## Sprites

```
Player:     =<O>=
Enemy:      <\v/>
Enemy 2:    {0+0}
Boss:       ({*})~~(0^0)~~({*})
Bullet:     |
Enemy Bomb: o
```
