
# 🐬 so_long — A Mini 2D Game in C

**"So Long, and thanks for all the fish!"**

Welcome to a small, simple, and fun 2D game project built using **C** and **MiniLibX**, designed as an introduction to graphics programming and game logic.

---

## 📸 Screenshot

![Game Screenshot](/assets/screen/42map.png)

---

## 🎯 Project Objectives

- Learn how to manage windows, events, textures, and basic gameplay elements.
- Practice working with sprites and maps in a grid-based system.
- Develop solid habits with memory management, clean code, and error handling.
- Improve your command of C, algorithms, and debugging techniques.

---

## 🕹️ Game Overview

- Collect all items on the map, then reach the exit using the shortest path.
- Navigate the map with `W`, `A`, `S`, `D` or arrow keys.
- Movement count is displayed in the terminal.

---

## 🖼️ Graphics

- Uses MiniLibX to create a game window and render textures.
- Clean exit via `ESC` key or closing the window.
- Smooth window handling (minimize, focus switch, etc).

---

## 🗺️ Map Format

- The map is a `.ber` file with the following characters:
  - `0` → empty space  
  - `1` → wall  
  - `C` → collectible  
  - `E` → exit  
  - `P` → player start
- Must be rectangular, enclosed by walls, and contain exactly one player start, one exit, and at least one collectible.
- The game checks for map validity and path accessibility.

---

## 🚀 Bonus Feature

- Instead of hardcoding a limit for the size of the window, the camera is following the player when the map is larger than the max display size.

---

## 📁 How to Run

```bash
make
./so_long your_map.ber
