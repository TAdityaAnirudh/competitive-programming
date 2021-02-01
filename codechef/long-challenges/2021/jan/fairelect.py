from sys import stdin, stdout

tests = int(stdin.readline())

while tests > 0:
    n, m = map(int, stdin.readline().split())

    john_votes = list(map(int, stdin.readline().split()))
    jack_votes = list(map(int, stdin.readline().split()))
    john_votes.sort()
    jack_votes.sort()

    # compute total votes
    john_count = sum(john_votes)
    jack_count = sum(jack_votes)

    john_idx = 0
    jack_idx = len(jack_votes) - 1

    count = 0

    while True:
        if john_count > jack_count:
            break
        elif john_idx >= len(john_votes):
            break
        elif jack_idx < 0:
            break
        else:
            if jack_votes[jack_idx] <= john_votes[john_idx]:
                break

            # if we can still increase vote count
            john_count += (jack_votes[jack_idx] - john_votes[john_idx])
            jack_count -= (jack_votes[jack_idx] - john_votes[john_idx])
            john_idx += 1
            jack_idx -= 1
            count += 1

    if john_count > jack_count:
        print(count)
    else:
        print (-1)

    # reduce test count
    tests = tests - 1
