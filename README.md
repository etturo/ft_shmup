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
│   ├── core/
│   │   ├── GameMode.hpp      # Game mode enum (menu, playing, paused, game over)
│   │   ├── GameState.hpp     # Game state struct (score, lives, entities, etc.)
│   │   ├── main.hpp          # Main function declarations
│   │   ├── Settings.hpp      # Game constants and configuration
│   │   └── Utils.hpp         # Utility functions (timing, etc.)
│   ├── entities/
│   │   ├── Boss.hpp          # Boss enemy class
│   │   ├── Bullet.hpp        # Player and enemy bullet classes
│   │   ├── Enemy.hpp         # Enemy class
│   │   ├── Entity.hpp        # Base entity class with position & collision
│   │   ├── Player.hpp        # Player class
│   │   └── Updatable.hpp     # Abstract updatable interface for entities
│   ├── world/
│   │   ├── Board.hpp         # Game board / window management
│   │   ├── Terrain.hpp       # Scrolling background
│   │   └── Hud.hpp           # Heads-up display (HUD)
├── src/
│   ├── core/
│   │   ├── main.cpp          # Main game loop and logic
│   │   └── Utils.cpp         # Utility function implementations
│   ├── entities/
│   │   ├── Boss.cpp          # Boss enemy logic
│   │   ├── Bullet.cpp        # Bullet logic
│   │   ├── Enemy.cpp         # Enemy logic
│   │   ├── Entity.cpp        # Base entity logic
│   │   ├── Player.cpp        # Player logic
│   │   └── Updatable.cpp     # Updatable interface implementation
│   ├── world/
│   │   ├── Board.cpp         # Board rendering and input
│   │   ├── Terrain.cpp       # Terrain rendering and update
│   │   └── Hud.cpp           # HUD rendering and update
├── bin/                      # Compiled binary output
├── obj/                      # Compiled object files
├── Makefile                  # Build system
├── ncurses.supp              # Valgrind suppression file for ncurses
├── supp_extra.supp           # Additional Valgrind suppressions
└── README.md                 # Project documentation
```

### Additional Notes
- The game uses a double-linked list for entity management, allowing efficient insertion and removal of entities during gameplay.
- Collision detection is performed between all entities, including player, enemies, bullets, and boss.
- The HUD displays lives, score, level, and elapsed time, updating in real time.
- The Makefile supports building, cleaning, running, and memory checking with Valgrind, and is adapted for the multi-folder structure.

## Sprites

```
Player:     =<O>=
Enemy:      <\v/>
Enemy 2:    {0+0}
Boss:       ({*})~~(0^0)~~({*})
Bullet:     |
Enemy Bomb: o
```
