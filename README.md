INSTRUCTIONS

1. Rename the "main_folder"
2. Inside the main folder, rename the folder Template_dll according to your project's name. For example: myproject_dll.  
3. Go to file premake5.lua and change the text "Template" to your project's name in lines 2,3,17 and 18 and save it
4. Run the File GenerateProject.bat
5. Rename the .plecs file to your project's name.
6. Open the .plecs file, and open the DLL block and on the file name copy the following string: "bin\Debug-x86_64\Template_dll\Template_dll.dll" Replace the text "Template" to the projects name that you write on the premake5.lua file in the 1st step. You're final result will be "bin\Debug-x86_64\myproject_dll\myproject_dll.dll"
7. Open the open.sh file with the notepad and change the text "Template.plecs" and "Template.sln"  for the name of your project. For example "myproject.plecs" "myproject.sln"
8. Compile the .sln file and run the .plecs file, in the .plecs file you should have a sine wave of amplitude 1 and 50 Hz
9. Make your own local repository with the folowing commands
	git init
	git add .
	git commit "new project initialized"
10. Synchronize with github repo
11. You're ready to go!

NOTE: In case you want to follow a gitflow workflow add two branches to your repo : main  develop
make the default option of this repo no fast forward with: git config --add merge.ff false
start making branch features and merging, happy coding!
