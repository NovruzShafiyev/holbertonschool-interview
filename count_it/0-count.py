#!/usr/bin/python3
"""
count_words module
"""

import requests


def count_words(subreddit, word_list, after='', word_count={}):
    """
    Queries the Reddit API, parses the title of all hot articles, and prints a sorted count of given keywords.

    Args:
        subreddit (str): The subreddit to query.
        word_list (list): The list of keywords to count.
        after (str): The next page ID for the Reddit API (used for recursion).
        word_count (dict): The dictionary to store the count of words.
    """
    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after}
    response = requests.get(url, headers=headers, params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data')
    if not data:
        return

    children = data.get('children')
    if not children:
        return

    for child in children:
        title = child.get('data').get('title').lower()
        for word in word_list:
            word_lower = word.lower()
            count = title.split().count(word_lower)
            if count > 0:
                if word_lower in word_count:
                    word_count[word_lower] += count
                else:
                    word_count[word_lower] = count

    after = data.get('after')
    if after:
        return count_words(subreddit, word_list, after, word_count)
    else:
        sorted_word_count = sorted(word_count.items(), key=lambda kv: (-kv[1], kv[0]))
        for word, count in sorted_word_count:
            print(f"{word}: {count}")
