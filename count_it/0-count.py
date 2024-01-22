#!/usr/bin/python3
from collections import Counter
import requests
import sys
"""Function count it"""


def count_words(subreddit, word_list, after='', counter=None):
    """Count word"""
    if counter is None:
        counter = Counter()
    headers = {'User-Agent': 'Keyword Counter Bot 0.1'}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json?limit=100&after={after}"
    response = requests.get(url, headers=headers)

    if response.status_code != 200:
        return

    data = response.json()
    posts = data.get('data', {}).get('children', [])
    if not posts:
        return

    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            word = word.lower()
            counter[word] += title.count(f' {word} ')

    after = data['data']['after']
    if after is not None:
        count_words(subreddit, word_list, after, counter)
    else:
        for word, count in sorted(
                counter.items(), key=lambda item: (-item[1], item[0])):
            if count > 0:
                print(f'{word}: {count}')


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <subreddit> <list of keywords>")
        print(f"Ex: {sys.argv[0]} programming 'python java javascript'")
    else:
        count_words(sys.argv[1], sys.argv[2].split())
