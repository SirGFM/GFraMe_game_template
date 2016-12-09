# GFraMe game template

Template for games built with libGFraMe.

This template was based on [https://github.com/SirGFM/jjat_2/tree/refactor](JJAT 2).
Look at that game's source for tips on how to use it.


## Troubleshooting


### Compiling for a specific platforms

Linux usually works by default (i.e., it shouldn't be necessary to set any
variable). If, however, there's any issue, set the OS to Linux when running the
Makefile:

```sh
$ make OS=Linux
```

For Windows, it's always necessary to set the OS to Win:

```sh
$ make OS=Win
```


### First compilation

When compiling for the first time, all .d files will fail to build. To fix that,
run:

```sh
$ make mkdirs OS=${YOUR_PLATFORM}
```


### Release build

When building for release, set RELEASE=yes:

```sh
$ make mkdirs RELEASE=yes OS=${YOUR_PLATFORM}
```


### Error creating './assets' (Linux only)

If after running `make` you see the following output:

```sh
ln: failed to create symbolic link ‘./assets’: File exists
make: *** [bin/Linux_debug/assets] Error 1
```

create an `assets` directory on the project's base directory.


### Adding an icon (Windows only)

To add an icon to the release build of your game, create the icon (a .ico file),
name it `icon.ico` and place it on the `assets` directory.

Create a file `icon.rc` with the single line:

```rc
1 ICON "assets/icon.ico"
```

Finally, uncomment line 38 of the Makefile.


### Tips for creating the icon (Windows only)

For better results, create a file with 4 layers. Those should be (from top-most
to bottom):

* layer_0: 256x256
* layer_1: 48x48
* layer_2: 32x32
* layer_3: 16x16

Then, layer_1 may be created by scaling layer_0 by a factor of 3 and layer_0 by
scaling layer_2 by 8.
