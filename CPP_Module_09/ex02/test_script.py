import subprocess
import random


def generate_random_list(size):
    return [str(random.randint(0, 100000000)) for _ in range(size)]


def run_test(data):
    args = ['./PmergeMe'] + data
    result = subprocess.run(args, capture_output=True, text=True)
    return result.stdout.strip()


if __name__ == '__main__':
    data = generate_random_list(5)
    output = run_test(data)
    print(f"Test with 5 numbers:\n{output}\n")

    data = generate_random_list(500)
    output = run_test(data)
    print(f"Test with 500 numbers:\n{output}\n")

    data = generate_random_list(1000)
    output = run_test(data)
    print(f"Test with 1000 numbers:\n{output}\n")

    data = generate_random_list(5000)
    output = run_test(data)
    print(f"Test with 5000 numbers:\n{output}\n")

    data = generate_random_list(10000)
    output = run_test(data)
    print(f"Test with 10000 numbers:\n{output}\n")

    data = generate_random_list(25000)
    output = run_test(data)
    print(f"Test with 25000 numbers:\n{output}\n")

    data = generate_random_list(50000)
    output = run_test(data)
    print(f"Test with 50000 numbers:\n{output}\n")

    data = generate_random_list(100000)
    output = run_test(data)
    print(f"Test with 100000 numbers:\n{output}\n")
