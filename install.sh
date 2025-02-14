#!/bin/bash
compiler1="gcc"
compiler2="clang"

#check whether raylib.c exists.
if [ ! -f "raylib.c" ]; then
  echo "Error : raylib.c not found"
  exit 1
fi

#checking for various C compilers.
checkCompiler(){
  echo "[-INFO-] Checking for gcc......"
  gcc --version > status.txt
  if [ $? -eq 0 ]
  then
    echo "[-INFO-] $compiler1 installed ^_^"
    echo -e "[-INFO-] Compiling...........\n"
    gcc -Wall raylib.c -o pong -lraylib -lGL -lm -ldl -lpthread -lrt -lX11
    checkEndStatus
  else
    echo "[-INFO-] Checking for clang......."
    clang --version > status.txt
    useClang
  fi
}

useClang(){
  local statuscompiler2=$?
  if [ "$statuscompiler2" -eq 0 ]
  then
    echo "[-INFO-] $compiler2 installed ^_^"
    echo "[-INFO-] Compiling........"
    clang -Wall raylib.c -o pong -lraylib -lGL -lm -ldl -lpthread -lrt -lX11
  fi
  checkEndStatus
}

checkEndStatus(){
  if [ $? -eq 0 ]
  then
    echo -e "\n[-INFO-] Compilation successful. Run './pong' to play! "
  fi
}

rm status.txt

# updateShellconfig(){
#   shell=$(basename $SHELL)
#   cwd=$(pwd)
#   if [ "$shell" = "zsh" ]
#   then
#     echo "Updating .zshrc...."
#     echo "alias pong='$cwd/pong'" >> ~/.zshrc
#   elif [ "$shell" == "bash" ]
#   then
#   #   echo "Updating .bashrc"
  #   echo "alias pong='$cwd/pong'" >> ~/.bashrc
  # # fi
#}  
#calling various functions.
checkCompiler
# updateShellconfig
