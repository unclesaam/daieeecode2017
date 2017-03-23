#!/bin/bash


clear
clear
echo "===================================================="
g++ main.cpp fonction.cpp -o main
if [ "$?" = "0" ]; then
        echo "Build completed successfully. Will run main:"
        ./main
else
        echo "Build failed. See errors above."
fi
