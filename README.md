INSTRUCTIONS
1. Rename the folder Template_dll according to your project's name. For example: myproject_dll.  
1. Go to file premake5.lua and change the text "Template" to your project's name in lines 2,3,17 and 18 and save it
2. Run the File GenerateProject.bat
3. Rename the .plecs file to your project's name.
4. Open the .plecs file, and open the DLL block and on the file name copy the following string: "bin\Debug-x86_64\Template_dll\Template_dll.dll" Replace the text "Template" to the projects name that you write on the premake5.lua file in the 1st step. You're final result will be "bin\Debug-x86_64\myproject_dll\myproject_dll.dll"
5. Open the open.sh file with the notepad and change the text "Template.plecs" and "Template.sln"  for the name of your project. For example "myproject.plecs" "myproject.sln"
6. You're ready to go!