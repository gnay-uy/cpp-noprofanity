# C++ Profanity Checker
## How it works
This program keylogs the last `n` characters you typed, where `n` is the longest disallowed word. Then, if a substring of the logged characters matches a disallowed word defined in `std::vector<std::string> bannedwords`, it'll blue screen your computer.

## Installation Guide
1. Ensure that you have `Visual Studio`.
2. Set the configuration to `Release`.
3. Right click on the Solution and press `Build`.
4. Find the compiled binary at `x64\Release\NoProfanity.exe`.

## Configuration Guide
If you want to modify the list of banned words, open up `main.cpp` and add words to the `bannedwords` vector.

## Disclaimer
I claim no responsibility for any damaged caused by my program, if anything happens consider it a lesson learnt to use less profanities :)
