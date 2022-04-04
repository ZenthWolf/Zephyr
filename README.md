# Zephyr
Game Engine

Startup instructions:

Clone with the command:

`git clone --recurse-submodules https://github.com/ZenthWolf/Zephyr`

in order to obtain the repo, plus submodules used. Project can then be generated via the included premake file in the top directory. Use "GenerateProject.bat" to automatically create the project for VisualStudio 2022.

Example of generating via premake file:

```
call vendor\bin\premake\premake5.exe vs2022
PAUSE
```
