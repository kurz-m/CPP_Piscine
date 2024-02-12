import subprocess
import os

PROGRAM = './RPN'
MAKE = ['re', 'fclean']

# Build the program
if not os.system(f"make {MAKE[0]}") == 0:
    print(f"Error building {PROGRAM}.")
    exit(1)

# Define test cases
TESTS = [
    "2 3 +",
    "5 7 -",
    "4 6 *",
    "8 2 /",
    "1 2 + 3 *",
    "9 3 / 2 *",
    "5 2 / 3 +",
    "0 9 - 2 *",
    "8 4 / 2 -",
    "2 3 4 * + 5 /",
    "1 2 3 * 4 / +",
    "7 3 * 4 2 / -",
    "8 4 / 2 * 6 +",
    "9 2 / 4 * 6 2 / +",
    "5 6 * 2 / 7 +",
    "1 2 + 3 4 * /",
    "4 2 / 3 * 5 -",
    "6 2 * 8 3 / + 3 *",
    "9 4 / 2 * 7 3 / + 6 *",
]

EXPECTED = [
    "5",
    "-2",
    "24",
    "4",
    "9",
    "6",
    "5.5",
    "-18",
    "0",
    "2.8",
    "2.5",
    "19",
    "10",
    "21",
    "22",
    "0.25",
    "1",
    "44",
    "41",
]

# Run simple tests
for TEST, EXPECT in zip(TESTS, EXPECTED):
    print(f"Running test: {TEST}")
    try:
        result = subprocess.check_output([PROGRAM, TEST], text=True).strip()
        if result == EXPECT:
            print(f"Test passed! Result: {result}")
        else:
            print(f"Test failed! Result: {result}")
    except subprocess.CalledProcessError as e:
        print(f"Error running test: {e}")

# Error tests
ERROR_TEST = [
    "2 - -",
    "2 2 2 -",
    "test"
]

for TEST in ERROR_TEST:
    print(f"Running test: {TEST}")
    try:
        subprocess.run([PROGRAM, TEST], check=True, stderr=subprocess.DEVNULL)
        print("Program did not catch the error.")
    except subprocess.CalledProcessError:
        print("Program works as expected.")

print("Testing complete.")

os.system(f"make {MAKE[1]}")
