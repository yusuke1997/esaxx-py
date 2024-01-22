from datasets import load_dataset
from esa import get_maximal_substrings_unicode


def main():
    T = '松島やああ松島や松島や'
    print(T)
    substrings = get_maximal_substrings_unicode(T)
    print("count\tlength\tstring")
    for substring in substrings:
        print(f'{substring.count}\t{substring.length}\t{substring.string}')


if __name__=='__main__':
    main()
