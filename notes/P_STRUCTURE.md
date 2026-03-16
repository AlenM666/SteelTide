## Project Structure
---

And here is the full project structure. This is organized by **domain** — each major game system lives in its own folder so the codebase scales without turning into spaghetti.
```
SteelTide/
│
├── CMakeLists.txt
├── .gitignore
├── .clang-format
├── .clang-tidy
│
│
├── assets/                         # All runtime assets (copied to bin/ on build)
│   ├── textures/
│   │   ├── tiles/                  # Terrain, ocean, biome tiles (16x16 or 32x32)
│   │   │   ├── ocean/
│   │   │   ├── jungle/
│   │   │   ├── volcanic/
│   │   │   ├── arctic/
│   │   │   ├── desert/
│   │   │   └── ruins/
│   │   ├── entities/
│   │   │   ├── player/
│   │   │   ├── ships/
│   │   │   ├── enemies/
│   │   │   └── npcs/
│   │   ├── factory/                # Machines, belts, pipes, power poles
│   │   ├── items/                  # Item icons (inventory grid)
│   │   ├── ui/                     # HUD frames, buttons, panels
│   │   ├── fx/                     # Particles, splashes, smoke, explosions
│   │   └── world/                  # World map, fog of war overlays
│   │
│   ├── audio/
│   │   ├── music/
│   │   │   ├── ocean/              # Sailing ambience tracks
│   │   │   ├── island/             # Per-biome exploration tracks
│   │   │   ├── combat/
│   │   │   └── menu/
│   │   └── sfx/
│   │       ├── player/
│   │       ├── ship/
│   │       ├── factory/            # Machine hums, belt ticks, item drops
│   │       ├── combat/
│   │       ├── environment/
│   │       └── ui/
│   │
│   ├── fonts/
│   │   ├── pixel_main.ttf
│   │   └── pixel_ui.ttf
│   │
│   └── shaders/                    # GLSL for water ripple, day-night, outlines
│       ├── water.fs
│       ├── outline.fs
│       └── day_night.fs
│
│
├── data/                           # JSON/text data files (game config, not code)
│   ├── items/
│   │   ├── raw_resources.json      # Wood, iron ore, fish, fruit ...
│   │   ├── processed_goods.json    # Planks, ingots, rope ...
│   │   └── equipment.json          # Weapons, ship parts, tools
│   │
│   ├── recipes/
│   │   ├── hand_crafting.json
│   │   ├── crafting_stations.json
│   │   └── factory_machines.json
│   │
│   ├── machines/
│   │   ├── extractors.json         # Mining drill, lumber mill, fishing net
│   │   ├── processors.json         # Smelter, sawmill, press
│   │   ├── logistics.json          # Belts, splitters, mergers, chests
│   │   └── power.json              # Wind turbine, furnace generator
│   │
│   ├── biomes/
│   │   ├── jungle.json
│   │   ├── volcanic.json
│   │   ├── arctic.json
│   │   ├── desert.json
│   │   ├── ruins.json
│   │   └── deep_ocean.json
│   │
│   ├── islands/
│   │   ├── island_templates.json   # Procedural gen parameters per biome
│   │   └── world_layout.json       # Fixed world seed or hand-placed islands
│   │
│   ├── ships/
│   │   ├── player_ships.json
│   │   └── enemy_ships.json
│   │
│   ├── enemies/
│   │   ├── pirates.json
│   │   ├── sea_creatures.json
│   │   └── island_enemies.json
│   │
│   ├── npcs/
│   │   ├── merchants.json
│   │   └── quest_givers.json
│   │
│   └── settings/
│       ├── game_config.json        # Resolution, volumes, keybinds defaults
│       └── balance.json            # Resource rates, damage values, costs
│
│
├── include/                        # Public headers (third-party or shared types)
│   └── steeltide/
│       └── types.h                 # Shared enums, forward declarations, aliases
│
│
└── src/
    │
    ├── main.cpp
    │
    ├── engine/                     # Platform-agnostic engine layer
    │   │                           # Nothing here knows about game rules
    │   ├── core/
    │   │   ├── application.h/.cpp  # App lifetime, init/shutdown order
    │   │   ├── game_loop.h/.cpp    # Fixed timestep, delta time, frame cap
    │   │   └── window.h/.cpp       # Raylib window + display config
    │   │
    │   ├── renderer/
    │   │   ├── renderer.h/.cpp         # Draw call queue, layer sorting
    │   │   ├── camera.h/.cpp           # 2D camera: pan, zoom, shake, clamp
    │   │   ├── sprite_batch.h/.cpp     # Batched texture draws
    │   │   ├── tilemap_renderer.h/.cpp # Chunked tilemap rendering
    │   │   └── animation.h/.cpp        # Sprite sheet animator (frame/fps)
    │   │
    │   ├── audio/
    │   │   └── audio_manager.h/.cpp    # Play/stop/fade music & SFX channels
    │   │
    │   ├── input/
    │   │   └── input_manager.h/.cpp    # Rebindable actions, keyboard/mouse/gamepad
    │   │
    │   ├── ecs/                        # Minimal entity-component system
    │   │   ├── entity.h                # EntityID typedef, null sentinel
    │   │   ├── entity_manager.h/.cpp   # Create/destroy/query entities
    │   │   └── component_registry.h/.cpp # Type-erased component storage
    │   │
    │   └── utils/
    │       ├── math.h/.cpp             # Vec2 helpers, lerp, clamp, rect ops
    │       ├── timer.h/.cpp            # Countdown & repeating timers
    │       ├── random.h/.cpp           # Seeded RNG wrappers
    │       └── logger.h               # Lightweight log macros (no .cpp needed)
    │
    │
    ├── world/                      # The game world: islands, ocean, biomes
    │   │
    │   ├── world.h/.cpp            # Top-level world state, chunk loading
    │   │
    │   ├── island/
    │   │   ├── island.h/.cpp           # Island data: tiles, resources, ownership
    │   │   └── island_generator.h/.cpp # Proc-gen: noise → biome → tile layout
    │   │
    │   ├── biome/
    │   │   ├── biome.h/.cpp            # Biome properties: color palette, resources, enemies
    │   │   └── biome_registry.h/.cpp   # Loads biomes from data/biomes/*.json
    │   │
    │   ├── ocean/
    │   │   ├── ocean.h/.cpp            # Ocean state: currents, weather, storms
    │   │   └── ocean_chunk.h/.cpp      # Tiled ocean segments, wave animation
    │   │
    │   └── map/
    │       ├── world_map.h/.cpp        # Full world layout, island positions
    │       └── minimap.h/.cpp          # Minimap render + fog of war
    │
    │
    ├── gameplay/                   # Game rules, systems, mechanics
    │   │
    │   ├── player/
    │   │   ├── player.h/.cpp           # Player entity: stats, state machine
    │   │   ├── player_controller.h/.cpp # Movement, interaction, on-foot combat
    │   │   └── player_stats.h/.cpp     # Health, stamina, hunger, reputation
    │   │
    │   ├── ship/
    │   │   ├── ship.h/.cpp             # Ship data: hull, sails, cargo hold
    │   │   ├── ship_controller.h/.cpp  # Sailing physics, wind, turning
    │   │   ├── ship_combat.h/.cpp      # Broadside, boarding, damage states
    │   │   ├── cannon.h/.cpp           # Cannon aim, reload, projectile spawn
    │   │   └── fleet_manager.h/.cpp    # Multiple ships, crew assignment
    │   │
    │   ├── factory/                # Satisfactory-style automation layer
    │   │   ├── factory_grid.h/.cpp     # Per-island build grid
    │   │   ├── machine.h/.cpp          # Base machine: input/output slots, tick
    │   │   ├── machine_registry.h/.cpp # Loads machines from data/machines/*.json
    │   │   ├── conveyor_belt.h/.cpp    # Item transport: direction, speed, capacity
    │   │   ├── resource_pipe.h/.cpp    # Fluid/bulk transport between machines
    │   │   └── power_grid.h/.cpp       # Power production, distribution, shortage
    │   │
    │   ├── items/
    │   │   ├── item.h/.cpp             # Item definition: id, stack size, flags
    │   │   ├── item_registry.h/.cpp    # Loads all items from data/items/*.json
    │   │   ├── inventory.h/.cpp        # Grid inventory with stack management
    │   │   └── resource_node.h/.cpp    # World resource deposits (ore vein, tree)
    │   │
    │   ├── crafting/
    │   │   ├── recipe.h/.cpp           # Recipe: inputs → outputs + time
    │   │   ├── recipe_registry.h/.cpp  # Loads recipes from data/recipes/*.json
    │   │   └── crafting_station.h/.cpp # Hand-bench, station, and auto variants
    │   │
    │   ├── combat/
    │   │   ├── combat_system.h/.cpp    # Damage resolution, hit detection
    │   │   ├── projectile.h/.cpp       # Cannonball, arrow — physics, lifetime
    │   │   └── hitbox.h/.cpp           # AABB + circle hitbox primitives
    │   │
    │   └── economy/
    │       ├── market.h/.cpp           # Island market: buy/sell prices, stock
    │       └── trade_route.h/.cpp      # Automated ship trade between islands
    │
    │
    ├── entities/                   # Actors in the world
    │   ├── npc/
    │   │   ├── npc.h/.cpp              # Friendly NPC base: schedule, wander
    │   │   └── npc_dialogue.h/.cpp     # Dialogue tree, quest hook
    │   │
    │   └── enemy/
    │       ├── enemy.h/.cpp            # Land enemy base: patrol, aggro, loot
    │       ├── enemy_ship.h/.cpp       # Enemy ship: AI sailing + combat
    │       └── pirate_crew.h/.cpp      # Crew-level boarding/melee enemies
    │
    │
    ├── scenes/                     # High-level game state machine
    │   ├── scene_manager.h/.cpp    # Push/pop scene stack
    │   ├── main_menu_scene.h/.cpp
    │   ├── gameplay_scene.h/.cpp   # Coordinator: owns world, player, systems
    │   ├── island_scene.h/.cpp     # On-foot island exploration mode
    │   └── ocean_scene.h/.cpp      # Open ocean sailing mode
    │
    │
    ├── ui/                         # All HUD and menu rendering
    │   ├── hud.h/.cpp              # Health bar, compass, current item, clock
    │   ├── inventory_screen.h/.cpp # Full inventory grid view
    │   ├── factory_ui.h/.cpp       # Machine placement, belt routing overlay
    │   ├── world_map_ui.h/.cpp     # Zoomable world map with island notes
    │   ├── dialogue_box.h/.cpp     # NPC speech bubbles and choice menus
    │   ├── crafting_ui.h/.cpp      # Recipe browser + craft queue
    │   ├── ship_ui.h/.cpp          # Ship cargo, crew, repair panel
    │   ├── main_menu.h/.cpp
    │   └── pause_menu.h/.cpp
    │
    │
    └── data/                       # Save/load and asset management
        ├── save_manager.h/.cpp     # Serialize world + player state to disk
        ├── json_loader.h/.cpp      # Thin wrapper around a JSON parser
        └── asset_registry.h/.cpp  # Central cache: textures, sounds, fonts

