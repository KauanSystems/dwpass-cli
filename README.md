<br>

<a id="home"></a>
<p align="center">
  <img src="assets/logo/Logo.svg" width="300" alt="dwpass-cli Logo">
</p>

<h1 align="center">
  dwpass-cli - A Diceware Passphrase Generator.
</h1> <br>

<p align="center">
  A Modern Cli Diceware Passphrase Generator. <br> Built with modern C++ for performance, simplicity, and reliability. <br><br>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Standard-green?logo=c%2B%2B" alt="C++ Standard">
  <img src="https://img.shields.io/badge/License-GPLv3-green?logo=gnu" alt="License GPLv3">
  <img src="https://img.shields.io/badge/Linux-Supported-green?logo=linux" alt="Linux Supported">
  <img src="https://img.shields.io/badge/Windows-Supported-green?logo=windows" alt="Windows Supported">
  <img src="https://img.shields.io/badge/CMake-Build-green?logo=cmake" alt="CMake">
</p> <br>

<div align="center">

[Project Structure](#project-structure) ·
[Supported Operating Systems](#supported-operating-systems) .
[Requirements](#requirements) ·
[Build](#build) ·
[Run Examples](#run-examples) ·
[Baseboard](#baseboard)

</div> <br>

A high-performance, security-focused command-line interface (CLI) tool for generating passphrases using the Diceware method. The project combines the convenience of terminal-based automation with the rigor of physical entropy and the operating system's cryptographic sources.

<br>

> [!IMPORTANT]
> To ensure maximum randomness and cryptographic security, the program makes direct use of the native entropy sources provided by the supported operating systems [Supported Operating Systems](#supported-operating-systems).

<br>

## About Project:

This project is a high-performance CLI Diceware generator, developed in modern C++ and structured using CMake. The tool prioritizes security and reliability in the creation of memorable passwords and passphrases. <br>

To ensure maximum randomness and cryptographic security, the application draws directly from the native entropy sources provided by the operating system, eliminating the need for complex external dependencies. Featuring an intuitive command-line interface, the generator is ideal both for users seeking secure credentials for everyday use and for integration into automation scripts.

<br>

## Project Structure:

```text
dwpass-cli/                                                          
├── assets/                             # Dwpass-cli Assets File.
│   └── logo/                           # Dwpass-cli Logo File.
│
├── program/                            # dwpass-cli program File.
│   ├── include/                        # Program Include Directory.
│   │   └── cli/                        # Cli Include Directory.
│   │
│   └── src/                            # program src Directory.
│       └── cli/                        # Cli src Directory.
│           └── command_table/          # Program Command Table. 
│
├── CMakeLists.txt                      # Project Root CMakeLists.txt
├── LICENSE                             # Project License.
└── README.md                           # Technical Documentation.
```

<br>

## Supported Operating Systems <br>

| Operating System | Support |
|---|---|
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat&logo=windows&logoColor=white) | Supported |
| ![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black) | Supported |

<br><br>

## Requirements:

Before building dwpass, make sure the following dependencies are installed. <br>

### <img src="https://img.shields.io/badge/Windows-0078D4?style=flat&logo=windows&logoColor=white" alt="Windows">

Open **PowerShell as Administrator** and run:

```powershell
winget install Git.Git
winget install Kitware.CMake

winget install Microsoft.VisualStudio.2022.BuildTools --override "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
```

### <img src="https://cdn.simpleicons.org/archlinux" width="24" alt="Arch Linux"> Arch Linux:

```bash
sudo pacman -S --needed base-devel cmake gcc git
```

### <img src="https://cdn.simpleicons.org/debian/d70a53" width="24" alt="Debian"> Debian:

```bash
sudo apt update
sudo apt install -y build-essential cmake gcc g++ git
```

### <img src="https://cdn.simpleicons.org/fedora/51A2DA" width="24" alt="Fedora"> Fedora:

```bash
sudo dnf upgrade --refresh
sudo dnf install -y gcc gcc-c++ make cmake git
```

### <img src="https://cdn.simpleicons.org/alpinelinux/0D597F" width="24" alt="Alpine Linux"> Alpine Linux:

```bash
sudo apk update
sudo apk add build-base cmake git
```

### <img src="https://cdn.simpleicons.org/opensuse/73BA25" width="24" alt="openSUSE"> openSUSE:

```bash
sudo zypper refresh
sudo zypper install -y gcc gcc-c++ make cmake git
```

<br><br>

Packages installed:

- `base-devel` — Essential build tools (make, linker, etc.).
- `gcc` — C/C++ compiler with C++20 support.
- `cmake` — Build system generator.
- `git` — Repository cloning.

<br><br>

# Build

Requires a compiler with **C++** support **clang++/g++**.

```bash
git clone https://github.com/KauanSystems/dwpass-cli.git
cd dwpass-cli

cmake -B build
cmake --build build
```

<br><br>

# Run Examples:

Practical examples of commands for using the program via a command-line interface, regardless of the operating system the user is running. <br><br>

> [!TIP]
> The -e parameter applies to all the statements below.

<br>

To simply generate a Diceware passphrase.
```bash
dwpass -g
``` 
<br>

To generate a Diceware file and export it.
```bash
dwpass -g -e
```
<br>

To give yourself the input of a real datum to guarantee maximum entropy to your diceware passphrase.
```bash
dwpass -i
```
<br>

To ensure maximum entropy and pass the desired number of phrases, pass the desired number of phrases.
```bash
dwpass -i NUM_PHRASES_PASS
```
<br>

Provide the program with a standard wordlist file so that it can generate content based on your language
```bash
dwpass -w FILE_PATH
```
<br>

To input values ​​and provide the program with a wordlist file so that it can generate content based on your language.
```bash
dwpass -i -w FILE_PATH
```
<br>

```bash
dwpass -i NUM_PHRASES_PASS -w FILE_PATH
```

<br><br><br><br><br>

<p align="center">
  <img src="assets/logo/Logo.svg" width="200" alt="dwpass-cli Logo">
</p>

<h1 align="center">Dwpass-cli</h1> <br>

<a id="baseboard"></a>
<p align="center">
  A Modern Cli Diceware Passphrase Generator. <br> Built with modern C++ for performance, simplicity, and reliability. <br><br>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Standard-green?logo=c%2B%2B" alt="C++ Standard">
  <img src="https://img.shields.io/badge/License-GPLv3-green?logo=gnu" alt="License GPLv3">
  <img src="https://img.shields.io/badge/Linux-Supported-green?logo=linux" alt="Linux Supported">
  <img src="https://img.shields.io/badge/Windows-Supported-green?logo=windows" alt="Windows Supported">
  <img src="https://img.shields.io/badge/CMake-Build-green?logo=cmake" alt="CMake">
</p> <br>

<div align="center">

[Home](#home) ·
[Project Structure](#project-structure) ·
[Supported Operating Systems](#supported-operating-systems) .
[Requirements](#requirements) ·
[Build](#build) ·
[Run Examples](#run-examples)

</div> <br><br>

<p align="center">
  Developed by KauanSysytems.
</p> <br>

<br><br><br><br><br>
