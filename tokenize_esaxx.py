from datasets import load_dataset
from esa import get_maximal_substrings_char


def main():
    #T = 'abracadabra|||Today is Beautiful day an an an a'
    T = 'シコタン コタンペッ シペッ'
    substrings = get_maximal_substrings_char(T)
    print("count\tlength\tstring")
    for substring in substrings:
        print(f'{substring.count}\t{substring.length}\t{substring.string}')


if __name__=='__main__':
    main()
