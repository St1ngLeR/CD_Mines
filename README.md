# Crashday 1.2 - Mines

<img src="https://github.com/user-attachments/assets/16e8dca1-ba70-4495-aaf7-3ae85b716ff8"/>

## Overview
This is a Crashday 1.2 plugin for recreating cut Mine weapon feature. The plugin restores all possible aspects that make mines a fully functional weapon in the game.

Features:
- Mines are available for purchase in the shop for $2,000 and become available for 45 respect points;
- Mines can be selected and used in single/multiplayer and career modes via `forcemines`;
- The mines capacity is unique for each car and can be increased via `add_minecapacity`;
- The mine drop key can be changed via the in-game control settings;
- When dropped, mines emit a characteristic drop sound and become explosive to cars, minigun bullets and missiles;
- The mines has a 3‑second cooldown to reset.
- The game controls the despawn of mines via race restart, mine explosion, and after 30 seconds of existing in the game world;
- The AI can also drop mines in all game modes;
- The AI starts behaving aggressively towards the player if they run over the player’s mine;
- The game records damage and the destruction of opponents using mines (just like with other types of weapons);
- The mine has a unique 3D model designed to match the overall style of the game.
- The mines have their own icon in the HUD and display the current number of mines.

## Modding the assets
The assets for the mine are moddable and can be changed as desired:
- `editor/mine.p3d` — the 3D model of the mine;
- `sounds/weapons/minedrop.wav` — the sound when the mine is dropped;
- `textures/misc/mines.dds` — the mine icon in the HUD.

## Install & usage
To make ASI plugin work in the game you need to use [ThirteenAG's Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) and put plugin files in to game directory or folders mentioned in ThirteenAG's loader GitHub page.
