# cub3d

A work-in-progress [42 school](https://42.fr) **cub3D** project: a small
raycasting "3D maze" viewer written in C on top of the MiniLibX (`mlx`)
graphics library, using a personal `libft` as its standard-library helper.

> **Project status: early skeleton.** At the moment the program only opens a
> 1000×1000 window and exits when you press any key or close the window.
> Map parsing, raycasting, rendering and movement are **not implemented yet**.
> This README documents what the code does today and lists the planned
> pieces separately so the two are never confused. See
> [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) for the engine design.

## What works today

- Argument count check (more than one argument prints `Not valid arguments`
  to stderr and exits with status 1).
- MiniLibX initialisation (`mlx_init`) and creation of a 1000×1000 window
  titled `Hello`.
- Event hooks: closing the window (X11 `DestroyNotify`, event 17) or pressing
  **any key** (`KeyPress`, event 2) destroys the window and exits with status 0.
- A `parsemap()` stub in `main.c` that currently returns `NULL`.

## Planned features (not implemented yet)

- Parsing a `.cub` scene description (map, textures, floor/ceiling colours).
- DDA raycasting and textured wall rendering into an off-screen image.
- Keyboard movement and rotation.

## Controls

| Input              | Current behaviour               |
| ------------------ | ------------------------------- |
| Any key            | Closes the window and exits     |
| Window close (✕)   | Closes the window and exits     |

Movement and rotation controls do not exist yet.

## Map file format

No map format is parsed yet: `parsemap(char *file)` is a stub returning
`NULL`, and the `file` argument (`av[1]`) is ignored. The program can be
started with zero or one argument. The format below is the one the 42
subject specifies and is the intended target; it is **not** validated or
read by the current code.

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

## Requirements

- Linux with X11 development headers and libraries (`libX11`, `libXext`)
- A C compiler (`cc`), `make`, and the math library (`-lm`)
- The MiniLibX header (`mlx.h`) and static library (`libmlx.a`), both of
  which are committed to the repository
- An X server (a real display or e.g. Xvfb) to actually run the window

## Build

```sh
make          # builds libft (libft/ -> ./libft.a) and then ./game
make clean    # remove objects
make fclean   # remove objects, ./game and ./libft.a
make re       # fclean + all
```

Targets: `all` (alias of `normal`, builds with `-g`), `strict`
(`-Wall -Wextra -Werror`), `clean`, `fclean`, `re`, `bonus` (same as `all`).

### Known build issues

- **Link order.** The Makefile links `-lXext -lX11 -lm` *before* `libmlx.a`,
  so with linkers that resolve symbols left to right (for example on
  current Debian/Ubuntu toolchains) `make` fails with `undefined reference to
  'XFlush'`-style errors. Linking manually with the libraries last works:

  ```sh
  make libft.a
  cc -g main.c libft.a libmlx.a -lXext -lX11 -lm -o game
  ```

  (Verified: this produces a working binary.)
- **`make strict` does not pass yet.** `main.c` currently triggers
  `-Wall -Wextra -Werror` errors (unused parameter `key`, unused parameter
  `ac`/`file`, missing return in `close_win`, and so on).
- Because of the target-specific `CFLAGS`, the default `make` build compiles
  with `-g` only and no warning flags.

## Run

```sh
./game            # needs a running X server
./game map.cub    # the argument is accepted but currently ignored
```

## Project structure

```
.
├── Makefile        Build rules; builds libft then links ./game
├── main.c          Entry point, window creation, close hooks, parsemap() stub
├── main.h          Includes and the t_game struct (mlx + window pointers)
├── mlx.h           MiniLibX public header
├── libmlx.a        Pre-built MiniLibX static library
├── libft/          Personal C library (ft_* string, memory, char, put* helpers)
├── docs/
│   └── ARCHITECTURE.md   Engine design: current state and planned pipeline
└── .gitignore
```

## Notes

Written as a 42 school project (Makefile headers credit `yel-bouz`).
