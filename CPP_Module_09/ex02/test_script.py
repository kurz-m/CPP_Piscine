import subprocess
import random
import os

PROGRAM = './PmergeMe'
MAKE = ['re', 'fclean']

def generate_random_list(size):
    return [str(random.randint(0, 100000000)) for _ in range(size)]


def run_test(data):
    args = ['./PmergeMe'] + data
    result = subprocess.run(args, capture_output=True, text=True)
    return result.stdout.strip()


if __name__ == '__main__':
    if not os.system(f"make {MAKE[0]}") == 0:
        print(f"Error building {PROGRAM}.")
        exit(1)

    args = ['./PmergeMe'] + [str(x) for x in range(1, 10)]
    result = subprocess.run(args, capture_output=True, text=True)
    output = result.stdout.strip()
    print(f"Test already sorted array:\n{output}\n")

    data = generate_random_list(5)
    output = run_test(data)
    print(f"Test with 5 numbers:\n{output}\n")

    data = generate_random_list(500)
    output = run_test(data)
    print(f"Test with 500 numbers:\n{output}\n")

    data = generate_random_list(1000)
    output = run_test(data)
    print(f"Test with 1000 numbers:\n{output}\n")

    data = generate_random_list(1250)
    output = run_test(data)
    print(f"Test with 1250 numbers:\n{output}\n")

    data = generate_random_list(2000)
    output = run_test(data)
    print(f"Test with 2000 numbers:\n{output}\n")

    data = generate_random_list(2500)
    output = run_test(data)
    print(f"Test with 2500 numbers:\n{output}\n")

    data = generate_random_list(3411)
    output = run_test(data)
    print(f"Test with 3410 numbers:\n{output}\n")

    data = generate_random_list(5000)
    output = run_test(data)
    print(f"Test with 5000 numbers:\n{output}\n")
