# FakePESELgenerator

This program can generate a fake PESEL numer which is fully correct. FOR EDUCATIONAL PURPOSES ONLY!

# Usage

The program is very simple to use. In /bin folder there are ready to use binary files.

## Windows

If you use Windows, open terminal in the /bin folder of this repo and run this command:

```
> fakepesel_windows.exe
```

Don't open the exe file by a double click.
If you want, you can make a new exe by yourself. To do this, install GCC and run this command in repo folder (not /bin!):

```
> g++ main.cpp -o fakepesel_windows.exe
```

## Linux

Using this program on Linux is very similar to Windows. Open your terminal in /bin folder and run this command:

```
$ ./fakepesel_linux
```

Don't open the exe file by a double click.
And here you can also make a new executable file. Just use this (make sure your terminal is opened in main repo folder, not /bin!):

```
$ g++ main.cpp -o fakepesel_linux
```

## macOS

There's no executable file for macOS yet, but you can make it by compilling `main.cpp` just like on Linux.
