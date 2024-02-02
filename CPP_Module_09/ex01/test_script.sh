#!/bin/bash

PROGRAM=./RPN

# Build the program
make re

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Error building $PROGRAM."
    exit 1
fi

# Define test cases
TESTS=(
    "2 3 +"
    "5 7 -"
    "4 6 *"
    "8 2 /"
    "1 2 + 3 *"
    "9 3 / 2 *"
    "6 4 * 7 /"
    "5 2 / 3 +"
    "0 9 - 2 *"
    "8 4 / 2 -"

    "2 3 4 * + 5 /"
    "1 2 3 * 4 / +"
    "7 3 * 4 2 / -"
    "8 4 / 2 * 6 +"
    "9 2 / 4 * 6 2 / +"
    "5 6 * 2 / 7 +"
    "1 2 + 3 4 * /"
    "4 2 / 3 * 5 -"
    "6 2 * 8 3 / +"
    "9 4 / 2 * 7 3 / +"
)

EXPECTED=(
    "5"
    "-2"
    "24"
    "4"
    "9"
    "6"
    "3"
    "5"
    "-18"
    "0"

    "2"
    "2"
    "19"
    "10"
    "21"
    "22"
    "0"
    "1"
    "14"
    "6"
)

# Run simple tests
for ((i=0; i<${#TESTS[@]}; i++)); do
    TEST="${TESTS[$i]}"
    EXPECT="${EXPECTED[$i]}"

    echo "Running test: $TEST"
    RESULT=$($PROGRAM "$TEST")

    # Check the result
    if [ "$RESULT" == "$EXPECT" ]; then
        echo "Test passed!"
    else
        echo "Test failed!"
    fi
done

ERROR_TEST=(
    "2 - -"
    "2 2 2 -"
    "test"
)

# Run tests with an error
for TEST in "${ERROR_TEST[@]}"; do
    echo "Running test: $TEST"
    $PROGRAM "$TEST" 2> /dev/null

    if [ $? -eq 1 ]; then
        echo "Program works as expected."
    else
        echo "Program did not catch the error."
    fi
done


echo "Testing complete."

make fclean
