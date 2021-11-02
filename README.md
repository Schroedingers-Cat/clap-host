# Minimal Clap Host

This repo serves as an example to demonstrate how to create a host for CLAP plugins.

## Building on various platforms

### macOS

To build the example host on macOS you need a few extra libraries, qt6, boost, portmidi and portaudio.
These are all available by homebrew and the CMake setup will find them assuming a standard
(/usr/local) homebrew setup. Before your first build do

```shell
brew install qt6
brew install boost
brew install portaudio
brew install portmidi
brew install pkgconfig
```

### Windows

In case you haven't already, install the necessary tools:
```powershell
choco install cmake python strawberryperl ninja -y
```

Dependencies on Windows are managed by vcpkg through CMake. For that to work, you'll have to init and checkout all submodules, which includes vcpkg:
```powershell
git submodule init
git submodule update
```

WARNING: Before opening the repository with CMake and expecting vcpkg to automatically fetch and build all dependencies, take note that the dependency `qtbase` is heavily affected by the 255 character path limitation and building will simply fail for mysterious reasons (files are not being found that are actually present). Therefore, make sure that the path to the cloned repository on your machine is very short, like `C:\clap-host` or `D:\clap\host`. You can move this repository on your machine to the root of your drive at this point without any issues.  

You can now open the project with CMake and configure & generate the solutions. CMake should be able to automatically detect vcpkg, bootstrap and acquire the necessary packages. This will take some time because `qtbase` will be downloaded and built from source on your machine. However, this is necessary only once after cloning.  

The generated solutions will have a problem that needs manual fixing atm. You'll have to fix the "Additional Dependencies" path in the clap-host solution in the linker settings from `portmidi.lib` to `..\..\vcpkg_installed\x64-windows\debug\lib\portaudio.lib`.  
