# C++ SDL2 project targeting WASM
In my amazing journey to setup a toolchain to compile an SDL2 project using Emscripten I have visited the deepest bowels of hell. So in order to prevent that in the future, I'm going to write down the instructions in this readme file.


# Table of contents
1. [Enviroment](#enviroment)
    - [SDL2](#sdl2)
    - [Emscripten](#emscripten)
2. [VSCode](#vscode)
    - [Compilation](#compilation)
    - [Writing code](#writing-code)

# Enviroment
I'm building this project using WSL2, but this should just work on Linux, if you're using VSCode, as I haven't bothered to write a makefile yet.

If you're on Windows, you'll need to [install WSL2](https://docs.microsoft.com/en-us/windows/wsl/install).

Once you have installed WSL and setup your user, you'll need to install a couple of things.

## SDL2
First off, you'll need to install SDL2. Whether or not this step is trully neccessary, I'm not sure, but just in case let's do it anyway.
To install it on Ubuntu, run this command

```
sudo apt install libsdl2-dev libsdl2-2.0-0 -y
```

## Emscripten
Emscripten requires more steps, so let's break them down.

First off, you'll need to clone their repo (very user-friendly, I know). Alternatively, you could download a ZIP archive, but we're using WSL, so that's out of the window.

So clone their repo

```
git clone https://github.com/emscripten-core/emsdk.git
```

and cd into it

```
cd emsdk
```

Now we need to INSTALL it. What that does is that installs the neccessary versions of Python, Nodejs, and Java, that Emscripten uses. Why it uses all of those things and not just one - I have no clue. It's also built on top of Clang, which, as of my testing, doesn't have full support for some C++20 features, but I digress.

So, install it with the following command

```
./emsdk install latest
```

Now we need to ACTIVATE it. 
```
./emsdk activate latest
```

And now the final step - activating PATH variables.
```
source ./emsdk_env.sh
```
This will add neccessary directories to PATH, but only for the current terminal, which means that you have to run it every time you reboot the system, and that is very nice and not annoying at all.
This can be negated by [adding the script to .bashrc](https://stackoverflow.com/a/38227522/10622326);


# VSCode
So now that we're done with enviroment, let's start writing some code, right? Well, almost.
First off, backout of **emsdk** folder back to your home directory and make a folder.
```
cd ..

mkdir whateverTheHellYouWant
```

Then cd in there and open up VSCode
```
code .
```
In WSL you'll see that it'll start to install some *magic*, and then it will open VSCode in Windows.
Create a **main.cpp** file, and write some stuff in there, like
```
#include <iostream>

int main() {
    std::cout << "Hello world" << std::endl;
}
```
Standart C++ stuff, yea. Naturally, install the neccessary C++ extensions, whatever you need.

Now here comes the fun part.

## Compilation
VSCode has a nice thing called tasks. They're located in **.vscode** folder at the root of your project, in **tasks.json** file. There you can setup commands that can be used to build your project.

Another file that is important is **c_cpp_properties.json**. There we're going to setup the compiler and IntelliSense™.

## c_cpp_properties.json
First off let's look at the **c_cpp_properties.json** file.
Here's mine:
```
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "cStandard": "c17",
            "cppStandard": "c++20",
            "intelliSenseMode": "linux-clang-x64",
            "compilerPath": "/home/sansanichick/emsdk/upstream/emscripten/emcc.py",
            "compilerArgs": [
                "-std=c++20"
            ]
        }
    ],
    "version": 4
}
```
The most important parts here are **intelliSenseMode**, **compilerPath**, **cppStandard**.

### intelliSenseMode
Emscripten uses Clang under the hood, so we choose "linux-clang-x64" as the mode.

### compilerPath
Here we need to put our path to the compiler. Emscripten compiler is python file (yea), and it is located in the "upstream" directory of the repo that you've cloned. 

### cppStandard
Version of C++ that IntelliSense™ is going to use. Be vary that Clang [didn't fully implement C++20 standart yet](https://clang.llvm.org/cxx_status.html), and stuff like modules doesn't fully bloody work even with -fmodules argument, at least it doesn't for me.

## tasks.json
Now let's look at **tasks.json**:
```
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: emcc build active file",
            "command": "/home/sansanichick/emsdk/upstream/emscripten/emcc.py",
            "args": [
                "-g",
                "-std=c++20",
                "${workspaceFolder}/*.cpp",
                "${workspaceFolder}/bench/*.cpp",
                "-o",
                "${fileDirname}/out/${fileBasenameNoExtension}.html",
                "-s",
                "USE_SDL=2",
                "-s",
                "ASYNCIFY"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task generated by Debugger."
        }
    ],
    "version": "2.0.0"
}
```

Most of this was generated by VSCode itself once I tried to run the main.cpp file, and the only things that I've changed are the arguments.

## Writing code
Finally.
For the most part you're gonna be writing regular C++ code, since that's essentially the entire point. The interesting part is when you need to use Emscripten's APIs to do stuff. The best practice is to include that stuff using **#ifdef \_\_EMSCRIPTEN__**, so that you can still compile your project as a regular application using other compilers.

For example:
```
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

int main() {
    // complicated code here

#ifdef __EMSCRIPTEN__         // telling the compiler to only include 
                              //this block when using Emscripten
    emscripten_sleep(10000);  // use an Emscripten thing
#else                         // otherwise we use regular C++ thing
    SDL_Delay(10000);
#endif

    // even more complicated code there
}
```

And that concludes this file