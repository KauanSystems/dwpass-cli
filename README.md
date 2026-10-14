<br><br><br>

<p align="center">
  <img src="assets/logo/Logo.svg" width="300" alt="dwpass-cli Logo">
</p> <br><br>

<h1 align="center">
  dwpass-cli - A Diceware Passphrase Generator.
</h1> <br><br>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Standard-blue?logo=c%2B%2B" alt="C++ Standard">
  <img src="https://img.shields.io/badge/License-GPLv3-blue?logo=gnu" alt="License GPLv3">
  <img src="https://img.shields.io/badge/Linux-Supported-green?logo=linux" alt="Linux Supported">
  <img src="https://img.shields.io/badge/Windows-Supported-green?logo=windows" alt="Windows Supported">
  <img src="https://img.shields.io/badge/CMake-Build-orange?logo=cmake" alt="CMake">
</p> <br><br><br>

## 🎲 dwpass-cli - A Diceware Passphrase Generator.

A high-performance, security-focused command-line interface (CLI) tool for generating passphrases using the Diceware method. The project combines the convenience of terminal-based automation with the rigor of physical entropy and the operating system's cryptographic sources.

<br><br>

## 📂 Project Structure:

```text
.
├── assets/                             # Dwpass-cli Assets File.
├── assets/logo                         # Dwpass-cli Logo.
├── program                             # dwpass-cli program File.
├── program/include                     # program Include Directory.
├── program/include/cli                 # Cli Include Directory.
├── program/src                         # program src Directory.
├── program/src/cli                     # Cli src Directory.
│
├── CMakeLists.txt                      # Project Root CMakeLists.txt
├── LICENSE                             # Project Root CMakeLists.txt
└── README.md                           # Technical documentation.
```

<br><br>

## 📦 Requirements

Before building dwpass, make sure the following dependencies are installed. <br>

### <img src="https://cdn.simpleicons.org/archlinux" width="24" alt="Arch Linux"> Arch Linux:

```bash
sudo pacman -S --needed base-devel cmake gcc git
```

<br>

### <img src="https://cdn.simpleicons.org/debian/d70a53" width="24" alt="Debian"> Debian:

```bash
sudo apt update

sudo apt install -y build-essential cmake gcc g++ git
```

<br>

### <img src="https://img.shields.io/badge/PowerShell-%23012456.svg?style=for-the-badge&logo=powershell&logoColor=white" width="24" alt="Windows"> Windows

Open **PowerShell as Administrator** and run:

```powershell
winget install Git.Git
winget install Kitware.CMake

winget install Microsoft.VisualStudio.2022.BuildTools --override "--add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
```

<br><br>

Packages installed:

- `base-devel` — Essential build tools (make, linker, etc.).
- `gcc` — C/C++ compiler with C++20 support.
- `cmake` — Build system generator.
- `git` — Repository cloning.

<br><br>

# 🛠️ Build & Run

Requires a compiler with **C++** support **clang++/g++**.

## <img src="https://img.shields.io/badge/Command%20Prompt-000000?style=for-the-badge&logo=windows&logoColor=white" width="30" alt="Command Prompt"> Command Prompt:

```bash
https://github.com/KauanSystems/dwpass-cli.git

cd dwpass-cli

cmake -B build

cmake --build build
```

<br><br><br><br><br>

<p align="center">
  <img src="assets/logo/Logo.svg" width="200" alt="dwpass-cli Logo">
</p>

<h1 align="center">Dwpass-cli</h1>

<p align="center">
  Developed by KauanSysytems.
</p><br>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Standard-blue?logo=c%2B%2B" alt="C++ Standard">
  <img src="https://img.shields.io/badge/License-GPLv3-blue?logo=gnu" alt="License GPLv3">
  <img src="https://img.shields.io/badge/Linux-Supported-green?logo=linux" alt="Linux Supported">
  <img src="https://img.shields.io/badge/Windows-Supported-green?logo=windows" alt="Windows Supported">
  <img src="https://img.shields.io/badge/CMake-Build-orange?logo=cmake" alt="CMake">
</p><br>

<p align="center">
  A Modern Cli Diceware Passphrase Generator. <br><br> Built with modern C++ for performance, simplicity, and reliability.
</p>

<br><br><br><br><br>
