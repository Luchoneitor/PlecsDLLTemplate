#/bin/zsh


if [[ "$OSTYPE" == "darwin"* ]]; then
	./premake/premake5 xcode4
else
   ./premake/premake5.exe vs2022
    read -p "Press Enter to continue" 
fi