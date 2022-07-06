if [ ! -d "./build" ] 
then
    mkdir build
fi


# echo "$PATH"


g++ $( find ./src/ -name *.cpp) -Wall -Wextra -o build/hurokul
./build/hurokul
