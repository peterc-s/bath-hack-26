# Apple //e Text-Based Adventure Game

To clone, since we use submodules, use:

```sh
git clone https://github.com/peterc-s/bath-hack-26 --recurse-submodules
```

## Requirements

- A Linux/MacOS machine (with `root` access, for accessing `/dev/tty*`), though this could be trivially ported to work on Windows.
- An Apple //e.
- [`Python 3.14.*`](https://www.python.org/downloads/) for using the Python stuff.
- [`astral-uv`](https://docs.astral.sh/uv/#installation) for running the Python project.
- [`c2t-96h`](https://github.com/datajerk/c2t) for converting tokenised BASIC into a casette.

If you're using Nix, you can use [this `bastoken` and `c2t` flake](https://github.com/peterc-s/c2t-nix) to use the latter two.

## Running the Game

In [trickle-down-dragonslayer](./trickle-down-dragonslayer/), run `make` to preprocess, tokenise, and convert the BASIC source code into a casette. This will then play the casette audio and start up the serial and AI model.

Before you run `make`, you should make sure the Apple //e is ready. In a `]` prompt:

```BASIC
LOAD
```

Then run `make`. Once you get a `*` prompt, run:

```
800.A00R 800G
```

And the game should boot up.

## Other Useful Stuff

Use [apple-tools](https://github.com/peterc-s/apple-tools) `preprocess` to turn unprocessed BASIC into a usable BASIC file:

```sh
uv run preprocess unprocessed.bas > processed.bas
```

Then, you can use [basic2tape.sh](./basic2tape.sh) to convert the processed BASIC into a casette tape:

```sh
# make sure you can execute the script
chmod u+x basic2tape.sh

# do the conversion
./basic2tape.sh processed.bas out.wav
```

On the Apple //e in a `]` prompt, run:

```BASIC
LOAD
```

Then, shortly after, play the casette over AUX.

You should now have a prompt with a `*`.

Finally, run the loaded program on the Apple //e with:

```BASIC
800.A00R 800G
```
