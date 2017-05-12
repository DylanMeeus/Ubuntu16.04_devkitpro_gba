devkitpro setup for GBA
=======================

When setting up my environment to build games for the gameboy advance, it took me some time to figure out the correct structure and get everything working due to version mismatches etc.

Thus my decision to commit my working environment, with the example GBAPong game that I have made in this environment.

You might need to install extra dependencies depending on your machine.

In order to run `make` you will need to set some variables to your path as well. It will inform you of these when you try to run, but if you copy this git repository to /opt/devkitpro/ as I did, these are the variables you can add to your `bashrc` file:

```
export DEVKITPRO=/opt/devkitpro/
export DEVKITARM=/opt/devkitpro/devkitARM
```

To test that the environment works, go to `/examples/GBAPong/` and run `make` in this directory. This should give you a `.gba` file that you can then run in your emulator of choice.