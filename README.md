# Apple //e Text-Based Adventure Game

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
