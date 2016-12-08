# GFraMe game template

Template for games built with libGFraMe.

This template was based on [https://github.com/SirGFM/jjat_2/tree/refactor](JJAT 2).
Look at that game's source for tips on how to use it.

## Troubleshooting

### Error creating './assets'

If after running `make` you see the following output:

```sh
ln: failed to create symbolic link ‘./assets’: File exists
make: *** [bin/Linux_debug/assets] Error 1
```

Create an `assets` directory on the project's base directory.

